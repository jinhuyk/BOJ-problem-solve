#include <iostream>

using namespace std;
int V[10001], C[10001], K[10001];
int dpk[10001][10001];
int main(void){
    int N,M;
    int k , max;
    dpk[0][0]  = 0;
    cin >> N >> M;
    for(int i = 1;i<=N;i++){
        cin >> V[i] >> C[i] >> K[i];
    }
    for(int i = 1; i<= M;i++){
        k = 0;
        max = 0;
        for(int j = 0; j<=N;j++){
            dpk[i][j] = 0;
        }
        for(int j = 1;j<=N;j++){
            if(i - V[j] >=0 && 1+dpk[i-V[j]][j] <= K[j]){
                if(i-V[j] > 0 && dpk[i-V[j]][0] == 0){
                    dpk[i][0] = 0;
                }
                else{
                    int temp = C[j] + dpk[i-V[j]][0];
                    if(max < temp){
                        k = j;
                        max = temp;
                    }
                }
                
            }
        }
        if(k == 0) continue;
        dpk[i][0] = max;
        dpk[i][k]++;
        for(int j = 1;j<=N;j++){
            dpk[i][j] += dpk[i-V[k]][j];
        }

    }
    max = 0;
    for(int i = 0;i<=M;i++){
        max = dpk[i][0] > max ? dpk[i][0] : max;
    }
    cout << max << "\n";
}