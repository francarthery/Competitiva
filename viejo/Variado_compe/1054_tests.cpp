#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
using namespace std;

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int n = rand() % 300 + 200;
	
	cout << n << endl;
	
	for(int i = 0; i < n; i++){
		int m = rand() % 60;
		int d = rand() % 100 + 60;
	
		cout << m << " " << d << endl;
		
		set<int> s;
		while(s.size() < m) s.insert(rand() % (d - 1) + 1);
		
		for(auto j : s){
			cout << 'B' << "-" << j << " ";
		}
	
		cout << endl;
	}
	return 0;
}

