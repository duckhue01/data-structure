#include <iostream>
#include <queue>
using namespace std;

template<typename type>
class binarySearchTree
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
    Node* getRoot() {
        return this->root;
    }

    binarySearchTree(type value){
            this->root = new Node(value);
            
            

            
    };
    void insertNode(type value, Node* temp){
        Node* newNode = new Node(value);
        // Node* temp  = this->root;
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

        return;
    }
    bool search(type key) {
        if (root == NULL || root->data == key)
            return root;
        
        // Key is greater than root's key
        if (root->data < key)
            return search(root->right, key);
    
        // Key is smaller than root's key
        return search(root->left, key);

    }

    bool searchByID(Node* root, int id) {
        if (root == NULL || root->data.id == id)
            return root;
        
       
        if (root->data.id  < id)
            return searchByID(root->right, id);
    
      
        return searchByID(root->left, id);

    }


    Node* deleteNode(Node* root, int key)
    {
        // base case
        if (root == NULL)
            return root;
    
        // If the key to be deleted is 
        // smaller than the root's
        // key, then it lies in left subtree
        if (key < root->data)
            root->left = deleteNode(root->left, key);
    
        // If the key to be deleted is
        // greater than the root's
        // key, then it lies in right subtree
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
    
        // if key is same as root's key, then This is the node
        // to be deleted
        else {
            // node with only one child or no child
            if (root->left == NULL) {
                 Node* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL) {
                 Node* temp = root->left;
                free(root);
                return temp;
            }
    
            // node with two children: Get the inorder successor
            // (smallest in the right subtree)
            Node* temp = minValueNode(root->right);
    
            // Copy the inorder successor's content to this node
            root->data = temp->data;
    
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    Node* minValueNode(struct Node* node)
    {
        struct Node* current = node;
    
        /* loop down to find the leftmost leaf */
        while (current && current->left != NULL)
            current = current->left;
    
        return current;
    }

    void searchBetween(type k1, type k2, Node* root) {

       {
            if (root == NULL)
                return;
        
            searchBetween(k1, k2, root->left);
            if (k1 <= root->data  && root->data  <= k2)
            {
                 cout << root->data << ' ';
            }
            
            searchBetween(k1, k2, root->right);
        }
    }
    void printInOrder(Node* temp)
    {
        if (temp == NULL)
            return;
    
        this->printInOrder(temp->left);
        cout << temp->data.id << ' ';
        this->printInOrder(temp->right);
    }
    void printPostOrder(Node* temp)
    {
        if (temp == NULL)
            return;
    
        this->printInOrder(temp->left);
        
        this->printInOrder(temp->right);
        cout << temp->data.id << ' ';
    }
    void printPreOrder(Node* temp)
    {
        if (temp == NULL)
            return;
        cout << temp->data.id << ' ';
        this->printInOrder(temp->left);
        
        this->printInOrder(temp->right);
    }

};

int main(int argc, char const *argv[])
{
    struct sinhvien
    {
        string name;
        int id;
        
    };

    sinhvien newsv =  {"cao duc khue" ,10};
    sinhvien newsv1 =  {"nguyen tuan dung" ,4};
    sinhvien newsv2 =  {"tong cong tu" ,22};
    sinhvien newsv3 =  {"cao duc khue3" ,1};
    sinhvien newsv4 =  {"cao duc khue4" ,44};
    
    binarySearchTree<sinhvien> myTree(newsv);
    myTree.insertNode(newsv1, myTree.getRoot());
    myTree.insertNode(newsv2, myTree.getRoot());
    myTree.insertNode(newsv3, myTree.getRoot());
    myTree.insertNode(newsv4, myTree.getRoot());

    
    // cout<<"\nduyet theo thu tu giua:";
    // myTree.printInOrder(myTree.getRoot());

    cout<<"\nduyet theo thu tu truoc:";
    myTree.printPreOrder(myTree.getRoot());

    // cout<<"\nduyet theo thu tu sau:";
    // myTree.printPostOrder(myTree.getRoot());






    // cout<<"hello world";
    return 0;
}

