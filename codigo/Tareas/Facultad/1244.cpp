#include <iostream>
using namespace std;

void insercion_dir(string listas[], int N);

int main(int argc, char *argv[]) {
	
	string listas[51];
	int N;
	bool iguales = true;
	
	cin >> N;
	cin.ignore();
	
	for(int i = 0; i < N; i++){
		getline(cin, listas[i]);
	}
	
	for(int i = 1; i < N; i++){
		if(listas[0].length() != listas[i].length())
			iguales = false;
	}
	
	if(iguales){
		for(int i = 0; i < N; i++){
			cout << listas[i];
		}
	}
	else{
		insercion_dir(listas, N);
		for(int i = 0; i < N; i++){
			cout << listas[i] << endl;
		}
	}
	
	return 0;
}

void insercion_dir(string listas[], int N){
	
	for(int i = 0; i < N; i++){
		
		string palabras[51];
		int j = 0, k = 0, p = 0;
		
		while(j < listas[i].length() and k < 50){
			if(listas[i][j] != ' '){
				palabras[k] += listas[i][j];
			}
			else{
				k++;
			}
			j++;
		}
		
		for(int l = 1; l < k+1; l++){
			p = l;
			
			while((p > 0) and (palabras[p].length() > palabras[p - 1].length())){
				swap(palabras[p], palabras[p - 1]);
				p--;
			}
		}
		
		listas[i].clear();
		for(int l = 0; l < k + 1; l++){
			listas[i] += palabras[l];
			if(l < k)
				listas[i] += " ";
		}
	}
}
	
	
	

