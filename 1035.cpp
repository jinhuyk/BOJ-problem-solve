#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;


int b[6][6];
int v[6][6];
int c = 0;

int dx[8] = {1,0,-1,0 , 1 , 1 , -1, -1};
int dy[8] = {0,1,0,-1, -1, 1, 1, -1};
void solve(){
    if(c==1) cout << 0 << "\n";

    while(c > 0){
        int x,y;
        for(int i = 1;i<=5;i++){
            for(int j = 1;j<=5;j++){
                int f[6][6];
                for(int i = 1;i<=5;i++){
                    for(int j = 1;j<=5;j++){
                        f[i][j] = 0;
                    }
                }

                if(b[i][j] == 1 && v[i][j] != -1){
                    x = i; y = j;
                    cout << x << " "<< y << " \n";
                    v[i][j] = -1;
                    for(int k = 0;k<8;k++){
                        int X = x+ dx[k];
                        int Y = y + dy[k];

                        queue<int> Q;
                        Q.push(X*10+Y);
                        v[X][Y] = 0;
                        f[X][Y] = 1;
                        while(!Q.empty()){  
                            int dist;
                            
                            int cur = Q.front();
                            
                            dist = v[(X/10)][X%10]+1;
                            cout << cur << "\n";
                            cout << dist << "\n";
                            Q.pop();
                            for(int ii = 0;ii<4;ii++){
                                
                                int nx = (X/10) + dx[ii];
                                int ny = (X%10) + dy[ii];
                                
                                if(nx <= 0 || nx > 5 || ny <= 0 || ny > 5 || f[nx][ny] ==1){
                                    continue;
                                }
                                cout << nx << ny << "\n";
                                Q.push(nx*10 + ny);
                                v[nx][ny] = min(dist , v[nx][ny]);
                                f[nx][ny] = 1;
                                
                            }
                            cout << "\n";
                             for(int i = 1;i<=5;i++){
                                for(int j = 1; j<=5;j++){
                                    cout << f[i][j] << " ";
                                }
                                cout << "\n";
                            }
                            cout << "\n";
                        }
                    }
                }
            }
        }
        c--;
       
        
    }

}

int main(void){
    
    

    for(int i = 1;i<=5;i++){
        string str;
        cin >> str;
        
        for(int j = 0;j<5;j++){
            if(str[j] == '*'){
                b[i][j+1] = 1;
                c++;
            }
            else{
                b[i][j+1] = 0;
            }
            v[i][j+1] = 10;
        }
        
    }
    solve();
}