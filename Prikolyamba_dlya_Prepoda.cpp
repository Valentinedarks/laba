#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int random = std::rand() % 6;
    if (random == 0) {
        std::cout << "Можеш жити дальше, но врахуй те, що в наступний раз бог буде не так милостивий" << endl;
    }
    else {
        std::cout << "Meow :3";
        remove ("C:/---/---");
    }
    return 0;
}