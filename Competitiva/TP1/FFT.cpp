#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

using cd = complex<double>;
const double PI = acos(-1);

void FFT(vector<cd> &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;

        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) for (auto & x : a) x /= n;
}

vector <ll> MULTIPLY(vector <int> const & a, vector <int> const & b) {
    vector <cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < (int)a.size() + (int)b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);

    FFT(fa, false); FFT(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i]; // MOD if need

    FFT(fa, true);

    vector <ll> result(n);
    for (int i = 0; i < n; ++i) result[i] = round(fa[i].real());

    return result;
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string xpal, ypal;

    while(cin >> xpal >> ypal){
        auto ini = chrono::high_resolution_clock::now(); //Obtener tiempo de inicio

        int acarreo = 0, dig, max_dig, inicio = 0;
        vector <int> fx, gx;
        for(int i = 0; i < xpal.length(); i++) fx.push_back(xpal[i] - '0'); //Conversion string a vector int
        for(int i = 0; i < ypal.length(); i++) gx.push_back(ypal[i] - '0');

        vector <ll> ans = MULTIPLY(fx, gx); //Ans es un vector que contiene el la suma de los productos de cada columna

        for(int i = xpal.size() + ypal.size() - 1; i >= 0; i--){ //Acomodo ans para que se vea como un numero
            dig = ans[i] + acarreo;
            ans[i] = dig % 10;
            acarreo = dig / 10;
        }
        if(acarreo)cout << acarreo;

        max_dig = xpal.size() + ypal.size() - 1; //Limito digitos para no mostrar ceros extra al final
        while(!ans[inicio]) inicio++; //Elimino ceros iniciales
        for(int i = inicio; i < max_dig; i++) cout << ans[i];
        cout << '\n';

        // Obtener el tiempo de fin
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - ini; // Calcular la duración
        cout << "El tiempo de ejecucion es: " << fixed << setprecision(10) << duracion.count() << " segundos" << '\n';
    }

    return 0;
}