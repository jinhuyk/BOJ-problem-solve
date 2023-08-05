#include <iostream>

using namespace std;

int dp [ 1000001][2];
int main(void){
    int N;

    dp[2][0] = 1;
    dp[1][1] = 1;
    dp[1][0] = 0;
    dp[0][0] = 0;
    dp[0][1] = 0;
    cin >> N;

    for(int i = 2; i<= N;i++){
        if(i>2) dp[i][0] = (dp[i-2][0] + dp[i-2][1])%15746;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % 15746;
    }
    cout << (dp[N][1] + dp[N][0]) % 15746 << "\n";
}