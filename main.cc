#include <iostream>
#include "CustomList.h"

using namespace std;
using namespace CustomList;

int main() {
    DoubleLinkedList list;

    // Добавляем элементы в список
    list.insert_at_tail(1, "Иван", "Иванов", 1);
    list.insert_at_tail(2, "Петр", "Петров", 2);
    list.insert_at_tail(3, "Иван", "Иванов", 1); // Дубликат
    list.insert_at_tail(4, "Мария", "Сидорова", 3);
    list.insert_at_tail(5, "Петр", "Петров", 2); // Дубликат

    cout << "Список до удаления дубликатов:" << endl;
    list.display();

    // Удаляем дубликаты
    list.remove_duplicates();

    cout << "Список после удаления дубликатов:" << endl;
    list.display();

    return 0;
}
