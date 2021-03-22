#include <iostream>

using namespace std;


template <typename type>
class avlTree
{
private:
    struct Node
    {
        type data;
        Node* left;
        Node* right;

        Node(type value) {
            this->data = value;
            this->left = this->right = NULL;
        }
        Node* root; 
    };
    
public:
    avlTree(){
        
    };
    Node* findMin() {
        
    }
    Node* findMax() {
        
    }




    void insertNode(type value, Node* temp){
        Node* newNode = new Node(value);
        if (temp->left == NULL && temp->data.id > value.id){
            temp->left = newNode;
            return;
        }
        if (temp->right == NULL && temp->data.id < value.id){
            temp->right = newNode;
            return;
        }
            
    
        if(temp->data.id < value.id) {
            insertNode(value, temp->right);


        } else {
                insertNode(value, temp->left);
        }

        // Starting from w, travel up and find the first unbalanced node. Let z be the first unbalanced node, y be the child of z that comes on the path from w to z and w be the grandchild of z that comes on the path from w to z. 

        return;
    }

    ~avlTree();
};








int main(int argc, char const *argv[])
{
    
    return 0;
}
