#include <queue>
#include <iostream>

using namespace std;

int main(){

    int a, d, min_a, x;

    while(cin >> a >> d and (a != 0 or d != 0)){
        min_a = 10000;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < a; i++){
            cin >> x;
            min_a = (x < min_a ? x : min_a);
        }

        for(int i = 0; i < d; i++){
            cin >> x;
            pq.push(x);
        }

        pq.pop();
        cout << (pq.top() > min_a ? 'Y' : 'N') << endl;
    }

    return 0;
}