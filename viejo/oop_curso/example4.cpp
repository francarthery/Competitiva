/*
Abstraccion: consiste en "esconder" cosas complejas y detalles de una clase

Clase abstracta: Es una clase que no puede ser instanciada directamente, sino que sirve
como plantilla para otras clases. Pueden contener funciones puras virtuales las cuales deben
ser implementadas por las clases derivadas.
*/

#include <iostream>

using std::string;

//Abstract class
class AbstractEmployee{
    //Pure virtual function or asbtract function
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee{
private:
    //Atributes
    string Name;
    string Company;
    int Age;

public:
    //Methods
    void setName(string name){ //setter
        Name = name;
    }
    string getName(){//getter
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        //Agregamos una regla de validacion
        if(age >= 18)
            Age = age;
    }
    int getAge(){
        return Age;
    }
    
    void IntroduceYourself(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    //Implementacion funcion heredada
    void AskForPromotion(){
        if(Age >= 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << " can't get promoted!" << std::endl;
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
    Employee employee1 = Employee("Saldina", "Tutocart", 30);

    employee1.AskForPromotion();

    return 0;
}