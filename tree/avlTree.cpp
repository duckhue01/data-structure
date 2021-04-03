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
        int height;

        Node(type value) {
            this->data = value;
            this->left = this->right = NULL;
            this->height = 1;
        }
        
    };
    Node* root; 
    
public:
    avlTree(type value){
        this->root = new Node(value);
    };
    Node* getRoot() {
        return this->root;

    }

    int max(int a , int b ) {
        return (a > b) ? a : b;
        
    }
    int height(Node* node){
        if (node == NULL){
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* temp) {
        if (temp == NULL){
            return 0;
        }
            
        return height(temp->left ) - height(temp->right);
    }
    Node* rightRotation(Node *y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotation(Node* x) {   
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = max(height(x->left),height(x->right)) + 1;
        y->height = max(height(y->left),height(y->right)) + 1;
        return y;
    }
    Node* insertNode(Node* temp, type value){
        if (temp == NULL)
        {
            return (new Node(value));
        }
        
        if (value > temp->data )
        {
            temp->right = insertNode(temp->right, value);
        }
        if (value  < temp->data )
        {
            temp->left = insertNode(temp->left, value);
        }

        

        temp->height = 1 + (max(height(temp->right), height(temp->left)));
        
        // right - left
        int balance = getBalance(temp);
        cout<<balance<<endl;

        // left left case
        if (balance > 1 && value < temp->left->data)
        {
            return rightRotation(temp);
            // cout<<"case left left";
        }

        // right right case
        if (balance < -1 && value > temp->right->data)
        {
            return leftRotation(temp);
        }

        // left right case 
        if (balance > 1 && value > temp->left->data)
        {
            temp->left = leftRotation(temp->left);
            return rightRotation(temp);
        }

        //  right left case
        if (balance < -1 && value < temp->right->data)
        {
            temp->right = rightRotation(temp->left);
            return leftRotation(temp);
        }
        this->root= temp;
        return temp;
    }

    Node* findMin() {
        
    }
    Node* findMax() {
        
    }


    void printInOrder(Node* temp)
    {
        if (temp == NULL){
            return;
        }
            
        cout << temp->height << ' '<<temp->data<<endl;
        this->printInOrder(temp->left);
        this->printInOrder(temp->right);
    }
};


int main(int argc, char const *argv[])
{
  
    avlTree<int> tree(50);
   
    // tree.insertNode(tree.getRoot(), 10);
    // tree.insertNode(tree.getRoot(), 100);
    // tree.insertNode(tree.getRoot(), 1000);
    tree.insertNode(tree.getRoot(), 70);
    tree.insertNode(tree.getRoot(), 80);
    // tree.insertNode(tree.getRoot(), 31); 
   
   

    tree.printInOrder(tree.getRoot());
    return 0;
}
