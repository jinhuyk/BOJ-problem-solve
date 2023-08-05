#include <iostream>
#include <cstring>
using namespace std;

int Coin[101];
int dp[10001];
int T, N;


int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    memset(dp,0,sizeof(dp));
    int M;
    cin >> N >> M;
    for(int i = 1;i<=N;i++){
        cin >> Coin[i];
    }
    dp[0] = 1;
    for(int i = 1;i<=N;i++){
        for(int j = Coin[i];j<=M;j++){
            dp[j] += dp[j-Coin[i]];
        }
    }
    cout << dp[M] << "\n";
}