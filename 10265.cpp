#include <iostream>

using namespace std;
int X[10001];
int dp[1001];
int Count[1001];
int main(void){
    int N,K;
    cin >> N >> K;
    for(int i = 1;i<=N;i++){
        cin >>X[i];
        Count[i] = 0;
    }
    for(int i = 1; i<= N;i++){
        bool flag = true;
        int now = i;
        int c = 0;
        while(true){
            if(Count[now]==1){
                break;
            }
            c++;
            Count[now]++;
            now = X[now];
        }
        dp[i] = c;
    }

    

    int max = 0;
    for(int i = 1;i<=N;i++){
        if(dp[i] <= K && max < dp[i]){
            max = dp[i];
        }
    }
    cout << max << "\n";

}