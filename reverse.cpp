#include <bits/stdc++.h>

using namespace std;

typedef struct node {
	int key;
	node *next;
} node;

node *createnext(int i) {
	node *temp = new node;
	temp->key = i;
	temp->next = NULL;
	return temp;
}

node *createll() {
	node *root, *temp;

	root = createnext(0);
	temp = root;

	int i;
	for (i = 1; i < 10; i++) {
		temp->next = createnext(i);
		temp = temp->next;
	}

	return root;
}

void recursive(node *root) {
	if (root == NULL) {
		return;
	}

	recursive(root->next);
	cout << root->key;
}

void display(node *root) {
	node *temp = root;
	while (temp != NULL) {
		cout << temp->key <<"\n";
		temp = temp->next;
	}
}

int main() {
	node *root = NULL;
	//root = createnext(0);
	root = createll();


	display(root);
	cout << "printing it in recursive fashion \n";
	recursive(root);
	return 0;
}