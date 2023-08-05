#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N, K;
    int num = 0;
    cin >> N >> K;
    vector<int> coin(N);
    for(int i =0;i<N;i++){
        int c;
        cin >> c;
        coin.push_back(c);
    }
    while(K>0){
        while(coin.back() > K){
            coin.pop_back();
        }
        int now = coin.back();
        num += K/now;
        K %= now;
    }
    cout << num << "\n";
}