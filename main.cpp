//Jaiden Bailey 


#include <iostream>
#include <string>
#include <array>
#include <cstdlib> // rand() and srand()
#include <ctime> //time()
#include <random> //Mersanne Twist

//generates a random number between min and mid (inclusive)
//assumes srand() has already been called
//assumes max - min <= RAND_MIX
int getRandomNumber(int min, int max) {
    static constexpr double fraction {1.0/(RAND_MAX + 1)};
    return min + static_cast<int>((max - min + 1) * (std::rand()*fraction));
}

class Creature{
    protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;
    public:
    Creature(std::string_view name, char symbol, int health, int damage, int gold)
    : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold{gold} {}
    std::string getName() {return m_name;}
    char getSymbol() {return m_symbol;}
    int getHealth() {return m_health;}
    int getDamage() {return m_damage;}
    int getGold() {return m_gold;}
    void reduceHealth(int damage) {m_health -= damage;}
    bool isDead() {return m_health <= 0;}
    void addGold(int gold) {m_gold += gold;}
};

class Player : public Creature{
    private:
    int m_level{1};
    public:
    Player(std::string_view name)
    : Creature{name, '@', 10, 1, 0} {}
    int getLevel() {return m_level;}
    bool hasWon() {return m_level >= 20;}
    void levelUp() {
        ++m_level;
        ++m_damage;}
};

class Monster : public Creature{
    public:
    enum Type {
        dragon,
        orc,
        slime,
        max_types
    };
    private:
    static const Creature& getDefaultCreature(Type type) {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData {
            {
                {"dragon", 'D', 20, 4, 100},
                {"orc", 'o', 4, 2, 25},
                {"slime", 's', 1, 1, 10} }
            };
            return monsterData.at(static_cast<size_t>(type));
        }
    public:
    Monster(Type monsterType)
    : Creature{getDefaultCreature(monsterType)} {}
    static Monster getRandomMonster() {
        int num{getRandomNumber(0, static_cast<int>(Type::max_types) - 1)};
        return Monster{static_cast<Type>(num)};
        }
    bool isDead() {return m_health <= 0;}
    };

void attackMonster(Player& player, Monster& monster) {
    if(player.isDead()) {
        return;
    }
    monster.reduceHealth(player.getDamage());
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage\n";
    if (monster.isDead()) {
        std::cout << player.getName() << " has defeated a " << monster.getName() << "!" << std::endl;
        player.addGold(monster.getGold());
        std::cout << "You have received " << monster.getGold() << " gold!" << std::endl;
        player.levelUp();
        std::cout << "You have leveled up!" << std::endl;
    }
}

void attackPlayer(Player& player, Monster& monster) {
    if (monster.isDead()) {
        return;
    }
    player.reduceHealth(monster.getDamage());
    std::cout << monster.getName() << " hit " << player.getName() << " for " << monster.getDamage() << " damage\n";
}

void fightMonster(Player& player) {
    Monster monster{Monster::getRandomMonster()};
    std::cout << "You have encounted a " << monster.getName() << " " << monster.getSymbol() << "." << std::endl;
    while (!player.isDead() && !monster.isDead()) {
        std::cout << "(R)un or (F)ight: ";
        char input{};
        std::cin >> input;
        if (input == 'R' || input == 'r') {
            if (getRandomNumber(1,2) == 1) {
                std::cout << "You've successfully fled\n";
                return;
            }
            else {
                std::cout << "You've failed to flee\n";
                attackPlayer(player, monster);
                continue;
            }
        }
        if (input == 'F' || input == 'f') {
            attackMonster(player, monster);
            attackPlayer(player, monster);
        }
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed time to system clock
    std::rand(); //get rid of the first result

    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;

    Player player{playerName};
    std::cout << "Welcome " << player.getName() << std::endl;
    while (!player.isDead() && !player.hasWon())
        fightMonster(player);

    if (player.isDead()) {
        std::cout << "You died at level " << player.getLevel() << " holding " << player.getGold() << " gold\n";
        std::cout << "Too bad you can't take it with you\n";
    }
    else {
        std::cout << "You have won the game with " << player.getGold() << " gold\n";
    }

    std::cout << std::rand();

    return 0;
}
