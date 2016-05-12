#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node_s {
    struct node_s *link;
    int data;
}node_t;

void IterateInorder(node_t *root);
void IteratePreorder(node_t *root);
void IteratePostorder(node_t *root);
node_t *Search(node_t *root, int data);
int Add(node_t *root, int data);
int Remove(node_t *root, int data);
