#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector < pair < int, int > > Pos;
long long outer(pair<long long, long long> x,pair<long long, long long> y){
    return x.first * y.second - x.second*y.first;
}

int N;
void solve(){
    double A = 0;
    for(int i = 1;i<N-1;++i){
        A  += (double)(outer({Pos[i].first - Pos[0].first, Pos[i].second-Pos[0].second},{Pos[i+1].first - Pos[0].first, Pos[i+1].second-Pos[0].second})/2.0);
    }
    
    printf("%.1lf",abs(A));

}

int main(void){
    cin >> N;
    for(int i = 0;i<N;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        Pos.push_back({x,y});
    }
    solve();
}