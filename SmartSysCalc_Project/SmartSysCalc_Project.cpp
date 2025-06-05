#include <iostream>
#include <string>
using namespace std;

// Base class
class Converter {
public:
    string decimalToBinary(int decimal) {
        if (decimal == 0) return "0";
        string binary = "";
        while (decimal > 0) {
            binary = char('0' + decimal % 2) + binary;
            decimal /= 2;
        }
        return binary;
    }

    int binaryToDecimal(const string& binary) {
        int decimal = 0;
        for (char bit : binary) {
            decimal = decimal * 2 + (bit - '0');
        }
        return decimal;
    }

    bool isValidBinary(const string& bin) {
        for (char c : bin) {
            if (c != '0' && c != '1') return false;
        }
        return true;
    }

    bool isValidDecimal(const string& dec) {
        for (char c : dec) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    }

    bool isValidOctal(const string& oct) {
        for (char c : oct) {
            if (c < '0' || c > '7') return false;
        }
        return true;
    }

    bool isValidHex(const string& hex) {
        for (char c : hex) {
            if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
                return false;
            }
        }
        return true;
    }
};

class HexConverter : public Converter {
public:
    int hexToDecimal(const string& hex) {
        int decimal = 0;
        for (char digit : hex) {
            decimal *= 16;
            if (digit >= '0' && digit <= '9') decimal += digit - '0';
            else if (digit >= 'A' && digit <= 'F') decimal += digit - 'A' + 10;
            else if (digit >= 'a' && digit <= 'f') decimal += digit - 'a' + 10;
        }
        return decimal;
    }

    void convert() {
        string hex;
        cout << "Enter hexadecimal number: ";
        cin >> hex;
        if (!isValidHex(hex)) {
            cout << "Invalid hexadecimal number!\n";
            return;
        }
        int decimal = hexToDecimal(hex);
        cout << "Binary: " << decimalToBinary(decimal) << endl;
    }

    void operate() {
        string a, b;
        char op;
        cout << "Enter first hex number: ";
        cin >> a;
        cout << "Enter operator (+ - * /): ";
        cin >> op;
        cout << "Enter second hex number: ";
        cin >> b;
        if (!isValidHex(a) || !isValidHex(b)) {
            cout << "Invalid hex input!\n";
            return;
        }
        int x = hexToDecimal(a);
        int y = hexToDecimal(b);
        int result = 0;
        switch (op) {
        case '+': result = x + y; break;
        case '-': result = x - y; break;
        case '*': result = x * y; break;
        case '/': if (y == 0) { cout << "Divide by zero!\n"; return; } result = x / y; break;
        default: cout << "Invalid operator!\n"; return;
        }
        cout << "Result in Hex: " << std::hex << result << std::dec << endl;
    }
};

class OctalConverter : public Converter {
public:
    int octalToDecimal(const string& octal) {
        int decimal = 0;
        for (char digit : octal) {
            decimal = decimal * 8 + (digit - '0');
        }
        return decimal;
    }

    void convert() {
        string octal;
        cout << "Enter octal number: ";
        cin >> octal;
        if (!isValidOctal(octal)) {
            cout << "Invalid octal number!\n";
            return;
        }
        int decimal = octalToDecimal(octal);
        cout << "Binary: " << decimalToBinary(decimal) << endl;
    }

    void operate() {
        string a, b;
        char op;
        cout << "Enter first octal number: ";
        cin >> a;
        cout << "Enter operator (+ - * /): ";
        cin >> op;
        cout << "Enter second octal number: ";
        cin >> b;
        if (!isValidOctal(a) || !isValidOctal(b)) {
            cout << "Invalid octal input!\n";
            return;
        }
        int x = octalToDecimal(a);
        int y = octalToDecimal(b);
        int result = 0;
        switch (op) {
        case '+': result = x + y; break;
        case '-': result = x - y; break;
        case '*': result = x * y; break;
        case '/': if (y == 0) { cout << "Divide by zero!\n"; return; } result = x / y; break;
        default: cout << "Invalid operator!\n"; return;
        }
        cout << "Result in Octal: " << std::oct << result << std::dec << endl;
    }
};

class DecimalConverter : public Converter {
public:
    void convert() {
        string input;
        cout << "Enter decimal number: ";
        cin >> input;
        if (!isValidDecimal(input)) {
            cout << "Invalid decimal number!\n";
            return;
        }
        int decimal = stoi(input);
        cout << "Binary: " << decimalToBinary(decimal) << endl;
    }

    void operate() {
        string a, b;
        char op;
        cout << "Enter first decimal number: ";
        cin >> a;
        cout << "Enter operator (+ - * /): ";
        cin >> op;
        cout << "Enter second decimal number: ";
        cin >> b;
        if (!isValidDecimal(a) || !isValidDecimal(b)) {
            cout << "Invalid decimal input!\n";
            return;
        }
        int x = stoi(a), y = stoi(b);
        int result = 0;
        switch (op) {
        case '+': result = x + y; break;
        case '-': result = x - y; break;
        case '*': result = x * y; break;
        case '/': if (y == 0) { cout << "Divide by zero!\n"; return; } result = x / y; break;
        default: cout << "Invalid operator!\n"; return;
        }
        cout << "Result: " << result << endl;
    }
};

class BinaryConverter : public Converter {
public:
    void convertToDecimal() {
        string binary;
        cout << "Enter binary number: ";
        cin >> binary;
        if (!isValidBinary(binary)) {
            cout << "Invalid binary number!\n";
            return;
        }
        cout << "Decimal: " << binaryToDecimal(binary) << endl;
    }

    void onesComplement() {
        string binary;
        cout << "Enter binary number: ";
        cin >> binary;
        if (!isValidBinary(binary)) {
            cout << "Invalid binary number!\n";
            return;
        }
        for (char& bit : binary) bit = (bit == '0') ? '1' : '0';
        cout << "1's Complement: " << binary << endl;
    }

    void twosComplement() {
        string binary;
        cout << "Enter binary number: ";
        cin >> binary;
        if (!isValidBinary(binary)) {
            cout << "Invalid binary number!\n";
            return;
        }
        for (char& bit : binary) bit = (bit == '0') ? '1' : '0';
        bool carry = true;
        for (int i = binary.length() - 1; i >= 0 && carry; --i) {
            if (binary[i] == '1') binary[i] = '0';
            else { binary[i] = '1'; carry = false; }
        }
        if (carry) binary = '1' + binary;
        cout << "2's Complement: " << binary << endl;
    }


    void operate() {
        string a, b;
        char op;
        cout << "Enter first binary number: ";
        cin >> a;
        cout << "Enter operator (+ - * /): ";
        cin >> op;
        cout << "Enter second binary number: ";
        cin >> b;
        if (!isValidBinary(a) || !isValidBinary(b)) {
            cout << "Invalid binary input!\n";
            return;
        }
        int x = binaryToDecimal(a);
        int y = binaryToDecimal(b);
        int result = 0;
        switch (op) {
        case '+': result = x + y; break;
        case '-': result = x - y; break;
        case '*': result = x * y; break;
        case '/': if (y == 0) { cout << "Divide by zero!\n"; return; } result = x / y; break;
        default: cout << "Invalid operator!\n"; return;
        }
        cout << "Result in Binary: " << decimalToBinary(result) << endl;
    }
};

int main() {
    int mainChoice;
    HexConverter hexConv;
    OctalConverter octConv;
    DecimalConverter decConv;
    BinaryConverter binConv;

    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Conversions Menu\n";
        cout << "2. Operations Menu\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            int choice;
            do {
                cout << "\n--- Conversions Menu ---\n";
                cout << "1. Hexadecimal to Binary\n";
                cout << "2. Octal to Binary\n";
                cout << "3. Decimal to Binary\n";
                cout << "4. Binary to Decimal\n";
                cout << "5. 1's Complement of Binary\n";
                cout << "6. 2's Complement of Binary\n";
                cout << "0. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice) {
                case 1: hexConv.convert(); break;
                case 2: octConv.convert(); break;
                case 3: decConv.convert(); break;
                case 4: binConv.convertToDecimal(); break;
                case 5: binConv.onesComplement(); break;
                case 6: binConv.twosComplement(); break;
                case 0: break;
                default: cout << "Invalid choice. Try again.\n";
                }
            } while (choice != 0);
        }
        else if (mainChoice == 2) {
            int choice;
            do {
                cout << "\n--- Operations Menu ---\n";
                cout << "1. Binary Operations\n";
                cout << "2. Decimal Operations\n";
                cout << "3. Octal Operations\n";
                cout << "4. Hexadecimal Operations\n";
                cout << "0. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice) {
                case 1: binConv.operate(); break;
                case 2: decConv.operate(); break;
                case 3: octConv.operate(); break;
                case 4: hexConv.operate(); break;
                case 0: break;
                default: cout << "Invalid choice. Try again.\n";
                }
            } while (choice != 0);
        }
        else if (mainChoice != 0) {
            cout << "Invalid choice. Try again.\n";
        }

    } while (mainChoice != 0);

    cout << "Exiting...\n";
    return 0;
}
