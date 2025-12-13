#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
	
	int X,Y;
	cin >> X >> Y;
	
	for(int i=1; i<=Y; i++){
		printf("%d", i);
		if(i%X==0)
			printf("\n");
		else
			printf(" ");
	}
	return 0;
}

