#ifndef DATASTRUCTURE_SLLIST_H
#define DATASTRUCTURE_SLLIST_H

template<class T>
struct Node {
    T item;
    Node *next;

    Node(T value, Node *n = nullptr) : item(value), next(n) {};

    Node() : item(nullptr), next(nullptr) {};
};


template<class T>
class SLList {
private:
    int size;
    Node<T> *sentinel;

public:
    SLList() {
        sentinel = new Node<T>();
        size = 0;
    }

    SLList(T value) {
        sentinel = new Node<T>(value);
        size = 0;
    }

    void addFirst(T value);

    void addLast(T value) {
        addLast(size, value, sentinel);
    }

    void insert(int pos, T value) {
        if (pos > size) {
            return;
        }
        insert(pos, value, sentinel);
    }

    T getFirst() {
        return sentinel->next->item;
    }

    T getLast() {
        return getLast(size, sentinel);
    }

    T get(int index) {
        return get(index, sentinel);
    }

    void print() {
        if (size == 0) {
            return;
        }
        print(size, sentinel->next);
    }

    int length();

private:
    T getLast(int len, Node<T> *node);

    void addLast(int len, T value, Node<T> *node);

    void insert(int pos, T value, Node<T> *node);

    T get(int index, Node<T> *node);

    void print(int len, Node<T> *node);
};

template<class T>
void SLList<T>::addFirst(T value) {
    sentinel->next = new Node<T>(value, sentinel->next);
    size++;
}

template<class T>
void SLList<T>::addLast(int len, T value, Node<T> *node) {
    if (len == 0) {
        size++;
        node->next = new Node<T>(value);
        return;
    }
    addLast(len - 1, value, node->next);
}

template<class T>
void SLList<T>::insert(int pos, T value, Node<T> *node) {
    if (pos == 0) {
        size++;
        node->next = new Node<T>(value, node->next);
        return;
    }
    insert(pos - 1, value, node->next);
}

template<class T>
T SLList<T>::getLast(int len, Node<T> *node) {
    if (len == 1) {
        return node->next->item;
    }
    return getLast(len - 1, node->next);
}


template<class T>
T SLList<T>::get(int index, Node<T> *node) {
    if (index == 0) {
        return node->next->item;
    }
    return get(index - 1, node->next);
}

template<class T>
void SLList<T>::print(int len, Node<T> *node) {
    if (len == 1) {
        std::cout << node->item << std::endl;
        return;
    }
    std::cout << node->item << " ";
    print(len - 1, node->next);
}

template<class T>
int SLList<T>::length() {
    return size;
}


#endif //DATASTRUCTURE_SLLIST_H
