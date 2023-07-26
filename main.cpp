#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// User structure to store user details
struct User {
    string name;
    string mobileNumber;
    string email;
    string accountNumber;
    string pin;
    double wallet;
    bool isSuspended;
};

// Function to generate a random 10-digit account number
string generateAccountNumber() {
    string accountNumber;
    srand(time(0));

    for (int i = 0; i < 10; ++i) {
        int digit = rand() % 10;
        accountNumber += to_string(digit);
    }

    return accountNumber;
}

// Function to create a new user account
User createUser() {
    User newUser;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newUser.name);
    cout << "Enter mobile number: ";
    cin >> newUser.mobileNumber;
    cout << "Enter email: ";
    cin >> newUser.email;
    newUser.accountNumber = generateAccountNumber();
    cout << "Generated account number: " << newUser.accountNumber << endl;
    cout << "Create a 4-digit PIN: ";
    cin >> newUser.pin;
    newUser.wallet = 0.0;
    newUser.isSuspended = false;

    return newUser;
}

// Function to display user details
void displayUserDetails(const User& user) {
    cout << "Name: " << user.name << endl;
    cout << "Mobile Number: " << user.mobileNumber << endl;
    cout << "Email: " << user.email << endl;
    cout << "Account Number: " << user.accountNumber << endl;
    cout << "Wallet Balance: " << user.wallet << endl;
    cout << "Account Status: " << (user.isSuspended ? "Suspended" : "Active") << endl;
}

// Function to find a user by account number
User* findUserByAccountNumber(vector<User>& users, const string& accountNumber) {
    for (auto& user : users) {
        if (user.accountNumber == accountNumber) {
            return &user;
        }
    }
    return nullptr;
}

// Function to update user details
void updateUserDetails(User& user) {
    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, user.name);
    cout << "Enter new mobile number: ";
    cin >> user.mobileNumber;
    cout << "Enter new email: ";
    cin >> user.email;
}

// Function to deposit funds to user wallet
void fundUserWallet(User& user) {
    double amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;
    user.wallet += amount;
    cout << "Funds deposited successfully!" << endl;
}

// Function to deduct funds from user wallet
void deductFromUserWallet(User& user, double amount) {
    user.wallet -= amount;
}



// Function to send money to another user's account
void sendMoney(User& sender, User& receiver) {
    double amount;
    cout << "Enter the amount to send: ";
    cin >> amount;

    if (amount > sender.wallet) {
        cout << "Insufficient funds in the wallet." << endl;
    } else {
        sender.wallet -= amount;
        receiver.wallet += amount;
        cout << "Money sent successfully!" << endl;
    }
}

// Function to display transaction history
void displayTransactionHistory(const vector<string>& transactions) {
    if (transactions.empty()) {
        cout << "No transaction history available." << endl;
    } else {
        cout << "Transaction History:" << endl;
        for (const auto& transaction : transactions) {
            cout << transaction << endl;
        }
    }
}

// Function to save user data to a file
void saveUserData(const vector<User>& users) {
    ofstream file("users.txt");

    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.name << "\n";
            file << user.mobileNumber << "\n";
            file << user.email << "\n";
            file << user.accountNumber << "\n";
            file << user.pin << "\n";
            file << user.wallet << "\n";
            file << user.isSuspended << "\n";
        }

        file.close();
    } else {
        cout << "Error saving user data to file." << endl;
    }
}

// Function to load user data from a file
vector<User> loadUserData() {
    vector<User> users;
    ifstream file("users.txt");

    if (file.is_open() && file.peek() != ifstream::traits_type::eof()) {
        while (!file.eof()) {
            User user;
            getline(file, user.name);
            getline(file, user.mobileNumber);
            getline(file, user.email);
            getline(file, user.accountNumber);
            getline(file, user.pin);
            file >> user.wallet;
            file >> user.isSuspended;
            file.ignore(); // Ignore newline character

            if (!user.name.empty()) {
                users.push_back(user);
            }
        }

        file.close();
    }

    return users;
}

// Function to display login options
void displayLoginOptions() {
	
    cout <<"\n>>BANK MANAGEMENT SYSTEM BUILT BY KINGSCONCEPT<<";
    cout << "Login as:\n";
    cout << "1. Admin\n";
    cout << "2. User\n";
    cout << "Enter your choice: ";
}

int main() {
    string adminUsername = "admin";
    string adminPassword = "1234";
    vector<User> users = loadUserData();
    vector<string> transactions;

    string accountNumber;
    string pin;

    cout << "==== Bank Management System ====" << endl;

    while (true) {
        displayLoginOptions();

        int loginChoice;
        cin >> loginChoice;

        if (loginChoice == 1) {
            // Admin login
            cout << "Please login as an admin." << endl;
            string username, password;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            if (username == adminUsername && password == adminPassword) {
                cout << "Admin login successful." << endl;

                while (true) {
                    int choice;
                    cout << "\nAdmin Menu:\n";
                    cout << "1. Create User Account\n";
                    cout << "2. Update User Details\n";
                    cout << "3. Fund User Wallet\n";
                    cout << "4. Suspend User Account\n";
                    cout << "5. Deduct Funds from User Account\n";
                    cout << "6. Upgrade User Account\n";
                    cout << "7. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            User newUser = createUser();
                            users.push_back(newUser);
                            saveUserData(users);
                            cout << "User account created successfully!" << endl;
                            break;
                        }
                        case 2: {
                            cout << "Enter the account number of the user to update: ";
                            cin >> accountNumber;
                            User* user = findUserByAccountNumber(users, accountNumber);
                            if (user != nullptr) {
                                updateUserDetails(*user);
                                saveUserData(users);
                                cout << "User details updated successfully!" << endl;
                            } else {
                                cout << "User not found!" << endl;
                            }
                            break;
                        }
                        case 3: {
                            cout << "Enter the account number of the user to fund: ";
                            cin >> accountNumber;
                            User* user = findUserByAccountNumber(users, accountNumber);
                            if (user != nullptr) {
                                fundUserWallet(*user);
                                saveUserData(users);
                            } else {
                                cout << "User not found!" << endl;
                            }
                            break;
                        }
                        case 4: {
                            cout << "Enter the account number of the user to suspend: ";
                            cin >> accountNumber;
                            User* user = findUserByAccountNumber(users, accountNumber);
                            if (user != nullptr) {
                                suspendUserAccount(*user);
                                saveUserData(users);
                            } else {
                                cout << "User not found!" << endl;
                            }
                            break;
                        }
                        case 5: {
                            cout << "Enter the account number of the user to deduct funds from: ";
                            cin >> accountNumber;
                            User* user = findUserByAccountNumber(users, accountNumber);
                            if (user != nullptr) {
                                double amount;
                                cout << "Enter the amount to deduct: ";
                                cin >> amount;
                                deductFromUserWallet(*user, amount);
                                saveUserData(users);
                                cout << "Funds deducted successfully!" << endl;
                            } else {
                                cout << "User not found!" << endl;
                            }
                            break;
                        }
                        case 6: {
                            cout << "Enter the account number of the user to upgrade: ";
                            cin >> accountNumber;
                            User* user = findUserByAccountNumber(users, accountNumber);
                            if (user != nullptr) {
                                double limit;
                                cout << "Enter the new transaction limit: ";
                                cin >> limit;
                                upgradeUserAccount(*user, limit);
                                saveUserData(users);
                            } else {
                                cout << "User not found!" << endl;
                            }
                            break;
                        }
                        case 7: {
                            cout << "Admin logout successful." << endl;
                            break;
                        }
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }

                    if (choice == 7) {
                        break;
                    }
                }
            } else {
                cout << "Invalid admin credentials. Please try again." << endl;
            }
        } else if (loginChoice == 2) {
            // User login
            cout << "Please login as a user." << endl;
            cout << "Enter your account number: ";
            cin >> accountNumber;
            cout << "Enter your 4-digit PIN: ";
            cin >> pin;

            User* user = findUserByAccountNumber(users, accountNumber);
            if (user != nullptr && user->pin == pin) {
                cout << "User login successful." << endl;

                while (true) {
                    int choice;
                    cout << "\nUser Menu:\n";
                    cout << "1. Display User Details\n";
                    cout << "2. Fund User Wallet\n";
                    cout << "3. Withdraw Funds from User Wallet\n";
                    cout << "4. Send Money to Another Account\n";
                    cout << "5. Display Transaction History\n";
                    cout << "6. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

            

                    if (choice == 6) {
                        break;
                    }
                }
            } else {
                cout << "Invalid user credentials. Please try again." << endl;
            }
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
