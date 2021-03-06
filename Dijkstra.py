import heapq

# 入力情報の受取
V,E,r = map(int,input().split())
Graph = list([] for _ in range(V))

for i in range(E):
    s,t,d = map(int,input().split())
    Graph[s].append([t,d])

# 最短経路の格納
Min_Cost = [float('inf')]*V
Min_Cost[r] = 0

# スタートからの距離と次に進む頂点を格納
Q = [[0,r]]

# 最短経路を更新していく
while Q:

    # d...重み/v...頂点
    # deappopを使えば、第一要素が小さい順から取り出してくれる
    d,v = heapq.heappop(Q)

    # 最短距離よりも到着距離が長ければ処理を行わない
    if Min_Cost[v]<d:
        continue

    for next_v, next_d in Graph[v]:
        # vまでの最短経路+次の頂点までの距離が最短距離ならば更新
        tmp = d+next_d
        if Min_Cost[next_v]>tmp:
            Min_Cost[next_v] = tmp
            # next_vを介して他の頂点に最短距離で行く可能性有
            heapq.heappush(Q, [tmp, next_v])

# 出力
for i in range(V):
    if Min_Cost[i] == float('inf'):
        print("INF")
    else:
        print(Min_Cost[i])