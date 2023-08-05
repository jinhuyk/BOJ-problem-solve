//minimum spanning tree Problem
// same 1922

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;


struct Vertex{
    int key, pi;

    Vertex(int key, int pi){
        this->key = key;
        this->pi = pi;
    }
    bool operator<(const Vertex &v)const{
        return key > v.key;
    }
};

vector<Vertex> G[100001];
bool vist[100001];
int V, E;
void solve(){
    int Answer = 0;

    priority_queue<Vertex> Q;
    Q.push(Vertex(0,1));
    while(!Q.empty()){
        Vertex u = Q.top(); Q.pop();
        if(vist[u.pi]) continue;
        vist[u.pi] = true;
        Answer += u.key;
        for(int i = 0;i< G[u.pi].size();i++){
            Q.push(G[u.pi][i]);
        }
    }
    cout << Answer << "\n";
}

int main(void){
    cin >> V >> E;
    for(int i = 0;i<E;i++){
        int A,B,C;
        cin >> A >> B >> C;
        G[A].push_back(Vertex(C,B));
        G[B].push_back(Vertex(C,A));
    }
    solve();

}