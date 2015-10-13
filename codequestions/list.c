// list.c

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list_node *list_create(int val) {
	struct list_node* head = (struct list_node*)malloc(sizeof(struct list_node));
		    
    head->val = val;
    head->next = NULL;
	return head;
}

int list_prepend(struct list_node **list, int val) {
	if (*list == NULL) {
		return 0;
	}

	struct list_node *newNode = (struct list_node*)malloc(sizeof(struct list_node));
	newNode->val = val;
	newNode->next = *list;
	*list = newNode;

	return 1;
}

int list_append(struct list_node *list, int val) {
	if (list == NULL) {
		return 0;
	}

	struct list_node *curr = list;

	struct list_node *newNode = (struct list_node*)malloc(sizeof(struct list_node));
	newNode->val = val;
	newNode->next = NULL;

	struct list_node *currNode = list;
	int len = 1;

	while(currNode->next != NULL) {
		len++;
		currNode = currNode->next;
	}

	currNode->next = newNode;
	return ++len;
}

int list_remove_at(struct list_node **list, int index) {
	if (*list == NULL || index < 0) {
		return 0;
	}

	struct list_node *curr = *list;

	if (index == 0) {
		*list = (*list)->next;
		free(curr);
	} else {
		for (int n = 0; n < index - 1; n++) {
			if (curr->next == NULL) {
				return 0;
			}

			curr = curr->next;
		}

		struct list_node *tmp = curr->next;
		curr->next = tmp->next;
		free(tmp);
	}

	return 1;
}

void list_free(struct list_node **list) {
	struct list_node *curr = *list;
	struct list_node *next = NULL;

	while(curr != NULL) {
		printf("Deallocating node with value %d\n", curr->val);
		next = curr->next;
		free(curr);
		curr = next;
	}

	*list = NULL;
} 

int list_size(struct list_node *list) {
	if (list == NULL) {
		return 0;
	}

	struct list_node *currNode = list;
	int len = 1;

	while(currNode->next != NULL) {
		len++;
		currNode = currNode->next;
	}

	return len;
}

int list_size_recursive(struct list_node *list) {
	return(list == NULL ? 0 : 1 + list_size_recursive(list->next));
}

int list_contains(struct list_node *list, int searchVal) {
	struct list_node *curr = list;

	while (curr != NULL) {
		if (curr->val == searchVal) {
			return 1;
		}
		curr = curr->next;
	}

	return 0;
}

void list_print(struct list_node *list) {
	if (list == NULL) {
		printf("Empty list.\n");
	} else {
		struct list_node *currNode = list;
		do {
			printf("%d ", currNode->val);
			currNode = currNode->next;
		} while(currNode != NULL);
		printf("\n");
	}
}