#include <iostream>
#include <vector>

// 함수 선언
void printMenu();
int getMenuChoice();
int getQuantity();
int getPrice(int menuNumber);
int calculateItemTotal(int price, int quantity);
void printFinalTotal(std::vector<int> cart);
void addItem(std::vector<int>& cart, int menuNumber, int quantity);
void printSelection(const int menuNumber, const int quantity);
void printCartItemCount(const std::vector<int>& cart);
void printReceipt(const std::vector<int>& cart);

int main() {
    std::cout << "================================\n";
    std::cout << "            C++ Kiosk\n";
    std::cout << "================================\n";
    std::cout << "Welcome to C++ Cafe!\n\n";

    printMenu();

    std::vector<int> cart;
    int menuNumber = -1;

    while (menuNumber != 0) {
        menuNumber = getMenuChoice();

        if (menuNumber == 0) {
            break;
        }

        if (menuNumber < 1 || menuNumber > 3) {
            std::cout << "Invalid menu number. Please try again.\n\n";
            continue;
        }

        int quantity = getQuantity();
        if (quantity <= 0) {
            std::cout << "Invalid quantity. Please try again.\n\n";
            continue;
        }
            
        addItem(cart, menuNumber, quantity);
        printSelection(menuNumber, quantity);
        printCartItemCount(cart);
    }

    // printFinalTotal(cart);
    printReceipt(cart);

    return 0;
}

void printMenu() {
    std::cout << "Menu\n";
    std::cout << "1. Americano - 4500 won\n";
    std::cout << "2. Latte     - 5000 won\n";
    std::cout << "3. Tea       - 4000 won\n";
    std::cout << "0. Checkout\n\n";
}

int getMenuChoice() {
    int menuNumber;

    std::cout << "Select menu number: ";
    std::cin >> menuNumber;

    return menuNumber;
}

int getQuantity() {
    int quantity;

    std::cout << "Quantity: ";
    std::cin >> quantity;

    return quantity;
}

int getPrice(int menuNumber) {
    switch (menuNumber) {
        case 1:
            return 4500;
        case 2:
            return 5000;
        case 3:
            return 4000;
        default:
            return 0;
    }
}

int calculateItemTotal(int price, int quantity) {
    return price * quantity;
}

void printFinalTotal(std::vector<int> cart) {
    int total = 0;

    for (int menuNumber : cart) {
        int price = getPrice(menuNumber);
        total += calculateItemTotal(price, 1);
    }

    std::cout << "\nFinal total: " << total << " won\n";
    std::cout << "Thank you for visiting C++ Cafe!\n";
}

// 이하 6주차 실습용 함수 - const 사용
void addItem(std::vector<int>& cart, int menuNumber, int quantity) {
    for (int count = 0; count < quantity; count++) {
        // 선택한 메뉴 번호를 cart에 추가
        cart.push_back(menuNumber);
    }
}

void printSelection(const int menuNumber, const int quantity) {
    switch (menuNumber) {
        case 1:
            std::cout << "Added: Americano x " << quantity << "\n";
            break;

        case 2:
            std::cout << "Added: Latte x " << quantity << "\n";
            break;

        case 3:
            std::cout << "Added: Tea x " << quantity << "\n";
            break;
    }
}

void printCartItemCount(const std::vector<int>& cart) {
    std::cout << "Items in cart: " << cart.size() << "\n\n";
}

void printReceipt(const std::vector<int> &cart) {
    int total = 0;

    for (int menuNumber : cart) {
        int price = getPrice(menuNumber);
        total += calculateItemTotal(price, 1);
    }

    std::cout << "\nFinal total: " << total << " won\n";
    std::cout << "Thank you for visiting C++ Cafe!\n";
}
