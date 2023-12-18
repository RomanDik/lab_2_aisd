
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

    // Конструктор, заполняющий список заданными значениями
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

    // Добавление элемента в конец списка
    void push_tail(const T& data) {
        Node<T>* newNode = new Node<T>{ data, nullptr };
        if (head == nullptr) {
            head = newNode;
        }
        else {
            tail->next = newNode;
        }
        tail = newNode;
        size++;
    }

    // Добавление другого списка LinkedList в конец списка
    void push_tail(const LinkedList& other) {
        Node<T>* temp = other.head;
        while (temp != nullptr) {
            push_tail(temp->data);
            temp = temp->next;
        }
    }

    // Добавление элемента в начало списка
    void push_head(const T& data) {
        Node<T>* newNode = new Node<T>{ data, head };
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
        size++;
    }

    // Добавление списка LinkedList в начало списка
    void push_head(const LinkedList& other) {
        LinkedList temp(other);
        Node<T>* current = temp.tail;
        Node<T>* prev = nullptr;
        while (current != nullptr) {
            Node<T>* newNode = new Node<T>{ current->data, prev };
            prev = newNode;
            if (head == nullptr) {
                tail = newNode;
            }
            head = newNode;
            size++;
            current = current->next;
        }
    }

    // Удаление элемента из начала списка
    void pop_head() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    // Удаление элемента из конца списка
    void pop_tail() {
        if (tail != nullptr) {
            if (head == tail) {
                delete tail;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node<T>* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                temp->next = nullptr;
                delete tail;
                tail = temp;
            }
            size--;
        }
    }

    // Удаление всех элементов Node с информационным полем, равным переданному
    void delete_node(const T& data) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current != nullptr) {
            if (current->data == data) {
                if (current == head) {
                    pop_head();
                }
                else if (current == tail) {
                    pop_tail();
                }
                else {
                    prev->next = current->next;
                    delete current;
                    size--;
                    current = prev;
                }
            }
            else {
                prev = current;
            }
            current = current->next;
        }
    }
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
    // Метод для разделения студентов на две подгруппы
    std::pair<LinkedList<T>, LinkedList<T>> divideByCourse() {
        LinkedList<T> seniorStudents;
        LinkedList<T> juniorStudents;
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data.course > 2) {
                seniorStudents.push_tail(current->data);
            }
            else {
                juniorStudents.push_tail(current->data);
            }
            current = current->next;
        }
        return { seniorStudents, juniorStudents };
    }
   
};



