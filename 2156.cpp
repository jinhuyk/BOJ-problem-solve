#include <iostream>

using namespace std;

int main(void)
{
    int stair[10001];
    int dp[10001];
    int N;

    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> stair[i];
    }
    dp[1] = stair[1];
    dp[2] = stair[1]+stair[2];
    for(int i = 3;i<=N;i++){
        dp[i] = max(dp[i-2]+stair[i], dp[i-1]);
        dp[i] = max(dp[i], stair[i]+stair[i-1]+dp[i-3]);
    }
    cout << dp[N] << "\n";
}