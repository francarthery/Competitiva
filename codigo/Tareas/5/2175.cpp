#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	double O, B, I;
	
	cin >> O >> B >> I;
	
	if(O<B and O<I)
		cout << "Otavio" << endl;
	else
		if(B<O and B<I)
			cout << "Bruno" << endl;
		else
			if(I<O and I<B)
				cout << "Ian" << endl;
			else
				if(O==I or O==B or B==I)
					cout << "Empate" << endl;
	return 0;
}

