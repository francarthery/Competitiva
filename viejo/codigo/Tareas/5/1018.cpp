#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N,nota100,nota50,nota20,nota10,nota5,nota2,nota1;
	cin >> N;
	
	nota100=N/100;
	nota50=(N-(100*nota100))/50;
	nota20=(N-(100*nota100)-(50*nota50))/20;
	nota10=(N-(100*nota100)-(50*nota50)-(20*nota20))/10;
	nota5=(N-(100*nota100)-(50*nota50)-(20*nota20)-(10*nota10))/5;
	nota2=(N-(100*nota100)-(50*nota50)-(20*nota20)-(10*nota10)-(5*nota5))/2;
	nota1=(N-(100*nota100)-(50*nota50)-(20*nota20)-(10*nota10)-(5*nota5)-(2*nota2));
	
	cout<<N<<endl;
	cout<<nota100<<" nota(s) de R$ 100,00"<<endl;
	cout<<nota50<<" nota(s) de R$ 50,00"<<endl;
	cout<<nota20<<" nota(s) de R$ 20,00"<<endl;
	cout<<nota10<<" nota(s) de R$ 10,00"<<endl;
	cout<<nota5<<" nota(s) de R$ 5,00"<<endl;
	cout<<nota2<<" nota(s) de R$ 2,00"<<endl;
	cout<<nota1<<" nota(s) de R$ 1,00"<<endl;
	
	return 0;
}


