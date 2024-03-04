#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

#pragma once
#include <iostream>
#include <random>
#include <string>

namespace CustomList {
    using namespace std;

    struct Node {
        int data;
        string name;
        string surname;
        int course;
        Node* prev;
        Node* next;

        Node() : data(0), name(""), surname(""), course(0), prev(nullptr), next(nullptr) {}
        Node(int data_val, string name_val, string surname_val, int course_val) : data(data_val), name(name_val), surname(surname_val), course(course_val), prev(nullptr), next(nullptr) {}
    };

    class DoubleLinkedList {
    private:
        Node* _head;
        Node* _tail;

    public:
        DoubleLinkedList() : _head(nullptr), _tail(nullptr) {}

        void insert_at_tail(int data, string name, string surname, int course) {
            Node* newNode = new Node(data, name, surname, course);
            if (_head == nullptr) {
                _head = newNode;
                _tail = newNode;
            }
            else {
                newNode->prev = _tail;
                _tail->next = newNode;
                _tail = newNode;
            }
        }

        void remove_duplicates() {
            Node* current = _head;

            while (current != nullptr) {
                Node* temp = current->next;

                while (temp != nullptr) {
                    if (current->name == temp->name && current->surname == temp->surname && current->course == temp->course) {
                        // Ќайден дубликат, удал€ем его из списка
                        Node* duplicate = temp;
                        temp = temp->next;
                        if (duplicate == _head) {
                            _head = temp;
                            if (temp) temp->prev = nullptr;
                        }
                        else if (duplicate == _tail) {
                            _tail = duplicate->prev;
                            _tail->next = nullptr;
                        }
                        else {
                            duplicate->prev->next = temp;
                            temp->prev = duplicate->prev;
                        }
                        delete duplicate;
                    }
                    else {
                        temp = temp->next;
                    }
                }

                current = current->next;
            }
        }
    };
}
#endif