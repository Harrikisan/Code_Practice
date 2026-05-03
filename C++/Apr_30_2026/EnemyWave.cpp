#include <iostream>
using namespace std;

class Enemy
{
private:
    string name;
    int health;
public:
    Enemy(string name, int health) : name(name), health(health) {}
    int getHealth()
    {
        return health;
    }
    string getName()
    {
        return name;
    }
    void takeDamage(int damage)
    {
        if (damage > 12)
        {
            cout << "Invalid attack power!"  << endl;
            return;
        }
        else if (damage > 0 && damage <= 12)
        {
            health -= damage;
            if (health <= 0)
            {
                cout << name << " defeated!" << endl;
                return;
            }
        }
    }
};

class Player
{
private:
    string name;
    int health;
public:
    Player(string name, int health) : name(name), health(health) {}
    int getHealth()
    {
        return health;
    }
    void attack(Enemy &enemy, int damage)
    {
        enemy.takeDamage(damage);
    }
};

int main(){
    Enemy enemies[3] = {
        Enemy("Goblin", 10),
        Enemy("Orc", 20),
        Enemy("Troll", 50)
    };
    
    Player hero("Hero", 100);

    for(int i = 0; i < 3; i++) {
        while(enemies[i].getHealth() > 0) {
            cout << "Fighting " << enemies[i].getName() << " HP (" << enemies[i].getHealth() << ")" << endl;
            int damage;
            cout << "Enter attack : ";
            cin >> damage;
            hero.attack(enemies[i], damage);
        }
    }

    cout << "Defeated enemies!" << endl;
    for (int i = 0; i < 3; i++) {
        cout << enemies[i].getName() << endl;
    }
    
}