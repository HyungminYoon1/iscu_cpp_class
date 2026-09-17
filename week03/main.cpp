#include <iostream>

int main() {
    std::cout << "================================\n";
    std::cout << "            C++ Kiosk\n";
    std::cout << "================================\n";
    std::cout << "Welcome to C++ Cafe!\n\n";

    std::cout << "<< Menu >>\n";
    std::cout << "1. Americano - 3500 won\n";
    std::cout << "2. Latte      - 5000 won\n";
    std::cout << "3. Tea        - 4000 won\n";
    std::cout << "0. Checkout\n\n";

    int menuNumber = -1;
    int quantity = 0;
    int total = 0;

    // ============================================================
    // TODO
    // README.md의 Code Bank에서 필요한 코드 조각을 골라
    // 아래 영역에 적절한 순서로 배치하여 주문 기능을 완성하세요.
    //
    // 모든 코드 조각을 사용하는 것은 아닙니다.
    // 일부 코드 조각은 수정해야 할 수도 있습니다.
    // ============================================================


    // 여기에 주문 처리 코드를 작성하세요.
    while (menuNumber != 0) {

        std::cout << "Select menu number: ";
        std::cin >> menuNumber;

        if (menuNumber == 0) {
            break;
        }

        if (menuNumber < 1 || menuNumber > 3) {
            std::cout << "Invalid menu number. Please try again.\n\n";
            continue;
        }

        std::cout << "Quantity: ";
        std::cin >> quantity;

        if (quantity < 1) {
            std::cout << "Invalid quantity number. Please try again.\n\n";
            continue;
        }

        switch (menuNumber) {
            case 1:
                total += 3500 * quantity;
                std::cout << "Added: Americano x " << quantity << "\n";
                break;

            case 2:
                total += 5000 * quantity;
                std::cout << "Added: Latte x " << quantity << "\n";
                break;

            case 3:
                total += 4000 * quantity;
                std::cout << "Added: Tea x " << quantity << "\n";
                break;
        }

        std::cout << "Current total: " << total << " won\n\n";
    }

    std::cout << "\nFinal total: " << total << " won\n";
    std::cout << "Thank you for visiting C++ Cafe!\n";

    return 0;
}
