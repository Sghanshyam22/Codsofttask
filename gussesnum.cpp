#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 10 + 1;

    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        std::cout << "Guess the number (between 1 and 10): ";
        std::cin >> userGuess;

        attempts++;

        if (userGuess == randomNumber) {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << std::endl;
            break;
        } else if (userGuess < randomNumber) {
            std::cout << "Too low. Try again!" << std::endl;
        } else {
            std::cout << "Too high. Try again!" << std::endl;
        }

    } while (true);

    return 0;
}


