#include <iostream>
using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string S;
    cin >> N >> M;
    cin >> S;
    int count = 0;
    for(int i = 0; i< M;i++){
        if(S[i] =='I'){
            int IOI = 0;
            while(S[i+1] == 'O' && S[i+2]=='I'){
                IOI++;
                if(IOI == N){
                    count ++;
                    IOI--;
                }
                i += 2;
            }
        }
    }
    cout << count;
}
