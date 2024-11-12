#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[10];
    char pos;
    int id;
    struct node *next;
};

void create(struct node *head)
{
    struct node *temp = head;
    char choice;
    do
    {
        struct node *curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the name, id and position: \n");
        scanf("%s%d %c", curr->name, &curr->id, &curr->pos);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;
        printf("Do you want to continue: \n Y for yes & N for no\n");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

int display(struct node *head)
{
    int count = 0;
    if (head->next == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        struct node *curr = head->next;
        while (curr != NULL)
        {
            count++;
            printf("%s %d %c\n", curr->name, curr->id, curr->pos);
            curr = curr->next;
        }
    }
    printf("Length of the linked list is %d\n", count);
    return count;
}

void insertbypos(struct node *head, int count)
{
    int i = 1;
    int pos;
    struct node *curr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the name, id and position for the new node: \n");
    scanf("%s%d %c", newnode->name, &newnode->id, &newnode->pos);
    printf("Enter the position where you would like to insert the new node: \n");
    scanf("%d", &pos);

    if (pos > count + 1)
    {
        printf("Data cannot be inserted\n");
    }
    else
    {
        while (curr != NULL && i < pos)
        {
            i++;
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
    display(head);
}

void deletebypos(struct node *head, int count)
{
    struct node *previous = head;
    struct node *curr = head->next;
    int ctr = 1;
    int pos;
    printf("Enter the position from where you would like to delete the node: \n");
    scanf("%d", &pos);
    if (count < pos)
    {
        printf("Position exceeds the length of the list. Data cannot be deleted\n");
    }
    else
    {
        while (ctr < pos && curr != NULL)
        {
            ctr++;
            previous = curr;
            curr = curr->next;
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = curr;
        previous->next = curr->next;
        curr->next = NULL;
        free(temp);
    }
    display(head);
}

void reverse(struct node *head)
{
    struct node *previous = NULL;
    struct node *curr = head->next;
    while (curr != NULL)
    {
        struct node *future = (struct node *)malloc(sizeof(struct node));
        future = curr->next;
        curr->next = previous;
        previous = curr;
        curr = future;
    }
    head->next = previous;
    printf("Reversed list is: \n");
    display(head);
}

void sortlist(struct node *head, int count)
{
    struct node *previous = (struct node *)malloc(sizeof(struct node));
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    for (int i = 1; i < count - 1; i++)
    {
        previous = head;
        curr = head->next;
        for (int j = 0; j < count - 1; j++)
        {
            temp = curr->next;
            if (curr->id > temp->id)
            {
                previous->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                previous = temp;
            }
            else
            {
                previous = curr;
                curr = curr->next;
            }
        }
    }
    printf("The sorted list is: \n");
    display(head);
}

void mergelist(struct node *head, struct node *head1)
{
    int flag;
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    struct node *curr1 = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    curr = head->next;
    curr1 = head1->next;
    if (curr->id < curr1->id)
    {
        temp = head;
        flag = 1;
    }
    else
    {
        temp = head1;
        flag = 0;
    }
    while (curr != NULL && curr1 != NULL)
    {
        if (curr->id < curr1->id)
        {
            temp->next = curr;
            temp = curr;
            curr = curr->next;
        }
        else
        {
            temp->next = curr1;
            temp = curr1;
            curr1 = curr1->next;
        }
    }
    if (curr == NULL)
        temp->next = curr1;
    if (curr1 == NULL)
        temp->next = curr;
    if (flag == 1)
        display(head);
    if (flag == 0)
        display(head1);
}

void copylist(struct node *head, struct node *head1)
{
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    struct node *curr1 = (struct node *)malloc(sizeof(struct node));
    curr = head->next;
    head1 = head;
    while (curr != NULL)
    {
        curr1 = curr;
        curr = curr->next;
    }
    printf("The copied list is:\n");
    display(head1);
}

int main()
{
    int choice;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    head1->next = NULL;
    create(head);
    int count = display(head);
    int count1 = display(head1);
    do
    {
        printf("Select the operation to be performed on the linked list:\n1. Insert a new node\n2. Delete an existing node\n3. Reverse \n4. Copy the linked list\n5. Sort the linked list\n6. Merge two linked lists with sorting\n7. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertbypos(head, count);
            break;
        case 2:
            deletebypos(head, count);
            break;
        case 3:
            reverse(head);
            break;
        case 4:
            copylist(head, head1);
            break;
        case 5:
            sortlist(head, count);
            break;
        case 6:
            create(head1);
            sortlist(head, count);
            sortlist(head1, count1);
            mergelist(head, head1);
            break;
        case 7:
            printf("exit \n");
            break;
        default:
            printf("Invalid choice! \n");
        }
    } while (choice != 7);
}
