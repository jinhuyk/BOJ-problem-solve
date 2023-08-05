#include <iostream>
#include <queue>

#include <vector>

using namespace std;

int N, M;
vector <int> V[32001];
int counter[32001];

void solve(){

    priority_queue <int , vector<int> , greater<int> > PQ;
    for(int i = 1;i<=N;i++){
        if(counter[i] == 0 ) PQ.push(i);
    }

    while(!PQ.empty()){
        int now = PQ.top(); PQ.pop();
        cout << now << " ";
        for(int i = 0; i<V[now].size();i++){
            if(counter[V[now][i]] == 1) PQ.push(V[now][i]);
            counter[V[now][i]]--;
        }
    }
}

int main(void){
    cin >> N >> M;
    for(int i = 1;i<=M;i++){
        int a,b;
        cin >> a >> b;
        counter[b]++;
        V[a].push_back(b);
    }
    solve();
    return 0;
}