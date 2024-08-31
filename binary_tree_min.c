#include <stdio.h>

typedef struct
{
    int key;
    int *left;
    int *right;
} node;

node createNode(node *x, int value)
{
    if(x == NULL)
    {
        x->key = value;
        x->left = NULL;
        x->right = NULL;
    }
    else
    {
        
    }
}

node minValue(node *x)
{
    if(x != NULL)
    {
        return minValue(x->left);
    }
}

int main()
{
}