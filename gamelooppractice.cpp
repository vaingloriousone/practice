//Game Loop test

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Variables for selection, win conditions, and game loop itself.
int game_over = 1;
int menu_select;
int save_select = 0;
int death_number;
int avoid_number = 0;
int success = 0; // Now with more stat tracking!
int config_sub_menu;
string trap_text; //For readability (becuase it would've annoyed me)

void title_menu() {
	
	cout << "[1] New Game\n";
	cout << "[2] Continue \n";
	cout << "[3] Configuration \n";
	cout << "[4] Exit \n";

}

 void file_menu() {
	game_over = 0;
	cout << "\nPlease select which save file you would like to load.\n\n";
	for (int i = 1; i <= 5; i++) {
		cout << "[" << i << "] Empty File \n";
	}
	cout << "[6] Exit\n";
	
	if (!(cin >> save_select)) { // Any instances of this will check that the input is actually an integer.
		cout << "Invalid value.\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		file_menu();
	} 
		
	if (save_select > 6) {
		cout << "Invalid value. \n";
		file_menu();
	}
	if (save_select > 0 && save_select < 6) {
		cout << "You do not appear to have any saved data... \n";
		file_menu();
	}
		game_over = 1;
}

 void config_menu() {

	 cout << "Configuration Menu\n\n";
	 cout << "[1] Video Configuration\n";
	 cout << "[2] Audio Configuration\n";
	 cout << "[3] Keyboard/Gamepad Configuration\n";
	 cout << "[4] Exit\n";

	if (!(cin >> config_sub_menu)) {
		 cout << "Invalid value.\n";
		 cin.clear();
		 cin.ignore(numeric_limits<streamsize>::max(), '\n');
		 config_menu();
	 }
	else {
		switch (config_sub_menu) {
		case 1:
			cout << "\n\nReally? It's a text game.\n";
			cout << "\nThere's really not much to configure.\n\n";
			config_menu();
			break;

		case 2:
			cout << "\n\nSorry, there's no audio to configure, either.\n";
			cout << "Just use your imagination, for now.\n\n";
			config_menu();
			break;

		case 3:
			cout << "\n\nI would hope your keyboard is already configured to use this.\n";
			cout << "There's not much to change right now. Also, Gamepads are not supported.\n\n";
			config_menu();
			break;
		case 4:
			game_over = 1;
			break;

		default:
			cout << "\n\nInvalid selection.\n\n";
			config_menu();
			break;
		}
	}

 }

int main() {

	//Initialize the game loop
	while(game_over == 1) {
		cout << "\n\n\tWelcome to the Magic Number of Death! Please select an option.\n\n";
		title_menu();
		while (!(cin >> menu_select)) {
			cout << "Invalid value.\n";
			title_menu();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
			switch (menu_select) {
			case 1: //New Game. Pick a number higher than random number and live to fight another day!
				game_over = 0;
				srand(time(0));

				while (game_over == 0) {
					death_number = rand() % 100 + 1;
					cout << "Please enter a number (1-100) to avoid death.\n";
					while (!(cin >> avoid_number)) {
						cout << "Invalid value.\n";
						cout << "Please enter a number (1-100) to avoid death.\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> avoid_number;
					}
					while (avoid_number >= 100 || avoid_number == 0) {
						cout << "Invalid value. \n";
						cout << "Please enter a number (1-100) to avoid death.\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> avoid_number;
					}
					
					if (avoid_number <= death_number) {
						if (success == 1) {
							trap_text = " trap ";
						}
						else {
							trap_text = " traps ";
						}
						cout << "\nOh no! You have died.\n";
						cout << "The magic number was " << death_number << ".\n";
						cout << "You successfully dodged " << success << trap_text << "before you met your demise.\n\n";
						success = 0;
						game_over = 1;
						cin.ignore(cin.rdbuf()->in_avail() + 1);
					}
					else {
						success = success + 1;
						cout << "Congratulations! You've avoided death!\n\n";
					}
				}
				break;
			case 2: // Loading from a previously saved game. Normally would have a means of looping through
				//detected save data, but skill is not quite there yet.
				file_menu();
				break;
			case 3: //Configuration menu elemnts.
				config_menu();
				break;

			case 4:
				game_over = 0;
				break;
			}
		}
	cout << "\nInvalid selection.\n\n";
	return 0;
}
