#include <iostream>
class square {
    private:
    double side;
    public:
    square(double s) {
        side = s;
    }
    double area() {
        return side * side;
    }
};
int main() {
    square s(5.1);
    std::cout << s.area() << std::endl;
    return 0;
}