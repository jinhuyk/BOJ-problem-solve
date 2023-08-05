#include <iostream>

using namespace std;

int P[1001];
int dp[1001];

void solve(int N){
    for(int i = 1;i<=N;i++){
        dp[i] = P[i];
        for(int j = 1;i-j>=1;j++){
            dp[i] = max(dp[i], P[j]+dp[i-j]);
        }
    }
    cout << dp[N] << "\n";
}

int main(void){
    int N;
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> P[i];
    }
    solve(N);
}