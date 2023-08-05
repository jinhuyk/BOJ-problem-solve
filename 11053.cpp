#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N;
    int dp[1001];
    int maxi = 0;
    cin >> N;
    vector<int> A;
    
    for(int i = 0;i<N;i++){
        int a; cin >> a;
        A.push_back(a);
    }
    for(int i = 0;i<N;i++){
        dp[i] = 1;
        for(int j = 0;j<i;j++){
            if(A[i] < A[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    cout << maxi<<'\n';

    
    
}