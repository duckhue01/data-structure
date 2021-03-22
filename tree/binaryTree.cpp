#include <iostream>
#include <queue>
using namespace std;

template<typename type>
class BinaryTree
{
private:
    struct Node {
        type data;
        Node* left;
        Node* right;
        Node(type value) {
            this->data = value;
            this->left = this->right = NULL;
        }
            
    };
    Node* root;
public:
    BinaryTree(type value){
        this->root = new Node(value);
        
        
    };
    void insertNode(type value) {
        // Node* temp = root;
        Node* newNode = new Node(value);
        queue<Node*> queue;
        queue.push(root);
        while ( !queue.empty())
        {
            Node* temp = queue.front();
            queue.pop();
            if ( temp->left != NULL)
            {
                queue.push(temp->left);

            } else {
                temp->left = newNode;
                break;
            }

            if ( temp->right != NULL)
            {
               queue.push(temp->right);

            } else {
                temp->right = newNode;
                break;
            }
            
        }
        
        
        
    }
    Node* getRoot() {
        return this->root;
    }

  
 

    void printInOrder(Node* temp)
        {
            if (temp == NULL)
                return;
        
            this->printInOrder(temp->left);
            cout << temp->data << ' ';
            this->printInOrder(temp->right);
        }


    void printPreOrder() {

    };

    void printPostOrder() {

    };
    
    void deleteNode() {
        
    }

    
   

   

};




int main(int argc, char const *argv[])
{
    BinaryTree<int> tree(10);
    tree.insertNode(20);
    tree.insertNode(30);
    tree.insertNode(40);
    tree.insertNode(50);
    tree.insertNode(60);


    

    cout<<"hello world";

    return 0;
}


