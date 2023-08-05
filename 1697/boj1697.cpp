#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int pos;
    int time;
};
int main(void){
    int N, K;
    cin >> N >> K;

    int minTime = 100001;
    queue<pos> n;
    bool check[100001] = {false};
    
    n.push({N,0});
    while(!n.empty()){
        int pos = n.front().pos;
        int time = n.front().time;
        n.pop();
        if(pos > 100000 || pos < 0) continue;
        if(check[pos]) continue;
        check[pos] = true;

        if(pos == K) minTime = min(minTime, time);
        if(time > minTime) break;
        n.push({pos+1, time+1});
        n.push({pos-1, time+1});
        n.push({pos*2, time+1});
    }
    cout << minTime << endl;
}