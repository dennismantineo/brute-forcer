#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Generate the password
std::string passwordGenerator(int length) {
    char possibleCharacters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'z'};
    std::string possiblePassword;

    for (int i = 0; i < length; i++) {
        int randomIndex = std::rand() % sizeof(possibleCharacters);
        possiblePassword += possibleCharacters[randomIndex];
    }

    return possiblePassword;
}

int main() {
    // Ask the user to insert a password
    std::string password;
    std::cout << "Please insert your password: ";
    std::cin >> password;
    int passwordLength = password.length();

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Password check
    std::string generatedPassword;
    while (password != (generatedPassword = passwordGenerator(passwordLength))) {
        std::cout << "Trying: " << generatedPassword << std::endl;
    }

    std::cout << "The password is: " << generatedPassword << std::endl;

    return 0;
}