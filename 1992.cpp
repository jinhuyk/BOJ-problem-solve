#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int QT[65][65];
string solve(int start_x,int start_y, int end_x,int end_y){
    char qt = (QT[start_x][start_y] == 1) ? '1':'0';
    if(start_x == end_x) return string(1,qt);
    
    bool flag = true;
    for(int i = start_x;i<end_x;i++){
        for(int j = start_y; j<end_y;j++){
            if(QT[i][j] != QT[start_x][start_y]){
                flag = false;
                break;
            }
        }
    }
    if(flag == true) return string(1, qt);

    int mid_x = (start_x + end_x)/2;
    int mid_y = (start_y + end_y)/2;
    string ul = solve(start_x,start_y,mid_x,mid_y);
    string ur = solve(start_x,mid_y,mid_x,end_y);
    string dl = solve(mid_x,start_y,end_x,mid_y);
    string dr = solve(mid_x,mid_y,end_x,end_y);
    return "(" + ul + ur + dl + dr + ")";
}

int main(void){
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            scanf("%1d",&QT[i][j]);
        }
    }
    cout << solve(0,0,N,N)<<"\n";

}