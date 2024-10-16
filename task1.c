#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 1 and 100
    int number_to_guess = std::rand() % 100 + 1;
    int user_guess = 0;
    int attempts = 0;

    std::cout << "Welcome to Guess the Number!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> user_guess;

        // Check if the input is valid
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            std::cout << "Please enter a valid integer." << std::endl;
            continue;
        }

        attempts++;

        // Check the user's guess
        if (user_guess < number_to_guess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (user_guess > number_to_guess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number " 
                      << number_to_guess << " in " << attempts << " attempts." << std::endl;
            break;
        }
    }

    return 0;
}
