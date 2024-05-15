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
     return root;
}

node_t *Search(node_t *root, int data)
{
    if(!root)
        return NULL;
    else if (root->data == data)
        return root;
    else if(root->data <= data)
        return(Search(root->right, data));
    else
        return(Search(root->left, data));
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

node_t *Delete(node_t *root, int data)
{
    if(!root)
        return root;
    // Case where the node to be deleted is available on left subtree.
    if(data < root->data)
        root->left = Delete(root->left, data);
    // Case where the node to be deleted is available on right subtree.
    else if(data > root->data)
        root->right = Delete(root->right, data);
    else {
        printf("\n Found Node %d that needs to be deleted at addr:%p\n", data, root);
        /* 1. This case is for when we are deleting a leaf node */
        if((root->left == NULL) && (root->right == NULL)) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            node_t *temp = root->right;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            node_t * temp = root->left;
            root = root->left;
            free(temp);
        } else {
            // Node to be deleted has both left and right subtree.
            node_t *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
        return root;
    }
}




int GetSize(node_t * root) {
    if(!root)
        return 0;
    int left_sz = GetSize(root->left);
    int right_sz = GetSize(root->right);
    return (left_sz + right_sz + 1);
}

bool IsSame(node_t *t1, node_t *t2) {
    if(t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    return (t1->data == t2->data && 
            IsSame(t1->left, t2->left) &&
            IsSame(t1->right, t2->right));
}

int Height(node_t * root) {
    if(!root)
        return 0;
    int lheight = Height(root->left);
    int rheight = Height(root->right);
    int max_height = lheight > rheight ? lheight:rheight;
    return (1 + max_height);
}

void userInputTask() {
    node_t *root = NULL;
    node_t *uroot = NULL;
    int option = -1;
    while(true)
    {
        printf("##########    Enter your option      ############\n");
        printf("#1. Add a node to the Binary Search Tree            #\n");
        printf("#2. Delete a node from the Binary Search Tree       #\n");
        printf("#3. Inorder Traversal of Binary Search tree         #\n");
        printf("#4. Pre-Order Traversal of Binary Search tree       #\n");
        printf("#5. Post-order Traversal of Binary Search Tree      #\n");
        printf("#6. Create default Binary Search Tree               #\n");
        printf("#7. Find Biggest node in a Binary Search Tree       #\n");
        printf("#8. Find Smallest node in a Binary Search Tree      #\n");
        printf("#9. Search a node in a Binary Search Tree           #\n");
        printf("#10. Create a new user defined Binary Search Tree   #\n");
        printf("#11. Get Size of a Binary Search Tree               #\n");
        printf("#12. Get Height of a Binary Search Tree             #\n");
        printf("#BST>");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                {
                    printf("\n\nAdding a node now\n");
                    printf("Enter node data: ");
                    int data = 0;
                    scanf("%d", &data);
                    root = Add(root, data);
                    printf("\n");
                    break;
                }
            case 2:
                {
                    int data = 0;
                    printf("\n\nDeleting a node now..Enter the node data:\n");
                    scanf("%d", &data);
                    node_t *ret = Delete(root, data);
                    if(!ret) {
                        printf("Failed to delete node for data: %d from tree\n", data);
                    }
                    printf("\n");
                    break;
                }
            case 3:
                {
                    printf("\n\nTraversing a BST in-order now\n");
                    IterateInorder(root);
                    printf("\n");
                    break;
                }
            case 4:
                {
                    printf("\n\nTraversing a BST pre-order now\n");
                    IteratePreorder(root);
                    printf("\n");
                    break;
                }
            case 5:
                {
                    printf("\n\nTraversing a BST post-order now\n");
                    IteratePostorder(root);
                    printf("\n");
                    break;
                }
            case 6:
                {
                    printf("\n\nCreating default BST\n");
                    root = Add(root, 10);
                    root = Add(root, 15);
                    root = Add(root, 8);
                    root = Add(root, 25);
                    root = Add(root, 1);
                    root = Add(root, 5);
                    root = Add(root, 9);
                    root = Add(root, 3);
                    root = Add(root, 100);
                    root = Add(root, 11);
                    root = Add(root, 19);
                    break;
                }
            case 7:
                {
                    printf("\n\nFind Max in BST\n");
                    if(!root) {
                        printf("Empty BST..\n");
                        continue;
                    }
                    
                    node_t *max = FindMax(root);
                    if(!max) {
                        printf("Failed to find max entry in BST with root node: [%d/%p]\n", root->data, root);
                    } else {
                        printf("Found max node: %d/%p\n\n", max->data, max);
                    }
                    printf("\n");
                    break;
                }
            case 8:
                {
                    printf("\n\nFind Min in BST\n");
                    if(!root) {
                        printf("Empty BST..\n");
                        continue;
                    }
                    
                    node_t *min = FindMin(root);
                    if(!min) {
                        printf("Failed to find max entry in BST with root node: [%d/%p]\n", root->data, root);
                    } else {
                        printf("Found max node: %d/%p\n\n", min->data, min);
                    }
                    printf("\n");
                    break;
                }
            case 9:
                {
                    printf("\n\nSearch a node in BST. Enter the node data: \n");
                    if(!root) {
                        printf("Empty BST..\n");
                        continue;
                    }
                    int searched = 0;
                    scanf("%d", &searched);
                    node_t *snode = NULL;
                    snode = Search(root, searched);
                    if(!snode) {
                        printf("Failed to find node with data: %d\n", searched);
                    } else {
                        printf("Found node with data: %d at address: %p in a BST with root at : %d/%p\n", searched, snode, root->data, root);
                    }
                    printf("\n");
                    break;
                }
            case 10:
                {
                    printf("Creating User defines Binary search tree..\n");
                    while(true) {
                        int ndata = 0;
                        printf("Enter the node data. Enter -1 to stop entering: \n");
                        scanf("%d", &ndata);
                        if(ndata == -1)
                            break;
                        uroot = Add(uroot, ndata);
                    }
                }
            case 11:
                {
                    printf("Getting the size of the binary tree..\n");
                    printf("default tree: %d\nUser-defined tree: %d\n", GetSize(root), GetSize(uroot));
                    break;
                }
            default:
                {
                    printf("\n\nInvalid option. Enter your option againa\n");
                    
                    break;
                }
        }
    }
}

int main()
{
    /*

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
    root = Add(root, 11);
    root = Add(root, 19);
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
    node_t * findnode = NULL;
    findnode = Search(root, 95);
    if(!findnode)
        printf("\n Node with data 95 not found\n");
    else
        printf("\nFound Node with data 95 at %p with data %d\n", findnode, findnode->data);
    findnode = NULL;
    findnode = Search(root, 100);
    if(!findnode)
        printf("\n Node with data 100 not found\n");
    else
        printf("\nFound Node with data 100 at %p with data %d\n", findnode, findnode->data);
    while (1)
    {
         continue;
    }
    */

    userInputTask();
    return 0;
}
