#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	
	float N;
	
	cin >> N;
	
	if (0<=N and N<=25)
		cout << "Intervalo [0,25]" <<endl;
	else
		if (25<N and N<=50)
			cout << "Intervalo (25,50]" <<endl;
		else
			if (50<N and N<=75)
				cout << "Intervalo (50,75]" <<endl;
			else
				if (75<N and N<=100)
					cout << "Intervalo (75,100]" <<endl;
				else
					cout << "Fora de intervalo" <<endl;
	
	
	return 0;
}
