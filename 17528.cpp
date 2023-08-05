#include <iostream>
#include <cstring>
using namespace std;
int main(void){
    int n;
    int dp [251*251];

    memset(dp, 251*251, sizeof(dp));

    dp[0] =0;
    int sum = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        sum += a;
        for(int i = 250* 250; i>= a;i--){
            dp[i] = min(dp[i], dp[i-a]+b);
        }
    }
    int ans = 251*251;
    for(int i = 0;i<=sum;i++){
        ans = min(ans, max(sum-i, dp[i]));
    }
    cout << ans;

}