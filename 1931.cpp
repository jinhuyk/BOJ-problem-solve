#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main(void){
    int N;
    int s,f;
    vector<pair<int, int> > T;

    cin >> N;
    for(int i = 0 ;i<N;i++){
        cin >> s >> f;
        T.push_back(pair<int, int>(s,f));
    }
    
    sort(T.begin(), T.end(), compare);
    int k = 0;
    int count  = 0;
    for(int m = 1;m < N;m++){
        if(T[m].first >= T[k].second){
            // cout << m << " " << k <<"\n";
            k = m;
            count++;
        }
    }
    cout << count +1 << "\n";
}