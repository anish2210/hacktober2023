#include <stdio.h>
#include <malloc.h>

// Define a structure for a binary tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to construct a new node with the given data
struct node *construct(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
}

// Function to check if a binary tree is a Binary Search Tree (BST)
int isbst(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isbst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isbst(root->right);
    }
    else
    {
        return 1;
    }
}

// Function to search for a key in a BST
struct node *searchit(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

// Function to insert a new node with a given key into a BST
struct node *insertion(struct node *root, int key)
{
    struct node *prev = NULL;
    if (root == NULL)
    {
        printf("Cannot insert. Root is NULL.");
        return construct(key);
    }
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            return NULL; // Key already exists in the BST
        }
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *ptr = construct(key);
    if (key < prev->data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
    return ptr;
}

int main()
{
    // Create a sample binary search tree
    struct node *p = construct(5);
    struct node *p1 = construct(3);
    struct node *p2 = construct(6);
    struct node *p3 = construct(1);
    struct node *p4 = construct(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Check if the tree is a BST
    if (isbst(p))
    {
        // Insert a new node with key 55 into the BST
        insertion(p, 55);
        // Print the data of the rightmost node in the BST
        printf("%d\n", p->right->right->data);
    }
    else
    {
        printf("The tree is not a BST.\n");
    }
    return 0;
}
