#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
	struct node* prev;
}Node;

void add_node(Node** start, int value);
void print_list(Node* node);
void inverse_print_list(Node* node);
void free_list(Node* node);

int main(int argc, char* argv[])
{
	// create first node "head"
	Node* head = NULL;
	add_node(&head, 5);
	add_node(&head, 128);
	add_node(&head, 41);

	print_list(head);

	Node* last = head;
	while (last->next != NULL) {
		last = last->next;
	}
	inverse_print_list(last);

	free_list(head);

	return 0;
}

void add_node(Node** start, int value)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*start == NULL) {
		*start = new_node;
		return;
	}
	else {
		Node* current;
		current = *start;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
		return;
	}
}

void print_list(Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void inverse_print_list(Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->prev;
	}
	printf("\n");
}

void free_list(Node* node)
{
	Node* current, * temp;
	current = node;
	while (current != NULL) {
		temp = current;
		current = current->next;
		free(temp);
	}
}