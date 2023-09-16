//NUMBER GUESSING GAME
/* Create a program that generates a random number and asks the user to guess it. Provide feedback on whether the guess is
 too high or too low until the user guesses the correct number */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    int userGuess;
    int numberOfGuesses = 0;

    cout << "Welcome to the Guess the Number Game!" <<endl;
    cout << "I have selected a random number between 1 and 100. Try to guess it." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        numberOfGuesses++;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number (" << randomNumber << ") in " << numberOfGuesses << " guesses!" << endl;
        }
    } 
    while (userGuess != randomNumber);

    return 0;
}
