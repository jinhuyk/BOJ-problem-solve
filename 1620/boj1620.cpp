#include <iostream>
#include <map>

using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;

    cin >> n >> m;
    map<string, int> memo;
    for(int i = 0;i<n;i++){
        string id;
        cin >> id;
        memo.insert({id,i});
    }
    for(int i = 0;i<m;i++){
        string quiz;
        cin >> nid;
        if(memo.find(nid)!=memo.end()){
            cout << memo.find(nid)->second <<'\n';
        }
    }
}