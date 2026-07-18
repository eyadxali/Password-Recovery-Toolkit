#include <cctype>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Password
{
private:
    string passwordUser;
    int counterL = 0;
    int counterD = 0;
    int counterS = 0;

public:

    void setPassword()
    {
        cout << "Enter your password: ";
        cin >> passwordUser;
    }

    int checkLength()
    {
        return passwordUser.length();
    }

    void checkStrength()
    {
        for (char c : passwordUser)
        {
            if (isalpha(c))
                counterL++;

            else if (isdigit(c))
                counterD++;

            else if (ispunct(c))
                counterS++;
        }

        cout << "Letters: " << counterL << endl;
        cout << "Digits: " << counterD << endl;
        cout << "Symbols: " << counterS << endl;
    }


    string generatePassword()
    {
        string chars =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789"
            "!@#$%^&*";

        string newPassword = "";

        srand(time(0));

        for (int i = 0; i < 14; i++)
        {
            newPassword += chars[rand() % chars.length()];
        }

        return newPassword;
    }


    void changePassword(int size)
    {
        if (size >= 9 && size <= 12 && counterD > 9 && counterS == 0)
        {
            cout << "Password is weak, generating a new password..." << endl;
            passwordUser = generatePassword();
        }
        else if (size > 12 && counterD > counterL && counterS == 0)
        {
            cout << "Password is too long and weak, generating a stronger password..." << endl;
            passwordUser = generatePassword();
        }
        else if (size == counterD || size == counterL)
        {
            cout << "Password is weak, generating a stronger password..." << endl;
            passwordUser = generatePassword();
        }
        else if (size < 8)
        {
            cout << "Password is weak, generating a stronger password..." << endl;
            passwordUser = generatePassword();
        }
        else
        {
            cout << "The password is good" << endl;
            return;
        }

        cout << "The new password is: " << passwordUser << endl;
    }

};


int main()
{
    Password edit;

    edit.setPassword();

    int size2 = edit.checkLength();

    edit.checkStrength();

    edit.changePassword(size2);

    system("pause");
    return 0;
}
