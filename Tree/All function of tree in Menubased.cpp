#include <stdio.h>
#include <stdlib.h>

struct Treenode {
    int data;
    struct Treenode *left;
    struct Treenode *right;
};

struct Treenode *createnode(int data) {
    struct Treenode *newnode = (struct Treenode *)malloc(sizeof(struct Treenode));
    if (newnode == NULL) {
        printf("Memory Allocation Failed:");
        exit(1);
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert(struct Treenode **root, int data) {
    if (*root == NULL) {
        *root = createnode(data);
    } else if (data <= (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

void inordertraversal(struct Treenode *root) {
    if (root != NULL) {
        inordertraversal(root->left);
        printf("%d ", root->data); // corrected: use %d instead of &root->data
        inordertraversal(root->right);
    }
}

void preordertraversal(struct Treenode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}

void postordertraversal(struct Treenode *root) {
    if (root != NULL) {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to delete a node with given key from subtree with given root
struct Treenode* deleteNode(struct Treenode* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Treenode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Treenode* temp = root->left;
            free(root);
            return temp;
        }
        struct Treenode* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Treenode *root = NULL;
    int choice, value;

    printf("Binary Search Tree Operations\n");
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inordertraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preordertraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postordertraversal(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

