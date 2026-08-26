#include <iostream>
class Calcule {
    private:
    int num1, num2;
    public:
    Calcule(int n1, int n2) : num1(n1), num2(n2){}
    int sum() const {
        return num1 + num2;
    }
    void print() const {
        std::cout << num1 << " + " << num2 << ": " << sum();
    }
};
int main() {
    int inp1;
    int inp2;
    std::cout << "Enter the first num: ";
    std::cin >> inp1;
    std::cout << "Enter the second num: ";
    std::cin >> inp2;
    Calcule c(inp1, inp2);
    c.print();
    return 0;
}