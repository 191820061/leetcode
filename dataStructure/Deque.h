#ifndef DATASTRUCTURE_DEQUE_H
#define DATASTRUCTURE_DEQUE_H

template<class T>
struct Node {
    T item;
    Node<T> *next;
    Node<T> *prev;

    Node<T>(T value, Node<T> *p, Node<T> *n) : item(value), prev(p), next(n) {};

    Node<T>(T value, Node<T> *n) : item(value), prev(nullptr), next(n) {};

    Node<T>(T value) : item(value), prev(nullptr), next(nullptr) {};
};

template<class T>
class LinkDeque {
private:
    int size;
    Node<T> *sentinel;

public:
    LinkDeque(T value) {
        sentinel = new Node<T>(value);
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        size = 0;
    }

    LinkDeque(LinkDeque<T> const &que){

    }

    void addFirst(T value) {
        sentinel->next = new Node<T>(value, sentinel->next);
        sentinel->next->prev = sentinel;
        sentinel->next->next->prev = sentinel->next;
        size++;
    }

    T removeFirst() {
        size--;
        T item = sentinel->next->item;
        sentinel->next->next->prev = sentinel;
        sentinel->next = sentinel->next->next;
        return item;
    }

    T getFirst() {
        return sentinel->next->item;
    }


    void addLast(T value) {
        size++;
        sentinel->prev->next = new Node<T>(value, sentinel);
        sentinel->prev->next->prev = sentinel->prev;
        sentinel->prev = sentinel->prev->next;
    }

    T removeLast() {
        T item = sentinel->prev->item;
        sentinel->prev = sentinel->prev->prev;
        sentinel->prev->next = sentinel;
        return item;
    }

    T getLast() {
        return sentinel->prev->item;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }
};

#endif //DATASTRUCTURE_DEQUE_H
