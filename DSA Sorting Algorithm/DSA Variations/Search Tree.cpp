// Example program
#include <iostream>
#include <string>
using namespace std;

/*************
* Binary Search Tree
Pointer-based
**************/


/*************
* Tree & Nodes
**************/

typedef int ItemType;
struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

class TreeType {
public:
    TreeType();
    ~TreeType();
    bool IsEmpty()const;
    int NumberOfNodes()const;
    void RetrieveItem(ItemType&, bool&);
    void InsertItem(ItemType);
    void DeleteItem(ItemType);
    void PrintTree() const;
private:
    TreeNode* root;
};

/*************
* Con/De constructors
**************/

void Destroy(TreeNode*& tree)
{
    if (tree != NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete(tree);
    }
}


TreeType::TreeType()
{
    root = NULL;
}
TreeType::~TreeType()
{
    Destroy(root);
}



bool TreeType::IsEmpty() const
{
    return root == NULL;
} // tree is not empty}

/*************
* Insert
**************/
void Insert(TreeNode*& tree, ItemType item)
{
    if (tree == NULL) { // base case
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
        Insert(tree->left, item);
    else
        Insert(tree->right, item);
}
void TreeType::InsertItem(ItemType item)
{
    Insert(root, item);
}

/*************
* Find
**************/
void Retrieve(TreeNode* tree, ItemType& item, bool& found)
{
    if (tree == NULL)
        found = false;

    else if (item < tree->info)
        Retrieve(tree->left, item, found);
    else if (item > tree->info)
        Retrieve(tree->right, item, found);
    else
    {
        //item = tree->info;
        found = true;
    }
}
void TreeType::RetrieveItem(ItemType& item, bool& found)
{
    Retrieve(root, item, found);
}


/*************
* Print
**************/
void  Print(TreeNode* tree)
{

    if (tree != NULL)
    {
        Print(tree->left);
        cout << tree->info;
        Print(tree->right);
    }
}
void TreeType::PrintTree() const
{
    Print(root);
}

/*************
*   Deletion    *
****************/


void GetSuccessor(TreeNode* tree, ItemType& data) {
    while (tree->left != NULL)
        tree = tree->left;
    data = tree->info;
}



void DeleteNode(TreeNode*& tree) {

    ItemType data;
    TreeNode* tempPtr;
    tree->info = data;
    tempPtr = tree;

    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
    }
    else {
        GetSuccessor(tree->right, data);
        //tree->info = data;
        //Delete(tree->left, data);

    }
}


// first, find which node should be deleted.
void Delete(TreeNode*& tree, ItemType item)
{
    if (item < tree->info)
        Delete(tree->left, item);
    else if (item > tree->info)
        Delete(tree->right, item);
    else
        DeleteNode(tree);  // Node found
}

void TreeType::DeleteItem(ItemType item)
{
    Delete(root, item);
}



int main()
{
    TreeType WorkersTree;
    WorkersTree.InsertItem(5);
    WorkersTree.InsertItem(1);
    WorkersTree.InsertItem(4);
    WorkersTree.InsertItem(3);
    WorkersTree.InsertItem(2);
    WorkersTree.PrintTree();
}

