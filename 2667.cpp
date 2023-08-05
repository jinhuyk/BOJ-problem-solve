#include <iostream>
#include <stack>
#include <stdio.h>
#include <algorithm>
using namespace std;

int map[26][26];
int flag[26][26];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int Count[500] = {0,};
void solve(int N){
    int c = 1;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if(map[i][j] == 0 || flag[i][j] != 0) continue;
            stack<int> s;

            s.push(i*100 + j);
            flag[i][j] = c;
            while(!s.empty()){
                int now = s.top();
                s.pop();
                int nx = now / 100;
                int ny = now % 100;
                for(int k = 0;k<4;k++){
                    int x = nx + dy[k];
                    int y = ny + dx[k];

                    if(x <=0 || x > N || y <=0 || y > N || flag[x][y] !=0 || map[x][y] == 0 ) continue;
                    s.push(x*100 + y);
                    flag[x][y] = c;
                }
            }
            Count[c] = 0;
            c++;  
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1; j<= N ;j++){
            if(flag[i][j] != 0){
                Count[flag[i][j]]++;
            }
        }
    }
    cout << c-1<<"\n";
    sort(Count, Count+c);
    for(int i = 1;i<=c-1;i++){
        cout << Count[i] << "\n";
    }
}

int main(void){
    int N;
    cin >> N;
    for(int i = 1;i<=N;i++){
        for(int j = 1 ;j<=N;j++){
            scanf("%1d",&map[i][j]);
            flag[i][j] = 0;
        }
    }
    solve(N);

}