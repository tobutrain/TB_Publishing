dataArray = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]  # データ配列
pointerArray = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]  # 次要素の添字
Top = 0  # 先頭要素の添字
num = 0  # 要素数
prv = -1

# inputValueをdataArrayの空いている先頭要素に追加する
# 返り値: 代入した場所の添字, 代入できなかったら-1を返す
def addData(inputValue):
    global dataArray, pointerArray, num
    for i in range(0,10):
        if dataArray[i] == -1:
            dataArray[i] = inputValue
            num = num + 1
            return i
    return -2

# removeIdxで指定した添字の場所のデータを削除し，前に詰める
# 返り値: なし
def removeData(removeIdx):
    global dataArray, pointerArray, Top, num
    curIdx = Top
    prevIdx = -1
    for i in range(0,10):
        if curIdx == removeIdx:
            if prevIdx != -1:
                pointerArray[prevIdx] = pointerArray[curIdx]
            else:
                Top = pointerArray[curIdx]
            dataArray[removeIdx] = -1
            pointerArray[removeIdx] = -1
            #print("true"+str(curIdx)+str(prevIdx))
            break
        else:
            prevIdx = curIdx
            curIdx = pointerArray[curIdx]
            #print("else"+str(curIdx)+str(prevIdx))
    num = num - 1

# inputValueで指定したデータをdataArrayから探し，有無を返す
# 返り値: 値がある->1, 値がない->0
def searchValue(inputValue):
    global dataArray
    for i in range(0,10):
        if inputValue == dataArray[i]:
            return 1
    return 0

# inputValueで指定したデータをdataArrayから探し，その添字を返す
# 返り値: データが格納されている場所の添字, ない場合は-2を返す
def searchIndex(inputValue):
    global dataArray
    for i in range(0,10):
        if inputValue == dataArray[i]:
            return i
    return -2


print("数値を入力")
while True:
    inNum = int(input())  # 値を入力する
    if inNum <= 0:  # 入力値が-1なら処理を終了する
        break
    #print(searchValue(inNum))
    if searchValue(inNum) == 1:  # 配列内に入力値があるかどうかを探索する
        # 値がある場合の処理
        cur = searchIndex(inNum)
        removeData(cur)
    else:
        # 値がない場合の処理
        cur = addData(inNum)
        if cur == -2:
            print("代入できません")
        if prv != -1:
            pointerArray[prv] = cur
        prv = cur
    #print(dataArray)
    #print(pointerArray)

print("入力終了")

cur = Top
for i in range(num):
    print(str(dataArray[cur])+", ",end="")
    cur = pointerArray[cur]