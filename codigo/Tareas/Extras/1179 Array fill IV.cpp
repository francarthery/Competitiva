#include <iostream>
#include <array>

using namespace std;

int main() {
	
	int N, CONT_P=0, CONT_I=0;
	int PARES[5], IMPARES[5];
	
	for(int i=0; i<=14; i++){
        cin >> N;
		if(N%2==0){
		    PARES[CONT_P]=N;
		    CONT_P++;}
        else{
            IMPARES[CONT_I]=N;
            CONT_I++;}

        if(CONT_P==5){
            for(int j=0; j<=4; j++)
                cout << "par[" << j << "] = " << PARES[j] << endl;
            CONT_P=0;}
        else if(CONT_I==5){
            for(int j=0; j<=4; j++)
                cout << "impar[" << j << "] = " << IMPARES[j] << endl;
            CONT_I=0;} }
	
	for(int i=0; i<CONT_P; i++){
		cout << "par[" << i << "] = " << PARES[i] << endl;}
    for(int i=0; i<CONT_I; i++){
		cout << "impar[" << i << "] = " << IMPARES[i] << endl;}
	
	return 0;
}