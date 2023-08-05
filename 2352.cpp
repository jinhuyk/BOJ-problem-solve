#include <iostream>
#include <vector>


using namespace std;

int main(void){
    int N, port;
    vector<int> P;
    cin >> N >> port;
    P.push_back(port);
    for(int i = 1;i<N;i++){
        cin >> port;
        if(P.back() < port) P.push_back(port); 
        else P[lower_bound(P.begin(),P.end(),port)-P.begin()] = port;
    }
    cout << N- P.size()<<"\n";

}