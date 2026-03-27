#include <iostream>
#include <string>
#include <queue>
#include <windows.h>
using namespace std;

struct Team {
    string name;
    string city;
    int points;
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    queue<Team> q;
    q.push({"Шахтар", "Донецьк", 45});
    q.push({"Динамо", "Київ", 42});
    q.push({"Буковина", "Чернівці", 30});
    q.push({"Зоря", "Луганськ", 35});
    q.push({"Оболон", "Київ", 20});

    queue<Team> uniqueCitiesQueue;
    queue<Team> highPointsQueue;
    queue<Team> restoreQueue;

    Team peremogium, loxi;
    bool first = true;
    int threshold = 35;

    string cities[100];
    int citiesCount = 0;

    while (!q.empty()) {
        Team current = q.front();
        q.pop();

        if (first) {
            peremogium = loxi = current;
            first = false;
        } else {
            if (current.points > peremogium.points) peremogium = current;
            if (current.points < loxi.points) loxi = current;
        }

        bool cityExists = false;
        for (int i = 0; i < citiesCount; i++) {
            if (cities[i] == current.city) {
                cityExists = true;
                break;
            }
        }
        if (!cityExists) {
            uniqueCitiesQueue.push(current);
            cities[citiesCount] = current.city;
            citiesCount++;
        }

        if (current.points > threshold) {
            highPointsQueue.push(current);
        }
        restoreQueue.push(current);
    }
    
    q = restoreQueue;
    
    cout << "--- Результати ---" << endl;
    cout << "Переможці: " << peremogium.name << " (" << peremogium.points << " очків)" << endl;
    cout << "Лохи: " << loxi.name << " (" << loxi.points << " очків)" << endl;

    cout << "\nПерші команди з міст: ";
    while (!uniqueCitiesQueue.empty()) {
        cout << uniqueCitiesQueue.front().name << " ";
        uniqueCitiesQueue.pop();
    }

    cout << "\nКоманди з очками > " << threshold << ": ";
    while (!highPointsQueue.empty()) {
        cout << highPointsQueue.front().name << " ";
        highPointsQueue.pop();
    }

    cout << "\n\nЧерга відновленна: " << q.size() << endl;

    return 0;
}