#include <iostream>
#include <bits/stdc++.h>

using namespace std;


template <typename type>
class LinkedListQueue{
    private:
        struct Node
        {
            type value;
            Node* next;

            Node(type value){
                this->value = value;
                this->next = NULL;
            }
            
        };
        Node* front;
        Node* back;
        int size;

    public:
        LinkedListQueue() {
            // front = NULL;
            // back = NULL;
            size = 0;

        };
        void enQueue(type value) {
            Node* newNode = new Node(value);
            if (size == 0)
            {
                back = newNode;
                front = newNode;
            } else {
                front->next = newNode;
                front = newNode;
            }
            size++;
           
            
        }
        void deQueue() {
            Node* old = back;
            back = back->next;
            delete old;
           

        }

        void print() {
            Node* temp = back;

            while (temp != NULL)
            {
                cout<< temp->value << " ";
                temp = temp->next;
            }
            
        }

        bool isEmpty() {
            return (size == 0);
        }
        int getSize() {
            return( this->size);
        }

        bool check(type value) {
            Node* temp = back;

            while (temp != NULL)
            {
                if (temp->value = value)
                {
                    return true;
                }                
                temp = temp->next;
            }
            return false;

        }
        

};