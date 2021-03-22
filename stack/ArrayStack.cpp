#include <iostream>

using namespace std;

// standard stack
template <typename type>
class ArrayStack
{
protected:
    static const int max = 50;
    type array[max];
    int peak;
   


public:
    ArrayStack(){
        peak = -1;
        

    };
    

    void push(type value) {
        if (isFull()) {
            cout << "Stack Overflow";
            abort();
        }
        
        peak++;
        array[peak] = value;
           

    }
    type pop() {
        if (isEmpty()) {
            cout << "Stack Underflow";
            
        }
            
        type x = array[peak];
        peak--;      
        return x;       
    }
    bool isEmpty(){
        return(peak == -1 ? true : false);

    }
    bool isFull() {
        return( peak == (max - 1) ? true : false);
    }
    int getSize() {
        return((peak + 1));
    }

    int getPeak() {
        return(array[peak]);
    }
    void getStack() {
     
        for (int i = 0; i < (peak  + 1); i++)
        {
            cout<<"\n"<< array[i];
            
        }
    }
    void print() {
        for (int i = 0; i <= peak; i++)
        {
            cout<<"\n"<<array[i];
        }
        
    }
    bool check(type value){
        for (int i = 0; i <= peak; i++)
        {
            if (array[i] == value)
            {
                return true;
            }
            
        }
        return false;
    }

};
int main(int argc, char const *argv[])
{
    ArrayStack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    cout<< myStack.check(30);
    myStack.print();

    
}



































// findmin stack
template <typename type>
class FindMinStack: public ArrayStack<type>{
    ArrayStack<type> min;
    
    public:
    void push(type value){
        if (ArrayStack<type>::isEmpty() == true)
        {
            min.push(value);
            ArrayStack<type>::push(value);

        } else {
            ArrayStack<type>::push(value);
            if (ArrayStack<type>::array[ArrayStack<type>::peak] > value)
            {
                min.push(value);
            } else {
                min.push(ArrayStack<type>::array[ArrayStack<type>::peak]);
            }
            
        }
        
        
    };
    void pop() {
        ArrayStack<type>::pop();
        min.pop();
        cout<<"pop has been exceuted";
       
    }
    int getMin() {
        type x = min.pop();
        min.push(x);
        return x;

        
    }

};




// implement two array in an stack
template <typename type>
class TwoStacks
{
private:
    static const int max = 20;
    type arr[max];
    int top1, top2;


public:
    TwoStacks(){
        top1 = -1;
        top2 = max ;


    };
    bool isEmpty() {
        return ((top2 - top1) == 51);

    }
    bool isFull() {
        return (top2 -top1 == 1);
    }
    
    void push1(type value) {
        if (top1 < (top2 - 1))
        {
            top1++;
            arr[top1] = value;
            cout <<value<<" have been pushed"<<"\n"; 

        }
        else { 
            cout << "Stack Overflow"<<"\n"; 
            exit(1); 
        } 
        
    }
   

    void pop1() {
        if (top1 > 0)
        {
            cout<< arr[top1]<< "have been poped"<<"\n";
            delete arr[top1];
            top1--;
        }
        else { 
            cout << "Stack Underflow"<<"\n"; 
            exit(1); 
        } 
        

    }

    void push2(type value) {
         if (top2 > (top1 + 1))
        {
            top2--;
            arr[top2] = value;
            cout <<value<<" have been pushed"<<"\n"; 

        }
        else { 
            cout << "Stack Overflow"<<"\n"; 
            exit(1); 
        }

    }

    void pop2() {
          if (top1 > 0)
        {
            cout<< arr[top1]<< "have been poped"<<"\n";
            delete arr[top1];
            top1--;
            
        }
        else { 
            cout << "Stack Underflow"<<"\n"; 
            exit(1); 
        } 

    }
    void print() {
        for (int i = 0; i < (max ); i++)
        {
            cout <<" "<<arr[i]<<" ";
        }
        
    }
};





















