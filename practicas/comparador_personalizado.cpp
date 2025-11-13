#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> pp;

struct compare{
	bool operator()(pp a, pp b){
		if(a.first != b.first) return a.first > b.first; //Si da true se elige a 'a' sino a 'b'
		else return a.second.first > b.second.first;
	}
};

int main(int argc, char *argv[]) {
	
	priority_queue<pp, vector<pp>, compare> pq;
	
	pq.push({5, {2, 3}});
	pq.push({3, {1, 4}});
	pq.push({5, {1, 2}});
	pq.push({4, {2, 1}});
	pq.push({3, {2, 5}});
	
	for(int i = 0; i < 5; i++){
		cout << pq.top().first << " " << pq.top().second.first << " " << pq.top().second.second << endl;
		pq.pop();
	}
	
	return 0;
}

