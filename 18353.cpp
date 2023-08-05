#include <iostream>
#include <vector>


using namespace std;
vector<int> P;
int lowerBound(int key) {
    int l = 0;
    int r = P.size();
    while (l < r) P[(l + r) / 2] <= key ? r = (l + r) / 2 : l = (l + r) / 2 + 1;
    return r;
}

int main(void){
    int N, power;
    
    cin >> N >> power;
    P.push_back(power);
    for(int i = 1;i<N;i++){
        cin >> power;
        if(P.back() > power) P.push_back(power); 
        else P[lowerBound(power)] = power;
    }
    cout << N- P.size()<<"\n";

}