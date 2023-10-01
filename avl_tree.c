#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data, height;
    struct node *left;
    struct node *right;
};

struct node *construct(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}
int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int getbalance(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}
struct node *right(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    return x;
}
struct node *left(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    return y;
}
struct node *insertion(struct node *n, int key)
{
    if (n == NULL)
    {
        return construct(key);
    }
    if (key < n->data)
    {
        n->left = insertion(n->left, key);
    }
    else if (key > n->data)
    {
        n->right = insertion(n->right, key);
    }
    n->height = 1 + max(getheight(n->left), getheight(n->right));

    int bf = getbalance(n);
    // ll
    if (bf > 1 && key < n->left->data)
    {
        return right(n);
    }
    // rr
    if (bf < -1 && key > n->right->data)
    {
        return left(n);
    }
    // lr
    if (bf > 1 && key > n->left->data)
    {
        n->left = left(n->left);
        return right(n);
    }
    // rl
    if (bf < -1 && key < n->right->data)
    {
        n->right = right(n->right);
        return left(n);
    }
    return n;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}
int main()
{
    struct node *root = NULL;
    root = insertion(root, 5);
    root = insertion(root, 6);
    root = insertion(root, 7);
    root = insertion(root, 8);
    root = insertion(root, 9);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n%d", root->data);
    return 0;
}