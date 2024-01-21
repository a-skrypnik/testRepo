#include <iostream>

class A
{
    static inline int NUMBER_OF_OBJECTS = 0;
    int id;
public:
    A() : id(NUMBER_OF_OBJECTS++) { 
        std::cout << "Created A [" << id << "]" << std::endl;
    }
    A(A& a) : id(NUMBER_OF_OBJECTS++) 
    {
        std::cout << "Copy Constructed A [" << id << "] from [" << a.id << "]" << std::endl;
    }
    A(const A& a) : id(NUMBER_OF_OBJECTS++) 
    {
        std::cout << "Copy Constructed const A [" << id << "] from [" << a.id << "]" << std::endl;
    }
    A(A&& a) : id(NUMBER_OF_OBJECTS++) 
    {
        std::cout << "Move Constructed A [" << id << "] from [" << a.id << "]" << std::endl;
    }
    A(const A&& a) : id(NUMBER_OF_OBJECTS++) 
    {
        std::cout << "Move Constructed const A [" << id << "] from [" << a.id << "]" << std::endl;
    }
    void draw() {
        std::cout << "Drawing A [" << id << "]" << std::endl;
    }
    ~A() {
        std::cout << "Deleted A [" << id << "]" << std::endl;
    }
};
