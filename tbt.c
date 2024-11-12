#include <stdio.h>
#include <stdlib.h>

struct tbtnode {
    char data;
    int rbit;
    int lbit;
    struct tbtnode *leftc;
    struct tbtnode *rightc;
};

void create(struct tbtnode *head) {
    struct tbtnode *root = (struct tbtnode *)malloc(sizeof(struct tbtnode));
    printf("Enter root data: ");
    scanf(" %c", &root->data);

    head->lbit = 1;
    root->leftc = root->rightc = head;
    root->lbit = root->rbit = 0;
    head->leftc = root;
    char ch2;
       
    do {
        int flag = 0;
        struct tbtnode *temp = root;
        struct tbtnode *curr = (struct tbtnode *)malloc(sizeof(struct tbtnode));
        printf("Enter current data: ");
        scanf(" %c", &curr->data);
        curr->lbit = curr->rbit = 0;

        while (flag == 0) {
            printf("Enter 'l' for left or 'r' for right to insert: ");
            char ch1;
            scanf(" %c", &ch1);
            
            if (ch1 == 'l') {
                if (temp->lbit == 0) {
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = 1;
                    flag = 1;
                    break;
                } else {
                    temp = temp->leftc;
                }
            }
            
            if (ch1 == 'r') {
                if (temp->rbit == 0) {
                    curr->leftc = temp;
                    curr->rightc = temp->rightc;
                    temp->rightc = curr;
                    temp->rbit = 1;
                    flag = 1;
                    break;
                } else {
                    temp = temp->rightc;
                }
            }
        }
        printf("To continue enter 'Y': ");
        scanf(" %c", &ch2);

    } while (ch2 == 'Y');
}

struct tbtnode *inordersucc(struct tbtnode *temp) {
    struct tbtnode *x = temp->rightc;
    if (temp->rbit == 1) {
        while (x->lbit == 1) {
            x = x->leftc;
        }
    }
    return x;
}

void inorder(struct tbtnode *head) {
    struct tbtnode *temp = head;
    while (1) {
        temp = inordersucc(temp);
        if (temp == head) {
            break;
        }
        printf("%c ", temp->data);
    }
}

void preorder(struct tbtnode *head) {
    struct tbtnode *temp = head->leftc;
    while (temp != head) {
        printf("%c ", temp->data);
        
        while (temp->lbit != 0) {
            temp = temp->leftc;
            printf("%c ", temp->data);
        }
        
        while (temp->rbit == 0 && temp->rightc != head) {
            temp = temp->rightc;
        }
        
        if (temp->rightc != head) {
            temp = temp->rightc;
        } else {
            break;
        }
    }
}

int main(){ //(int argc, char const *argv[]) {
    struct tbtnode *head = (struct tbtnode *)malloc(sizeof(struct tbtnode));
    head->rbit = 1;
    head->lbit = 0;
    head->leftc = head->rightc = head;

    create(head);
    
    int choice;
    printf("Enter 1 for inorder display and 2 for preorder display: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            inorder(head);
            break;
        case 2:
            preorder(head);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
