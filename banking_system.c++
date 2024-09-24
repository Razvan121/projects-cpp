//banking system

#include <iostream>
#include <vector>
#include <string>
#define pb push_back
using namespace std;

static int MIN_Balance = 500;
long long int MAX_BalanceTransfer = 100000;

class Bank{
private:
    string accountHolderName;
    int pin;
    int accountNumber;
    unsigned int accountBalance;

public:
    Bank(string name, int pin, int accNumber) {
        accountHolderName = name;
        this->pin = pin;
        accountNumber = accNumber;
        accountBalance = 0;
       
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Balance: $" << accountBalance << endl;
        if(accountBalance<MIN_Balance){
            cout<<"!!! YOU HAVE TO DEPOSIT: "<<MIN_Balance-accountBalance<<endl;
            cout<<"Your account will be dezactivated in 1 hour "<<endl;
        }
    }

    bool verifyPin(int enteredPin) {
        return pin == enteredPin;
    }    

    void deposit(unsigned int amount) {
        accountBalance += amount;
        cout << "Amount deposited successfully! New balance: $" << accountBalance << endl;
    }

    bool withdraw(unsigned int amount) {
        if (amount > accountBalance) {
            cout << "Insufficient balance!" << endl;
            return false;
        } else if(amount>MAX_BalanceTransfer)
                {
                    cout<<"The maxim amount you can withdraw/transfer is: "<<MAX_BalanceTransfer<<endl;
                }else{
            accountBalance -= amount;
            cout << "Amount withdrawn successfully! New balance: $" << accountBalance << endl;
            return true;
        }
    }

    void deleteAccount() {
        accountHolderName = "";
        pin = 0;
        accountBalance = 0;
        cout << "Account deleted successfully!" << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    int getPin() {
        return pin;
    }
    
   
};

int findAccount(vector<Bank>& accounts, int accNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNumber) {
            return i;
        }
    }
    return -1;
}


int main() {
    vector<Bank> accounts;
    int choice;
    int accNumber;
    int pin;
    string name;
    unsigned int amount;
    int index;

    do {
        for(int i=1;i<=3;i++)
        cout<<endl;
        cout << " \n\tCHEBank" << endl;
        cout << "\n\t1. Create a New Account" << endl;
        cout << "\n\t2. Display Account Info" << endl;
        cout << "\n\t3. Deposit Funds" << endl;
        cout << "\n\t4. Withdraw Funds" << endl;
        cout << "\n\t5. Delete Account" << endl;
        cout<< "\n\t6. Transfer Money" << endl;
        cout << "\n\t7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter PIN (4 digits): ";
                cin >> pin;
                accNumber = accounts.size() + 1;
                accounts.pb(Bank(name, pin, accNumber));
                cout << "Account created successfully! Account Number: " << accNumber << endl;
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                index = findAccount(accounts, accNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for Verification: ";
                    cin >> enteredPin;
                    if (accounts[index].verifyPin(enteredPin)) {
                        accounts[index].displayAccountInfo();
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                index = findAccount(accounts, accNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for Verification: ";
                    cin >> enteredPin;
                    if (accounts[index].verifyPin(enteredPin)) {
                        cout << "Enter Deposit Amount: $";
                        cin >> amount;
                        accounts[index].deposit(amount);
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                index = findAccount(accounts, accNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for Verification: ";
                    cin >> enteredPin;
                    if (accounts[index].verifyPin(enteredPin)) {
                        cout << "Enter Withdrawal Amount: $";
                        cin >> amount;
                        if (accounts[index].withdraw(amount)) {
                        }
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 5:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                index = findAccount(accounts, accNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for Verification: ";
                    cin >> enteredPin;
                    if (accounts[index].verifyPin(enteredPin)) {
                        accounts[index].deleteAccount();
                        accounts.erase(accounts.begin() + index);
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 6:
             cout << "Enter Account Number: ";
                cin >> accNumber;
                index = findAccount(accounts, accNumber);
                if (index != -1) 
                {
                    int enteredPin;
                    cout << "Enter PIN for Verification: ";
                    cin >> enteredPin;
                    if (accounts[index].verifyPin(enteredPin))
                     {
                            cout<<"Transfer Money to: "<<endl;
                            cout<<"     Different Bank Account\n(Note press 1)"<<endl;
                            cout<<"     CHEBank Account\n(Note press 2) "<<endl;
                            int who;
                            cout<<"Enter: (1/2)";
                            cin>>who;
                            if(who==1)
                            {
                            cout<<"\n\t !!!!! Include 2$ taxes !!!!!";
                            int amount=0;
                            cout<<"Enter amount of money: "<<endl;
                            cin>>amount;
                            accounts[index].withdraw(amount+2);

                            }else 
                            {
                            int amount=0;
                            cout<<"Enter amount of money: "<<endl;
                            cin>>amount;
                            accounts[index].withdraw(amount);
                            }
                     }else 
                     {
                        cout << "Incorrect PIN!" << endl;
                    }
                }else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 7:
                cout << "Thank you for using CHEBank. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
