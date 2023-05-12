#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);
string reverseString(const string& s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here

void flipString(string &s) {
    if (s.size() == 0) { // keep going until size of s becomes 0
        return;
    }

    else {
        char frontLetter = s.front(); //get first letter of string
        s = s.substr(1); // s becomes substring of second letter to end of string
        flipString(s); // recursive call
        s += frontLetter; // concatenate s and all the first letters
    }
}

string reverseString(const string& s) {
	//base case
    if (s.empty()) {
		return "";
	}
	
	//suppose the string is abcd
	//want to reverse the remaining string and add “a” at the end of it
	//reverse(bcd) + “a”
	//dcb + a
	//dcba
	else {
		return reverseString(s.substr(1)) + s.at(0);
	}
}
