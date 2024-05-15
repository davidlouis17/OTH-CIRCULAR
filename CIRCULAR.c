#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    if (head != NULL) {
        do {
            printf("Address: %p, Data: %d\n", (void*)temp, temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

void sortList(Node** head) {
    if (*head == NULL) return;
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int tempData = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = tempData;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    int N;
    scanf("%d", &N);

    Node* head = NULL;

    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Before sorting:\n");
    printList(head);

    sortList(&head);

    printf("After sorting:\n");
    printList(head);

    return 0;
}
