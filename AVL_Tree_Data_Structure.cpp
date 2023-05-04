#include <iostream>
using namespace std;
class AVLTREE
{
public:
    int data;
    AVLTREE *Left; // left child
    AVLTREE *Right; //right child
    int Height;
};
//Find Height
int Height(AVLTREE *node)
{
    if (node == NULL)
        return 0;
    else
        return node->Height;
}
int Maximum(int x, int y)
{
    // if (x > y)
    //     return x;
    // else
    //     return y;
    return x > y ? x : y; // ternary operator
}
AVLTREE *CreateNode(int data)
{
    AVLTREE *newNode = new AVLTREE();
    newNode->data = data;
    newNode->Left = NULL;
    newNode->Right = NULL;
    newNode->Height = 1;
    return newNode;
}
//Find Balance Factor(-1,0,1)
int GetBalanceFactor(AVLTREE *node)
{
    if (node == NULL)
        return 0;
    return Height(node->Left) - Height(node->Right); // For find balance factor 👉 left Height - right Height
}
//for balance the tree to perform rotataion
AVLTREE *RightRotation(AVLTREE *y)
{
    // Bfore Rotation
    AVLTREE *x = y->Left;
    AVLTREE *xrchild = x->Right;
    // After rotation
    x->Right = y;
    y->Left = xrchild;

    y->Height = Maximum(Height(y->Left), Height(y->Right)) + 1;
    x->Height = Maximum(Height(x->Left), Height(x->Right)) + 1;
    return x;
}
//for balance the tree to perform rotataion
AVLTREE *LeftRotation(AVLTREE *x)
{
    // Before Rotation
    AVLTREE *y = x->Right;
    AVLTREE *ylchild = y->Left;
    // After Rotation
    y->Left = x;
    x->Right = ylchild;
    x->Height = Maximum(Height(x->Left), Height(x->Right)) + 1;
    y->Height = Maximum(Height(y->Left), Height(y->Right)) + 1;
    return y;
}
AVLTREE *InsertNode(AVLTREE *node, int data)
{
    // First we will generate binary tree
    //  creating first node
    //Insert Node Same AS BST but perform rotations
    if (node == NULL)
        return CreateNode(data);
    if (data < node->data)
        node->Left = InsertNode(node->Left, data);
    else if (data > node->data)
        node->Right = InsertNode(node->Right, data);
    else
        return node;
    node->Height = Maximum(Height(node->Left), Height(node->Right)) + 1;
    int bFactor = GetBalanceFactor(node);
    if (bFactor > 1) //Check Balance factor
    {
        if (data < node->Left->data)
            return RightRotation(node);
        else if (data > node->Left->data)
        {
            node->Left = LeftRotation(node->Left);
            return RightRotation(node);
        }
    }
    if (bFactor < -1) //Check Balance Factor
    {
        if (data > node->Right->data)
            return LeftRotation(node);
        else if (data < node->Right->data)
        {
            node->Right = RightRotation(node->Right);
            return LeftRotation(node);
        }
    }
    return node;
}
void PreOrder(AVLTREE *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        PreOrder(node->Left);
        PreOrder(node->Right);
    }
}
void InOrder(AVLTREE *node)
{
    if (node != NULL)
    {
        InOrder(node->Left);
        cout << node->data << " ";
        InOrder(node->Right);
    }
}
void PostOrder(AVLTREE *node)
{
    if (node != NULL)
    {
        PostOrder(node->Left);
        PostOrder(node->Right);
        cout << node->data << " ";
    }
}
AVLTREE *Predecessor(AVLTREE *root)
{
    while (root && root->Right != NULL)
        root = root->Left;
    return root;
}
AVLTREE *Succesor(AVLTREE *root)
{
    while (root && root->Left != NULL)
        root = root->Right;
    return root;
}
AVLTREE *DeleteNode(AVLTREE *root, int key)
{
    AVLTREE *tempPtr;
    // check if root is empty
    if (root == NULL)
        return NULL;
    // deleting leaf node
    if (root->Left == NULL && root->Right == NULL)
    {
        if (key == root->data)
        {
            root = NULL;
            delete root;
            return NULL;
        }
    }
    // first search and than delete
    if (key < root->data)
        root->Left = DeleteNode(root->Left, key);
    else if (key > root->data)
        root->Right = DeleteNode(root->Right, key);
    else
    {
        if (Height(root->Left) > Height(root->Right))
        {
            tempPtr = Predecessor(root->Left);
            root->data = tempPtr->data;
            root->Left = DeleteNode(root->Left, tempPtr->data);
        }
        else
        {

            tempPtr = Succesor(root->Right);
            root->data = tempPtr->data;
            root->Right = DeleteNode(root->Right, tempPtr->data);
        }
    }
    root->Height = Maximum(Height(root->Left), Height(root->Right)) + 1;
    int bFactor = GetBalanceFactor(root);
    if (bFactor > 1)
    {
        if (key < root->Left->data)
            return RightRotation(root);
        else if (key > root->Left->data)
        {
            root->Left = LeftRotation(root->Left);
            return RightRotation(root);
        }
    }
    if (bFactor < -1)
    {
        if (key > root->Right->data)
            return LeftRotation(root);
        else if (key < root->Right->data)
        {
            root->Right = RightRotation(root->Right);
            return LeftRotation(root);
        }
    }
    return root;
}

int main()
{
    AVLTREE *node = NULL;
    node = InsertNode(node, 6);
    node = InsertNode(node, 150);
    node = InsertNode(node, 129);
    node = InsertNode(node, 210);
    node = InsertNode(node, 121);
    node = InsertNode(node, 110);
    node = InsertNode(node, 25);
    node = InsertNode(node, 90);
    node = InsertNode(node, 100);
    node = InsertNode(node, 120);
    node = InsertNode(node, 140);
    node = InsertNode(node, 170);
    node = InsertNode(node, 190);
    node = InsertNode(node, 185);
    cout << "\n-----------InOrder-----------------\n";
    InOrder(node);
    cout << "\n-----------postrder-----------------\n";
    PostOrder(node);
    cout << "\n-----------PreOrder-----------------\n";
    PreOrder(node);
    cout << "\n-----------deletion of node-----------------\n";
    node = DeleteNode(node, 6);
    InOrder(node);
}