itemName = ["商品A","商品B","商品C","商品D","商品E"]  # 商品名を定義した配列 itemName[5] (要素数5)
votesNum = [0,0,0,0,0]  # 得票数を記録する配列 votesNum[5] (要素数5)
print("投票を入力")  # 画面に"投票を入力"と出力する

# 配列でカウントをする作業部分
while True :  # breakされるまで繰り返す (Trueの間繰り返す -> 無限に繰り返す(Falseになることがないから) )
    numIn = int(input())  # 変数 numIn に，画面で入力された値をint型にキャスト(変換)して代入する
    if numIn == -1 :  # もし入力された値が-1なら
        break  # breakする (Whileループから抜け出す)
    votesNum[numIn] = votesNum[numIn] + 1  # votesNumの，numIn番目の要素を +1 する。

# 1番得票数が多かったものを並び替えで特定する作業部分
topItem = 0  # 並べ替えで使用する変数 topItem を 0 に初期化する。最終的にこの変数には，得票数が一番多かった商品の添字が代入される。
for i in range(1,len(votesNum)):  # 変数 i が，1から votesNumの要素数まで+1される間に
    if votesNum[i-1] < votesNum[i]:  # もし，votesNumの i番目の要素が，i-1番目の要素より大きかったら
        topItem = i  # topItemにiを代入する

# 最後に人気商品を出力する部分
print("人気商品")  # "人気商品"と出力する
print(itemName[topItem])  # itemNameのtopItem番目の要素を出力する
