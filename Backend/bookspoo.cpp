#include <iostream>
#include <string>
class Book {
private:
    std::string title;
    int pages;
public:
    Book(std::string t, int p) : title(t), pages(p){}
    bool isLong() const {
        return pages > 300;
    }
};
int main() {
    Book b1("random history", 218);
    Book b2("random history 2", 400);
    std::cout << "Is b1 long? " << b1.isLong() << std::endl;
    std::cout << "Is b2 long? " << b2.isLong() << std::endl;
    return 0;
}
