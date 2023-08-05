#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long num = 0;
bool is_visit = false;
long long r,c;
void solve(long long start_x,long long start_y,long long end_x,long long end_y){
    if(is_visit) return;
    else{
        if((r >= start_x && r < end_x ) && (c >= start_y && c < end_y)){
            if(end_x - start_x ==2){
                for(long long i = start_x;i<end_x;i++){
                    for(long long j = start_y;j<end_y;j++){
                        if(i == r && j == c){
                            is_visit = true;
                            return;
                        }
                        num++;
                    }
                }
            }
            else{
                long long mid_x = (start_x + end_x)/2;
                long long mid_y = (start_y + end_y)/2;
                solve(start_x,start_y,mid_x,mid_y);
                solve(start_x,mid_y,mid_x,end_y);
                solve(mid_x,start_y,end_x,mid_y);
                solve(mid_x,mid_y,end_x,end_y);
            }
            
        }
        else{
            num += pow((end_x - start_x),2);
        }

    }
}

int main(void){
    int N;
    cin >> N >> r >> c;
    solve(0,0,pow(2,N),pow(2,N));
    cout <<  num<<"\n";

}