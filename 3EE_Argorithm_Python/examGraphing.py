examPoint = [100,69,45,83,52,31,14,2,4,50,3,52,69,85,98,33,40,69,59]  # 試験の点数を記録する配列

for num in range(len(examPoint)):
    graph = []
    cnt = 0
    for star in range(0,int(examPoint[num]/10)):
        graph = graph + ["*"]
        cnt = cnt + 1
    for space in range(10-cnt):
        graph = graph + [" "]
    
    print("{0:2}人目: ".format(num+1),end="")
    for i in range(0,len(graph)):
        print(graph[i],end="")
    print("")
        