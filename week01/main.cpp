#include <iostream>
#include <string>
#include <limits>

int main() {
    /* TODO: 다음이 화면에 출력되게 해보세요:

    ================================
                C++ Kiosk
    ================================
    
    Welcome to C++ Cafe!

    Enter customer name: Mina
    Hello Mina! You are a member!
    */


    std::cout << "================================\n";
    std::cout << "            C++ Kiosk\n";
    std::cout << "================================\n\n";
    
    std::cout << "Welcome to C++ Cafe!\n";

    int age = -1;
    std::cout << "Age: " << std::flush;
    
    if (!(std::cin >> age)) {
        // 정수 입력 실패
        std::cin.clear();  // failbit 해제
        age = -1;
    }

    // std::cin.ignore(); // 버퍼의 마지막 1개만 제거
    // 성공했으면 개행을, 실패했으면 잘못 입력한 문자열 전체를 제거
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name;

    std::cout << "Enter customer name: ";
    std::getline(std::cin, name);

    std::cout << "Hello " << name << "! You are a member!\n";
    
    if (age == -1) {
        std::cout << "Your age is not recognized!\n";
    } else if (age>=0) {
        std::cout << "You are " << age << " years old!\n";
    } else {
        std::cout << "Your age information is wrong!\n";
    }

    return 0;
}
