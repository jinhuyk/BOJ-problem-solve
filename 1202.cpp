#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> Jew[300100];
int bag[300100];
priority_queue<int> pq;
int N,K;
void solve(){
    unsigned long long sum = 0;
    int now  = 0;
    sort(Jew, Jew+N);
    sort(bag, bag+K);
    for(int i =0;i<K;i++){
        while(now < N && bag[i] >= Jew[now].first){
            pq.push(Jew[now++].second);
        }
        if(!pq.empty()){
            sum += pq.top(); pq.pop();
        }
    }
    cout << sum << "\n";
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;
    cin >> N >> K;
    for(int i = 0; i< N ;i++){
        cin >> Jew[i].first >> Jew[i].second;
    }
    for(int i = 0;i<K;i++){
        cin >> bag[i];
    }
    solve();
    return 0;
}