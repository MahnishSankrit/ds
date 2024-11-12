#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct treenode {
    char data;
    struct treenode* left;
    struct treenode* right;
};

struct treenode* stack[STACK_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(struct treenode* node) {
    if (top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = node;
}

struct treenode* pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack[top--];
}

struct treenode* createNode(char data) {
    struct treenode* newNode = (struct treenode*)malloc(sizeof(struct treenode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void create_r(struct treenode* temp) {
    char ch;

    printf("Do you want to add a left child to %c? (y/n): ", temp->data);
    scanf(" %c", &ch);
    if (ch == 'y') {
        char data;
        printf("Enter data for left child: ");
        scanf(" %c", &data);
        struct treenode* current = createNode(data);
        temp->left = current;
        create_r(current);
    }

    printf("Do you want to add a right child to %c? (y/n): ", temp->data);
    scanf(" %c", &ch);
    if (ch == 'y') {
        char data;
        printf("Enter data for right child: ");
        scanf(" %c", &data);
        struct treenode* current = createNode(data);
        temp->right = current;
        create_r(current);
    }
}

void inorder_r(struct treenode* root) {
    if (root != NULL) {
        inorder_r(root->left);
        printf("%c ", root->data);
        inorder_r(root->right);
    }
}

void preorder_r(struct treenode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder_r(root->left);
        preorder_r(root->right);
    }
}

void postorder_r(struct treenode* root) {
    if (root != NULL) {
        postorder_r(root->left);
        postorder_r(root->right);
        printf("%c ", root->data);
    }
}

void inorder_nr(struct treenode* root) {
    struct treenode* temp = root;

    while (1) {
        while (temp != NULL) {
            push(temp);
            temp = temp->left;
        }
        if (isEmpty()) {
            break;
        }
        temp = pop();
        printf("%c ", temp->data);
        temp = temp->right;
    }
}

void preorder_nr(struct treenode* root) {
    struct treenode* temp = root;
    while (1) {
        while (temp != NULL) {
            printf("%c ", temp->data);
            push(temp);
            temp = temp->left;
        }
        if (isEmpty()) {
            break;
        }
        temp = pop();
        temp = temp->right;
    }
}

void postorder_nr(struct treenode* root) {
    struct treenode* temp = root;

    while (1) {
        while (temp != NULL) {
            push(temp);
            temp = temp->left;
        }
        if (stack[top]->right == NULL) {
            temp = pop();
            printf(" %c", temp->data);
        }
        while ((!isEmpty()) && (stack[top]->right == temp)) {
            temp = pop();
            printf(" %c", temp->data);
        }
        temp = stack[top]->right;
    }
}

void create_nr() {  
    char data;
    int cont;

    struct treenode* root = NULL;
    struct treenode* temp = NULL;

    printf("Enter data for root of the non-recursive tree: ");
    scanf(" %c", &data);
    root = createNode(data);
    temp = root;

    do {
        printf("Enter data for current node: ");
        scanf(" %c", &data);
        struct treenode *curr = createNode(data);

        while (1) {
            printf("Do you want to add to the left (l) or right (r) of node %c? ", temp->data);
            char b;
            scanf(" %c", &b);

            if (b == 'l') {
                if (temp->left == NULL) {
                    temp->left = curr;
                    break;
                }
                temp = temp->left;
            } else if (b == 'r') {
                if (temp->right == NULL) {
                    temp->right = curr;
                    break;
                }
                temp = temp->right;
            } else {
                printf("Invalid input. Please enter 'l' or 'r'.\n");
            }
        }

        printf("To continue inserting, enter 5: ");
        scanf("%d", &cont);
    } while (cont == 5);

    printf("\nIn-order traversal (non-recursive): ");
    inorder_nr(root);
    printf("\nPre-order traversal (non-recursive): ");
    preorder_nr(root);
    printf("\nPost-order traversal (non-recursive): ");
    postorder_nr(root);
}

int main() {
    struct treenode* root = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create tree recursively\n");
        printf("2. Create tree non-recursively\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char rootData;
                    printf("Enter data for root: ");
                    scanf(" %c", &rootData);

                    root = createNode(rootData);
                    create_r(root);
                    printf("\nIn-order traversal (recursive): ");
                    inorder_r(root);
                    printf("\nPre-order traversal (recursive): ");
                    preorder_r(root);
                    printf("\nPost-order traversal (recursive): ");
                    postorder_r(root);
                }
                break;
            case 2:
                create_nr();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
