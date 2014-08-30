//Guess My Number - Computer Version

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
	unsigned int guess, number = 0, tries = 0;
	string try_text;
	char play_again;

	cout << "\tWelcome to Guess My Number -- Computer Version!\n\n";
	do {
		cout << "Please enter a number (1-100) and the computer will try to guess it. ";
		while (!(cin >> number) || number >= 101 || number < 1) {
			cout << "\nInvalid input. Please enter a number between 1 and 100.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		srand(time(0));
		guess = rand() % 100 + 1;
		while (guess != number) {
			++tries;
			guess = rand() % 100 + 1;
		}
		if (guess == number) {
			if (tries == 1) {
				try_text = " try.";
			}
			else {
				try_text = " tries.";
			}
			cout << "The computer correctly guessed your number, " << number << " in " << tries << try_text;
			cout << "\n\nWould you like to play again? (y/n): ";
			cin >> play_again;
		} 
	} while (play_again == 'y');
	return 0;
}
