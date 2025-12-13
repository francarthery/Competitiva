#include <bits/stdc++.h>
using namespace std;

int cont = 0;
void f(vector<int> v, vector<int> c){
	if(v.empty()){
		for(int i = 0; i < (int)c.size(); i++){
			cout << c[i] << ' ';
		}
		if(!c.empty()) cout << '\n';
		cont++;
	}
	else{
		int elem = v.back();
		v.pop_back();
		f(v, c);
		c.push_back(elem);
		f(v, c);
	}
}

int main(int argc, char *argv[]) {
	
	vector<int> v{1,2,3}, c;
	f(v, c);
	cout << '\n' << cont << '\n';
	
	return 0;
}

