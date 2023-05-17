#include <iostream>

int main()
{


    int x;
    try
    {
        std::cout << "Enter x: ";
        std::cin >> x;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "X: " << x << '\n';
    

    return 0;
}