#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N, maximo, num;
	bool flag = false;
	string jug;
	
	cin >> N;
	
	set<pair<int, string>> lista;
	
	for(int i = 0; i < N; i++){
		cin >> jug;
		flag = false;
		//Capitalizamos jugadores
		for(int j = 0; j < jug.length(); j++){
			if(j == 0) jug[j] = toupper(jug[j]);
			else jug[j] = tolower(jug[j]);
		}
		
		
		for (auto pareja : lista){
			if(pareja.second == jug){
				num = pareja.first;
				lista.erase(pareja);
				lista.insert({num+1, jug});
				flag = true;
				break;
			}
		}
		
		if(flag == false)
			 lista.insert({1,jug});
	}
	
	maximo = 0;
	set<pair<string, int>> repetidos;
	
	for (auto pareja : lista){
		if(pareja.first > maximo){
			maximo = pareja.first;
		}
	}
	for (auto pareja : lista){
		if(pareja.first == maximo){
			repetidos.insert({pareja.second, pareja.first});
		}
	}
	for (auto pareja : repetidos){
		cout << pareja.first << " " << pareja.second << endl;
	}
	
	
	
	return 0;
}


