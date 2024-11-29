#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert_beg();
void insert_end();
void insert_pos();
void display();
int count_node();

void delete_beg();
void delete_end();
void delete_pos();

Node *create_node();

void main() {
    int item, ch, ch1;
    
    do {
        printf("\n---Main Menu---\n\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at a particular position\n4.Go to main menu");
                printf("\n\nEnter your choice : ");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1: insert_beg(); break;
                    case 2: insert_end(); break;
                    case 3: insert_pos(); break;
                    case 4: break;
                    default: printf("Invalid choice");
                }
                break;
            case 2: 
                printf("\n1.Delete at beginning\n2.Delete at end\n3.Delete at a particular position\n4.Go to main menu");
                printf("\nEnter your choice : ");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1: delete_beg(); break;
                    case 2: delete_end(); break;
                    case 3: delete_pos(); break;
                    case 4: break;
                    default: printf("Invalid choice");
                }
                break;
            case 3: 
                display(); 
                break;
            case 4: 
                exit(0); 
                break;
            default: 
                printf("\nInvalid choice");
        }
    } while (ch < 5 && ch > 0);
}

void insert_beg() {
    Node *ptr = create_node();
    if (ptr != NULL) {
        ptr->next = head;
        head = ptr;
    }
}

void insert_end() {
    Node *temp = head;
    Node *ptr = create_node();
    if (head == NULL) {
        printf("\nList is empty\n");
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL) {
            while (temp->next->next != NULL)
                temp = temp->next;
        }
        temp->next = ptr;
    }
}

void insert_pos() {
    int count = count_node(), p, i;
    Node *ptr, *temp;
    if (head != NULL) {
        printf("\nEnter the position to insert node : ");
        scanf("%d", &p);
        if (p > 0 && p < count) {
            i = 1;
            temp = head;
            while (i <= p - 1) {
                temp = temp->next;
                i++;
            }
        } else {
            printf("Invalid position\n");
            return;
        }
        ptr = create_node();
        if (ptr != NULL) {
            ptr->next = temp->next;
            temp->next = ptr;
        }
    } else {
        printf("\nList is empty\n");
    }
}

int count_node() {
    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display() {
    printf("\nDISPLAY\n");
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node *create_node() {
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL) {
        printf("\nOverflow memory not allocated");
    } else {
        printf("\nEnter data value : ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
    }
    return ptr;
}

void delete_beg() {
    if (head == NULL)
        printf("\nList is empty, nothing to delete\n");
    else {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("\nNode deleted from beginning\n");
    }
}

void delete_end() {
    if (head == NULL)
        printf("\nList is empty, nothing to delete\n");
    else {
        Node *temp = head;
        if (temp->next == NULL) {
            free(head);
            head = NULL;
            printf("\nNode deleted from end\n");
            return;
        }
        while (temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
        printf("\nNode deleted from end\n");
    }
}

void delete_pos() {
    int count = count_node(), p;
    if (head != NULL) {
        printf("\nEnter the position to delete node (1 to %d): ", count);
        scanf("%d", &p);
        if (p < 1 || p > count) {
            printf("Invalid position\n");
            return;
        } else {
            Node *temp = head;
            if (p == 1) {
                head = head->next;
                free(temp);
            } else {
                for (int i = 1; i < p - 1; i++)
                    temp = temp->next;
                Node *node_to_delete = temp->next;
                temp->next = node_to_delete->next;
                free(node_to_delete);
            }
            printf("\nNode deleted from position %d\n", p);
        }
    } else
        printf("\nList is empty\n");
}
