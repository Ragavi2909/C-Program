#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("Node with data %d inserted as the head.\n", data);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node with data %d inserted at the end.\n", data);
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with data %d deleted.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not found
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", key);
}

// Function to traverse the linked list from head to tail
void traverseFromToLast(struct Node* head) {
    printf("Linked List (Head to Tail): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Helper function to print the linked list in reverse
void printReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printReverse(head->next);
    printf("%d -> ", head->data);
}

// Function to traverse the linked list from tail to head
void traverseLastToFirst(struct Node* head) {
    printf("Linked List (Tail to Head): ");
    printReverse(head);
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Traverse from head to tail\n");
        printf("4. Traverse from tail to head\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        fflush(stdout);  // Ensure prompt is displayed immediately
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                fflush(stdout);
                scanf("%d", &value);
                insertNode(&head, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                fflush(stdout);
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                traverseFromToLast(head);
                break;
            case 4:
                traverseLastToFirst(head);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}