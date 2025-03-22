#include <iostream>
#include <string>
using namespace std;
int maxAccounts = 100;

struct BankAccount {
    int accountNumber;
    float balance;
    string firstName;
    string lastName;
};
BankAccount accounts[100];
int numberOfAccounts = 0;

void createAccount() {
    if (numberOfAccounts < maxAccounts) {
    	cout<<"Enter your First Name: ";
    	cin>>accounts[numberOfAccounts].firstName;
    	cout<<"Enter your Last Name: ";
    	cin>>accounts[numberOfAccounts].lastName;
        cout << "Enter account number: ";
        cin >> accounts[numberOfAccounts].accountNumber;
        cout << "Enter initial balance: ";
        cin >> accounts[numberOfAccounts].balance;
        numberOfAccounts++;
        cout << "Account created successfully." << endl;
    } else {
        cout << "Cannot create more accounts. Maximum limit reached." << endl;
    }
}
void deposit() {
    int accountNum;
    float amount;
    cout << "Enter account number: ";
    cin >> accountNum;
    for (int i = 0; i < numberOfAccounts; i++) {
        if (accounts[i].accountNumber == accountNum) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            accounts[i].balance += amount;
            cout << "Deposit successful. New balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

void withdraw() {
    int accountNum;
    float amount;
    cout << "Enter account number: ";
    cin >> accountNum;
    for (int i = 0; i < numberOfAccounts; i++) {
        if (accounts[i].accountNumber == accountNum) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                cout << "Withdrawal successful. New balance: " << accounts[i].balance << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
            return;
        }
    }
    cout << "Account not found." << endl;
}

void checkBalance() {
    int accountNum;
    cout << "Enter account number: ";
    cin >> accountNum;
    for (int i = 0; i < numberOfAccounts; i++) {
        if (accounts[i].accountNumber == accountNum) {
            cout << "Account balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

int main() {
    int choice;
    do {
        cout << "\nBanking Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}