#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void preorderTraversal(struct Node*);
void postorderTraversal(struct Node*);
void inorderTraversal(struct Node*);
struct Node* newNode(int);

void main() {
    int ch;
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    do {
        printf("---Main Menu---\n1.Preorder\n2.Postorder\n3.Inorder\n4.Exit\n\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 2:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice");
        }
    } while (ch < 5 && ch > 0);
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* node) {
    if (node == NULL)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
