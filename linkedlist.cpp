#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(NULL) {}
    Node(): data(0), next(NULL) {}
};

void push_tail(Node** head, int x)
{
    if (*head == NULL) {
	*head = new Node(x);
	return;
    }
    Node* end = *head;
    while (end->next != NULL)
	end = end->next;
    end->next = new Node(x);
    return;
}

void push_head(Node** head, int x)
{
    if (*head == NULL) {
	*head = new Node(x);
	return;
    }
    Node* temp = new Node(x);
    temp->next = *head;
    (*head) = temp;
    return;
}
int main()
{
    Node* head = NULL;
    push_tail(&head, 10);
    push_tail(&head, 11);
    push_head(&head, 9);
    cout << head->next->data << endl;
    return 0;
}
