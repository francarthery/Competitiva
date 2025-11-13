#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N,K,M,X,Y;
	
	cin >> K;
	
	while(K!=0){
	
		cin >> N >> M;
		
		for(int i=1; i<=K; i++){
			cin >> X >> Y;
			if(X>N and M<Y)
				cout << "NE" << endl;
			else
				if(Y>M and N>X)
					cout << "NO" << endl;
				else
					if(Y<M and N<X)
						cout <<"SE" << endl;
					else
						if(X<N and Y<M)
							cout << "SO" << endl;
						else
							cout << "divisa" << endl;
		}
		cin >> K;
	}
	
	return 0;
}

