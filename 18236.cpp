#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N, n;
    int m[10001][10001];
    long long rst = 0;
    vector<int> P;
    cin >> N;
    for(int i = 0;i<N;i++){
        int r,c;
        cin >> r >> c;
        if(i == 0 ) P.push_back(r);
        P.push_back(c);
    }
    n = P.size()-1;
    for(int j = 1 ;j<=n;j++){
        m[j][j] = 0;
    }
    for(int l = 2; l<=n;l++){
        for(int i = 1;i<=n-l+1;i++){
            int j = i+l -1;
            m[i][j] = 922337;
            for(int k = i;k<=j-1;k++){
                long long q = m[i][k] + m[k+1][j] + P[i-1]*P[k]*P[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                }
            }  
        }      
    }
    cout << m[1][n]<<"\n";

}