#include <iostream>
#include <queue>

#include <vector>

using namespace std;

int N, M;
vector <int> V[1001];
int counter[1001];

void solve(){
    vector<int> Answer;

    queue <int> PQ;
    for(int i = 1;i<=N;i++){
        if(counter[i] == 0 ) PQ.push(i);
    }
    
    while(!PQ.empty()){
        int now = PQ.front(); PQ.pop();
        Answer.push_back(now);
        for(int i = 0; i<V[now].size();i++){
            counter[V[now][i]]--;
            if(counter[V[now][i]] == 0) PQ.push(V[now][i]);
            
        }
    }
    if(Answer.size() != N) cout << 0 << "\n";
    else for(auto i : Answer) cout << i <<"\n";
}

int main(void){
    cin >> N >> M;
    for(int i = 1;i<=M;i++){
        int K;
        cin >> K;
        int now, next;
        cin >> now;
        for(int j=1;j<K;j++){
            cin >> next;
            counter[next]++;
            V[now].push_back(next);
            now = next;
        }
    }
    solve();
    return 0;
}