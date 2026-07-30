#include <iostream>
int main() {
    int num = 15;
    int* ptr = &num;
    *ptr = 30;
    std::cout << num;
    return 0;
}