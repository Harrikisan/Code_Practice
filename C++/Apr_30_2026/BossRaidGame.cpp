#include <iostream>
using namespace std;

class Boss
{
private:
    string name;
    int health;

public:
    Boss(string name, int health) : name(name), health(health) {}
    string getName()
    {
        return name;
    }
    int getHealth()
    {
        return health;
    }
    void setHealth(int newHealth)
    {
        health = newHealth;
    }
};

class Player
{
private:
    string name;
    int health;

public:
    Player(string name, int health) : name(name), health(health) {}
    string getName()
    {
        return name;
    }
    int getHealth()
    {
        return health;
    }
    void setHealth(int newHealth)
    {
        health = newHealth;
    }
};

class Bossfight
{
public:
    void Playerattack(Boss &boss, Player &player, int damage)
    {

        if (damage <= 15 && damage > 0)
        {
            boss.setHealth(boss.getHealth() - damage);
            if (boss.getHealth() <= 0)
            {
                cout << "Dragon defeated!" << endl;
                cout << "Winner : Player" << endl;
                return;
            }
            else
            {
                Bossattack(boss, player);
            }
        }
        else if (damage > 15)
        {
            cout << "Your attack was too strong !" << endl;
        }
        else
        {
            cout << "Invalid damage value." << endl;
        }
    }

    void Bossattack(Boss &boss, Player &player)
    {
        player.setHealth(player.getHealth() - 8);
        if (player.getHealth() <= 0)
        {
            cout << "You have been defeated Dragon " << endl;
            cout << "Winner : Dragon" << endl;
            return;
        }
    }
}
;

int main()
{
    Boss boss("Dragon", 50);
    Player player("Hero", 40);
    cout << "Battle: Hero vs Dragon";
    while (boss.getHealth() > 0 && player.getHealth() > 0)
    {
        int damage;
        cout << "Dragon HP : " << boss.getHealth() << " | Hero HP : " << player.getHealth() << endl;
        cout << "Enter attack: ";
        cin >> damage;
        Bossfight fight;
        fight.Playerattack(boss, player, damage);
    };
}