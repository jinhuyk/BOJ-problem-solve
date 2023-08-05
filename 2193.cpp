#include <iostream>


using namespace std;
int main(void)
{
    int N;
    long long prev = 0;
    long long next = 1;
    cin >> N;
    for(int i = 1;i<=N;i++){
        long long temp = next;
        next = prev + next;
        prev = temp;
    }
    cout << prev << "\n";
}