#include <iostream>
#include <cstdlib> 
#include <ctime>  

using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(0)));

    int randomNumber = rand() % 100 + 1;

    int userInput;
    int userGuess;

    cout << "Welcome to the Guess the Number Game!\n";
    cout << "Try to guess the number between 1 and 100.\n\n";

    do {
 
        cout << "Enter your guess: ";
        cin >> userInput;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(INT_MAX, '\n'); 
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        userGuess = userInput;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << "\n";
        }

    } while (userGuess != randomNumber);

    return 0;
}
