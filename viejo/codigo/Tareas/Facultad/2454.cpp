#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int P, R;
	
	cin >> P >> R;
	
	if(P == 1)
		if(R == 0)
			cout << "B" << endl;
		else
			cout << "A" << endl;
	else
		cout << "C" << endl;
	
	return 0;
}

