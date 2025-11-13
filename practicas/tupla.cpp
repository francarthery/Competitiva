#include <bits/stdc++.h>

using namespace std;

int main(){
    
    //Objeto que puede contener elementos de distinto tipo
    tuple<char, int, float> t;
    
    t = {'a', 4, 6.75};

    get<2>(t) = 10.8; //Notación para acceder a un elemento de la tupla

    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

    cout << tuple_size<decltype(t)>::value << endl; //Tam de la tupla


    char c; float f;
    tie(c, ignore, f) = t; //Guardo en variables separadas los elementos de la tupla
    cout << c << " " << f << endl;


    tuple<double, string> t2 = {5.1983, "hola mundo"};

    auto t3 = tuple_cat(t, t2); //Concatenar dos tuplas
    cout << get<0>(t3) << " " << get<1>(t3) << " " << get<2>(t3) << " " << get<3>(t3) << " " << get<4>(t3) << endl;


    return 0;
}