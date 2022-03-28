//Coded by Collin Morrison starting at 3:05PM and ending at 5:13PM on 3/27/22, taking 2 hours and 8 minutes.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int RomanToDecimal(string roman);

string DecimalToRoman(int decimal);

int ConvertCharacterToInt(char letter);

int main() {
    bool rerun = true;
    char rerunChar = ' ';
    while (rerun) {
        string roman = " ";
        int decimal = 0;
        cout << "Please enter a number in Roman Numeral form: ";
        cin >> roman;
        decimal = RomanToDecimal(roman);
        roman = DecimalToRoman(decimal);
        cout << endl << endl << "Your number in Decimal form is: " << decimal << endl;
        cout << "You number converted back to Roman Numeral Form is: " << roman << endl << endl;
        cout << "To quit, type \"n\" and press enter. To enter another number, type any other character and press enter" << endl;
        cin >> rerunChar;
        if (rerunChar == 'n') {
            cout << "Thank you." << endl;
            rerun = false;
        }
    }
    return 0;

}

//Convert a roman numeral argument to its decimal equivalent
int RomanToDecimal(string roman) {
    int totalDecimal = 0;
    vector<int> decimals;
    //convert each character to its integer equivalent and insert it into vector
    for (int i = 0; i < roman.size(); ++i) {
        decimals.push_back(ConvertCharacterToInt(roman.at(i)));
    }
    //handle subtraction case
    for (int i = 0; i < (decimals.size() - 1); ++i) {
        if (decimals.at(i) < decimals.at(i + 1)) {
            decimals.at(i) = (decimals.at(i + 1) - decimals.at(i));
            decimals.erase(decimals.begin() + i + 1);
        }
    }
    //total the numbers
    for (int i = 0; i < decimals.size(); ++i) {
        totalDecimal += decimals.at(i);
    }
    return totalDecimal;
}


//decrement decimal until it equals 0, pushing the correct
//characters onto the end of the string being returned
string DecimalToRoman(int decimal) {
    string roman = " ";
    while (decimal >= 1000) {
        roman.push_back('M');
        decimal -= 1000;
    }
    while (decimal >= 900) {
        roman.push_back('C');
        roman.push_back('M');
        decimal -= 900;
    }
    while (decimal >= 500) {
        roman.push_back('D');
        decimal -= 500;
    }
    while (decimal >= 100) {
        roman.push_back('C');
        decimal -= 100;
    }
    while (decimal >= 90) {
        roman.push_back('X');
        roman.push_back('C');
        decimal -= 90;
    }
    while (decimal >= 50) {
        roman.push_back('L');
        decimal -= 50;
    }
    while (decimal >= 40) {
        roman.push_back('X');
        roman.push_back('L');
        decimal -= 40;
    }
    while (decimal >= 10) {
        roman.push_back('X');
        decimal -= 10;
    }
    if (decimal == 9) {
        roman.push_back('I');
        roman.push_back('X');
        decimal -= 9;
    }
    while (decimal >= 5) {
        roman.push_back('V');
        decimal -= 5;
    }
    if (decimal == 4) {
        roman.push_back('I');
        roman.push_back('V');
        decimal -= 4;
    }
    while (decimal >= 1) {
        roman.push_back('I');
        decimal -= 1;
    }
    return roman;
}

//return the integer equivalent of each character
int ConvertCharacterToInt(char letter) {
    if (letter == 'I') {
        return 1;
    }
    if (letter == 'V') {
        return 5;
    }
    if (letter == 'X') {
        return 10;
    }
    if (letter == 'L') {
        return 50;
    }
    if (letter == 'C') {
        return 100;
    }
    if (letter == 'D') {
        return 500;
    }
    if (letter == 'M') {
        return 1000;
    }
    else {
        return 0;
    }
}