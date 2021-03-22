#include <iostream>

using namespace std;
#define MAX 1000 



class IndexMapping
{
private:
    bool has[MAX + 1][2];
public:
  

    void search(int value){
        if(value >= 0) {
            if (has[value][0] == 1)
            {
                cout<<"present";
                 return;
            }
            cout<< "not present";
             return;
            
        } else {
            if (has[abs(value)][1] == 1)
            {
                cout<< "present";
                return;
            }
            cout<< " not present";
             return;
        }
        


    }


    void insert(int arr[], int len){
        for (int i = 0; i < len; i++)
        {
            if (arr[i] > 0)
            {
                has[arr[i]][0] = 1;
            } else {
                has[abs(arr[i])][1] = 1;
            }
            
        }
        

    }


};



int main(int argc, char const *argv[])
{  
    IndexMapping index;
    int myArr[5] = {1,-2,3,4,5};
    int n = sizeof(myArr)/sizeof(myArr[0]); 
    index.insert(myArr, n);
    index.search(-2);


    return 0;
}












