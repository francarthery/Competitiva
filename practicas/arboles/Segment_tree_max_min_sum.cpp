#include <iostream>

using namespace std;

struct Nodo{
    int max;
    int min;
    int suma;
};

Nodo *T;
int *a;

void init(int nodo, int l, int r){
    if(r == l) T[nodo].max = T[nodo].min = T[nodo].suma = a[r];
    else{
        int mi = (r + l) / 2;
        init(nodo * 2, l, mi);
        init(nodo * 2 + 1, mi + 1, r);
        T[nodo].max = max(T[nodo * 2].max, T[nodo * 2 + 1].max);
        T[nodo].min = min(T[nodo * 2].min, T[nodo * 2 + 1].min);
        T[nodo].suma = T[nodo * 2].suma + T[nodo * 2 + 1].suma;
    }
}

void update(int x, int val, int nodo, int l, int r){
    if(x > r or x < l) return;
    
    if(r == l) T[nodo].max = T[nodo].min = T[nodo].suma = val;
    else{
        int mi = (r + l) / 2;
        update(x, val, nodo * 2, l, mi);
        update(x, val, nodo * 2 + 1, mi + 1, r);
        T[nodo].max = max(T[nodo * 2].max, T[nodo * 2 + 1].max);
        T[nodo].min = min(T[nodo * 2].min, T[nodo * 2 + 1].min);
        T[nodo].suma = T[nodo * 2].suma + T[nodo * 2 + 1].suma;
    }
}

int suma(int x, int y, int nodo, int l, int r){
    if(x > r or y < l) return 0;
    if(y >= r and x <= l) return T[nodo].suma;
    else{
        int mi = (r + l) / 2;
        return suma(x, y, nodo * 2, l, mi) + suma(x, y, nodo * 2 + 1, mi + 1, r);
    }
}
	
int maximo(int x, int y, int nodo, int l, int r){
	if(x > r or y < l) return -1000000; //Numero que nunca va a ser el maximo
	if(y >= r and x <= l) return T[nodo].max;
	else{
		int mi = (r + l) / 2;
		return max(maximo(x, y, nodo * 2, l, mi), maximo(x, y, nodo * 2 + 1, mi + 1, r));
	}
}
	
int minimo(int x, int y, int nodo, int l, int r){
	if(x > r or y < l) return 1000000; //Numero que nunca va a ser el minimo
	if(y >= r and x <= l) return T[nodo].min;
	else{
		int mi = (r + l) / 2;
		return min(minimo(x, y, nodo * 2, l, mi), minimo(x, y, nodo * 2 + 1, mi + 1, r));
	}
}

int main(){

    int n;
    cin >> n;

    a = new int[n];
    T = new Nodo[n * 4];

    for(int i = 0; i < n; i++) cin >> a[i];

    init(1, 0, 7);
    update(4, 1, 1, 0, 7);

    for(int i = 1; i < 16; i++) cout << T[i].max << " " << T[i].min << " " << T[i].suma << endl;

    cout << minimo(5, 7, 1, 0, 7) << endl;

    return 0;
}
