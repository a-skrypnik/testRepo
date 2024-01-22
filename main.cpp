#include <iostream>
#include <type_traits>
#include <variant>
#include <vector>
#include <map>
#include "AorB/A.hpp"
#include "AorB/B.hpp"

template<typename ... T>
void print(const T& ... v)
{
    (std::cout << ... << v);
    std::cout << std::endl;
}

using AorB = std::variant<A, B>;

std::vector<AorB> getMyVector() 
{
    std::vector<AorB> v;
    print("Adding A");
    v.emplace_back(A());
    v.emplace_back(A());
    v.emplace_back(A());
    print("Adding B");
    v.emplace_back(B());
    print("Returning the created vector");
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
    print("hi", " ", 234, " ", "blum");
    std::map<int,std::string> m;
    m[1] = "one";
    m[2] = "two";
    for(auto & [a,b] : m)
    {
        print(a, " : ", b);
    }
    std::vector<AorB> v = getMyVector();
    print("Constructed vector v");
    draw(v);
    print("Drawing is concluded for v");
    v.clear();
    print("Program terminated...");
}