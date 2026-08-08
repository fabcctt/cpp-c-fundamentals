#include <iostream>
#include <string>
class UserAuth {
private:
    std::string username;
    std::string password;

public:
    UserAuth(const std::string& u, const std::string& p) : username(u), password(p) {}
    bool verifyUser(const std::string& u) const {
        return username == u;
    }
    bool verifyPassword(const std::string& p) const {
        return password == p;
    }
};
int main() {
    std::string u, p;
    std::cout << "Welcome! Set your username: ";
    std::getline(std::cin, u);
    std::cout << "Set your password: ";
    std::getline(std::cin, p);
    UserAuth account(u, p);
    std::cout << "\n== Welcome to Log In ==\n";
    std::string inputUser, inputPass;
    std::cout << "Enter username: ";
    std::getline(std::cin, inputUser);
    if (!account.verifyUser(inputUser)) {
        std::cout << "Incorrect username.\n";
        return 1;
    }
    std::cout << "Correct username.\n";
    std::cout << "Enter password: ";
    std::getline(std::cin, inputPass);
    if (!account.verifyPassword(inputPass)) {
        std::cout << "Incorrect password.\n";
        return 1;
    }
    std::cout << "Correct password. Welcome!\n";

    return 0;
}