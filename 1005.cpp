#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> cost;
vector<int> order;
vector< vector<int> > build;
vector<int> d;

void solve(int N, int W){
    queue<int> Q;
    for(int i = 1;i<=N;i++){
        if(order[i] == 0){
            Q.push(i);
            d[i] = cost[i];
        }
    }
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        if(now == W) break;
        for(int &next : build[now]){
            if(--order[next] == 0) Q.push(next);
            d[next] = max(d[next], d[now]+cost[next]);
        }
    }
    cout << d[W] << "\n";
}


int main(void){
    int T;
    int N, K, W;
    cin >> T;

    while(T--){
        cost.clear();
        order.clear();
        build.clear();
        d.clear();
        
        cin >> N >> K;

        cost.resize(N+1);
        order.resize(N+1);
        build.resize(N+1);
        d.resize(N+1);

        for(int i = 1;i<=N;i++){
            cin >> cost[i];
        }
        for(int i = 1;i<=K;i++){
            int a,b;

            cin >> a >> b;

            build[a].push_back(b);
            order[b]++;

        }
        cin >> W;
        solve(N,W);
    }
}