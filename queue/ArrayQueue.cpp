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


int main(int argc, char const *argv[])
{
    LinkedListQueue<int> queue;
    queue.enQueue(10);
    queue.enQueue(20);
    queue.enQueue(30);
    queue.enQueue(40);
    queue.enQueue(50);
    queue.print();
    cout<<"\n";
    queue.deQueue();
    queue.deQueue();
    queue.print();


   
}































class QueueBaseStack{
    public:
    stack<int> stack01, stack02;

    void enQueue(int value) {
        stack01.push(value);

    }
    int deQueue() {
        if (stack01.empty() && stack02.empty())
        {
            cout<< "queue is empty";
            exit(0);
        }
        if (stack02.empty())
        {
            while (!stack01.empty())
            {
                stack02.push(stack01.top());
                stack01.pop();
            }
        }
        int x =  stack02.top();
        stack02.pop();
        return x;
    }

    void print() {
        if (stack01.empty())
        {
            while (!stack02.empty())
            {
                stack01.push(stack02.top());
                stack02.pop();
            }
        
             stack<int> temp = stack01;
         
            while (!temp.empty())
            {
                 int x = temp.top();
                temp.pop();
                cout<< x << " ";
            }            
        }else {
            stack<int> temp = stack01;
         
            while (!temp.empty())
            {
                 int x = temp.top();
                temp.pop();
                cout<< x << " ";
            }          
        }
    }
};






