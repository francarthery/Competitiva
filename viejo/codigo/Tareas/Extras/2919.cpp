#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	vector<int> v;
	int N, x, ind;
	
	while(cin >> N){
		v.clear();
		
		cin >> x;
		v.push_back(x);
		
		for(int i = 1; i < N; i++){
			cin >> x;
			
			if(x > v.back())
				v.push_back(x);
			else{
				ind = lower_bound(v.begin(), v.end(), x) - v.begin();
				v[ind] = x;
			}
		}
		
		cout << v.size() << endl;
	}
	return 0;
}

