#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N;
    int updp[1001];
    int dwdp[1001];
    int maxi = 0;
    cin >> N;
    vector<int> A;
    
    for(int i = 0;i<N;i++){
        int a; cin >> a;
        A.push_back(a);
    }
    for(int i = 0;i<N;i++){
        updp[i] = 1;
        
        for(int j = 0;j<i;j++){
            if(A[i] > A[j]){
                updp[i] = max(updp[i], updp[j]+1);
            }
        }

    }
    for(int i = N-1;i>=0;i--){
        dwdp[i] = 1;
        for(int j = N-1;j>=i;j--){
            if(A[i] > A[j]){
                dwdp[i] = max(dwdp[i], dwdp[j]+1);
            }
        }
    }
    for(int i = 0;i<N;i++){
        maxi = max(dwdp[i]+updp[i], maxi);
    }
    cout << maxi-1<<'\n';

    
    
}