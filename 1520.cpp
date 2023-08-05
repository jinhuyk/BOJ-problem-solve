#include <iostream>
#include <stack>

using namespace std;

int map[504][504];
int dp[504][504];

int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0, 1, 0 , -1};
int W,H;
int solve(int x, int y){
    if(dp[x][y] != -1 ) return dp[x][y];
    if(x == H && y == W) return 1;

    dp[x][y] = 0 ;
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <= 0 ||nx > H || ny <= 0 || ny > W || map[x][y] <= map[nx][ny]) continue;
        if(dp[nx][ny] != -1) dp[x][y] += dp[nx][ny];
        else{
            dp[x][y] += solve(nx,ny);
        }
    }
    return dp[x][y];

}

int main(void){ios::sync_with_stdio(false);cin.tie(NULL);

    cin >> H >> W;

    for(int i = 1;i<=H;i++){
        for(int j = 1;j<= W ;j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << solve(1,1) <<"\n";

}