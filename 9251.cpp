#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string X,Y,Z;
    cin >> X;
    cin >> Y;
    cin >> Z;

    int m = X.length();
    int n = Y.length();
    int p = Z.length();
    int c[m+1][n+1][p+1];
    for(int i = 0;i<=m;i++){
        for(int j =0;j<=n;j++){
            for(int k = 0;k<=p;k++){
                    if(i == 0 || j == 0 || k ==0) c[i][j][k] = 0;
                    else if(X[i-1] == Y[j-1] && Y[j-1] == Z[k-1]) {
                        c[i][j][k] = c[i-1][j-1][k-1] +1; 
                        }
                    else c[i][j][k] = max(c[i-1][j][k] , max(c[i][j-1][k], c[i][j][k-1]));
            }
            
        }
    }
    cout << c[m][n][p] <<'\n';

}