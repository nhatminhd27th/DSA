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

int minValue(node *x)
{
    int min;
    if(x->left == NULL)
    {
        min = x->key;
        return min;
    }
    else minValue(x->left);
}

int maxValue(node *x)
{
    int max;
    if(x->right == NULL)
    {
        max = x->key;
        return max;
    }
    else minValue(x->right);
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
    struct node *node1 = createNode(100);
    for(int i = 0; i < 100; i++) insertNode(node1, i);
    displayTree(node1);
    printf("\n");
    printf("Min value is: %d\n", minValue(node1));
    printf("Max value is: %d\n", maxValue(node1));
}