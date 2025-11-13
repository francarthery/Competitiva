#include <iostream>
using namespace std;

int main() {
	
	int X,Y,A,B,suma;
	
	cin >> X >> Y;
	
	if(Y>X){
		A=X;
		B=Y;}
	else{
		A=Y;
		B=X;}
	
	if(A%2==0)
	   A++;
	else
	   A=A+2;
	
	if(B%2==0)
		B--;
	else
		B=B-2;
	
	suma=0;
	
	for(int i=A; i<=B; i=i+2){
		suma=suma+i;
		cout << suma <<endl;}

	cout << suma <<endl;
	return 0;
}

//Hacer 1149
