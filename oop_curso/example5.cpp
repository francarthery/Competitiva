/*
Herencia: Consiste en hacer que una clase herede los atributos y metodos de otra clase.
Tenemos una clase padre o superclase y la clase hija o derivada.

La clase hija no puede acceder a los atributos de la clase padre directamente si estos 
son privados. Con el modo protected las clases heredadas si pueden acceder a estos.

La herencia por defecto se hace de forma privada por lo que una instancia de la clase hija
no podra acceder a los metodos de la clase padre a menos que la herencia se haga publica
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
    string Company;
    int Age;
protected:
    string Name;

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
//Developer hereda todos los atributos y metodos de Employee
class Developer:public Employee{
public:
    string FavProgLanguage;

    //Constructor
    Developer(string name, string company, int age, string favProgLanguage)
        :Employee(name, company, age) //Los atributos de Employee se los pasamos a su constructor
    {
        FavProgLanguage = favProgLanguage;
    }

    void FixBug(){
        //Para acceder a los atributos de la clase padre, solo se puede mediante el
        std::cout << Name << " fixed bug using " << FavProgLanguage << std::endl;
    }

};

class Teacher:public Employee{
public:
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }

    string Subject;
    void PrepareLesson(){
        std::cout << Name << " is preparing a " << Subject << " lesson" << std::endl;
    }
};

int main(){

    //Creamos un objeto de tipo Employee y lo iniciamos con el constructor
    Employee employee1 = Employee("Saldina", "Tutocart", 30);

    Developer d = Developer("Saldina", "Tutocart", 25, "C++");
    d.FixBug();
    d.AskForPromotion();

    Teacher t = Teacher("Puppo", "UTN", 42, "Algebra");
    t.PrepareLesson();
    t.AskForPromotion();

    return 0;
}