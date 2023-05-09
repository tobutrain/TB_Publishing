dataArray = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
pointerArray = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
Top = 0
num = 0
cur,prv = -1
data = -1

def changeCurData(nextIdx):
    prv = cur
    cur = nextIdx
    return dataArray[nextIdx]

def addData(inputData):
    curIdx = Top
    addIdx = -1
    for i in range(10):
        if dataArray[i] == -1:
            addIdx = i
            break
    if addIdx == -1:
        print("追加不可")
        return -1
    else:
        dataArray[addIdx] = inputData
    
    return 0


    

def deleteData(changeIdx):
    curIdx = Top
    for i in range(num):
        if pointerArray[i] == changeIdx:
            break
        else:
            prvChgIdx = i
            i = pointerArray[i]
    pointerArray[prvChgIdx] = pointerArray[changeIdx]
    dataArray[changeIdx] = -1


while True:
    print("数値を入力: ",end="")
    inNum = int(input())
    if inNum == -1:
        break

print("入力終了")

cur = Top
for i in range(num):
    outNum = changeCurData(cur)

