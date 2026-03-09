#pragma execution_character_set("utf-8") // ★ VS에게 모든 글자를 UTF-8로 처리하라고 명령
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iomanip> // 16진수 출력을 위해 추가

using namespace std;

const int MEMORY_SIZE = 30000;

enum class Command {
    START, EXIT, RIGHT, LEFT, LOOP_START, LOOP_END, COND,
    PRINT_INT, PRINT_CHAR, INPUT, UNKNOWN
};
// 키워드 사전 
unordered_map<string, Command> keyword_map = {
    {"야하", Command::START}, {"yaha", Command::START}, {"やは", Command::START}, {"ヤハ", Command::START}, {"呀哈", Command::START},
    {"이얏하!", Command::EXIT}, {"iyah!", Command::EXIT}, {"イヤッハー!", Command::EXIT}, {"哎呀哈!", Command::EXIT},
    {"캬핫", Command::RIGHT}, {"kyahat", Command::RIGHT}, {"きゃはっ", Command::RIGHT}, {"キャハッ", Command::RIGHT}, {"咔哈", Command::RIGHT},
    {"하웁", Command::LEFT}, {"haup", Command::LEFT}, {"はうっ", Command::LEFT}, {"ハウッ", Command::LEFT}, {"哈唔", Command::LEFT},
    {"후응?", Command::LOOP_START}, {"huung?", Command::LOOP_START}, {"ふぅん?", Command::LOOP_START}, {"フゥン?", Command::LOOP_START}, {"哼?", Command::LOOP_START},
    {"푸랴", Command::LOOP_END}, {"purya", Command::LOOP_END}, {"ぷりゃ", Command::LOOP_END}, {"プリャ", Command::LOOP_END}, {"噗呀", Command::LOOP_END},
    {"하아?", Command::COND}, {"haa?", Command::COND}, {"はぁ?", Command::COND}, {"ハァ?", Command::COND}, {"哈?", Command::COND},
    {"우라", Command::PRINT_INT}, {"ura", Command::PRINT_INT}, {"うら", Command::PRINT_INT}, {"ウラ", Command::PRINT_INT}, {"呜啦", Command::PRINT_INT},   // 숫자 출력
    {"우-라-", Command::PRINT_CHAR},{"u-ra-", Command::PRINT_CHAR}, {"うぅらぁ", Command::PRINT_CHAR}, {"ウーラー", Command::PRINT_CHAR}, {"呜—啦—", Command::PRINT_CHAR}, // 문자 출력
    {"하아하아?", Command::INPUT}, {"haha?", Command::INPUT}, {"はぁはぁ?", Command::INPUT}, {"ハァハァ?", Command::INPUT}, {"哈啊哈啊?", Command::INPUT}
};

vector<string> plus_prefixes = { "푸", "pu", "ぷ", "プ", "噗" };
vector<string> minus_prefixes = { "우", "u", "う", "ウ", "呜" };
vector<string> ru_units = { "루", "ru", "る", "ル", "噜", "lu" };

void usagi_panic(const string& token) {
    cerr << "\n하아? 하아아? 하아-?!! ( # ﾟДﾟ)" << endl;
    cerr << " 잘못된 기합 -> [" << token << "]" << endl;
    exit(1);
}

int count_multilingual_ru(const string& token, const vector<string>& prefixes) {
    for (const string& p : prefixes) {
        if (token.find(p) == 0) {
            int count = 0;
            size_t pos = p.length();
            while (pos < token.length()) {
                bool found = false;
                for (const string& unit : ru_units) {
                    if (token.substr(pos, unit.length()) == unit) {
                        count++; pos += unit.length(); found = true; break;
                    }
                }
                if (!found) break;
            }
            return count;
        }
    }
    return 0;
}

void execute_yaha(string filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) return;

    stringstream buffer;
    buffer << file.rdbuf();
    string source = buffer.str();

    // UTF-8 BOM(0xEF 0xBB 0xBF) 제거
    if (source.size() >= 3 && (unsigned char)source[0] == 0xEF && (unsigned char)source[1] == 0xBB && (unsigned char)source[2] == 0xBF) {
        source = source.substr(3);
    }

    // ★ '야하' 찾기 (인코딩이 안 맞으면 여기서 실패함)
    size_t start_pos = string::npos;
    vector<string> starts = { "야하", "yaha", "やは", "ヤハ", "呀哈" };
    for (const auto& s : starts) {
        size_t f = source.find(s);
        if (f != string::npos && (start_pos == string::npos || f < start_pos)) start_pos = f;
    }

    if (start_pos == string::npos) {
        cerr << "하아-?!! ( # ﾟДﾟ)" << endl;
        
        for (int i = 0; i < 5 && i < source.size(); ++i)
            cerr << hex << setw(2) << setfill('0') << (int)(unsigned char)source[i] << " ";
        
        return;
    }

    source = source.substr(start_pos);
    stringstream ss(source);
    vector<string> tokens;
    string t;
    while (ss >> t) tokens.push_back(t);

    vector<int> memory(MEMORY_SIZE, 0);
    int ptr = 0;
    bool is_started = false;

    for (size_t pc = 0; pc < tokens.size(); pc++) {
        string token = tokens[pc];
        if (token[0] == '#' || token[0] == '(') continue;

        if (keyword_map.count(token)) {
            Command cmd = keyword_map[token];
            if (cmd == Command::START) { is_started = true; continue; }
            if (!is_started) continue;

            switch (cmd) {
            case Command::EXIT: return;
            case Command::RIGHT: ptr++; 
                if (ptr >= MEMORY_SIZE) usagi_panic("하아?( # ﾟДﾟ)");
                break;
            case Command::LEFT: ptr--; 
                if (ptr >= MEMORY_SIZE) usagi_panic("하아? ( ﾟДﾟ # )");
                break;
            case Command::PRINT_INT: cout << memory[ptr] << " "; break;
            case Command::PRINT_CHAR: cout << (char)memory[ptr]; break;
            case Command::INPUT: cin >> memory[ptr]; break;
            case Command::COND:
                if (memory[ptr] == 0) {
                    pc++; // 일단 다음으로 이동
                    // 주석(# 또는 ()이 나오면 진짜 명령어를 만날 때까지 계속 전진!
                    while (pc < tokens.size() && (tokens[pc][0] == '#' || tokens[pc][0] == '(')) {
                        pc++;
                    }
                }
                break;
            case Command::LOOP_START:
                if (memory[ptr] == 0) {
                    int nest = 1;
                    while (nest > 0 && pc < tokens.size() - 1) {
                        pc++;
                        if (keyword_map.count(tokens[pc])) {
                            if (keyword_map[tokens[pc]] == Command::LOOP_START) nest++;
                            if (keyword_map[tokens[pc]] == Command::LOOP_END) nest--;
                        }
                    }
                }
                break;
            case Command::LOOP_END:
                if (memory[ptr] != 0) {
                    int nest = 1;
                    while (nest > 0 && pc > 0) {
                        pc--;
                        if (keyword_map.count(tokens[pc])) {
                            if (keyword_map[tokens[pc]] == Command::LOOP_END) nest++;
                            if (keyword_map[tokens[pc]] == Command::LOOP_START) nest--;
                        }
                    }
                }
                break;
            }
        }
        else if (is_started) {
            int inc = count_multilingual_ru(token, plus_prefixes);
            if (inc > 0) { memory[ptr] += inc; continue; }
            int dec = count_multilingual_ru(token, minus_prefixes);
            if (dec > 0) { memory[ptr] -= dec; continue; }
            usagi_panic(token);
        }
    }
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        ofstream tmp("ura world.yaha");
        tmp << "야하 푸루루루루루루루루루루 후응? 캬핫 푸루루루루루루루루루루루루 캬핫 푸루루루루루루루루루루 캬핫 푸루루루 캬핫 푸루루루루루루루루루루루루 캬핫 푸루루루루루루루루루루 하웁 하웁 하웁 하웁 하웁 우루 푸랴 캬핫 우루루루 우-라- 우루루루 우-라- 캬핫 우루루루 우-라- 캬핫 푸루루 우-라- 캬핫 푸루 우-라- 하웁 하웁 우-라- 캬핫 캬핫 캬핫 푸루루루루 우-라- 하웁 하웁 하웁 우-라- 이얏하!";
        tmp.close();
        cout << "" << endl;
        execute_yaha("ura world.yaha");
    }
    else {
        execute_yaha(argv[1]);
    }
    return 0;
}