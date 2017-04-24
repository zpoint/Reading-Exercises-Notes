// http://stackoverflow.com/questions/33640144/sum-function-with-return-type-large-enough-to-hold-result
#include <iostream>
#include <limits>

template<typename T>
struct promote;

template<> // and so on for all types that you want to promote
struct promote<unsigned int> // type to be promoted from
{
    using type = unsigned long int; // type to be promoted to
};

// helper a la C++14
template<typename T>
using promote_t = typename promote<T>::type;

template <typename It> 
auto my_sum(It first, It second) -> promote_t<It>
{
    return static_cast<promote_t<It>>(first) + second; // promotion
}

int main()
{
    unsigned int a = std::numeric_limits<unsigned int>::max();
    unsigned int b = std::numeric_limits<unsigned int>::max();

    auto c = my_sum(a, b); // type is promoted to unsigned long int
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << c << std::endl;
}
