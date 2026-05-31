#include <iostream>

int main()
{
    // Integer Types
    std::cout << "--- Integer Types ---\n";
    std::cout << "Size of short is: " << sizeof(short) << " bytes\n";
    std::cout << "Size of int is: " << sizeof(int) << " bytes\n";
    std::cout << "Size of long is: " << sizeof(long) << " bytes\n";
    std::cout << "Size of long long is: " << sizeof(long long) << " bytes\n\n";

    // Floating-Point Types (Decimals)
    std::cout << "--- Floating-Point Types ---\n";
    std::cout << "Size of float is: " << sizeof(float) << " bytes\n";
    std::cout << "Size of double is: " << sizeof(double) << " bytes\n\n";

    // Character and Boolean Types
    std::cout << "--- Character & Boolean Types ---\n";
    std::cout << "Size of char is: " << sizeof(char) << " byte\n";
    std::cout << "Size of bool is: " << sizeof(bool) << " byte\n";

    return 0;
}