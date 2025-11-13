#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    
    //Sintax
    [/*Capture close*/](/*parameters*/){/*definition*/};

    std::vector <int> v{2, 3, 7, 14, 23};

    std::for_each(v.begin(), v.end(), [](int &x){return ++x;});

    std::for_each(v.begin(), v.end(), [](int x){std::cout << x << " ";});

    std::cout << std::endl;



    int d = 3;

    //Entre corchetes pasamos variables a la funcion. Si las queremos modificar si o si por referencia
    std::for_each(v.begin(), v.end(), [d](int x){
        if(x % d == 0)
            std::cout << x << " is divisible by " << d << std::endl;  
        else
            std::cout << x << " is not divisible by " << d << std::endl;  
    });
    
    return 0;
}