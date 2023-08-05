#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
    while (true){
        int N, cost;
        vector<int> V;
        cin >> N;
        if(cin.eof() == true){
            break;
        }
        cin >> cost;
        V.push_back(cost);
        for(int i = 1;i<N;i++){
            cin >> cost;
            if(V.back() < cost) V.push_back(cost);
            else V[lower_bound(V.begin(),V.end(),cost)-V.begin()] = cost;
        }
        cout << V.size() << "\n";
    }

}