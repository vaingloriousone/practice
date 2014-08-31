//Sign Text
// Output should be something like
// ======
// =text=
// ======

#include <iostream>
#include <string>

using namespace std;



int main() {
	
	string sign_text;

	cout << "What would you like your sign to say?\n";
	getline(cin,sign_text);
  
	unsigned int length = sign_text.size() + 2;
	string lines(length, '=');
	
	cout << lines;
	cout << "\n=" << sign_text << "=\n";
  	cout << lines;
  
	cin.ignore(cin.rdbuf()->in_avail() + 1);
}


