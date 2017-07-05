// Ali Bayati
// binary tree

#include <iostream>

using namespace std;

// struct
struct node
{
	int value;
	node *left;
	node *right;
};

// function prototypes
node * getNode(int);
void printTree(node *);
void insert(node*&, int);

int main()
{
	node *header = NULL;		// empty tree

	for (int i = 0; i < 10; i++)
	{
		int randValue = rand() % 100;	// 0 - 99
		cout << "inserting: " << randValue << endl;

		insert(header, randValue);
	}

	printTree(header);
	cout << endl;

	return 0;
}

void insert(node *&header, int insertValue)
{
	if (header == NULL)
		header = getNode(insertValue);
	else
	{
		// there is a root node
		if (insertValue < header->value)
		{
			if (header->left == NULL)
				header->left = getNode(insertValue);
			else
				insert(header->left, insertValue);	// recursive step

		}
		else // it goes in right subtree
		{
			if (header->right == NULL)
				header->right = getNode(insertValue);
			else
				insert(header->right, insertValue);		// recursive step
		}
	}
}

// printTree (LNR, or infix)
void printTree(node *header)
{
	if (header != NULL)
	{
		// LNR
		printTree(header->left);
		cout << header->value << ", ";
		printTree(header->right);
	}
}

// getNode
node * getNode(int intValue)
{
	node *newNode = new node;

	newNode->value = intValue;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}