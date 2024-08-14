#include <iostream>
#include <string>
#include <vector>


class Weapon {
public:
    Weapon(const std::string& name, int energyCost, int damage, int maxUses)
        : name(name), energyCost(energyCost), damage(damage), maxUses(maxUses), uses(maxUses) {}

    virtual std::string getName() const { return name; }
    virtual int getEnergyCost() const { return energyCost; }
    virtual int getDamage() const { return damage; }
    virtual int getUsesRemaining() const { return uses; }
    virtual bool canUse() const { return uses > 0; }
    virtual void use() {
        if (canUse()) {
            --uses;
            std::cout << "Used " << name << "." << std::endl;
        } else {
            std::cout << name << " has no uses remaining." << std::endl;
        }
    }

protected:
    std::string name;
    int energyCost;
    int damage;
    int maxUses;
    int uses;
};

class Shield {
public:
    Shield(const std::string& name, int energyCost, int maxUses)
        : name(name), energyCost(energyCost), maxUses(maxUses), uses(maxUses) {}

    virtual std::string getName() const { return name; }
    virtual int getEnergyCost() const { return energyCost; }
    virtual int getUsesRemaining() const { return uses; }
    virtual bool canUse() const { return uses > 0; }
    virtual void use() {
        if (canUse()) {
            --uses;
            std::cout << "Used " << name << "." << std::endl;
        } else {
            std::cout << name << " has no uses remaining." << std::endl;
        }
    }

protected:
    std::string name;
    int energyCost;
    int maxUses;
    int uses;
};

class Character {
    public:
        Character(const std::string& name, Weapon* weapon, Shield* shield)
            : name(name), weapon(weapon), shield(shield) {}

        void attack(Character& target) {
            if (weapon && weapon->canUse()) {
                std::cout << name << " attacks " << target.name << " with " << weapon->getName() << "!" << std::endl;
                target.takeDamage(weapon->getDamage());
                weapon->use();
            } else {
                std::cout << name << " has no usable weapon and cannot attack." << std::endl;
            }
        }

        void defend() {
            if (shield && shield->canUse()) {
                std::cout << name << " uses " << shield->getName() << " to defend." << std::endl;
                shield->use();
                // Implement shield usage logic
            } else {
                std::cout << name << " has no usable shield and cannot defend." << std::endl;
            }
        }

        void takeDamage(int damage) {
            std::cout << name << " took " << damage << " damage." << std::endl;
            // Implement character damage handling
        }

        bool isDead() const {
            // Implement character death logic
            return false;
        }

    std :: string getName() const { return name; }

    private:
        std::string name;
        Weapon* weapon;
        Shield* shield;



};

class Fight {
public:
            static void battle(Character& character1, Character& character2) {
        std::cout << "Fight begins between " << character1.getName() << " and " << character2.getName() << "!" << std::endl;

        while (true) {
            character1.attack(character2);
            if (character2.isDead()) {
                std::cout << character1.getName() << " wins the fight!" << std::endl;
                break;
            }

            character2.defend();
            if (character1.isDead()) {
                std::cout << character2.getName() << " wins the fight!" << std::endl;
                break;
            }
        }
    }
};

int main()
{
    Weapon* batarang = new Weapon("Batarang", 10, 20, 5);
    Shield* capeGlide = new Shield("Cape Glide", 15, 3);

    Character batman("Batman", batarang, capeGlide);
    Character joker("Joker", nullptr, nullptr);

    Fight::battle(batman, joker);

    delete batarang;
    delete capeGlide;
    return 0;
}