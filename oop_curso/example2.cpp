/*
Constructor: tipo especial de metodo que es invocado cada vez que se crea un objeto de una clase
Si no se crea un constructor, el compilador crea uno por defecto.

--Los constructores no tienen un tipo de dato de retorno.
--Tiene el mismo nombre que la clase a la que pertenece.
--En general tienen que ser publicos.
*/

#include <iostream>

using std::string;

class Employee{
public:
    //Atributes
    string Name;
    string Company;
    int Age;

    //Method
    void IntroduceYourself(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    //Constructor
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
};

int main(){

    //Creamos un objeto de tipo Employee y lo iniciamos con el constructor
    Employee employee1 = Employee("Saldina", "Tutocart", 25);

    employee1.IntroduceYourself();

    return 0;
}
