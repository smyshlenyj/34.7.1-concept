#include <iostream>

template <typename T> concept ComplexConcept = requires (const T v)
{
    { v.hash() } -> std::convertible_to<long>;
    { v.toString() } -> std::same_as<std::string>;
    !std::has_virtual_destructor<T>::value;
};

void printSmth(ComplexConcept auto &t)
{
    std::cout << t.toString() << std::endl;
}

struct maybeString
{
    std::string str = "Maybe yes, maybe no";
    int number = 777;
    std::string toString() const { return str; }
    int hash() const { return number; }
};

int main()
{
    maybeString test;
    printSmth(test);

    return 0;
}
