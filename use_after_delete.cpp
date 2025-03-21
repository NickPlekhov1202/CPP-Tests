#include <iostream>

class Example {
public:
    int* data;

    Example() {
        std::cout << "test" << std::endl;
    }

    void useAfterDelete() {
        std::cout << "Accessing deleted memory: " << *data << std::endl; // Undefined behavior
    }
};

void danglingPointerDemo() {
    int* ptr = new int(100);
    std::cout << "Value before delete: " << *ptr << std::endl;

    delete ptr;  // Free memory

    std::cout << "Accessing deleted pointer: " << *ptr << std::endl; // Use-after-delete
}

void accessAfterScope() {
    int* danglingPtr;

    {
        std::cout << "test" << std::endl;
    }

    std::cout << "After scope, accessing deleted memory: " << *danglingPtr << std::endl; // Undefined Behavior
}

int main() {
    std::cout << "----- Use-after-delete in a class -----" << std::endl;
    Example* obj = new Example();
    delete obj;
    obj->useAfterDelete(); // Use-after-delete

    std::cout << "\n----- Dangling pointer -----" << std::endl;
    danglingPointerDemo();

    std::cout << "\n----- Double delete -----" << std::endl;
    doubleDeleteDemo();

    std::cout << "\n----- Access after scope -----" << std::endl;
    accessAfterScope();

    return 0;
}
