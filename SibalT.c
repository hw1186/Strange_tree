#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
    int data;
    struct _TreeNode* left;
    struct _TreeNode* right;
} TreeNode;


TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


TreeNode* ndnode(TreeNode* parent, int data) {
    if (parent == NULL) {
        return createNode(data);
    }
    else if (parent->left == NULL) {
        parent->left = createNode(data);
    }
    else {
        parent->right = createNode(data);
    }
    return parent;
}

TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = createNode(5);
    root = ndnode(root, 3);
    root = ndnode(root, 2);
    root->left = ndnode(root->right, 4);
    root->left->left->left = ndnode(root->left->left->right , 6);
    root->left->left->left-> left = ndnode(root->left->left->left->right , 8);
    inorderTraversal(root);
    return 0;
}


