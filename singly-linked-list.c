/***********************Linked List*******************************
 * Given a singly linked list and a value to insert, insert a new node caontaining that value at a specific position ( or at the end if no position is specified).
 * 1-->2-->3-->NULL     initial list
 * 1-->2-->3-->4-->NULL insert 4 at the end
 * 1-->2-->5-->3-->NULL insert 5 after 2
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
void insertAtEnd(struct node** head, int newData){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = NULL;

	if(*head == NULL){
		*head = newNode;
		return ;
	}
	struct node* lastNode = *head;
	while(lastNode->next != NULL){
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
}
void printList(struct node* head){
	struct node* temp = head;
	while(temp != NULL){
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
printf("NULL\n");
}
int main(){
	struct node* head = NULL;
	insertAtEnd(&head,1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head,3);

	printf("ORIGINAL LIST:");
	printList(head);
	insertAtEnd(&head,4);
	printf("List after inserting 4 at the end: ");
	printList(head);

	struct node* current = head;
	while(current != NULL){
		struct node* temp = current;
		current = current->next;
		free(temp);
	}
	return 0;
}

