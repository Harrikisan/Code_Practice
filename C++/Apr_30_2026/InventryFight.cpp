#include <iostream>
using namespace std;

class Weapons
{
private:
    string name;
    int damage;

public:
    Weapons() : name(""), damage(0) {}
    Weapons(string name, int damage) : name(name), damage(damage)
    {
    }
    int getDamage()
    {
        return damage;
    }
};

class Player
{
private:
    string name;

public:
    Weapons weapon[3];
    Player(string name, Weapons w1, Weapons w2, Weapons w3) : name(name)
    {
        weapon[0] = w1;
        weapon[1] = w2;
        weapon[2] = w3;
    }
};

class Enemy
{
private:
    int health;

public:
    Enemy(int health) : health(health) {}
    int getHealth()
    {
        return health;
    }
    void takeDamage(int damage)
    {
        if (damage > 12)
        {
            cout << "Weapon too powerful" << endl;
            return;
        }
        else if (damage > 0 && damage <= 12)
        {
            health -= damage;
            if (health < 0)
            {
                cout << "Enemy defeated!";
                return;
            }
        }
    }
};

int main()
{
    Weapons Sword("Sword", 10);
    Weapons Axe("Axe", 15);
    Weapons Dagger("Dagger", 5);
    Player player = Player("Hero", Sword, Axe, Dagger);
    Enemy boss = Enemy(40);
    while (boss.getHealth() > 0)
    {
        cout << "Enemy HP: " << boss.getHealth() << endl;
        cout << "Choose your weapon:\n1. Sword\n2. Axe\n3. Dagger\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            boss.takeDamage(Sword.getDamage());
            break;
        case 2:
            boss.takeDamage(Axe.getDamage());
            break;
        case 3:
            boss.takeDamage(Dagger.getDamage());
            break;
        default:
            cout << "Invalid choice";
        }
    }
}