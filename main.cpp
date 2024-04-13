#include <iostream>
#include <vector>

// Enum for character classes
enum class CharacterClass {
    Warrior,
    Wizard,
    Archer
};

// Structure for character data
struct Character {
    int id;
    CharacterClass charClass;
    float meleeAttack;
    float rangedAttack;
};

// Function to find the name of the strongest character
int findStrongestCharacter(const std::vector<Character>& characters) {
    if (characters.empty()) return -1; // Return -1 if the vector is empty

    int strongestId = characters[0].id;
    float maxStrength = characters[0].meleeAttack + characters[0].rangedAttack;

    for (const auto& character : characters) {
        float currentStrength = character.meleeAttack + character.rangedAttack;
        if (currentStrength > maxStrength) {
            maxStrength = currentStrength;
            strongestId = character.id;
        }
    }

    return strongestId;
}

int main() {
    // Example characters
    std::vector<Character> characters = {
        {1, CharacterClass::Warrior, 15.5, 10.0},
        {2, CharacterClass::Wizard, 12.0, 13.5},
        {3, CharacterClass::Archer, 10.0, 18.0}
    };

    int strongestCharacterId = findStrongestCharacter(characters);
    std::cout << "The strongest character ID is: " << strongestCharacterId << std::endl;

    return 0;
}
