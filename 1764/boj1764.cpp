#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;
    map<string,bool> li;
    set<string> fli;
    for(int i = 0;i<N;i++){
        string name;
        cin >> name;
        li.insert({name,true});
    }
    for(int i = 0;i<M;i++){
        string name;
        cin >> name;
        if(li.count(name)!=0) fli.insert(name);
    }
    cout << fli.size() << endl;
    for(auto i : fli) cout << i << '\n';
}