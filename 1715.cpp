#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int N;

void solve(){
    int cmp = 0;

    while(pq.size() > 1){
        int t1, t2;
        t1 = pq.top(); pq.pop();
        t2 = pq.top(); pq.pop();
        pq.push(t1+t2);
        cmp += t1+t2;
    }
    cout << cmp << "\n";

}
int main(void){
    cin >> N;
    for(int i = 0;i<N;i++){
        int a;
        cin >> a; pq.push(a);
    }
    solve();
    return 0;
}