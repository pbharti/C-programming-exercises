#include "queue.h"
#include "stack.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint32_t u32_t;
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node_t;

Node_t* Insert(Node_t* root, int val)
{
    if (root == NULL) {
        Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
        if (newNode == NULL) {
            printf("Failed to allocate memory for new node\n");
            return NULL;
        }
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (val < root->val)
        root->left = Insert(root->left, val);
    else
        root->right = Insert(root->right, val);
    return root;
}

Node_t* IterativeInsert(Node_t* root, int val)
{
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    if (newNode == NULL) {
        printf("Failed to allocate memory for new node\n");
        return NULL;
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL) {
        return newNode;
    }
    Node_t *parent, *current = root;
    while (current != NULL) {
        parent = current;
        if (val < current->val)
            current = current->left;
        else
            current = current->right;
    }
    if (val < parent->val)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}

void PrintInorder(Node_t* root)
{
    if (root == NULL)
        return;
    PrintInorder(root->left);
    printf("%d ", root->val);
    PrintInorder(root->right);
}

u32_t MaxDepth(Node_t* root)
{
    if (root == NULL)
        return 0;
    uint32_t hLeft = MaxDepth(root->left);
    uint32_t hRight = MaxDepth(root->right);
    return 1 + (hLeft > hRight ? hLeft : hRight);
}

void PrintPreorder(Node_t* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->val);
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

void PrintPostorder(Node_t* root)
{
    if (root == NULL)
        return;
    PrintPostorder(root->left);
    PrintPostorder(root->right);
    printf("%d ", root->val);
}

Node_t* Search(Node_t* root, int key)
{
    if (root == NULL) {
        printf("Node with key: %d not found\n", key);
        return NULL;
    }
    if (root->val == key)
        return root;
    if (key < root->val)
        root = Search(root->left, key);
    else
        root = Search(root->right, key);
    return root;
}

int main()
{
    printf("## hello world\n");
    Node_t* root = NULL;
    // root = Insert(root, 5);
    // root = Insert(root, 2);
    // root = Insert(root, 4);
    // root = Insert(root, 10);
    // root = Insert(root, 9);
    // root = Insert(root, 7);
    // root = Insert(root, 12);
    // root = Insert(root, 15);
    // root = Insert(root, 35);
    // root = Insert(root, 25);
    root = IterativeInsert(root, 5);
    root = IterativeInsert(root, 2);
    root = IterativeInsert(root, 4);
    root = IterativeInsert(root, 10);
    root = IterativeInsert(root, 9);
    root = IterativeInsert(root, 7);
    root = IterativeInsert(root, 12);
    root = IterativeInsert(root, 15);
    root = IterativeInsert(root, 35);
    root = IterativeInsert(root, 25);
    printf("Inorder: ");
    PrintInorder(root);
    printf("\n");
    printf("Preorder: ");
    PrintPreorder(root);
    printf("\n");
    printf("Postorder: ");
    PrintPostorder(root);
    printf("\n");
    printf("Max Dept of tree: %d\n", MaxDepth(root));
    int key = 12;
    Node_t* found = Search(root, 12);
    if (found)
        printf("Found key %d at node: %p/%d\n", key, found, found->val);
    else
        printf("Key %d not found\n", key);
    return 0;
}
