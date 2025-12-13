#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	
	double x = 3.14156712837593;
	
	cout << "X = " << x << endl;
	
	// 1 decimal
	cout << fixed << setprecision(1);
	cout << "X = " << x << endl;
	
	// 3 decimales
	cout << fixed << setprecision(3);
	cout << "X = " << x << endl;
	
	return 0;
}






