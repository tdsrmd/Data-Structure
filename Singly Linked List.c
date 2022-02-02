#include "stdio.h"
#include "stdlib.h"

struct node {
  int data;
  struct node *next;
};
struct node *head = NULL;

void insertBeg() {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  printf("Enter value:");
  int num;
  scanf_s("%d", &num);
  newNode->data = num;
  if (head == NULL) {
    newNode->next = NULL;
    head = newNode;
    printf("\nNode created \n\n");
  } else {
    newNode->next = head;
    head = newNode;
    printf("\nNode added \n\n");
  }
}
void insertEnd() {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  printf("Enter value:");
  int num;
  scanf_s("%d", &num);
  newNode->data = num;
  if (head == NULL) {
    newNode->next = NULL;
    head = newNode;
    printf("\nNode created \n\n");
  } else {
    struct node *key = head;
    while (key->next != NULL) {
      key = key->next;
    }
    key->next = newNode;
    newNode->next = NULL;
    printf("\nNode added \n\n");
  }
}
void deleteBeg() {
  if (head == NULL) {
    printf("\nList is empty\n\n");
  } else {
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("\nNode deleted from the beginning\n\n");
  }
}
void deleteEnd() {
  if (head == NULL) {
    printf("\nList is empty\n\n");
  } else if (head->next == NULL) {
    head = NULL;
    free(head);
    printf("\nDeleted a single node of the list\n\n");
  } else {
    struct node *key = head;
    while (key->next->next != NULL) {
      key = key->next;
    }
    free(key->next);
    key->next = NULL;
    printf("\nNode deleted from the last\n\n");
  }
}
void display() {
  if (head == NULL) {
    printf("\nList is Empty\n\n");
  } else {
    struct node *key = head;
    printf("\nNodes\n");
    while (key != NULL) {
      printf("%d ", key->data);
      key = key->next;
    }
    printf("\n\n");
  }
}

int main() {
  int option;
  do {
    printf("1-Insert Beg \n");
    printf("2-Insert End \n");
    printf("3-Delete Beg \n");
    printf("4-Delete End \n");
    printf("5-Display \n");
    printf("6-Exit \n");
    printf("Enter value:");
    scanf_s("%d", &option);
    switch (option) {
    case 1:
      insertBeg();
      break;
    case 2:
      insertEnd();
      break;
    case 3:
      deleteBeg();
      break;
    case 4:
      deleteEnd();
      break;
    case 5:
      display();
      break;
    }

  } while (option != 6);
  return 0;
}
