
#pragma once
#include <iostream>
#include <string>
#include <list>
#include <random>

// Структура для представления элементов списка
template <class T>
struct Node {
    T data;
    Node<T>* next;
};

struct Student {
    std::string lastName;
    std::string firstName;
    int course;
    float averageGrade;
};

// Шаблонный класс связного списка
template <class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    // Конструктор по умолчанию
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Конструктор копирования
    LinkedList(const LinkedList& other) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node<T>* temp = other.head;
        while (temp != nullptr) {
            push_tail(temp->data);
            temp = temp->next;
        }
    }

    // Конструктор, заполняющий список случайными значениями
    LinkedList(int n) : head(nullptr), tail(nullptr), size(0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> courseDist(1, 5);
        std::uniform_real_distribution<> gradeDist(3.0, 5.0);
        for (int i = 0; i < n; i++) {
            push_tail({ "Student", std::to_string(i), courseDist(gen), gradeDist(gen) });
        }
    }

    // Деструктор
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Операция присваивания
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            LinkedList temp(other);
            std::swap(head, temp.head);
            std::swap(tail, temp.tail);
            std::swap(size, temp.size);
        }
        return *this;
    }
    //
    int getSize(){
        return size;
    }


    // Операция доступа по индексу для чтения
    T& operator[](int index) {
        Node<T>* current = head;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                return current->data;
            }
            current = current->next;
            i++;
        }
        throw std::out_of_range("Index out of range");
    }

    // Операция доступа по индексу для записи
    const T& operator[](int index) const {
        Node<T>* current = head;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                return current->data;
            }
            current = current->next;
            i++;
        }
        throw std::out_of_range("Index out of range");
    }

   
};



