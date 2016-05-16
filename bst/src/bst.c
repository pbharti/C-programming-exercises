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
     IteratePostorder(root->left);
     IteratePostorder(root->right);
     printf("%d ", root->data);
}

node_t * Add(node_t *root, int data)
{
    if(!root) {
        node_t *temp = (node_t *)malloc(sizeof(node_t));
        if(!temp) {
            printf("\n memory allocation failed \n");
            return NULL;
        }
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        return root;
    }
     if(data <= root->data)
         root->left = Add(root->left, data);
     else
         root->right = Add(root->right, data);
}

int Delete(node_t *root, int data)
{
#if 0
    if(!root)
        return -1;
    else if(root->data == data)
#endif
}

node_t *Search(node_t *root)
{
    if(!root)
        return NULL;
    else if()
}
node_t *FindMax(node_t * root)
{
    if(!root)
        return NULL;
    else if(!root->right)
        return root;
    else
        return(FindMax(root->right));
}
node_t *FindMin(node_t *root)
{
     if(!root)
         return NULL;
     else if(!root->left)
         return root;
     else
         return(FindMin(root->left));
}
int main()
{
     node_t *root = NULL;
     root = Add(root, 10);
     root = Add(root, 15);
     root = Add(root, 8);
     root = Add(root, 25);
     root = Add(root, 1);
     root = Add(root, 5);
     root = Add(root, 9);
     root = Add(root, 3);
     root = Add(root, 100);
     printf("\n######### Inorder Traversal #########\n");
     IterateInorder(root);
     printf("\n######### End ######################\n");
     printf("\n######### Preorder Traversal #########\n");
     IteratePreorder(root);
     printf("\n######### End ######################\n");
     printf("\n######### Postorder Traversal #########\n");
     IteratePostorder(root);
     printf("\n######### End ######################\n");
     node_t *MinNode = NULL;
     MinNode = FindMin(root);
     if(!MinNode)
         printf("\n Failed to get smallest Node \n");
     else
        printf("\nSmallest Entry: %d\n", MinNode->data);
     node_t *MaxNode = NULL;
     MaxNode = FindMax(root);
     if(!MaxNode)
         printf("\nFailed to get Biggest Node \n");
     else
        printf("\nBiggest Entry: %d\n", MaxNode->data);
     return 0;
}
