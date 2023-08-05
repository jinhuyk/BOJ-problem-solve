#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

pair <int, int> times[200001];
priority_queue<int, vector<int>, greater<int> > pq;

int N;

bool cmp(pair <int, int>  A, pair <int, int>  B){
    return A.first < B.first;
}

void solve(){
    sort(times+1, times+N+1, cmp);

    pq.push(times[1].second);
    for(int i = 2 ; i<=N;i++){
        if(pq.top() <= times[i].first) pq.pop();
        pq.push(times[i].second);
    }
    cout << pq.size() << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i<=N;i++){
        cin >> times[i].first >> times[i].second;
    }
    solve();
    return 0;
}