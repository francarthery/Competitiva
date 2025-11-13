/*
Encapsulacion: Consiste en agrupar la informacion junto con los metodos que operan esa info.
Se hace para prevenir que alguien pueda modificar nuestra clase de forma directa.
Hacemos privados los atributos y creamos metodos publicos especificos (getters and setters)
para modificar esta info
*/

#include <iostream>

using std::string;

class Employee{
private:
    //Atributes
    string Name;
    string Company;
    int Age;

public:
    //Method
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

    employee1.setAge(15);
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old" << std::endl;

    return 0;
}