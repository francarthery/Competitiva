#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, string> mp;
    string pal;

    mp.insert({"brasil", "Feliz Natal!"});
    mp.insert({"alemanha", "Frohliche Weihnachten!"});
    mp.insert({"austria", "Frohe Weihnacht!"});
    mp.insert({"coreia", "Chuk Sung Tan!"});
    mp.insert({"espanha", "Feliz Navidad!"});
    mp.insert({"grecia", "Kala Christougena!"});
    mp.insert({"estados-unidos", "Merry Christmas!"});
    mp.insert({"inglaterra", "Merry Christmas!"});
    mp.insert({"australia", "Merry Christmas!"});
    mp.insert({"portugal", "Feliz Natal!"});
    mp.insert({"suecia", "God Jul!"});
    mp.insert({"turquia", "Mutlu Noeller"});
    mp.insert({"argentina", "Feliz Navidad!"});
    mp.insert({"chile", "Feliz Navidad!"});
    mp.insert({"mexico", "Feliz Navidad!"});
    mp.insert({"antardida", "Merry Christmas!"});
    mp.insert({"canada", "Merry Christmas!"});
    mp.insert({"irlanda", "Nollaig Shona Dhuit!"});
    mp.insert({"belgica", "Zalig Kerstfeest!"});
    mp.insert({"italia", "Buon Natale!"});
    mp.insert({"libia", "Buon Natale!"});
    mp.insert({"siria", "Milad Mubarak!"});
    mp.insert({"marrocos", "Milad Mubarak!"});
    mp.insert({"japao", "Merii Kurisumasu!"});

    while(cin >> pal){
        if(mp.find(pal) != mp.end()) cout << mp[pal] << '\n';
        else cout << "--- NOT FOUND ---\n";
    }

    return 0;
}