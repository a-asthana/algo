#include <bits/stdc++.h>

using namespace std;

typedef struct node {
	int key;
	node *left;
	node *right;
} node;

node *newNode (int val) {
	node *temp = new node;
	temp->key = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void maxlevel(node *root, int con[], int len) {
	if (root == NULL) {
		return;
	}
	con[len]++;

	maxlevel(root->left, con, len + 1);
	maxlevel(root->right, con, len + 1);
}


int size (node *root) {
	if (root == NULL) {
		return 0;
	}

	else return (size(root->left) + 1 + size(root->right));
}

int ht (node *root) {
	if (root == NULL) {
		return 0;
	}

	int left_ht = ht(root->left);
	int right_ht = ht(root->right);

	return (max(left_ht, right_ht) + 1);
}

int isBalanced(node *root) {
	
}

void mirror(node *root) {
	if (root == NULL) {
		return;
	}

	mirror(root->left);
	mirror(root->right);

	node *temp = NULL;
	temp = root->left;
	root->left = root->right;
	root->right = temp;

}

void printpath (int path[], int pathlen) {
	for (int i = 0; i < pathlen;i++) {
		cout << path[i] <<" ";
	}
	cout << endl;
}

void printp(node *root, int path[], int pathlen) {
	if (root == NULL) 
		return;

	path[pathlen++] = root->key;

	if ((root->right == NULL) && (root->left == NULL)) {
		printpath(path,pathlen);
	}

	printp(root->left,path, pathlen);
	printp(root->right,path, pathlen);
}


void inorder(node *root) {
	node *temp = root;
	if (temp == NULL) {
		return;
	}

	inorder(temp->left);
	printf("%d \n", temp->key);
	inorder(temp->right);

}


int identical(node *t1, node *t2) {
	if (t1 == NULL && t2 == NULL) {
		return 1;
	}
	else {
		return ((t1->key == t2->key) && (identical(t1->left, t2->left)) && (identical(t1->right, t2->right)));
	}

	return 0;
}

int lev(node *root, int data ,int level) {
	if (root == NULL) {
		return 0;
	}

	if (root->key == data) {
		return level;
	}

 	int levi = lev(root->left,data, level + 1);
 	if (levi != 0) {
 		return levi;
 	}
 	levi = lev(root->right,data, level + 1);
 	return levi;
}

void lot(node *root) {
	queue <node *> q;
	if (root != NULL) {
		q.push(root);
	}
	else 
		return;

	while (!q.empty()) {
		node *temp;
		temp = q.front();
		cout << q.front()->key << endl;
		q.pop();

		if (temp->right != NULL) {
			q.push(temp->right);
		}
		if (temp->left != NULL) {
			q.push(temp->left);
		}
	}
}
bool ident(node *T, node *S) {
	
	if ((T == NULL) && (S == NULL)) 
		return true;
	if ((T == NULL) || (S == NULL))
		return false;

	return ((T->key == S->key) && (ident(T->left, S->left) && (ident(T->right, S->right))));

}

bool subgroup(node *T, node *S) {
	if (T == NULL) {
		return false;
	}
	if (S == NULL) {
		return true;
	}

	if (ident(T, S)) {
		return true;
	}

	return (subgroup(T->left, S) || subgroup(T->right,S));
}


node *LCA (node * root, int n1, int n2) {
	if (root == NULL) {
		return NULL;
	}

	if ((root->key == n1) || (root->key == n2)) {
		return root;
	}

	node *left_lca = LCA(root->left, n1, n2);
	node *right_lca = LCA(root->right, n1, n2);

	if ((left_lca) && (right_lca)) {
		cout << "hi \n";
		return root;
	
	}

	 return ((left_lca != NULL) ? left_lca : right_lca);
	
}

bool ancestors(node *root, int item) {
	if (root == NULL) {
		return false;
	}
	if (root->key == item) {
		return true;
	}

	if (ancestors(root->left, item) || ancestors(root->right,item)) {
		cout <<root->key;
		return true;
	}

	return false;
}

int findmax(node *root) {
	if (root == NULL) {
		return INT_MIN;
	}
	int res = root->key;
	int lmax = findmax(root->left);
	int rmax = findmax(root->right);

	if (res < lmax) {
		res = lmax;
	}
	if (res < rmax) {
		res = rmax;
	}
	return res;
}

bool isFull(node *root) {
	if (root == NULL) {
		return true;
	}
	if ((root->left == NULL) && (root->right == NULL)) {
		return true;
	}

	if ((root->left) && (root->right))
		return (isFull(root->left) && isFull(root->right));

	return false;
}

node *delk(node *root,int k, int level) {
	if (root == NULL) {
		return NULL;
	}

	root->left = delk(root->left,k, level + 1);
	root->right = delk(root->right,k, level + 1);

	if ((root->left == NULL) && (root->right == NULL) && (level < k)) {
		delete root;
		return NULL;
	}

	return root;
}

node *delhalf(node *root) {
	if (root == NULL) {
		return NULL;
	}

	root->left = delhalf(root->left);
	root->right = delhalf(root->right);

	if ((root->right == NULL) && (root->left == NULL))
		return root;

	if (root->right == NULL) {
			node *n = root->left;
			delete root;
			return n;
	}

	if (root->left == NULL) {
		node *n = root->right;
		delete root;
		return n;
	}

	return root;
}
map <int, vector<int> > mp;
map <int, vector<int> >::iterator it;


void vertical(node *root, int ht) {
	if (root == NULL) 
		return;

	//cout << ht <<" " << root->key <<"\n";
	mp[ht].push_back(root->key);

	

	vertical(root->left,ht-1);
	vertical(root->right,ht+1);
}

int main() {
	
	node *root2;

	 node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

/*
	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
     root->left->left->left = newNode(8); */

      vertical(root,0);

     root2 = newNode(3);
     root2->left = newNode(6);
     root2->right = newNode(7);

  /*   if (subgroup(root, root2)) {
     	cout <<"YESSSSSSSSSSSSSSSSS\n";
     }
	
  /*  cout << "LCA(4, 5) = " << LCA(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << LCA(root, 4, 6)->key;
    cout << "\nLCA(2, 4) = " << LCA(root, 8, 5)->key;
    cout << "\nsize is " << size(root) << "\n";

    int con[100];
    memset (con, 0, sizeof (con));

    cout <<"\n========================================\n";
    int max = 0;

    maxlevel(root, con, 0);
    for (int i = 0; i < 100; i++) {
    	if (max < con[i]) {
    		max = con[i];
    	}
    }
    cout <<" max level is ===== " << max << "\n";
    cout <<"\n=========================================\n";

    cout << "\nhieght of tree " << ht(root) << "\n";

    cout <<"\n===================================================\n";
    int path[1000];
    printp(root, path, 0);

    cout <<"\n====================================================\n";
    inorder(root);
    mirror(root);
    inorder(root);

     cout <<"\n====================================================\n";

     lot(root);
     cout <<"\n level of node 1 is " << lev(root, 5, 1)<<" "<< lev(root, 8, 1)<< endl;
     if (ancestors(root, 8)) {
     	
     }

     cout << "\nmax is " << findmax(root) << endl;
     cout <<"\n====================================================\n";
     if (isFull(root)) {
     	cout <<"its full\n";
     }
     else
     	cout <<"its not full\n";
     inorder(root);
     root = delhalf(root);
     inorder(root);
     root = delk(root, 4, 1);

     inorder(root);
	 cout <<"\n====================================================\n";
	 
	*/
	 int j;
	 for (it = mp.begin(); it != mp.end(); it++) {
	 	for (j = 0; j < it->second.size(); j++) {
	 		cout << it->second[j] << " " ;
	 	}
	 	cout << endl;	
	 } 
	 mp.clear();
	return 0;
}
