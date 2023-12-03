#include <iostream>
#include <cmath>
using namespace std;
string decimalToBase(double num, int base);
double baseToDecimal(const string& num, int base);

int main() {
    double num;
    int sourceBase, targetBase;
    string inputNum, result;

    cout << "Enter a number: ";
    cin >> inputNum;

    cout << "Enter the source base (2 for binary, 8 for octal, 10 for decimal, 16 for hexadecimal): ";
    cin >> sourceBase;

    cout << "Enter the target base (2 for binary, 8 for octal, 10 for decimal, 16 for hexadecimal): ";
    cin >> targetBase;

    num = baseToDecimal(inputNum, sourceBase);
    result = decimalToBase(num, targetBase);

    cout << "Result: " << result << std::endl;

    return 0;
}
// Function to convert a decimal number to another base
  	string decimalToBase(double num, int base) {
    string result = "";
    int intPart = static_cast<int>(num);//coverts from double to int data 1type
    double fracPart = num - intPart;//: Calculate the fractional part of the decimal number by subtracting the integer part from the original number.

	//Start a loop that will continue until the integer part (intPart) becomes zero. This loop is used to convert the integer part of the decimal number into the target base.
    while (intPart > 0) {
        int remainder = intPart % base;
        result = (remainder < 10) ? char('0' + remainder) + result : char('A' + remainder - 10) + result;
        intPart /= base;
    }

    if (fracPart > 0) {
        result += ".";
        for (int i = 0; i < 5; i++) {  // Specify the number of decimal places to convert
            fracPart *= base;
            int digit = static_cast<int>(fracPart);
            result += (digit < 10) ? char('0' + digit) : char('A' + digit - 10);
            fracPart -= digit;
        }
    }

    return result;
}

// Function to convert a number from any base to decimal
double baseToDecimal(const std::string& num, int base) {
    double result = 0.0;
    int intPart = 0;
    double fracPart = 0.0;
    int decimalPosition = num.find('.');

    for (size_t i = 0; i < num.length(); i++) {
        if (i < decimalPosition) {
            intPart = intPart * base + (isdigit(num[i]) ? (num[i] - '0') : (toupper(num[i]) - 'A' + 10));
        } else if (i > decimalPosition) {
            fracPart += (isdigit(num[i]) ? (num[i] - '0') : (toupper(num[i]) - 'A' + 10)) * std::pow(1.0 / base, i - decimalPosition);
        }
    }

    result = intPart + fracPart;
    return result;
}
