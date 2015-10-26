// main.c

#include <stdio.h>
#include "list.h"

int main(int argc, char **argv) {
    struct list_node *myList = NULL;
    int listSize = 0;

    /* First demo - using list_create */
    printf("\nBuild a basic list of integers.\n");
    myList = list_create(5);
    if (myList) {
    	list_print(myList);
    	printf("List size: %d\n", list_size(myList));
    	listSize = list_append(myList, 6);
    	list_print(myList);
    	printf("List size: %d\n", listSize);
    	listSize = list_append(myList, 7);
    	list_print(myList);
    	printf("List size: %d\n", listSize);

    	printf("\nTry some list_contains tests.\n");
    	if (list_contains(myList, 6)) {
    		printf("List contains 6\n");
    	} else {
    		printf("ERROR: List does not contain 6?\n");
    	}

    	if (list_contains(myList, 7)) {
    		printf("List contains 7\n");
    	} else {
    		printf("ERROR: List does not contain 7?\n");
    	}

    	if (list_contains(myList, 99)) {
    		printf("ERROR: List contains 99?\n");
    	} else {
    		printf("List does not contain 99.\n");
    	}

    	printf("\nTry some list_remove_at tests.\n");
    	if (list_remove_at(&myList, 1)) {
    		list_print(myList);
    		printf("List size: %d\n", list_size(myList));
    	} else {
    		printf("ERROR: Failed to remove element at index 1.\n");
    	}

    	if (list_remove_at(&myList, 99)) {
    		printf("ERROR: Attempt to remove element at index 99 did not report an error.\n");
    	} else {
    		printf("No item at index 99, so nothing removed.\n");
    		list_print(myList);
    		printf("List size: %d\n", list_size(myList));
    	}

    	printf("\nAdd another item back into the list.\n");
    	listSize = list_append(myList, 6);
    	list_print(myList);
    	printf("List size: %d\n", list_size(myList));

    	printf("\nAttempting to remove head item.\n");
    	if (list_remove_at(&myList, 0)) {
    		list_print(myList);
    		printf("List size: %d\n", list_size(myList));
    	} else {
    		printf("Failed to remove element at index 0.\n");
    	}

    	printf("\nAttempting to prepend 8 to front of list.\n");
    	if (list_prepend(&myList, 8)) {
    		list_print(myList);
    		printf("List size: %d\n", list_size(myList));
    	} else {
    		printf("Failed to prepend 8 to front of list!\n");
    	}

    	printf("\nComparing list_size and list_size_recursive.\n");
    	printf("List size: %d\n", list_size(myList));
    	printf("List size recursive method: %d\n", list_size_recursive(myList));

    	printf("\nAttempting to deallocate myList memory.\n");
    	list_free(&myList);
    	if (myList) {
    		printf("Failed to clean up myList properly.\n");
    	} else {
    		printf("Cleaned up myList successfully.\n");
    	}

		printf("\nBuild a list of integers to test recursive insert after.\n");
		myList = list_create(1);
		list_append(myList, 2);
		list_append(myList, 3);
		list_append(myList, 4);
		list_print(myList);
		printf("\nNow recursively adding 5 after 3...\n");
		list_insert_after_recursive(&myList, 3, 5);
		list_print(myList);
		printf("\nNow recursively adding 7 after 99 should do nothing as no 99.\n");
		list_insert_after_recursive(&myList, 99, 7);
		list_print(myList);
    } else {
    	printf("Error creating myList.\n");
    }

    return 1;
}
