#include <iostream>
#include <string>
#include <limits>

// 함수 선언
void printMenu();
int getMenuChoice();
int getQuantity();
int getPrice(int menuNumber);
int calculateItemTotal(int price, int quantity);
void printFinalTotal(int total);

int main()
{
    std::cout << "================================\n";
    std::cout << "            C++ Kiosk\n";
    std::cout << "================================\n";
    std::cout << "Welcome to C++ Cafe!\n\n";

    printMenu();

    int total = 0;
    int menuNumber = -1;

    const int startMenuNumber = 1;
    const int endMenuNumber = 3;

    while (menuNumber != 0)
    {
        menuNumber = getMenuChoice();

        if (menuNumber == 0)
        {
            break;
        }

        if (menuNumber < startMenuNumber || menuNumber > endMenuNumber)
        {
            std::cout << "Invalid menu number. Please try again.\n\n";
        }
        else
        {
            int quantity = getQuantity();
            if (quantity <= 0)
            {
                std::cout << "Invalid quantity. Please try again.\n\n";
                continue; // 이번 주문의 계산과 Added 출력을 건너뛰고 메뉴 선택으로 이동
            }

            int price = getPrice(menuNumber);
            int itemTotal = calculateItemTotal(price, quantity);

            total += itemTotal;

            switch (menuNumber)
            {
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

            std::cout << "Current total: " << total << " won\n\n";
        }
    }

    printFinalTotal(total);

    return 0;
}

void printMenu()
{
    std::cout << "<< Menu >>\n";
    std::cout << "1. Americano - 3500 won\n";
    std::cout << "2. Latte      - 5000 won\n";
    std::cout << "3. Tea        - 4000 won\n";
    std::cout << "0. Checkout\n\n";
}

int getMenuChoice()
{
    int menuNumber;

    std::cout << "Select menu number: ";
    std::cin >> menuNumber;

    return menuNumber;
}

int getQuantity()
{
    int quantity;

    std::cout << "Quantity: ";
    std::cin >> quantity;

    return quantity;
}

int getPrice(int menuNumber)
{
    switch (menuNumber)
    {
    case 1:
        return 3500;
    case 2:
        return 5000;
    case 3:
        return 4000;
    default:
        return 0;
    }
}

int calculateItemTotal(int price, int quantity)
{
    return price * quantity;
}

void printFinalTotal(int total)
{
    std::cout << "\nFinal total: " << total << " won\n";
    std::cout << "Thank you for visiting C++ Cafe!\n";
}
