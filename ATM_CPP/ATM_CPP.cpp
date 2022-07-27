#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

void withdraw();
void deposit();
void view();
void convert();
void inputDecider(char input);

void toPound();
void toEuro();
void toRuble();

double balance = 0.00;

int main()
{
    cout << "Welcome to my ATM machine!!!" << endl;
    string userInput;
    while(true) {
        cout << "Would you like to: (W)ithdraw, (D)eposit, (L)eave, (V)iew, or (C)onvert the money in your account?:";
        std::getline(cin, userInput);
        if (userInput.length() == 1) inputDecider(userInput.at(0));
        else cout << "Not a valid input" << endl;
        
    }
}

void inputDecider(char input)
{
	switch(tolower(input))
	{

	case 'w':
        if (balance == 0.0) {
            cout << "You do not have sufficient funds to withdraw from this account. Redirecting to main page." << endl;
            return;
        }
        withdraw();
        break;
	case 'd':
        deposit();
        break;
	case 'l':
        exit(0);
	case 'v':
        view();
        break;
	case 'c':
        convert();
        break;
	default:
        cout << "Not a valid input." << endl;
	}
}

void withdraw()
{
    while (true) {
        double withdrawAmountRequest = 0.0;

        cout << "How much money would you like to take out of your account?: ";
        cin >> withdrawAmountRequest;
        cout << endl;
        if (balance > withdrawAmountRequest && withdrawAmountRequest > 0) {
            balance -= withdrawAmountRequest;
            cout << "You have withdrawn $" + std::to_string(withdrawAmountRequest).substr(0, std::to_string(withdrawAmountRequest).length() - 4) + " dollars from your account" << endl;
            cout << "Your balance is now $" + std::to_string(balance).substr(0, std::to_string(balance).length() - 4) <<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        	return;
        }

            cout << "Error: not a valid request due to incorrect type request or lack of sufficient funds" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void deposit()
{
    while(true) {
        double depositRequest;

        cout << "How much money would you like to deposit into your account?: ";
        cin >> depositRequest;
        cout << endl;
        if (depositRequest > 0) {
            balance += depositRequest;
            cout << "Your balance is now $" + std::to_string(balance).substr(0, std::to_string(balance).length() - 4) << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
            cout << "Not a valid deposit number. Try again." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void view()
{

	cout << "You have $" + std::to_string(balance).substr(0, std::to_string(balance).length() - 4) + " in your account." << endl;
    
}

void convert()
{
    while (true) {
        string convertInput;
        cout << "From U.S. dollars you can convert into:" << endl;
        cout << "U.K. (P)ounds, European (E)uros, Russian (R)ubles:" << endl;
        cin >> convertInput;

        if (convertInput.length() == 1) {
            switch (tolower(convertInput.at(0)))
            {
            case 'p':
                toPound();
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            case 'e':
                toEuro();
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            case 'r':
                toRuble();
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            default:
                break;

            }
            
        }
    	cout << "Not a valid input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void toEuro()
{
    double euroConversion = 0.99;
	cout << "Your balance in Euros is " + std::to_string(balance * euroConversion).substr(0, std::to_string(balance).length() - 4) + " Euros." << endl;

}

void toPound()
{
    double poundConversion = 0.83;
    cout << "Your balance in Pounds is " + std::to_string(balance * poundConversion).substr(0, std::to_string(balance).length() - 4) + " Pounds." << endl;

}
void toRuble()
{
    double rubleConversion = 60.13;
    cout << "Your balance in Rubles is " + std::to_string(balance * rubleConversion).substr(0, std::to_string(balance).length() - 4) + " Rubles." << endl;

}

