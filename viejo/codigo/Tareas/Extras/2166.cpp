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
		x=x+2;
		x=1.0/x;
	}
	
	cout << fixed << setprecision(10);
	cout << x+1 <<endl;
	return 0;
}

/* Regla para el deducir el problema:

Hacer 1/(6+(resultado con N valiendo 1 menos)) 

ejemplo: Si N=2  la raíz sería  3+  1/(6+(1/6))


Si N=3 la raíz será 3+  1/(6+(resultado con N=2))
Lo cual es igual a: 3+   1/(6+(1/(6+(1/6))

*/ 
