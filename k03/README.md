# 課題3 レポート
学生番号　氏名


## 課題  

以下の2つのアルゴリズムで文字列を検索するプログラムを作成する。  
- 力ずく法
- BM法

1. 使用するデータ  
以下のデータを使用する。ただし、検索対象文字列、検索する文字列は変更しても良い。  
    - StrOriginal: 検索対象データ
    - StrKey: 検索する文字列

2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。C言語の標準ライブラリは使用しないこと。  
    (1) ForceSearch: 力ずく法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  

    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

    (2) BMSearch: BM法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  
 
    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

3. 補助関数  
なし

## ソースコードの説明
ForceSearch
-探索対象文字列と探索する文字列の文字数をそれぞれlen1,len2に格納する
‐startは検索対象文字列内での比較開始位置、posは探索する文字列内での比較している場所を表す
-1つ目のfor文は検索対象文字列で比較開始位置を頭から１つずらしていくため
‐2つ目のfor文は検索対象文字列と検索する文字列のそれぞれの文字を比較していっている
‐1つ合うごとに比較位置を１つ後ろにずらす
‐合わなければ、２つ目のfor文を抜ける
‐比較していき、検索する文字列の文字数と比較する位置+1の値が等しくなったら、その時の比較開始位置を出力する
‐見つからなかった場合NULLを出力する

BMSearch
‐比較して一致しなかった場合の比較開始位置をどれだけずらすかを決めるテーブルを作成する
‐とりあえず一致しなかった場合、すべての文字において検索する文字列分ずらすようにする
‐検索する文字列の後ろの文字からずらす量を0から順に1ずつ増やしていく。そしてそれを先ほど決めたテーブルの対応する場所に新たに代入していく
‐探索対象文字列と探索する文字列の文字数をそれぞれlen1,len2に格納する
‐startは検索対象文字列内での比較開始位置、posは探索する文字列内での比較している場所を表す
‐BM法は検索する文字列の後ろから比較していくので、startの値をlen2-1とする
‐はじめのwhile文は比較開始位置をずらしていく
‐次のfor文では検索する文字列とそれに対応する検索対象文字列を比較していく
‐1つ合うごとに比較位置を１つ前にずらす
‐合わなければ、for文を抜ける
‐posの値が0となったらその時の比較開始位置を出力する
‐比較開始位置ははじめの方で決めたテーブルに従ってずれていくようにするために、間違った文字に対応するtableの値を現在のstartの値に足していく
‐見つからなかった場合NULLを出力する

## 出力結果

```
PS C:\Users\bb35319050\OneDrive - Nagasaki University\ドキュメント\GitHub\2020psp3\k03> & .\"k03.exe" 
Force Search. Find keyword at:wind in my hair.
On a dark deseart highway, cool wind in my hair.
wind
On a dark deseart highway, cool wind in my hair.
    wind
On a dark deseart highway, cool wind in my hair.
        wind
On a dark deseart highway, cool wind in my hair.
            wind
On a dark deseart highway, cool wind in my hair.
                wind
On a dark deseart highway, cool wind in my hair.
                  wind
On a dark deseart highway, cool wind in my hair.
                      wind
On a dark deseart highway, cool wind in my hair.
                          wind
On a dark deseart highway, cool wind in my hair.
                              wind
On a dark deseart highway, cool wind in my hair.
                                wind
BM Search. Find keyword at:wind in my hair.
```

## 修正履歴

