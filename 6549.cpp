#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long > h;
long long solve(int l, int r){
    if(l == r) return h[l];
    int mid = (l+r)/2;
    long long ret = max(solve(l, mid), solve(mid+1,r));

    int lo = mid, hi = mid+1;
    long long height = min(h[lo],h[hi]);
    ret = max(ret, height*2);
    while( l < lo || hi < r){
        if(hi < r && (lo == l || h[lo-1]<h[hi+1])){
            ++hi;
            height = min(height, h[hi]);

        }
        else{
            --lo;
            height = min(height, h[lo]);
        }
        ret = max(ret,height * (hi - lo + 1));
    }
    return ret;
}

int main(void){
    while(true){
        int N;
        cin >> N;
        if(N == 0 ) break;
        while(!h.empty()){
            h.pop_back();
        }
        for(int i = 0 ;i<N ;i++){
            long long height;
            cin >> height;
            h.push_back(height);
        }
        cout << solve(0,h.size())<< "\n";
    }
}