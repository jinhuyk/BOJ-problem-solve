#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int QT[128][128];
int 
void solve(int start_x,int start_y, int end_x,int end_y){
    if(start_x == end_x){
        if(QT[start_x][start_y] == 1) blue++;
        else white++;
        return;
    };
    
    bool flag = true;
    for(int i = start_x;i<end_x;i++){
        for(int j = start_y; j<end_y;j++){
            if(QT[i][j] != QT[start_x][start_y]){
                flag = false;
                break;
            }
        }
    }
    if(flag == true){
        if(QT[start_x][start_y] == 1) blue++;
        else white++;
        return;
    }

    int mid_x = (start_x + end_x)/2;
    int mid_y = (start_y + end_y)/2;
    solve(start_x,start_y,mid_x,mid_y);
    solve(start_x,mid_y,mid_x,end_y);
    solve(mid_x,start_y,end_x,mid_y);
    solve(mid_x,mid_y,end_x,end_y);

}

int main(void){
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            scanf("%d",&QT[i][j]);
        }
    }
    solve(0,0,N,N);
    cout <<  white <<"\n" << blue<<"\n";

}