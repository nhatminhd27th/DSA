#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right; 
} node;

struct node* createNode(int value)
{
    node* newNode = malloc(sizeof(struct node));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertNode(node *x, int value)
{
    if(x->key > value)
    {
        if(x->left != NULL) insertNode(x->left, value);
        else x->left = createNode(value);
    }
    else
    {
        if(x->right != NULL) insertNode(x->right, value);
        else x->right = createNode(value);
    }
}

node* minNode(node *x)
{
    if(x->left == NULL) return x;
    else return minNode(x->left);
}

node* maxNode(node *x)
{
    if(x->right == NULL) return x;
    else return maxNode(x->right);
}

node* secondMaxNode(node *x)
{
    if(x->right != NULL)
    {
        if(x->right->right == NULL && x->right->left == NULL) return x;
        else return secondMaxNode(x->right);
    }
    else return maxNode(x->left);
}

node* secondMinNode(node *x)
{
    node* secondMin;
    if(x->left != NULL)
    {
        if(x->left->right == NULL && x->left->left == NULL) return x;
        else return secondMinNode(x->left);
    }
    else return minNode(x->right);
}

void displayTree(node *x)
{
    if(x == NULL) return;
    else
    {
        displayTree(x->left);
        printf(" %d ",x->key);
        displayTree(x->right);
    }
}

int main()
{
    struct node *node1 = createNode(15);
    insertNode(node1, 6);
    insertNode(node1, 18);
    insertNode(node1, 3);
    insertNode(node1, 7);
    insertNode(node1, 17);
    insertNode(node1, 20);
    insertNode(node1, 2);
    insertNode(node1, 4);
    insertNode(node1, 13);
    insertNode(node1, 9);
    // for(int i = 0 ; i < 100 ; i++) insertNode(node1, i);
    displayTree(node1);
    printf("\n");
    printf("%d\n", node1->right->right->key);
    printf("Min value is: %d\n", minNode(node1)->key);
    printf("Max value is: %d\n", maxNode(node1)->key); 
    printf("2nd Min value is: %d\n", secondMinNode(node1)->key);
    printf("2nd Max value is: %d\n", secondMaxNode(node1)->key);
}