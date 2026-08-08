#include <iostream>
class isEven {
    private:
    int x;
    int y;
    public:
    isEven(int a, int b) : x(a), y(b){}
    bool Even(int num) {
        return num % 2 == 0;
    }
    void print() {
        std::cout << "Is " << x << " Even? " << std::boolalpha << Even(x) << std::endl;
        std::cout << "Is " << y << " Even? " << std::boolalpha << Even(y) << std::endl;
    }
};
int main() {
    isEven e(7, 10);
    e.print();
    return 0;
}