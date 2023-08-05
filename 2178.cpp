#include <iostream>
#include <queue>
#include <iostream>

int main(void){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int N,M;
    int MAZE[101][101], dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
    int visit[101][101] = {0}, level[101][101] = {0};
    std:: queue< std::pair<int,int> > q;

    scanf("%d %d",&N,&M);
    for(int i = 0;i<N;i++){
        for(int j = 0 ;j<M;j++){
            scanf("%1d",&MAZE[i][j]);
        }
    }
    visit[0][0] = 1;
    q.push(std::make_pair(0,0));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < N  && 0<=ny && ny < M){
                if(MAZE[nx][ny] == 1 && visit[nx][ny] == 0){
                    level[nx][ny] = level[x][y] +1;
                    visit[nx][ny] = 1;
                    q.push(std::make_pair(nx,ny));
                }
            }
        }
    }
    std::cout << level[N-1][M-1]+1;
    return 0;
}