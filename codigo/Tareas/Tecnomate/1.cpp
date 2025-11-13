#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N, M, R=0;
	
	cin  >> N;
	
	for(int i=1; i<=N; i++){
		cin >> M;
		if(i!=N and M>=6)
			R+=21;
		else if(i==N){
			for(int j=1; j<=M; j++)
			R+=j;}
		else{
			for(int j=1; j<=M; j++)
				R+=j;}
	}
	
	cout << R << endl;
	
	return 0;
}

