#include <stdio.h>
#include <stdlib.h>

struct Product {
    int productID;
    char productName[50];
    double price;
    int quantity;
};

struct node {
    struct Product data;
    struct node *next;
};

struct node *head;

void insertSubMenu();
void deleteSubMenu();
void beginsert();
void lastinsert();
void begin_delete();
void last_delete();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 7) {
        printf("\n***Main Menu***\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert\n2.Delete\n3.Search for an element\n4.Show\n5.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertSubMenu();
                break;
            case 2:
                deleteSubMenu();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice..\n");
        }
    }
    return 0;
}

void insertSubMenu() {
    int insertChoice = 0;
    printf("\nChoose one option for insertion ...\n");
    printf("1.Insert at beginning\n2.Insert at end\n");
    printf("Enter your choice?\n");
    scanf("%d", &insertChoice);

    switch (insertChoice) {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        default:
            printf("Invalid choice for insertion.\n");
    }
}

void deleteSubMenu() {
    int deleteChoice = 0;
    printf("\nChoose one option for deletion ...\n");
    printf("1.Delete from beginning\n2.Delete from end\n");
    printf("Enter your choice?\n");
    scanf("%d", &deleteChoice);

    switch (deleteChoice) {
        case 1:
            begin_delete();
            break;
        case 2:
            last_delete();
            break;
        default:
            printf("Invalid choice for deletion.\n");
    }
}

void beginsert() {
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter the Product data:\n");
        printf("Product ID: ");
        scanf("%d", &ptr->data.productID);
        printf("Product Name: ");
        scanf("%s", ptr->data.productName);
        printf("Price: ");
        scanf("%lf", &ptr->data.price);
        printf("Quantity: ");
        scanf("%d", &ptr->data.quantity);

        if (head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nNode inserted at the beginning\n");
    }
}

void lastinsert() {
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter Product data:\n");
        printf("Product ID: ");
        scanf("%d", &ptr->data.productID);
        printf("Product Name: ");
        scanf("%s", ptr->data.productName);
        printf("Price: ");
        scanf("%lf", &ptr->data.price);
        printf("Quantity: ");
        scanf("%d", &ptr->data.quantity);

        if (head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
        printf("\nNode inserted at the end\n");
    }
}

void begin_delete() {
    struct node *ptr;
    if (head == NULL) {
        printf("\nUNDERFLOW");
    } else if (head->next == head) {
        head = NULL;
        free(head);
        printf("\nNode deleted from the beginning\n");
    } else {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nNode deleted from the beginning\n");
    }
}

void last_delete() {
    struct node *ptr, *preptr;
    if (head == NULL) {
        printf("\nUNDERFLOW");
    } else if (head->next == head) {
        head = NULL;
        free(head);
        printf("\nNode deleted from the end\n");
    } else {
        ptr = head;
        while (ptr->next != head) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nNode deleted from the end\n");
    }
}

void search() {
    struct node *ptr;
    int id, flag = 0;
    ptr = head;
    if (ptr == NULL) {
        printf("\nEmpty List\n");
    } else {
        printf("\nEnter ID which you want to search?\n");
        scanf("%d", &id);
        if (head->data.productID == id) {
            printf("Item found\n");
            flag = 1;
        } else {
            while (ptr->next != head) {
                if (ptr->data.productID == id) {
                    printf("Item found\n");
                    flag = 1;
                    break;
                }
                ptr = ptr->next;
            }
        }
        if (flag == 0) {
            printf("Item not found\n");
        }
    }
}

void display() {
    struct node *ptr;
    ptr = head;
    if (head == NULL) {
        printf("\nNothing to print\n");
    } else {
        printf("\nPrinting values...\n");
        do {
            printf("Product ID: %d, Product Name: %s, Price: %.2lf, Quantity: %d\n",
                   ptr->data.productID, ptr->data.productName, ptr->data.price, ptr->data.quantity);
            ptr = ptr->next;
        } while (ptr != head);
    }
}
