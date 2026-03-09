---------------------------------------------------------------------------------------------------------------------------------------------------------

Korean



🐰 Yaha-Lang (야하랭)

먼작귀(ちいかわ)의 토끼 (うさぎ)의 언어로 코딩하는 프로그래밍 언어입니다.

🌟우사기란?

우사기 (うさぎ / Usagi)

나노(Nagano) 작가의 만화 '먼작귀(치이카와)'에 등장하는 주인공 3인방 중 한 명으로, 이 구역의 광기어린 천재이자 자유로운 영혼을 담당하고 있습니다.

🛠️ 설치 및 실행 방법

1\. 필요한 파일

yaha.exe (엔진 실행 파일)

run.bat (실행용 배치 파일)



2\. 실행 순서

작성한 코드를 .yaha 확장자로 저장합니다. (예: test.yaha)

저장한 .yaha 파일을 run.bat 파일 위로 드래그 앤 드롭합니다.

우사기의 언어가 컴퓨터 언어가 되었습니다!



📝 문법

야하랭은 0번부터 29,999번까지의 메모리 칸을 가집니다. 

커맨드는 다음과 같습니다.



\*\*\*\*\*중국어 커맨드는 현재 정상 작동하지 않습니다.\*\*\*\*\*\*\*

시작 (START)

야하, yaha, やは, ヤハ, 呀哈



종료 (EXIT)

이얏하!, iyah!, イヤッハー!, 哎呀哈!



오른쪽 이동 (RIGHT)

캬핫, kyahat, きゃはっ, キャハっ, 咔哈



왼쪽 이동 (LEFT)

하웁, haup, はうっ, ハウッ, 哈唔



루프 시작 (LOOP\_START)

후응?, huung?, ふぅん?, フゥン?, 哼?



루프 종료 (LOOP\_END)

푸랴, purya, ぷりゃ, プリャ, 噗呀



조건문 (COND)

하아?, haa?, はぁ?, ハァ?, 哈?



숫자 출력 (PRINT\_INT)

우라, ura, うら, ウラ, 呜啦



문자 출력 (PRINT\_CHAR)

우-라-, u-ra-, うぅらぁ, ウーラー, 呜—啦—



입력 (INPUT)

하아하아?, haha?, はぁはぁ?, ハァハァ?, 哈啊哈啊?



증감 연산 로직

푸루 (1 증가), 푸루루 (2 증가), 푸루루루 (3 증가)...

puru, pururu, purururu...

ぷる, ぷるる, ぷるるる...

プル,プルル,プルルル...

噗噜, 噗噜噜, 噗噜噜噜...

(앞의 글자를 제외한 '루/ru/ル/噜'의 개수만큼 현재 칸의 값이 커집니다.)



기합 빼기 (Decrement)

우루 (1 감소), 우루루 (2 감소), 우루루루 (3 감소)...

uru, ururu, urururu...

うる, うるる, うるるる...

ウル,ウルル,ウルルル...

呜噜, 呜噜噜, 呜噜噜噜...

(앞의 글자를 제외한 '루/ru/ル/噜'의 개수만큼 현재 칸의 값이 작아집니다.)



⚠️ 주의사항 (필독!)

주석 사용 시 공백 금지

주석을 달 때는 반드시 띄어쓰기(공백)가 없어야 합니다. 안전한 예: #이것은\_주석입니다, (이것은\_주석입니다)



💡 간단한 예시

example 폴더에서 코드 예시를 확인할 수 있습니다.

1.echo.yaha

사용자가 입력한 숫자를 숫자와 문자로 동시에 보여줍니다.



2\. zero\_check.yaha

입력값이 0이면 0을, 아니면 1을 더해 출력합니다.



3\. even\_odd.yaha

입력값이 짝수면 0을, 홀수면 -1을 출력합니다.



4.star\_pyramid.yaha

입력값 만큼의 줄의 역피라미드를 출력합니다.



---------------------------------------------------------------------------------------------------------------------------------------------------------------

English



🐰 Yaha-Lang (야하랭)

A programming language coded in the energetic language of Usagi from the manga Chiikawa (ちいかわ).



🌟 Who is Usagi?

Usagi (うさぎ) is one of the three main protagonists in Nagano's manga Chiikawa. He is the resident "mad genius" and "free spirit," known for his unpredictable behavior and signature high-energy screams.



🛠️ Installation \& Execution

1\. Required Files

yaha.exe (The engine/interpreter)



run.bat (Batch file for easy execution)



2\. How to Run

Save your code with the .yaha extension (e.g., test.yaha).



Drag and drop your .yaha file onto the run.bat file.



Usagi's language has now become a computer language!



📝 Syntax

Yaha-Lang uses a memory array consisting of 30,000 cells (indices 0 to 29,999).



Commands

⚠️ Note: Chinese commands are currently not functioning correctly.



START 야하, yaha, 야は, ヤハ, 呀哈



EXIT 이얏하!, iyah!, イヤッハー!, 哎呀哈!



RIGHT (Move pointer right) 캬핫, kyahat, きゃはっ, キャハっ, 咔哈



LEFT (Move pointer left) 하웁, haup, はうっ, ハウッ, 哈唔



LOOP\_START (Start while current cell != 0) 후응?, huung?, ふぅん?, フゥン?, 哼?



LOOP\_END (End while loop) 푸랴, purya, ぷりゃ, プリャ, 噗呀



COND (Skip next command if current cell == 0) 하아?, haa?, はぁ?, ハァ?, 哈?



PRINT\_INT (Output as integer) 우라, ura, うら, ウラ, 呜啦



PRINT\_CHAR (Output as ASCII character) 우-라-, u-ra-, うぅらぁ, ウーラー, 呜—啦—



INPUT (Integer input) 하아하아?, haha?, はぁはぁ?, ハァ하ぁ?, 哈啊哈啊?



Increment/Decrement Logic

The value changes based on the number of "ru" characters following the initial sound.



Increment (+) - 푸루 (+1), 푸루루 (+2), 푸루루루 (+3)...



puru, pururu, purururu...



ぷる, ぷるる, ぷるるる...



プル, プルル, プルルル...



噗噜, 噗噜噜, 噗噜噜噜...



(The value increases by the count of "루/ru/ル/噜" excluding the first character.)



Decrement (-) - 우루 (-1), 우루루 (-2), 우루루루 (-3)...



uru, ururu, urururu...



うる, うるる, うるるる...



ウル, ウルル, ウルルル...



呜噜, 呜噜噜, 呜噜噜噜...



(The value decreases by the count of "루/ru/ル/噜" excluding the first character.)



⚠️ Important Warning (Read Carefully!)

NO SPACES IN COMMENTS

Comments must not contain any spaces. The interpreter treats words separated by spaces as separate commands.



✅ Safe: #This\_is\_a\_comment, (This\_is\_a\_comment)



❌ Unsafe: # This is a comment



💡 Examples

Check out the example folder for more sample codes.



echo.yaha Displays the user's input as both a number and an ASCII character.



zero\_check.yaha Outputs 0 if the input is 0, and increments to 1 otherwise.



even\_odd.yaha Outputs 0 for even numbers and -1 for odd numbers.



star\_pyramid.yaha Prints an inverted pyramid with a height based on the user's input.





-----------------------------------------------------------------------------------------------------------------------------------------------------------

Japanese



🐰 Yaha-Lang (ヤハラン)

人気漫画『ちいかわ』に登場するうさぎの言葉でコーディングする、世界初のプログラミング言語（難解プログラミング言語）です。



🌟 うさぎ（Usagi）とは？

ナガノ先生による漫画『ちいかわ』に登場する主要キャラクター。

常にテンションが高く、「ヤハ！」「ウラ！」「プルルル！」といった奇声を発する\*\*「狂気的な天才」であり、「自由な魂」\*\*の持ち主です。予測不能な行動で周囲を驚かせますが、実は非常に高い能力を秘めています。



🛠️ インストールおよび実行方法

1\. 必要なファイル

yaha.exe (エンジン実行ファイル)



run.bat (実行用バッチファイル)



2\. 実行手順

作成したコードを .yaha 拡張子で保存します。（例：test.yaha）



保存した .yaha ファイルを run.bat ファイルの上にドラッグ＆ドロップします。



うさぎの言葉がコンピュータ言語として動き出します！



📝 文法

ヤハランは 0番から 29,999番までのメモリセルを持ちます。

コマンドは以下の通りです。



⚠️ 注意: 中国語コマンドは現在、正常に動作しません。



開始 (START)

ヤハ, yaha, やは, ヤハ, 呀哈



終了 (EXIT)

イ얏하! (イヤッハー!), iyah!, イヤッハー!, 哎呀哈!



右へ移動 (RIGHT)

캬핫 (キャハッ), kyahat, きゃはっ, キャハっ, 咔哈



左へ移動 (LEFT)

하웁 (ハゥッ), haup, はうっ, ハウッ, 哈唔



ループ開始 (LOOP\_START)

후응? (フゥン?), huung?, ふぅん?, フゥン?, 哼?



ループ終了 (LOOP\_END)

푸랴 (プリャ), purya, ぷりゃ, プリャ, 噗呀



条件分岐 (COND)

하아? (ハァ?), haa?, はぁ?, ハァ?, 哈?



数値出力 (PRINT\_INT)

우라 (ウラ), ura, うら, ウラ, 呜啦



文字出力 (PRINT\_CHAR)

우-라- (ウーラー), u-ra-, うぅらぁ, ウーラー, 呜—啦—



入力 (INPUT)

하아하아? (ハァハァ?), haha?, はぁはぁ?, ハァハァ?, 哈啊哈啊?



増減演算ロジック（インクリメント/デクリメント）

「る/ru/ル/噜」の数によって値が変化します。



値を増やす (Increment)



ぷる (+1), ぷるる (+2), ぷるるる (+3)...



puru, pururu, purururu...



푸루, 푸루루, 푸루루루...



プル, プルル, プルルル...



噗噜, 噗噜噜, 噗噜噜噜...



(最初の文字を除いた「る/ru/ル/噜/루」の数だけ現在のセルの値が増加します。)



値を減らす (Decrement)



うる (-1), うるる (-2), うるるる (-3)...



uru, ururu, urururu...



우루, 우루루, 우루루루...



ウル, ウルル, ウルルル...



呜噜, 呜噜噜, 呜噜噜噜...



(最初の文字を除いた「る/ru/ル/噜/루」の数だけ現在のセルの値が減少します。)



⚠️ 注意事項 (必読!)

コメント使用時の空白禁止

コメントを記述する際は、絶対にスペース（空白）を入れないでください。 インタプリタがスペースで区切られた単語をコマンドとして誤認してしまいます。



✅ 安全な例: #これは\_コメントです, (これは\_コメントです)



❌ 危険な例: # これは コメント です



💡 簡単な例

example フォルダにコードの例が用意されています。



echo.yaha: 入力された数値を「数値」と「文字（ASCII）」で同時に出力します。



zero\_check.yaha: 入力値が0なら0を、それ以外なら1を加えて出力します。



even\_odd.yaha: 入力が偶数なら0、奇数なら-1を出力します。



star\_pyramid.yaha: 入力された数値の高さの逆ピラミッド（星型）を出力します。

