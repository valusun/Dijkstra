#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct edge{
  int to,cost;
};

long long INF = 1000000000;

int main(){
    int V,E,r;
    cin >> V >> E >> r;
    
    vector<edge> Graph[V];
    for(int i=0; i<E; i++){
        int s,t,d;
        cin >> s >> t >> d;
        Graph[s].push_back((edge){t,d});
    }

    vector<long long> Min_Cost(V, INF);
    Min_Cost[r]=0;

    priority_queue<pair<int,int>> Q;
    Q.push(make_pair(0,r));

    while(!Q.empty()){
        
        // Queueの先頭を取り出す
        pair<int,int> Q_top = Q.top();
        Q.pop();
        // それぞれをv(頂点)とd(重み)に振り分ける
        // priority_queueは降順に出力するため、重みを-変換している(1->-1, 2->-2 ... -1が取り出される)
        int v=Q_top.second;
        int d=-Q_top.first;
        // 暫定の最短経路よりdが大きければ処理を行わない
        if(Min_Cost[v]<d) continue;

        for(int i=0;i<Graph[v].size();i++){
            edge e = Graph[v][i];
            int next_v = e.to;
            int next_d = e.cost;
            int tmp = d+next_d;
            if(Min_Cost[next_v]>tmp){
                Min_Cost[next_v] = tmp;
                Q.push(make_pair(-tmp,next_v));
            }
        }
    }

    for(int i=0;i<V;i++){
        if(Min_Cost[i]==INF)printf("INF\n");
        else cout << Min_Cost[i] << endl;
    }

    return 0;
}