//minimum spanning tree Problem
// same 1922

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


struct Vertex{
    double key;
    int pi;

    Vertex(double key, int pi){
        this->key = key;
        this->pi = pi;
    }
    bool operator<(const Vertex &v)const{
        return key > v.key;
    }
};

vector<Vertex> G[101];
bool vist[101];
int N;
void solve(){
    double Answer = 0;

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
    cout << fixed; cout.precision(2);
    cout << Answer << "\n";
}

int main(void){
    cin >> N;
    vector< pair<double, double> > pos;
    for(int i = 0;i<N;i++){
        double x,y;
        cin >> x >> y;
        pos.push_back(make_pair(x,y));
    }
    for(int i = 0;i<pos.size();i++){
        for(int j = i;j<pos.size();j++){
            double key;
            key = sqrt( (pos[i].first - pos[j].first)*(pos[i].first - pos[j].first) + (pos[i].second - pos[j].second)*(pos[i].second - pos[j].second) );
            G[i].push_back(Vertex(key,j));
            G[j].push_back(Vertex(key,i));
        }
    }
    solve();

}