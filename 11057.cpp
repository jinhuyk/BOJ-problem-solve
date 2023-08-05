#include <iostream>

using namespace std;

long long dp[1001][10];
void solve(int N){
    for(int i = 0;i<=9;i++){
        dp[1][i] = 1;
    }
    for(int i = 2;i<=N;i++){
        for(int j = 0;j<=9;j++){
            dp[i][j] = 0;
            for(int k = j;k<=9;k++){
                dp[i][j] += dp[i-1][k] % 10007;
            }
        }
    }
    long long rst = 0;
    for(int i = 0;i<=9;i++){
        rst += dp[N][i] % 10007;
    }
    cout << rst %10007 << "\n";

}
int main(void){
    int N;
    cin >> N;
    solve(N);

}