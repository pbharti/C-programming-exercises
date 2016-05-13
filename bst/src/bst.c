#include "bst.h"

void IterateInorder(node_t *root)
{
    if(!root)
        return;
    IterateInorder(root->left);
    printf("%d ",root->data);
    IterateInorder(root->right);
}

void IteratePreorder(node_t *root)
{
    if(!root)
        return;
    printf("%d ",root->data);
    IteratePreorder(root->left);
    IteratePreorder(root->right);
}

void IteratePostorder(node_t *root)
{
     if(!root)
         return;

}
