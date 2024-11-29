#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *left, *right;
};

struct BinaryTreeNode* newNodeCreate(int value) {
    struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct BinaryTreeNode* searchNode(struct BinaryTreeNode* root, int target) {
    if (root == NULL || root->key == target)
        return root;
    if (root->key < target)
        return searchNode(root->right, target);
    return searchNode(root->left, target);
}

struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value) {
    if (node == NULL)
        return newNodeCreate(value);
    if (value < node->key)
        node->left = insertNode(node->left, value);
    else if (value > node->key)
        node->right = insertNode(node->right, value);
    return node;
}

void postOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

void inOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct BinaryTreeNode* findMin(struct BinaryTreeNode* root) {
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return findMin(root->left);
    return root;
}

struct BinaryTreeNode* delete(struct BinaryTreeNode* root, int x) {
    if (root == NULL)
        return NULL;

    if (x > root->key)
        root->right = delete(root->right, x);
    else if (x < root->key)
        root->left = delete(root->left, x);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            struct BinaryTreeNode* temp;
            if (root->left == NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        } else {
            struct BinaryTreeNode* temp = findMin(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }
    return root;
}

int main() {
    struct BinaryTreeNode* root = NULL;
    int data, ch;

    do {
        printf("\n---Main Menu---\n1.Insert Element\n2.Perform Post-Order Traversal\n3.Perform Pre-Order Traversal\n4.Perform In-Order Traversal\n5.Delete Node\n6.Search Element\n7.Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element : ");
                scanf("%d", &data);
                if (root == NULL)
                    root = insertNode(root, data);
                else
                    insertNode(root, data);
                break;

            case 2:
                printf("\nPost-Order Traversal\n");
                postOrder(root);
                break;

            case 3:
                printf("\nPre-Order Traversal\n");
                preOrder(root);
                break;

            case 4:
                printf("\nIn-Order Traversal\n");
                inOrder(root);
                break;

            case 5:
                printf("\nEnter element to search : ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("After Delete: \n");
                inOrder(root);
                break;

            case 6:
                printf("\nEnter element to search : ");
                scanf("%d", &data);
                if (searchNode(root, data) != NULL)
                    printf("%d found\n", data);
                else
                    printf("%d not found\n", data);
                break;

            case 7:
                exit(0);
                break;

            default:
                printf("Invalid choice : ");
        }
    } while (ch < 8 && ch > 0);
    return 0;
}
