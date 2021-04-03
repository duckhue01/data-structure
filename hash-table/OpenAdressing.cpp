#include <iostream>


using namespace std;


class LinearPobing
{
private:
    int tableSize;
    int insertedItem;
    int* table;

public:
    LinearPobing(int size=20){
        this->tableSize = size;
        this->table = new int[tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = -1;
        }
        

    };
    // ~LinearPobing();
    void insertItem(int value){
        int index = hashFunction(value);
      
        if (index != -1){
            int startIndex = index;
            while (table[index] != -1)
            {
                index = hashFunction(++index);
                if (index == startIndex)
                {
                    cout<<"table is full";
                    return;
                }
                
            }
        }
        table[index] = value;
        cout<<"insert successfully";
        
        

    };
    bool srearchitem(int value){
        int index = hashFunction(value);
      
        if (table[index] != value){
            int startIndex = index;
            while (table[index] != value)
            {
                index = hashFunction(++index);
                if (index == startIndex)
                {

                    return false;
                }
                
            }
        }
        return true;
        

    };
    void deleteItem(int value){
        int index = hashFunction(value);
      
        if (table[index] != value){
            int startIndex = index;
            while (table[index] != value)
            {
                index = hashFunction(++index);
                if (index == startIndex)
                {
                    cout<< "item isn't exist";
                    return;
                }
                
            }
        }
        table[index] = -1;
        cout<< "item has been deleted";

    };

    void displayTable(){
        for (int i = 0; i < tableSize; i++) {
            if (table[i] != -1)
                cout << i << " --> "
                    << table[i] << endl;
            else
                cout << i << endl;
        }
        
    }


    int hashFunction(int value) {
        return (abs(value % tableSize));
    }
};


int main(int argc, char const *argv[])
{
    LinearPobing table;
    table.insertItem(123);
    table.insertItem(234);
    table.insertItem(1);

    table.insertItem(2334);
    table.insertItem(3);
    table.insertItem(2344);
    cout<<endl;
    cout<<table.srearchitem(3);
    




    return 0;
}
