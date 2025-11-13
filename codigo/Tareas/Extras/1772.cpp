#include <iostream>

using namespace std;

int main(){

    unsigned n, k, a, b, ma, mi;
    bool bit1, bit2;

    while(cin >> n >> k and (n != 0 or k != 0)){
        mi = ma = n;

        for(int i = 0; i < k; i++){
            cin >> a >> b;

            bit1 = n & (1 << a);
            bit2 = n & (1 << b);

            if(bit1 != bit2){
                if(bit1)
                    n = n & ~(1 << a);
                else
                    n = n | (1 << a);

                if(bit2)
                    n = n & ~(1 << b);
                else
                    n = n | (1 << b);
            }

            mi = min(mi, n);
            ma = max(ma, n);
        }

        cout << n << " " << ma << " " << mi << endl;
    }

    return 0;
}