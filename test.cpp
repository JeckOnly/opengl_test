//
// Created by 24502 on 2025/8/22.
//


#include <iostream>
#include <string>

void modifyWithPointer(std::string* strPtr) {
    // strPtr 是一个指针变量，它有自己的地址，比如 0x2000
    // strPtr 的值是 myString 的地址，即 0x1000
    *strPtr = "New (Pointer)"; // 通过解引用修改 0x1000 地址处的对象
    // strPtr = nullptr; // 可以这样做，但之后就不能再用*strPtr了，危险！
}

int main() {
    std::string myString = "Old";
    std::cout << "Before: " << myString << std::endl; // Output: Old

    modifyWithPointer(&myString); // 显式传递 myString 的地址 (& -> 取地址)

    std::cout << "After: " << myString << std::endl; // Output: New (Pointer)
    return 0;
}