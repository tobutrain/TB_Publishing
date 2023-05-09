dataArray = []
pointerArray = []
Top = 0

for i in range(10):
    dataArray = dataArray + [-1]
    pointerArray = pointerArray + [-1]

print("数値を入力")

#初回入力
inNum = int(input())
for i in range(10):
    if dataArray[i] == -1:
        dataArray[i] = inNum
        Top = i
        break

#継続入力
while True:
    # リスト入力
    inNum = int(input())
    if inNum < 0:
        break
    for i in range(10):
        if dataArray[i] == -1:
            dataArray[i] = inNum
            break