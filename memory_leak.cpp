#include <iostream>

class MemoryLeakExample {
public:
    int* data;

    MemoryLeakExample() {
        data = new int(42); // Memory allocated but never freed
        std::cout << "Memory allocated: " << *data << std::endl;
    }

    ~MemoryLeakExample() {
        // Oops! No delete here -> Memory Leak!
        std::cout << "Destructor called, but memory not freed!" << std::endl;
    }
};

void memoryLeakFunction() {
    int* ptr = new int(100); // Memory allocated but not freed
    std::cout << "Leaking memory, value: " << *ptr << std::endl;
    // Memory leak occurs because we never delete ptr
}

void loopMemoryLeak() {
    for (int i = 0; i < 5; ++i) {
        int* arr = new int[100]; // Allocating an array in a loop
        std::cout << "Iteration " << i << ": Memory allocated but never freed" << std::endl;
        // Memory is leaked in each iteration
    }
}

int main() {
    std::cout << "----- Memory Leak in Function -----" << std::endl;
    memoryLeakFunction(); // Leaks memory

    std::cout << "\n----- Memory Leak in Class -----" << std::endl;
    MemoryLeakExample* obj = new MemoryLeakExample();
    delete obj; // Destructor does not free memory

    std::cout << "\n----- Loop-based Memory Leak -----" << std::endl;
    loopMemoryLeak(); // Leaks memory in a loop

    return 0;
}
