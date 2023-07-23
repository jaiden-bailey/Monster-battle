# Monster Battle Game

This is a C++ console-based game where players can engage in epic monster battles. Players control a character, known as the "Player," who faces various monsters in combat. The game generates monsters randomly, each with unique attributes and abilities. The objective is for the player to defeat monsters, level up, and accumulate gold.

## Features

- **Random Monster Generation**: The game utilizes the Mersenne Twister algorithm to generate random monsters from a predefined set. Each monster has its name, symbol, health, damage, and gold attributes.

- **Battle System**: Players can either choose to fight the encountered monster or attempt to flee. The outcome of the battles depends on the player's actions and the generated random numbers.

- **Player Leveling**: As the player defeats monsters, they gain experience points and level up. Leveling up increases the player's damage output, making them more powerful as the game progresses.

- **Gold Accumulation**: Defeated monsters reward the player with gold. The player can collect gold by defeating monsters, which can be used for various purposes within the game.

## How to Play

1. The game starts by asking the player to enter their name.

2. The player controls their character, represented by the '@' symbol.

3. Monsters appear randomly during the game. The player has the option to either fight or attempt to flee from each encountered monster.

4. Battles are turn-based. The player and monster take turns attacking each other.

5. The player can defeat monsters by reducing their health to zero. Upon victory, the player receives gold and gains experience points.

6. The game continues until the player's character is defeated or the player reaches level 20.

7. If the player's character dies, the game ends, displaying their level and the amount of gold held.

8. If the player successfully reaches level 20, the game ends, declaring the player as the winner with their total gold accumulated.

## Running the Game

To run the game, ensure you have a C++ compiler that supports C++11 or later. Compile the source code and execute the resulting binary. During gameplay, follow the on-screen instructions and input options when prompted.


Feel free to contribute to the game by adding new features or improving existing ones. Happy gaming!
