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
        Node* newNode = new Node(value);
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty())
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


    void printPreOrder(Node* temp) 
        {
            if (temp == NULL)
                return;
            cout << temp->data << ' ';
            this->printInOrder(temp->left);
            
            this->printInOrder(temp->right);
        };

    void printPostOrder(Node* temp) {
        if (temp == NULL)
            return;
       
        this->printInOrder(temp->left);   
        this->printInOrder(temp->right);
        cout << temp->data << ' ';
    };

    void delDeepestNode(Node* deletedNode) {
        queue<Node*> queue;
        queue.push(this->root);
        while (!queue.empty())
        {
            Node* temp = queue.front();
            queue.pop();
            if (temp == deletedNode) {
                temp = NULL;
                delete (deletedNode);
                return;
            }
            if (temp->left == deletedNode)
            {
                temp->left = NULL;
                delete (deletedNode);
                return;

            } else {
                 queue.push(temp->left);
            }

            if (temp->right == deletedNode)
            {
                temp->right = NULL;
                delete (deletedNode);
                return;
            } else {
                                 queue.push(temp->right);
            }
            
        }
       
    }



    
    void deleteNode(type value) {

        if (root == NULL)
            return;
    
        if (root->left == NULL && root->right == NULL) {
            if (root->data == value)
                delDeepestNode(root);
                
        }
        
        queue<Node*> queue;
        queue.push(this->getRoot());

        Node* del_node = NULL;
        Node* temp = NULL;
        while (!queue.empty())
        {
            temp = queue.front();
            queue.pop();
            if (temp->data == value)
                del_node = temp;


            if (temp->left)
                queue.push(temp->left);


            if (temp->right )
                queue.push(temp->right);

            
        }

        if (del_node != NULL)
        {
            del_node->data = temp->data;
            delDeepestNode(temp);
        } else {
            cout<< " khong tim thay phan tu";
        }
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

    tree.printInOrder(tree.getRoot());
    tree.deleteNode(60);
    tree.printInOrder(tree.getRoot());

    cout<<"hello world";

    return 0;
}


