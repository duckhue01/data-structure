#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class ListChainingHashTable
{
private:
    int BUCKET;
    list<int>* table;

public:
    ListChainingHashTable(int size){
        this->BUCKET = size;
        this->table  = new list<int>[BUCKET];

    };
    void insertItem(int value){
       int index = this->hashFunction(value);
       table[index].push_back(value);
    }

    void deleteItem(int value) {
        int index = this->hashFunction(value);
        list<int> :: iterator i;
        for(i = table[index].begin(); i != table[index].end(); i++ ){
            if(*i == value){
                break;
            }
        }
         if (i != table[index].end()) 
            table[index].erase(i); 
        

         

    }

    
    void displayItem(){
        for (int i = 0; i < BUCKET; i++) { 
            cout << i; 
            for (auto x : table[i]) 
                cout << " --> " << x; 
            cout << endl; 
        } 

    }
    int hashFunction(int value) {
        return ( abs(value % this->BUCKET));
    }
    
};



int main(int argc, char const *argv[])
{
    int a[] = {15, 11, 27, 8, 12}; 
    int len =  sizeof(a)/sizeof(a[1]);
    ListChainingHashTable hash(7);



    for (int  i = 0; i < len; i++)
    {
        hash.insertItem(a[i]);
    }
    hash.displayItem();
    hash.deleteItem(12); 
    hash.displayItem();

    
    return 0;
}
