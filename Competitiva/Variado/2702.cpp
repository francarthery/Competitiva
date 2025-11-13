#include <iostream>

using namespace std;

int main(){

    int a, b, c, d, e, f, res = 0;

    cin >> a >> b >> c >> d >> e >> f;

    if(a < d) res += d - a;
    if(b < e) res += e - b;
    if(c < f) res += f - c;

    cout << res << endl;
}