#include <iostream>
#include "CustomList.h"

using namespace std;
using namespace CustomList;

int main() {
    DoubleLinkedList list;

    // ��������� �������� � ������
    list.insert_at_tail(1, "����", "������", 1);
    list.insert_at_tail(2, "����", "������", 2);
    list.insert_at_tail(3, "����", "������", 1); // ��������
    list.insert_at_tail(4, "�����", "��������", 3);
    list.insert_at_tail(5, "����", "������", 2); // ��������

    cout << "������ �� �������� ����������:" << endl;
    list.display();

    // ������� ���������
    list.remove_duplicates();

    cout << "������ ����� �������� ����������:" << endl;
    list.display();

    return 0;
}
