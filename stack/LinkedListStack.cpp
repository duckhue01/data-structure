#include <iostream>

using namespace std;

template <typename T>
class LinkedListStack{
private:
  

    struct Node
    {
        T value;
        Node* next;

        Node(T value, Node* next){
            this->value = value;
            this->next = next;
        }

    };
    Node* head;
    int size;
public:
    LinkedListStack(){
        head = NULL;
        size = 0;
    }


     bool empty()
	{
		return (head == NULL);
	}
	
	// Tra ve kich thuoc (so phan tu).
	int getSize()
	{
		return size;
	}
	

    void print() {
        Node* temp = head;

        
		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		
		cout << endl;

    }
    
    void push(T value) {
        Node* newNode = new Node(value, head);
        head = newNode;
        size++;

    }
    void pop(){
        Node* old = head;
        head = head->next;
        delete old;
        size --;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
