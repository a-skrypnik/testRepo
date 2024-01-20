#include <iostream>

int main(int number, const char** args) {
    std::cout << "hello " << std::endl;

    for(int i = 0; i < number; ++i)
    {
        std::cout << args[i] << std::endl;
    }

    std::cout << "Program terminated..." << std::endl;
}