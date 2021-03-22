#include <iostream>

using namespace std;

template <typename T>

class LinkedList
{
private:
   Node* head;
   int size;

    struct Node
    {
        T value;
        Node* next;

        Node(T value, Node* netxt){
            this->value = value;
            this->next = next;
        }

        
    };
    
public:
    LinkedList(){
        head = NULL;
        size = 0;
    }
    ~LinkedList() {
        while (!empty())
        {
            popFont();
        }
        
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
	
	// Tra ve phan tu dau danh sach.
	T front()
	{
		return head->elem;
	}

    void print() {
        Node* temp = head;

        
		while (p != NULL)
		{
			cout << p->elem << " ";
			p = p->next;
		}
		
		cout << endl;

    }
    
    void pushFront(T value) {
        Node* newNode = new Node(value, head);
        head = newNode;
        size++;

    }
    void popFront(){
        Node* old = head;
        head = head->next;
        delete old;
        size --;
    }

    bool containts(t value) {
        Node* p  = head;
        while (p->next != NULL)
        {
            if (p-> value == value)
            {
                return true;
            }
            p = p->next;
            
        }
        return false;
        
    } 
    void remove(T value){
         Node* tmp  = head;
         Node* prev = NULL;
        while (tmp->next != NULL)
        {
            if (tmp-> value == value)
            {
               
            }
            tmp = tmp->next;
            
        }

    }
    
};





int main(int argc, char const *argv[])
{
    cout<<"";
    return 0;
}

