#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} node;

int length(node* head) {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

char* toCString(node* head) {
    int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    int i = 0;
    node* current = head;
    while (current != NULL) {
        str[i] = current->data;
        i++;
        current = current->next;
    }
    str[i] = '\0';  // Add null terminator at the end
    return str;
}

void insertChar(node** pHead, char c) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = c;
    newNode->next = NULL;

    if (*pHead == NULL) {
        *pHead = newNode;
    } else {
        node* current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteList(node** pHead) {
    node* current = *pHead;
    while (current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }
    *pHead = NULL;
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int numStrings;
    fscanf(file, "%d", &numStrings);

    for (int i = 0; i < numStrings; i++) {
        int stringLength;
        fscanf(file, "%d", &stringLength);

        node* head = NULL;

        for (int j = 0; j < stringLength; j++) {
            char c;
            fscanf(file, " %c", &c);
            insertChar(&head, c);
        }

        char* str = toCString(head);
        printf("%s\n", str);
        free(str);

        deleteList(&head);
    }

    fclose(file);
    return 0;
}
