#include <iostream>

using namespace std;

int main(void){
    int arr[501][501];
    int dp[501][501];
    int N;
    int rst=  0;
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<=i;j++){
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for(int i = 1;i<N;i++){
        for(int j = 0;j<=i;j++){
            dp[i][j] = 0;
            if(j == 0 ){
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else if (j == i){
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<=i;j++){
            rst = max(rst, dp[i][j]);
        }
    }
    cout << rst << "\n";
}