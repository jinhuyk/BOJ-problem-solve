#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int> max_heap;

int N;

void solve(){
    if(!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()){
        int t1,t2;
        t1 = max_heap.top(); max_heap.pop();
        t2 = min_heap.top(); min_heap.pop();
        max_heap.push(t2); min_heap.push(t1);
    }
    cout << max_heap.top()<<"\n";
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0;i<N;i++){
        int a; cin >> a;
        if(max_heap.size() == min_heap.size()){
            max_heap.push(a);
        }else min_heap.push(a);
        solve();
    }
    
    return 0;
}