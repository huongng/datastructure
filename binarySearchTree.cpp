#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node() = delete;
    Node(int item): data(item), left(NULL), right(NULL) {}
};

/* Utility functions for BST */
void insert(Node** node, int key);
Node* search(Node* node, int key);
void inorder(Node* head);
void preorder(Node* head);
void postorder(Node* head);

int main()
{
    Node* head = NULL;
    insert(&head, 50);
    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 40);
    insert(&head, 70);
    insert(&head, 60);
    insert(&head, 80);

    inorder(head);
    cout << endl;

    cout << search(head, 40)->data << endl;
    return 0;
}

Node* search(Node* node, int key)
{
    if (node == NULL || key == node->data) return node;
    if (key < node->data) {
	return search(node->left, key);
    }
    return search(node->right, key);
}

void inorder(Node* node)
{
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node* node)
{
    if (node == NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void insert(Node** node, int key)
{
    // if tree is empty, set new node as head
    if (*node == NULL) {
	*node = new Node(key);
	return;
    }
    Node* current = *node;
    if (key < current->data) {
	insert(&(current->left), key);
    }
    else {
	insert(&(current->right), key);
    }
    return;
}
    
    
	
