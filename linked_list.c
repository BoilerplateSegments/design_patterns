/* =========================

Complie & run with:
gcc -o linked_list linked_list.c -std=c11 && ./linked_list

DesierdL output:
0 1 2 3 4 5 6 7 8 9 10 

========================= */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void printList(struct Node *node)
{
	// Linked List Traversal
	while (node != NULL) {
		printf("%d \n", node->data);
		node = node->next;
	}
}

int main(int argc, char const *argv[])
{
	int nsize = sizeof(struct Node);

	struct Node *mptr[10];

	struct Node *temp = NULL;

	mptr[0] = (struct Node *)malloc(nsize);
	mptr[0]->data = 0;

	for (int i = 1; i <= 10; i++) {
		mptr[i] = (struct Node *)malloc(nsize);
		mptr[i]->data = i;
		mptr[i - 1]->next = mptr[i];
	}

	printList(*mptr);

	return 0;
}
