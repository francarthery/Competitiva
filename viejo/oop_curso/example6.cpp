/*
Polimorfismo: Principio que permite a objetos de diferentes clases ser tratados de forma
uniforme a traves de una interfaz comun. Un objeto puede comportarse de distintas formas
segun el contexto en el que se utiliza.

El uso más común es utilizando una referencia a una clase padre para referir a un objeto
de la clase hija. Así conseguimos que si hay dos metodos con el mismo nombre en una clase
hija y una padre, se va a ejecutar la funcion de mayor
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

    virtual void Work(){
        std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
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

    void Work(){
        std::cout << Name << " is writing " << FavProgLanguage << " code" << std::endl;
    }
};

class Teacher:public Employee{
public:
    string Subject;

    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }

    void PrepareLesson(){
        std::cout << Name << " is preparing a " << Subject << " lesson" << std::endl;
    }

    void Work(){
        std::cout << Name << " is teaching " << Subject << std::endl;
    }
};

int main(){

    //Creamos un objeto de tipo Employee y lo iniciamos con el constructor
    Employee employee1 = Employee("Saldina", "Tutocart", 30);
    Developer d = Developer("Saldina", "Tutocart", 25, "C++");
    Teacher t = Teacher("Puppo", "UTN", 42, "Algebra");
    
    //Usamos una referencia de la clase padre para referirnos a un objetod de la clase hija
    Employee *e1 = &d;
    Employee *e2 = &t;
    Employee *e3 = &employee1;

    e1 -> Work();
    e2 -> Work(); //Como la clase derivada tiene un metodo Work(), se ejecuta ese.
    e3 -> Work(); //Como referenciamos un objeto de la clase padre. Se ejecuta el metodo de la clase padre
    
    return 0;
}