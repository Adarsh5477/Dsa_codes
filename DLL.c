#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int productID;
    char productName[50];
    double price;
    int quantity;
};

struct node {
    struct node *prev;
    struct node *next;
    struct Product data;
};

struct node *head;

void insertion_menu();
void deletion_menu();
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();

void main() {
    int choice = 0;
    while (choice != 5) {
        printf("\n***Main Menu***\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Show\n5. Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertion_menu();
                break;
            case 2:
                deletion_menu();
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
}

void insertion_menu() {
    int choice = 0;
    while (choice != 4) {
        printf("\n***Insertion Menu***\n");
        printf("1. Insert at the Beginning\n2. Insert at the End\n3. Insert at a Specific Position\n4. Back to Main Menu\n");
        printf("Enter your choice?\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                insertion_specified();
                break;
            case 4:
                break;
            default:
                printf("Please enter a valid choice..\n");
        }
    }
}

void deletion_menu() {
    int choice = 0;
    while (choice != 4) {
        printf("\n***Deletion Menu***\n");
        printf("1. Delete from the Beginning\n2. Delete from the End\n3. Delete at a Specific Position\n4. Back to Main Menu\n");
        printf("Enter your choice?\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                deletion_beginning();
                break;
            case 2:
                deletion_last();
                break;
            case 3:
                deletion_specified();
                break;
            case 4:
                break;
            default:
                printf("Please enter a valid choice..\n");
        }
    }
}

void insertion_beginning() {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter Product details:\n");
        printf("Product ID: ");
        scanf("%d", &ptr->data.productID);
        printf("Product Name: ");
        scanf("%s", ptr->data.productName);
        printf("Price: ");
        scanf("%lf", &ptr->data.price);
        printf("Quantity: ");
        scanf("%d", &ptr->data.quantity);

        if (head == NULL) {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        } else {
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
}

void insertion_last() {
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter Product details:\n");
        printf("Product ID: ");
        scanf("%d", &ptr->data.productID);
        printf("Product Name: ");
        scanf("%s", ptr->data.productName);
        printf("Price: ");
        scanf("%lf", &ptr->data.price);
        printf("Quantity: ");
        scanf("%d", &ptr->data.quantity);

        if (head == NULL) {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
        printf("\nNode inserted\n");
    }
}

void insertion_specified() {
    struct node *ptr, *temp;
    int loc, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\n OVERFLOW");
    } else {
        temp = head;
        printf("Enter the location");
        scanf("%d", &loc);
        for (i = 0; i < loc; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("\n There are fewer than %d elements", loc);
                return;
            }
        }

        printf("Enter Product details:\n");
        printf("Product ID: ");
        scanf("%d", &ptr->data.productID);
        printf("Product Name: ");
        scanf("%s", ptr->data.productName);
        printf("Price: ");
        scanf("%lf", &ptr->data.price);
        printf("Quantity: ");
        scanf("%d", &ptr->data.quantity);

        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        printf("\nNode inserted\n");
    }
}


void deletion_beginning() {
    struct node *ptr;
    if (head == NULL) {
        printf("\n UNDERFLOW");
    } else if (head->next == NULL) {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    } else {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void deletion_last() {
    struct node *ptr;
    if (head == NULL) {
        printf("\n UNDERFLOW");
    } else if (head->next == NULL) {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void deletion_specified() {
    struct node *ptr, *temp;
    int val;
    printf("\nEnter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while (ptr->data.productID != val)
        ptr = ptr->next;
    if (ptr->next == NULL) {
        printf("\nCan't delete\n");
    } else if (ptr->next->next == NULL) {
        ptr->next = NULL;
    } else {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\nNode deleted\n");
    }
}

void display() {
    struct node *ptr;
    printf("\nPrinting values...\n");
    ptr = head;
    while (ptr != NULL) {
        printf("\nProduct ID: %d\nProduct Name: %s\nPrice: %.2lf\nQuantity: %d\n", ptr->data.productID, ptr->data.productName, ptr->data.price, ptr->data.quantity);
        ptr = ptr->next;
    }
}

void search() {
    struct node *ptr;
    int id, flag = 0;
    ptr = head;
    if (ptr == NULL) {
        printf("\nEmpty List\n");
    } else {
        printf("\nEnter Product ID to search for: ");
        scanf("%d", &id);
        while (ptr != NULL) {
            if (ptr->data.productID == id) {
                printf("\nProduct found:\nProduct ID: %d\nProduct Name: %s\nPrice: %.2lf\nQuantity: %d\n", ptr->data.productID, ptr->data.productName, ptr->data.price, ptr->data.quantity);
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 0) {
            printf("\nProduct not found\n");
        }
    }
}





