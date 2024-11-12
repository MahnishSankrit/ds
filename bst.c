#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bst
{
    char keyword[10];
    char meaning[10];
    struct bst *left;
    struct bst *right;
};

void create(struct bst *root)
{
    char ch;
    do
    {
        struct bst *temp = root;
        struct bst *curr = (struct bst *)malloc(sizeof(struct bst));

        printf("\nEnter key and meaning\n");
        scanf("%s %s", curr->keyword, curr->meaning);
        curr->left = NULL;
        curr->right = NULL;
        int flag =0 ;

        while (flag == 0)
        {
            if (strcmp(curr->keyword, temp->keyword) < 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }

        printf("Do you want to continue? (y/n)\n");
        scanf(" %c", &ch);
    } while (ch == 'y');
}

void inorder(struct bst *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%s: %s\n", temp->keyword, temp->meaning);
        inorder(temp->right);
    }
}

void display(struct bst *root)
{
    inorder(root);
}

struct bst *find_min(struct bst *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct bst *delete_node(struct bst *root, char key[10])
{
    if (root == NULL)
        return root;

    if (strcmp(key, root->keyword) < 0)
    {
        root->left = delete_node(root->left, key);
    }
    else if (strcmp(key, root->keyword) > 0)
    {
        root->right = delete_node(root->right, key);
    }
    else // one child
    {
        if (root->left == NULL)
        {
            struct bst *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct bst *temp = root->left;
            free(root);
            return temp;
        }
        else{ //two children 
            struct bst *temp = find_min(root->right);
            strcpy(root->keyword, temp->keyword);
            strcpy(root->meaning, temp->meaning);
            root->right = delete_node(root->right, temp->keyword);
        }
    }
    return root;
}

void search(struct bst *root)
{
    char key[10];
    printf("\nEnter the keyword to search: ");
    scanf("%s", &key);
    struct bst *temp = root;
    int found = 0;

    while (temp != NULL)
    {
        if (strcmp(key, temp->keyword) == 0)
        {
            printf("Found! Meaning: %s\n", temp->meaning);
            found = 1;
            break;
        }
        else if (strcmp(key, temp->keyword) < 0)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (!found)
    {
        printf("Keyword not found!\n");
    }
}

struct bst *copy_tree_recursive(struct bst *root)
{
    if (root == NULL)
        return NULL;

    struct bst *new_node = (struct bst *)malloc(sizeof(struct bst));
    strcpy(new_node->keyword, root->keyword);
    strcpy(new_node->meaning, root->meaning);
    new_node->left = copy_tree_recursive(root->left);
    new_node->right = copy_tree_recursive(root->right);
    return new_node;
}

struct bst *copy_tree_non_recursive(struct bst *root)
{
    if (root == NULL)
        return NULL;

    struct bst *new_root = (struct bst *)malloc(sizeof(struct bst));
    strcpy(new_root->keyword, root->keyword);
    strcpy(new_root->meaning, root->meaning);
    new_root->left = NULL;
    new_root->right = NULL;

    struct bst *stack[100];
    struct bst *nodes_stack[100];
    int top = -1;

    stack[++top] = root;
    nodes_stack[top] = new_root;

    while (top != -1)
    {
        struct bst *node = stack[top];
        struct bst *new_node = nodes_stack[top--];

        if (node->left != NULL)
        {
            new_node->left = (struct bst *)malloc(sizeof(struct bst));
            strcpy(new_node->left->keyword, node->left->keyword);
            strcpy(new_node->left->meaning, node->left->meaning);
            new_node->left->left = NULL;
            new_node->left->right = NULL;
            stack[++top] = node->left;
            nodes_stack[top] = new_node->left;
        }

        if (node->right != NULL)
        {
            new_node->right = (struct bst *)malloc(sizeof(struct bst));
            strcpy(new_node->right->keyword, node->right->keyword);
            strcpy(new_node->right->meaning, node->right->meaning);
            new_node->right->left = NULL;
            new_node->right->right = NULL;
            stack[++top] = node->right;
            nodes_stack[top] = new_node->right;
        }
    }

    return new_root;
}

void mirror_recursive(struct bst *root)
{
    if (root == NULL)
        return;
    struct bst *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror_recursive(root->left);
    mirror_recursive(root->right);
}

void mirror_non_recursive(struct bst *root)
{
    if (root == NULL)
        return;
    struct bst *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front != rear)
    {
        struct bst *node = queue[front++];
        struct bst *temp = node->left;
        node->left = node->right;
        node->right = temp;

        if (node->left != NULL)
            queue[rear++] = node->left;
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
}

int main()
{
    struct bst *root = (struct bst *)malloc(sizeof(struct bst));
    printf("\nEnter key & meaning for root:\n");
    scanf("%s %s", root->keyword, root->meaning);
    root->left = NULL;
    root->right = NULL;

    create(root);

    int option;
    char key[10];
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Display Tree\n");
        printf("2. Search a Keyword\n");
        printf("3. Delete a Keyword\n");
        printf("4. Copy Tree (Recursive)\n");
        printf("5. Copy Tree (Non-Recursive)\n");
        printf("6. Mirror Tree (Recursive)\n");
        printf("7. Mirror Tree (Non-Recursive)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            display(root);
            break;
        case 2:
            search(root);
            break;
        case 3:
            printf("Enter the keyword to delete: ");
            scanf("%s", key);
            root = delete_node(root, key);
            printf("Node deleted.\n");
            break;
        case 4:
        {
            struct bst *new_tree = copy_tree_recursive(root);
            printf("Tree copied successfully (recursive). Displaying copied tree (inorder):\n");
            inorder(new_tree);
            free(new_tree);
            break;
        }
        case 5:
        {
            struct bst *new_tree = copy_tree_non_recursive(root);
            printf("Tree copied successfully (non-recursive). Displaying copied tree (inorder):\n");
            inorder(new_tree);
            free(new_tree);
            break;
        }
        case 6:
            mirror_recursive(root);
            printf("Tree mirrored recursively.\n");
            break;
        case 7:
            mirror_non_recursive(root);
            printf("Tree mirrored non-recursively.\n");
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
