#include <iostream>
#include <string>
#define ll long long

using namespace std;





template <typename T>
class vector
{
private:
    int size;
    int capacity;
    T* array;
    void expand(int newCapacity){
        if (newCapacity <= this->capacity)
        {
            return;

        }
        T* old = array;
        array = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            array[i] = old[i];
        }
        delete[] old;
        this->capacity = newCapacity;
        
        
    }
public:
    vector(int initCapacity = 16){
        this->size = 0;
        this->capacity = initCapacity;
        this->array = new T[capacity];
    };
    ~vector(){
        delete[] array;
    }

    vector& operator = (vector& rhs){
        if (this != &rhs)
        {
            delete[] array;
            this->size = rhs.size;
            capacity = rhs.capacity;
            array = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                this->array[i] = rhs.array[i];
            }
            return *this;
            
        }
        
    }
    int getSize(){
        return this->size;
    }
    bool isEmpty(){
        return(this->size == 0);
    }

    T & operator [] (int index) {
        return array[index];
    }
    void pushBack(T newElement) {
        if(size == capacity){
            expand(capacity * 2);
        }
        array[size] = newElement;
        size++;



    }
    void popBack(T newElement) {
        
        delete array[size -1];
        size--;



    }
    void insert(int pos, T newElement){
        if (pos > 0 && pos <= size)
        {
            if(size == capacity){
                expand(capacity * 2);
            }
            for (int i = size + 1; i > pos; i--)
            {
                array[i] = array[i - 1];
            }
            

            array[pos] = newElement;
            size++;
            
        }
        
        
    }

    void removeElements(int start, int end) {
        int space =  end - start;
        if (start >= 0  && end <= size && space > 0)
        {
            
             for (int i = start; i < size - space; i++)
            {
                array[i] = array[i + space];
                
                
            }
            size-= space;
            
        }
        

    }

    void print() {
        for (int i = 0; i < size; i++)
        {
            // cout<<array[i].toString<< " ";
            array[i].toString();
        }
        
    }

};






int main(int argc, char const *argv[])
{


    struct vt
    {
        string name;
        int grade;
        string dob;
        void toString() {
            cout<< name<< " "<< grade<< " "<< dob<< "\n";

        }
        

    };
    vt student1=  {"cao duc khue", 10, "11/06/2001"};
    vt student2=  {"cao duc khue", 10, "11/06/2001"};
    vt student3=  {"cao duc khue", 10, "11/06/2001"};
    vt student4=  {"cao duc khue", 10, "11/06/2001"};


    
    vector<vt> vector;



    vector.pushBack(student1);
    vector.pushBack(student2);
    vector.pushBack(student3);
    vector.pushBack(student4);

    vector.print();

    return 0;
}
