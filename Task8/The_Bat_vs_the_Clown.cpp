#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Classes for Batman's and Joker's weapon and shields
class Weapon
{
    protected:
        string name;
        int energy_consumption;
        int damage;

    public:
        Weapon(string name, int energy_consumption, int damage)
        : name(name), energy_consumption(energy_consumption), damage(damage){}

        virtual string getName() { return name; }
        virtual int getEnergyConsumption() { return energy_consumption; }
        virtual int getDamage() { return damage; }
};

class Shield
{
    protected:
        string name;
        int save_percent;
        int energy_consumption;

    public:
        Shield(string name, int save_percent, int energy_consumption)
        : name(name), save_percent(save_percent), energy_consumption(energy_consumption){}

        virtual string getName() { return name; }
        virtual int getSavePercent() { return save_percent; }
        virtual int getEnergyConsumption() { return energy_consumption; }

        //virtual void setEnergyConsumption(int energy_consumption) { this->energy_consumption = energy_consumption
};


//Batman Weapon and Shields
class Batarang : public Weapon
{
    public:
        Batarang() : Weapon("Batarang", 50, 11) {}
};

class Grapple_Gun : public Weapon
{
    public:
    Grapple_Gun() : Weapon("Grapple_Gun", 88, 20) {}
};

class Explosive_Gel : public Weapon
{
    public:
        Explosive_Gel() : Weapon("Explosive_Gel", 92, 10){}
};

class Batclaw : public Weapon
{
    public:
        Batclaw() : Weapon("Batclaw", 120, 20){}
};

class Cape_Glide : public Shield
{
    public:
        Cape_Glide() : Shield("Cape_Glide", 100, 100){}
};

class Smoke_Pellet : public Shield
{
    public:
        Smoke_Pellet() : Shield("Smoke_Pellet", 90, 100){}
};

//Joker Weapon and Shields
class JoyBuzzer : public Weapon {
public:
    JoyBuzzer() : Weapon("Joy Buzzer", 40, 8) {}
};

class LaughingGas : public Weapon {
public:
    LaughingGas() : Weapon("Laughing Gas", 56, 13) {}
};

class AcidFlower : public Weapon {
public:
    AcidFlower() : Weapon("Acid Flower", 100, 22) {}
};

class TrickShield : public Shield {
public:
    TrickShield() : Shield("Trick Shield", 15, 0.32) {}
};

class RubberChicken : public Shield {
public:
    RubberChicken() : Shield("Rubber Chicken", 40, 0.8) {}
};

class Character
{
    protected:
        int health;
        int energy;
        int shield;

    public:
        Character() : health(100), shield(0), energy(500){}

        static int character_count;

        //getters
        int getHealth(){return health;}
        int getEnergy(){return energy;}


        //Setters
        void setEnergy(int energy)
        {
            if (energy < 0)
            {
                cout << "0 energy" << endl;
                return;
            }
            this->energy = energy;
        }

        void setShield(int shield)
        {
            if (shield < 0)
            {
                cout << "0 shield" << endl;
                return;
            }
            this->shield = shield;
        }


        void setHealth(int health)
        {
            if (health < 0)
            {
                cout << "Health cannot be negative!" << endl;
                return;
            }
            this->health = health;
        }

        virtual void attack(Character* opponent) = 0;
        virtual void defend(int damage) = 0;

        void takeDamage(int damage)
        {
            health -= damage;
            if (health <= 0)
                health = 0;
        }

        ~Character()
        {
            //cout << "Character destroyed!"<< endl;
            character_count--;
        }

};


class Batman : public Character
{
    private:
        Batarang batarang;
        Grapple_Gun grapple_gun;
        Explosive_Gel explosive_gel;
        Batclaw batclaw;

    public:
        void attack(Character* opponent) override
        {
            int choice = rand() % 4;
            switch(choice)
            {
                case 0:
                    useWeapon(&batarang, opponent);

                    break;
                case 1:
                    useWeapon(&batclaw, opponent);
                    break;
                case 2:
                    useWeapon(&grapple_gun, opponent);
                    break;
                case 3:
                    useWeapon(&explosive_gel, opponent);
                    break;
            }

        }

        private:
            void useWeapon(Weapon* weapon, Character* opponent)
            {
                if(energy >= weapon->getEnergyConsumption())
                {
                    energy -= weapon->getEnergyConsumption();
                    opponent->takeDamage(weapon->getDamage());
                    cout << "Batman used " << weapon->getName() << " against Joker" << endl;
                    cout << "Remaining energy: " << energy << endl;
                }
                else
                {
                    cout << "Not enough energy to use " << weapon->getName() << endl;
                }
            }

            void useShield(Shield* shield, int damage)
            {
                if (energy >= shield->getEnergyConsumption()) {
                    energy -= shield->getEnergyConsumption();
                    int reducedDamage = static_cast<int>(damage * (1 - shield->getSavePercent()));
                    takeDamage(reducedDamage);
                    std::cout << "Batman used " << shield->getName() << "." << std::endl;
                    std::cout << "Batman's health: " << getHealth() << std::endl;
                } else {
                    std::cout << "Batman doesn't have enough energy to use " << shield->getName() << "." << std::endl;
                }
            }
};


class Joker : public Character
{
    private:
        JoyBuzzer joy_buzzer;
        LaughingGas laughing_gas;
        AcidFlower acid_flower;
        TrickShield trick_shield;
        RubberChicken rubber_chicken;

    public:
        void attack(Character* opponent) override
        {
            int choice = rand() % 3;
            switch(choice)
            {
                case 0:
                    useWeapon(&joy_buzzer, opponent);
                    break;
                case 1:
                    useWeapon(&laughing_gas, opponent);
                    break;
                case 2:
                    useWeapon(&acid_flower, opponent);
                    break;
            }
        }

        private:
            void useWeapon(Weapon* weapon, Character* opponent)
            {
                if(energy >= weapon->getEnergyConsumption())
                {
                    energy -= weapon->getEnergyConsumption();
                    opponent->takeDamage(weapon->getDamage());
                    cout << "Joker used " << weapon->getName() << " against Batman" << endl;
                    cout << "Remaining energy: " << energy << endl;
                }
                else
                {
                    cout << "Not enough energy to use " << weapon->getName() << endl;
                }
            }

            void useShield(Shield* shield, int damage)
            {
                if (energy >= shield->getEnergyConsumption())
                {
                    energy -= shield->getEnergyConsumption();
                    int reducedDamage = static_cast<int>(damage * (1 - shield->getSavePercent()));
                    takeDamage(reducedDamage);
                    std::cout << "Batman used " << shield->getName() << "." << std::endl;
                    std::cout << "Batman's health: " << getHealth() << std::endl;
                } else
                {
                    std::cout << "Batman doesn't have enough energy to use " << shield->getName() << "." << std::endl;
                }
            }

};

int main()
{

    return 0;
}

