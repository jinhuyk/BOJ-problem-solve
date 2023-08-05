#include <iostream>
#include <queue>
int main(void){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    int N, input;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        if (input == 0){
            if(pq.empty()){
                std::cout << 0 <<"\n";
            }else{
                std::cout << pq.top()<<"\n";
                pq.pop();
            }
        }
        else pq.push(input);
       
    }
}