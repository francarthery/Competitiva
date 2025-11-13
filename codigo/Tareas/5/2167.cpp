#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N, R, index=0, anterior=0;
	
	cin >> N;
	
	for(int i=1; i<=N; i++){
		cin >> R;

		if(R<anterior){
			index=i;
			break;}
		anterior=R;
		}
	cout << index << endl;
	
	return 0;
}

