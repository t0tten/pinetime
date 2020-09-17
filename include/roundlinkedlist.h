#ifndef ROUND_LINKED_LIST_H
#define ROUND_LINKED_LIST_H

#include <iostream>
#include <string>

template <class T>
class RoundLinkedList {
        private:
                class Node {
                        public:
                                T* data;

                                Node* next = NULL;
                                Node* previous = NULL;

                                Node(T* data) : data(data) {}
                                ~Node() {
                                        delete data;
                                }
                };

                Node* current;
                RoundLinkedList* parent;
                Node* start;

                void addItem(Node* node);
        public:
                RoundLinkedList();
                ~RoundLinkedList();

                void addItem(T* data);
                void addItem(T* data, bool start);

                T* getCurrentItem();
                T* getNextItem();
                T* getPreviousItem();

                void rotateNext();
                void rotatePrev();
                void reset();

                bool hasParent();
                RoundLinkedList<T>* getParent();
                void setParent(RoundLinkedList* parent);
                void removeParent();
};

template <class T>
RoundLinkedList<T>::RoundLinkedList() : 
        current(NULL), 
        parent(NULL),
        start(NULL) {}

template <class T>
RoundLinkedList<T>::~RoundLinkedList() {
        if(this->current != NULL) {
                while((this->current != this->current->next) && 
                      (this->current != this->current->previous)) {
                        Node* garbage = this->current;

                        this->current->previous->next =this->current->next;
                        this->current->next->previous = this->current->previous;

                        this->current = this->current->next;

                        garbage->previous = garbage->next = NULL;
                        delete garbage;
                        garbage = NULL;
                }

                delete this->current;
                this->current = NULL;
        }
}

template <class T>
void RoundLinkedList<T>::addItem(T* data) {
        Node* newNode = new Node(data);
        this->addItem(newNode);
}

template <class T>
void RoundLinkedList<T>::addItem(T* data, bool start) {
        Node* newNode = new Node(data);
        if (start)
                this->start = newNode;

        this->addItem(newNode);

}

template <class T>
void RoundLinkedList<T>::addItem(Node* newNode) {
        if (this->current == NULL) {
               this->current->previous = this->current->next = this->current = newNode;
        } else {
                newNode->previous = this->current;
                newNode->next = this->current->next;

                this->current->next->previous = newNode;
                this->current->next = newNode;

                this->current = this->current->next;
        }
}

template <class T>
T* RoundLinkedList<T>::getCurrentItem() {
        if(this->current == NULL)
                throw "Empty list";

        return this->current->data;
}

template <class T>
T* RoundLinkedList<T>::getNextItem() {
        if(this->current == NULL)
                throw "Empty list";

        return this->current->next->data;
}

template <class T>
T* RoundLinkedList<T>::getPreviousItem() {
        if(this->current == NULL)
                throw "Empty list";

        return this->current->previous->data;
}

template <class T>
void RoundLinkedList<T>::rotateNext() {
        if(this->current != NULL) this->current = this->current->next; 
}

template <class T>
void RoundLinkedList<T>::rotatePrev() {
        if(this->current != NULL) this->current = this->current->previous;
}

template <class T>
void RoundLinkedList<T>::reset() {
        if (this->start != NULL) {
                while (this->current != this->start) {
                        this->current = this->current->next;
                }
        }
}

template <class T>
bool RoundLinkedList<T>::hasParent() {
        return this->parent != NULL;
}

template <class T>
RoundLinkedList<T>* RoundLinkedList<T>::getParent() {
        return this->parent;
}

template <class T>
void RoundLinkedList<T>::setParent(RoundLinkedList* parent) {
        this->parent = parent;
}

template <class T>
void RoundLinkedList<T>::removeParent() {
        this->parent = NULL;
}

#endif // ROUND_LINKED_LIST_H
