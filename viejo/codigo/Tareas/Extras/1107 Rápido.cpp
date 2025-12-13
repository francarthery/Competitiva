#include <iostream>

using namespace std;

int main() {
	
	int A, C, X, laser, anterior;

	for(;;){
		laser=0;
		cin >> A >> C;
        anterior=A;
		if(A==0 and C==0)break;
		
		for(int i=0; i<C; i++){
			cin >> X;
            if(anterior>=X) laser+=anterior-X;
            anterior=X;
		}
        cout << laser << endl;
	}
       
	return 0;
}
