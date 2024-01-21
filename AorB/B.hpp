#include <iostream>

class B
{
    static inline int NUMBER_OF_OBJECTS = 0;
    int id;
public:
    B() : id(NUMBER_OF_OBJECTS++) { 
        std::cout << "Created B [" << id << "]" << std::endl;
    }
    B(B& b) : id(NUMBER_OF_OBJECTS++)
    {
        std::cout << "Copy Constructed B [" << id << "] from [" << b.id << "]" << std::endl;
    }
    B(const B& b) : id(NUMBER_OF_OBJECTS++)
    {
        std::cout << "Copy Constructed const B [" << id << "] from [" << b.id << "]" << std::endl;
    }
    B(B&& b) : id(NUMBER_OF_OBJECTS++)
    {
        std::cout << "Move Constructed B [" << id << "] from [" << b.id << "]" << std::endl;
    }
    B(const B&& b) : id(NUMBER_OF_OBJECTS++)
    {
        std::cout << "Move Constructed const B [" << id << "] from [" << b.id << "]" << std::endl;
    }
    void draw() {
        std::cout << "Drawing B [" << id << "]" << std::endl;
    }
    ~B() {
        std::cout << "Deleted B [" << id << "]" << std::endl;
    }
};
