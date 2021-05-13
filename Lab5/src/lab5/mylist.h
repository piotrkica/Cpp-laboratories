#ifndef MYLIST_H
#define MYLIST_H

#include <stdexcept>
#include <memory>
#include <iterator>

template <typename T> class MyList{
protected:
    class Node{
        private:
            T value;
        public:
            friend class MyList;
            Node *next = nullptr;

            Node() {}
            Node(T val): value(val){};
            Node get_value(){ return value;}
    };

protected:
    int _size;
    Node *head;

public:
    typedef T value_type;
    MyList(): _size(0), head(nullptr){}
    MyList (const MyList&) = delete;
    MyList& operator=(const MyList&) = delete;

    int size() const { return _size; }

    void push_front(T value);

    T pop_front();

    T front() const{ return head->value; }

    void remove(T val_to_remove);

    class Iterator : public std::iterator<std::bidirectional_iterator_tag,int> {
         private:
             Node *current;
         public:
              typedef T value_type;
              Iterator(Node *node): current(node) {};
              Iterator& operator=(Node *node) { this->current = node; return *this; }
              Iterator& operator++() { if(current) current = current->next; return *this; }
              Iterator operator++(int) { Iterator iterator = *this; ++*this; return iterator; }
              bool operator!=(const Iterator& iterator) { return current != iterator.current; }
              T& operator*() const { return current->value; }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }

    template <class R>
    friend std::ostream& operator<<(std::ostream& os, const MyList<R>& list);

};

template <class T> void MyList<T>::push_front(T value){
    Node *node = new Node(value);
    if (head == nullptr){
        head = node;
    }
    else{
        node->next = head;
        head = node;
    }
    _size++;
}

template <class T> T MyList<T>::pop_front(){
    T value;
    if (head == nullptr){
        throw std::out_of_range("List is empty");
    }
    else{
        value = head->value;
        Node* front_node = head;
        head = head->next;
        delete(front_node);
    }
    _size--;
    return value;
}

template <class T> void MyList<T>::remove(T val_to_remove){
    if (head == nullptr ){
        return;
    }
    while (head != nullptr and head->value == val_to_remove){
        head = head->next;
        _size--;
    }
    if (head->next == nullptr){
        return;
    }
    Node* prev = head;
    Node* current = head->next;
    while(current != nullptr){
        if (current->value == val_to_remove){
            current = current->next;
            prev->next = current;
            _size--;
        }
        else{
            current = current->next;
            prev = prev->next;
        }
    }
}

template <class R>
std::ostream& operator<<(std::ostream &os, const MyList<R>& list) {
    for (auto node_val : list){
        os << node_val << " ";
    }
    return os;
}





#endif // MYLIST_H
