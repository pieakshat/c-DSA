#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

struct Node *getSuccessor(struct Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key) // traversing the tree
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // 0 children or only right child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // when both children are present
        struct Node *succ = getSuccessor(root);
        root->key = succ->key;
        root->right = deleteNode(root->right, succ->key);
    }
    return root;
}

void inOrder(struct Node *root) // left -- root -- right
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(struct Node *root) // root -- left -- right
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root) // left -- right -- root
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

void inOrderNonRecursive(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;
    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->key);
        current = current->right;
    }
}

void preOrderNonRecursive(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        struct Node *current = stack[top--];
        printf("%d ", current->key);
        if (current->right)
            stack[++top] = current->right;
        if (current->left)
            stack[++top] = current->left;
    }
}

void postOrderNonRecursive(struct Node *root)
{
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1)
    {
        struct Node *current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left)
            stack1[++top1] = current->left;
        if (current->right)
            stack1[++top1] = current->right;
    }
    while (top2 != -1)
    {
        printf("%d ", stack2[top2--]->key);
    }
}

void mirror(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    struct Node *root = NULL;
    int choice, key;
    while (1)
    {
        printf("\nSelect an operation:\n");
        printf("1. Insert\n2. Delete\n3. Inorder Traversal (Recursive)\n4. Inorder Traversal (Non-Recursive)\n");
        printf("5. Preorder Traversal (Recursive)\n6. Preorder Traversal (Non-Recursive)\n");
        printf("7. Postorder Traversal (Recursive)\n8. Postorder Traversal (Non-Recursive)\n");
        printf("9. Mirror Image\n10. Count Nodes\n11. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 3:
            inOrder(root);
            printf("\n");
            break;
        case 4:
            inOrderNonRecursive(root);
            printf("\n");
            break;
        case 5:
            preOrder(root);
            printf("\n");
            break;
        case 6:
            preOrderNonRecursive(root);
            printf("\n");
            break;
        case 7:
            postOrder(root);
            printf("\n");
            break;
        case 8:
            postOrderNonRecursive(root);
            printf("\n");
            break;
        case 9:
            mirror(root);
            printf("Tree mirrored.\n");
            break;
        case 10:
            printf("Total nodes: %d\n", countNodes(root));
            break;
        case 11:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid input! Try again.\n");
        }
    }
}
