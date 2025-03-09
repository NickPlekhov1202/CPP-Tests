#include <iostream>

class DoubleDeleteExample {
public:
    int* data;

    DoubleDeleteExample() {
        data = new int(42);
        std::cout << "Memory allocated: " << *data << std::endl;
    }

    ~DoubleDeleteExample() {
        delete data; // First delete
        std::cout << "Memory freed in destructor" << std::endl;

        delete data; // Second delete (Undefined Behavior)
        std::cout << "Memory freed again (double delete!)" << std::endl;
    }
};

void doubleDeleteFunction() {
    int* ptr = new int(100);
    std::cout << "Value before delete: " << *ptr << std::endl;

    delete ptr; // First delete
    std::cout << "Memory freed once" << std::endl;

    delete ptr; // Second delete (Undefined Behavior)
    std::cout << "Memory freed twice (double delete!)" << std::endl;
}

int main() {
    std::cout << "----- Double delete using a function -----" << std::endl;
    doubleDeleteFunction();

    std::cout << "\n----- Double delete using a class -----" << std::endl;
    DoubleDeleteExample* obj = new DoubleDeleteExample();
    delete obj; // Destructor will delete memory twice

    return 0;
}
