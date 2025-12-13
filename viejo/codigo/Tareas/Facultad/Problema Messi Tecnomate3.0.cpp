#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	map<string, int> frec;
	string pepe;
	
	for(int i = 0; i < 10; i++){
		cin >> pepe;
		frec[pepe]++;
	}
	
	vector<pair<string, int>> vec_frec(frec.begin(), frec.end());
	
	sort(vec_frec.begin(), vec_frec.end(), [](auto &a, auto &b){return a.second > b.second;});
	
	for(auto i : vec_frec){
		cout << i.first << "  " << i.second << endl;
	}
	
	return 0;
}

