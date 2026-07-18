#include <iostream>

using namespace std;

const int CORRECT_PASSWORD = 3345;
const int MAX_ATTEMPTS = 3;

int getPassword()
{
    int enteredPassword;

    cout << "Enter your password: ";
    cin >> enteredPassword;

    return enteredPassword;
}

bool verifyPassword()
{
    int failedAttempts = 0;

    while (failedAttempts < MAX_ATTEMPTS)
    {
        int enteredPassword = getPassword();

        if (enteredPassword == CORRECT_PASSWORD)
        {
            cout << "\nAccess granted." << endl;
            return true;
        }

        failedAttempts++;

        cout << "Incorrect password. Attempt "
            << failedAttempts << " of "
            << MAX_ATTEMPTS << "." << endl;
    }

    cout << "\nAccess denied. Maximum number of attempts exceeded." << endl;
    return false;
}

int main()
{
    verifyPassword();
    system("pause");
    return 0;
}
