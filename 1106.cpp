#include <iostream>

using namespace std;

int main(void){
    int C[21], P[21];
    int dp[1000001] = {0,};

    int c, n;
    int mm = 1000001;
    cin >> c >> n;
    for(int i =1;i<=n;i++){
        cin >> C[i] >> P[i];
    }
    
    dp[0] = 0;
    for(int i =1;i<=c+101;i++){
        int min = -1;
        bool flag = false;
        for(int j = 1;j<=n;j++){
            if(i-P[j] >= 0){
                if(dp[i-P[j]] == -1) continue;
                int temp = C[j] + dp[i-P[j]];
                if(flag == false) {
                    min = temp;
                    flag = true;
                }
                else{
                    min = min > temp ? temp : min;
                }
            }
        }
        dp[i] = min;
        if(i >= c){ mm = (mm > dp[i])? dp[i] : mm;
        }
    }
    cout << mm << "\n";
}