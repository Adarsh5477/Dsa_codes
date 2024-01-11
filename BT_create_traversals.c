#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;// Stores the rating A,B,C... for the employees
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(char data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(char arr[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node *buildTree(char inorder[], char preorder[], int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd)
        return NULL;

    struct Node *node = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);

    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

void postorderTraversal(struct Node *root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->data);
}

int main() {
    char inorder[50], preorder[50];
    printf("Enter inorder traversal: ");
    scanf("%s", inorder);

    printf("Enter preorder traversal: ");
    scanf("%s", preorder);

    int preIndex = 0;
    int inStart = 0;
    int inEnd = strlen(inorder) - 1;

    struct Node *root = buildTree(inorder, preorder, inStart, inEnd, &preIndex);

    printf("Postorder traversal: ");
    postorderTraversal(root);

    return 0;
}
