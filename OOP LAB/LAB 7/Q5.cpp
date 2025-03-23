#include <iostream>
using namespace std;

class Character
{
public:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
    Character(int id, string n, int l, int h, string w) : characterID(id), name(n), level(l), healthPoints(h), weaponType(w) {}
    virtual void attack()
    {
        cout << name << " attacks with " << weaponType << "!" << endl;
    }

    virtual void defend()
    {
        cout << name << " defends against the attack!" << endl;
    }
    virtual void displayStats()
    {
        cout << "\nCharacter ID: " << characterID << "\nName: " << name << "\nLevel: " << level << "\nHealth Points: " << healthPoints << "\nWeapon Type: " << weaponType << endl;
    }
};

class Warrior : public Character
{
public:
    int armorStrength;
    int meleeDamage;
    Warrior(int id, string n, int l, int h, string w, int a, int md) : Character(id, n, l, h, "Sword"), armorStrength(a), meleeDamage(md) {}
    void attack() override
    {
        cout << name << " swings their sword for " << meleeDamage << " damage!" << endl;
    }
};

class Mage : public Character
{
public:
    int manaPoints;
    int spellPower;
    Mage(int id, string n, int l, int h, string w, int mp, int sp) : Character(id, n, l, h, "Magic Staff"), manaPoints(mp), spellPower(sp) {}
    void defend()
    {
        cout << name << " casts a spell for " << spellPower << " damage!" << endl;
    }
};

class Archer : public Character
{
public:
    int arrowCount;
    int rangedAccuracy;
    Archer(int id, string n, int lvl, int hp, int arrows, int accuracy) : Character(id, n, lvl, hp, "Bow"), arrowCount(arrows), rangedAccuracy(accuracy) {}
    void attack() override
    {
        if (arrowCount > 0)
        {
            cout << name << " shoots an arrow with " << rangedAccuracy << "% accuracy!" << endl;
            arrowCount--;
        }
        else
        {
            cout << name << " has no arrows left!" << endl;
        }
    }
};

class Rogue : public Character
{
public:
    int stealthLevel;
    int agility;
    Rogue(int id, string n, int lvl, int hp, int s, int a) : Character(id, n, lvl, hp, "Daggers"), stealthLevel(s), agility(a) {}
    void displayStats() override
    {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << endl;
    }
};

int main() {
    Warrior w1(1, "Thor", 10, 150, "Sword", 50, 30);
    Mage m1(2, "Merlin", 12, 100, "Magic Staff", 200, 40);
    Archer a1(3, "Legolas", 15, 120, 10, 90);
    Rogue r1(4, "Ezio", 14, 110, 80, 95);

    w1.displayStats();
    m1.displayStats();
    a1.displayStats();
    r1.displayStats();

    cout << "\n--- Battle Begins! ---" << endl;
    w1.attack();
    m1.defend();
    a1.attack();
    a1.attack();
    a1.displayStats();
    return 0;
}
