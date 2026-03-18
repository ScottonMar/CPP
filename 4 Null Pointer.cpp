#include <iostream>

int main() {
    int* safePtr = nullptr;

    if (safePtr != nullptr) {
        *safePtr = 99;
    } else {
        std::cout << "Safety Halt: Pointer is null. System crash prevented."
                  << std::endl;
    }

    return 0;
}
