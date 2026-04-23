#include <iostream>
#include <windows.h>
using namespace std;

void checkPassword(const char* pass) {
    char errors[500] = "";
    int len = strlen(pass);
    bool hasDigit = false;
    bool hasUpper = false;

    if (len < 8) {
        strcat(errors, "- Пароль коротший за 8 символів\n");
    }

    for (int i = 0; i < len; i++) {
        if (isdigit(pass[i])) hasDigit = true;
        if (isupper(pass[i])) hasUpper = true;
    }

    if (!hasDigit) strcat(errors, "- Немає цифри в паролі\n");
    if (!hasUpper) strcat(errors, "- Немає великої літери\n");

    if (strlen(errors) > 0) {
        throw runtime_error(errors);
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    char password[100];
    printf("Введіть пароль: ");
    scanf("%s", password);

    try {
        checkPassword(password);
        printf("Пароль дійсний\n");
    }
    catch (const exception& e) {
        printf("Помилки:\n%s", e.what());
    }

    return 0;
}