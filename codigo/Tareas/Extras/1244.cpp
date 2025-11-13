#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	int N;
	string frase, palabra;
	
	auto comp_largo = [](const string& str1, const string& str2) {
		return str1.length() > str2.length();
	};
	
	vector<string> vec;
	
	cin >> N;
	cin.ignore();
	
	for(int i = 0; i < N; i++){
		getline(cin, frase);
		//Se piden las palabras individualmente
		istringstream stream(frase);
		vec.clear();
		
		while(stream >> palabra){
			vec.push_back(palabra);
		}
		
		stable_sort(vec.begin(), vec.end(), comp_largo);
		
		for(unsigned j = 0; j < vec.size(); j++){
			cout << vec[j];
			if(j != vec.size() - 1) cout << " ";
		}
		
		cout << endl;
	}
	
	return 0;
}

