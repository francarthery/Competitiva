/*
En C++ hay 3 modificadores de acceso:
--Private: No se puede ver desde afuera el interior de la clase. Establecido por defecto.
--Public: Cualquiera puede acceder desde afuera.
--Protected: Un punto medio. Tiene ciertas reglas.
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
};

int main(){

    //Creamos un objeto de tipo Employee
    Employee employee1;

    //Asignamos atributos
    employee1.Name = "Saldina";
    employee1.Company = "Tutocart";
    employee1.Age = 25;

    employee1.IntroduceYourself();

    return 0;
}