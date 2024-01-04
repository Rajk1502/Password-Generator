#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class PasswordGenerator {
public:
    void inputPasswordLength() {
        cout << "Enter the length you want for your password: ";
        int passwordLength;
        cin >> passwordLength;

        if (passwordLength >= 8 && passwordLength <= 20) {
            cout << "Generating a password of length " << passwordLength << "...\n";
            cout << generatePassword(passwordLength) << endl;
        } else {
            cout << "Invalid password length! Please choose a value between 8 and 20\n";
            inputPasswordLength();
        }
    }

private:
    string generatePassword(int passwordLength) {
        char characterSet[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                                'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                                'z', 'x', 'c', 'v', 'b', 'n', 'm',
                                'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                                'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                                'Z', 'X', 'C', 'V', 'B', 'N', 'M',
                                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                '!', '@', '#', '_', '-', '.'};

        string password;
        srand(static_cast<unsigned>(time(0)));

        for (int i = 0; i < passwordLength - 2; i++) {
            password += characterSet[rand() % 68];
        }

        // Making sure that password contains at least 1 special character and 1 digit as required by most platforms
        for (int i = password.length(); i < passwordLength - 1; i++) {
            password += characterSet[rand() % 17 + 52];
        }
        for (int i = password.length(); i < passwordLength; i++) {
            password += characterSet[rand() % 7 + 62];
        }

        return "Your password is: " + password;
    }
};

int main() {
    PasswordGenerator passwordGenerator;
    passwordGenerator.inputPasswordLength();
    return 0;
}