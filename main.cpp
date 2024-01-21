#include <iostream>
#include <type_traits>
#include <variant>
#include <vector>
#include "AorB/A.hpp"
#include "AorB/B.hpp"

using AorB = std::variant<A, B>;

std::vector<AorB> getMyVector() 
{
    std::vector<AorB> v;
    std::cout << "Adding A" << std::endl;
    v.emplace_back(A());
    v.emplace_back(A());
    v.emplace_back(A());
    std::cout << "Adding B" << std::endl;
    v.emplace_back(B());
    std::cout << "Returning the created vector" << std::endl;
    return v;
}

void draw(std::vector<AorB>& vector)
{
    for(auto& v : vector)
    {
        std::visit([](auto& obj){obj.draw();}, v);
    }
}

int main(int number, const char **args)
{
    std::vector<AorB> v = getMyVector();
    std::cout << "Constructed vector v" << std::endl;
    draw(v);
    std::cout << "Drawing is concluded for v" << std::endl;
    v.clear();
    std::cout << "Program terminated..." << std::endl;
}