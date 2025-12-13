#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	double x=0;
	
	int n;
	
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		x=x+6;
		x=1.0/x;
	}
	
	cout << fixed << setprecision(10);
	cout << x+3 <<endl;
	return 0;
}

/* Regla para el deducir el problema:

Hacer 1/(6+(1/6)) 
