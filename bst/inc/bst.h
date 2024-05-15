#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct node_s {
    struct node_s *left;
    struct node_s *right;
    int data;
}node_t;

void IterateInorder(node_t *root);
void IteratePreorder(node_t *root);
void IteratePostorder(node_t *root);
node_t *Search(node_t *root, int data);
node_t *Add(node_t *root, int data);
node_t *Delete(node_t *root, int data);
