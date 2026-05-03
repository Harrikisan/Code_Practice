#include <iostream>
using namespace std;

class Pokemon {
protected:
    int health;
public:
    string name;

    Pokemon() {}

    Pokemon(string name, int health): name(name), health(health) {}

    int getHealth() {
        return health;
    }

    void hit(int amount) {
        health -= amount;
    }
};

class Trainer {
private:
    Pokemon myCollection[100];
    int currentCollected = 0;

public:
    string name;
    Trainer(string name): name(name) {}

    void displayCollection() {
        cout << name << "'s Pokemon Collection:\n";
        for (int i = 0; i < currentCollected; i++) {
            cout << "- " << myCollection[i].name << " (Health: " << myCollection[i].getHealth() << ")\n";
        }
    }
    
    void tryCollect(Pokemon targetPokemon) {
        cout << "# \n\n";
        cout << "battle begins: \n " << name << " vs " << targetPokemon.name << endl;

        for (int i = 0; i < 3; i++) {
            int attackPower = 10;
            targetPokemon.hit(attackPower);
            cout << "Current Health: " << targetPokemon.getHealth() << endl;
            
        }

        cout << "Congratulations! You have collected " << targetPokemon.name << endl;
        myCollection[currentCollected++] = targetPokemon;
    }
};

Pokemon p1("Pikachu", 30);
Pokemon p2("Charmander", 50);
Pokemon p3("Bulbasaur", 20);

int main() {
    Trainer t1("Ash");
    t1.tryCollect(p1);
    t1.tryCollect(p2);
    t1.tryCollect(p3);
    
    t1.displayCollection();

    return 0;
}