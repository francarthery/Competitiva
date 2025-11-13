#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;

int main(int argc, char *argv[]) {
	
	
	auto start_time = high_resolution_clock::now();

	string cadena1, cadena2;
	bool flag;
	int maxigual = 0, igual;
	
	while(getline(cin, cadena1) and getline(cin, cadena2)){
		
		unsigned m = cadena1.length();
		unsigned n = cadena2.length();
		maxigual = 0;
		
		//Analizamos si las cadenas son iguales
		if(cadena1 == cadena2)
			maxigual = m;
		//Analizamos si una cedena es subcadena de otra
		else if(cadena1.find(cadena2) <= m or cadena2.find(cadena1) <= n)
			maxigual = min(m, n);
		//En el peor de los casos, buscamos caracter a caracter la mayor coincidencia
		else{
			//hacemos que no pase de maxigual ya que si hay una igualdad mayor al final, si o si el primer digito estara antes de maxigual
			for(unsigned i = 0; i < m - maxigual; i++){
				for(unsigned j = 0; j < n - maxigual; j++){
					
					if(cadena1[i] == cadena2[j]){
						igual = 1;
						flag = true;
						
						while(flag){
							if(cadena1[i + igual] == cadena2[j + igual])
								igual++;
							else
								flag = false;
						}
						if(igual > maxigual)
							maxigual = igual;
						
						j += igual - 1;
					}
				}
			}
		}
		cout << maxigual << endl;
		if(cadena1 == "pepe")
			break;
	}
	
	auto end_time = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end_time - start_time);
	
	// Mostrar el tiempo de ejecución en milisegundos
	cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

	return 0;
}
/*
Find the longest common substring
The substring can be any part of the String
If there is no common substring, return 0
The search is case sensitive
The input contains several test cases
Each test case is composed by two lines
that contains a string each
Both input Strings will contain between
abcdef
cdofhij
TWO
FOUR
abracadabra
open
Hey This java is hot
Java is a new paradigm
a
aaa
aaa
a
a
a
asss
saaa
ssssssssssssa
a
ss
hhhhhhhhhhhhhhhhhhhhhhss
abc
cjjjjjjab
a a a a a
b b a a b
AAAAAAAAABCD
AAAAAAAAACD
axaxaxa
aabbbbbbbbaa
GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
pepe
pepe




*/


/*
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

string cadena1, cadena2;
bool flag;
int maxigual = 0, igual;

while(EOF){

getline(cin, cadena1);
getline(cin, cadena2);
maxigual = 0;

for(unsigned i = 0; i < cadena1.length() - maxigual; i++){
for(unsigned j = 0; j < cadena2.length() - maxigual; j++){

if(cadena1[i] == cadena2[j]){
igual = 1;
flag = true;

while(flag){
if(cadena1[i + igual] == cadena2[j + igual])
igual++;
else
flag = false;
}
if(igual > maxigual)
maxigual = igual;

j += igual - 1;
}
}
}

cout << maxigual << endl;

}


return 0;
}


*/
