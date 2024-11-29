#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL;
Node *create_node();

void insert_beg();
void insert_end();
void insert_pos();
void display_forward();
void display_backward();
int count_node();
void delete_beg();
void delete_end();
void delete_pos();

int main() {
    int ch, ch1;

    do {
        printf("\n---Main Menu---\n\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at a particular position\n4. Go to main menu");
                printf("\n\nEnter your choice: ");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1: insert_beg(); break;
                    case 2: insert_end(); break;
                    case 3: insert_pos(); break;
                    case 4: break;
                    default: printf("Invalid choice\n");
                }
                break;
            case 2:
                printf("\n1. Delete at beginning\n2. Delete at end\n3. Delete at a particular position\n4. Go to main menu");
                printf("\nEnter your choice: ");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1: delete_beg(); break;
                    case 2: delete_end(); break;
                    case 3: delete_pos(); break;
                    case 4: break;
                    default: printf("Invalid choice\n");
                }
                break;
            case 3:
                printf("\n1. Display in forward order\n2. Display in backward order\n3. Go to main menu");
                printf("\n\nEnter your choice: ");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1: display_forward(); break;
                    case 2: display_backward(); break;
                    case 3: break;
                    default: printf("Invalid choice\n");
                }
                break;
            case 4: exit(0);
            default: printf("\nInvalid choice\n");
        }
    } while (ch < 5 && ch > 0);

    return 0;
}

void insert_beg() {
    Node *ptr = create_node();
    if (ptr != NULL) {
        if (head != NULL) {
            head->prev = ptr;
        }
        ptr->next = head;
        head = ptr;
    }
}

void insert_end() {
    Node *ptr = create_node();
    if (ptr != NULL) {
        if (head == NULL)
            head = ptr;
        else {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = ptr;
            ptr->prev = temp;
        }
    }
}

void insert_pos() {
    int count = count_node(), p, i;
    Node *ptr, *temp;
    if (head != NULL) {
        printf("\nEnter the position to insert node (1 to %d): ", count + 1);
        scanf("%d", &p);
        if (p > 0 && p <= count + 1) {
            ptr = create_node();
            if (ptr != NULL) {
                if (p == 1) {
                    ptr->next = head;
                    if (head != NULL)
                        head->prev = ptr;
                    head = ptr;
                } else {
                    temp = head;
                    for (i = 1; i < p - 1; i++)
                        temp = temp->next;
                    ptr->next = temp->next;
                    if (temp->next != NULL)
                        temp->next->prev = ptr;
                    temp->next = ptr;
                    ptr->prev = temp;
                }
            }
        } else
            printf("Invalid position\n");
    } else
        printf("\nList is empty\n");
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

void delete_beg() {
    if (head == NULL)
        printf("\nList is empty, nothing to delete\n");
    else {
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
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
        } else {
            while (temp->next != NULL)
                temp = temp->next;
            temp->prev->next = NULL;
            free(temp);
            printf("\nNode deleted from end\n");
        }
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
                if (head != NULL) {
                    head->prev = NULL;
                }
                free(temp);
            } else {
                for (int i = 1; i < p - 1; i++) {
                    temp = temp->next;
                }
                Node *node_to_delete = temp->next;
                if (node_to_delete != NULL) {
                    temp->next = node_to_delete->next;
                    if (node_to_delete->next != NULL)
                        node_to_delete->next->prev = temp;
                    free(node_to_delete);
                }
            }
            printf("\nNode deleted from position %d\n", p);
        }
    } else
        printf("\nList is empty\n");
}

void display_forward() {
    printf("\nDisplay - Forward\n");
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display_backward() {
    printf("\nDisplay - Backward\n");
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

Node *create_node() {
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL) {
        printf("\nOverflow, memory not allocated\n");
        return NULL;
    } else {
        printf("\nEnter data value: ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    return ptr;
}
