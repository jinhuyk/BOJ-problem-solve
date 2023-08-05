//minimum spanning tree Problem
// same 1922

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


struct Vertex{
    long long key;
    int pi;

    Vertex(long long key, int pi){
        this->key = key;
        this->pi = pi;
    }
    bool operator<(const Vertex &v)const{
        return key > v.key;
    }
};

vector<Vertex> G[100001];
bool vist[100001];
int N;
void solve(){
    long long Answer = 0;

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

bool x_comp(pair<int, pair<int, int > > A, pair<int, pair<int, int > > B){
    return A.first < B.first;
}
bool y_comp(pair<int, pair<int, int > > A, pair<int, pair<int, int > > B){
    return A.second.first < B.second.first;
}
bool z_comp(pair<int, pair<int, int > > A, pair<int, pair<int, int > > B){
    return A.second.second < B.second.second;
}

int main(void){
    cin >> N;
    vector< pair<int, pair<int, int > > > pos;
    for(int i = 0;i<N;i++){
        int x,y,z;
        cin >> x >> y >> z;
        pos.push_back(make_pair(x,make_pair(y,z)));
    }
    sort(pos.begin(), pos.end());
    for(int i = 0;i<pos.size();i++){
        for(int j = i;j<pos.size();j++){
            long long key;
            key = min( abs(pos[i].first - pos[j].first) , min(abs(pos[i].second.first - pos[j].second.first) , abs(pos[i].second.second - pos[j].second.second)));
            G[i].push_back(Vertex(key,j));
            G[j].push_back(Vertex(key,i));
        }
    }
    solve();

}