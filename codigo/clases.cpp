#include <iostream>

using std::string;

class AbstractCharacter{
    
};

class Character{
protected:
    string Name;
    int Health;
    int Damage;

public:
    Character(string name, int health, int damage){
        Name = name;
        Health = health;
        Damage = damage;
    }

    void SetName(string name){
        Name = name;
    }
    string GetName(){
        return Name;
    }
    void SetHealth(int health){
        if(health > 0)
            Health = health;
        else
            Health = 0;
    }
    int GetHealth(){
        return Health;
    }
    void SetDamage(int damage){
        Damage = damage;
    }
    int GetDamage(){
        return Damage;
    }

    void CharInfo(){
        std::cout << "Nombre: " << Name << std::endl;
        std::cout << "Salud: " << Health << std::endl;
        std::cout << "Daño: " << Damage << std::endl;
    }

    void HealthInfo(){
        if(Health > 0)
            std::cout << "Salud de " << Name << ": " << Health << std::endl << std::endl;
        else
            std::cout << Name << " ha muerto." << std::endl;
    }
};

class CapitanAmerica:public Character{
private:
    bool Shield;
    bool Steroids;

public:
    CapitanAmerica(string name, int health, int damage, bool shield, bool steroids)
        :Character(name, health, damage)
    {
        Shield = shield;
        Steroids = steroids;
    }
    bool ShieldConditon(){
        return Shield;
    }
    void ChangeShield(){
        Shield = !Shield;
        std::cout << "Escudo " << (Shield ? "activado" : "desactivado") << std::endl;
    }
    bool SteroidsCondition(){
        return Steroids;
    }
    void DrinkSteroids(){
        Steroids = true;
        std::cout << "Esteroides tomados" << std::endl;
    }

    void Info(){
        CharInfo();
        std::cout << "Escudo: " << (Shield ? "activado" : "desactivado") << std::endl;
        std::cout << "Esteroides: " << (Steroids ? "Juiced" : "Natty") << std::endl << std::endl;
    }
};

class IronMan:public Character{
private:
    bool Fly;
    bool Beam;

public:
    IronMan(string name, int health, int damage, bool fly, bool beam)
        :Character(name, health, damage)
    {
        Fly = fly;
        Beam = beam;
    }

    void StartFly(){
        Fly = true;
        std::cout << "Vuelo inicido" << std::endl;
    }

    void Blast(){
        Beam = !Beam;
        std::cout << "Beam " << (Beam ? "activado" : "desactivado") << std::endl;
    }

    void Attack(CapitanAmerica& target){
        std::cout << Name << " ataco a " << target.GetName() << std::endl;

        if(target.ShieldConditon())
            target.ChangeShield();
        else{
            target.SetHealth(target.GetHealth() - Damage * (Beam ? 1.5 : 1));
            if(Beam) Blast();
        }

        target.HealthInfo();
    }

    void Info(){
        CharInfo();
        std::cout << "Volando: " << (Fly ? "Si" : "No") << std::endl;
        std::cout << "Beam: " << (Beam ? "Activado" : "Desactivado") << std::endl << std::endl;
    }
};

int main(){

    CapitanAmerica jug1 = CapitanAmerica("Capi", 140, 20, 1, 0);
    jug1.Info(); 

    IronMan jug2 = IronMan("Tony", 200, 35, 0, 0);
    jug2.Info();

    jug2.Attack(jug1);

    jug2.Blast();
    jug2.Attack(jug1);
    jug2.Attack(jug1);
    jug2.Attack(jug1);
    jug2.Attack(jug1);

    return 0;
}