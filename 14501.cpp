#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int N;
    int dp[16];
    int T[16], P[16];

    cin >> N;
    for(int i =1;i<=N;i++){
        cin >> T[i] >> P[i];
        dp[i] = 0;
    }

    for(int i = 1; i<= N ; i++){
        if(T[i] + i > N+1) continue;
        dp[i] = P[i];
        for(int j =1; j<=i;j++){
            if(i >= j+T[j]){
                dp[i] = max(dp[i] , dp[j] + P[i]);
            }
        }
    }
    int maxi = 0;
    for(int i = 1;i<=N;i++){
        maxi = max(maxi, dp[i]);
    }
    cout << maxi << "\n";
}