#include <iostream>
#include <string>
class Person {
    private:
    std::string name;
    int age;
    public:
    Person(std::string n, int a) : name(n), age(a){}
    void print() const {
        std::cout << "Name: " << name << "\nAge: " << age << std::endl;
    }
};
int main(void)
{
    std::string inpName;
    int inpAge;
    std::cout << "Name: ";
    std::getline(std::cin, inpName);
    std::cout << "Age: ";
    if (!(std::cin >> inpAge)) {
        std::cout << "Do a correct entry";
        return 1;
    }
    Person p(inpName, inpAge);
    p.print();
    return 0;
}