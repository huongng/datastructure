#include <iostream>

using namespace std;

struct Node
{
    int priority;
    int data;
    Node* link; // pointing toward front
};

class Priority_Queue
{
public:
    Priority_Queue(): front(NULL) {}
    Priority_Queue(int item, int priority): priority(priority), data(item), front(NULL) {}
    /*
     * Insert into Priority Queue
     */
    void insert(int item, int priority)
    {
	Node* tmp;
	Node* q;
	tmp = new Node(item, priority);

	// check if Priority Queue is empty OR
	// new item has the highest priority
	if (front == NULL || front->priority > priority) {
	    tmp->link = front;
	    front = tmp;
	}
	else {
	    q = front;
	    while (q->link != NULL && q->link->priority <= priority) {
		q = q->link;
	    }
	    tmp->link = q->link;
	    q->link = tmp;
	}
    }

    /*
     * Delete from Priority Queue
     */
    void del()
    {
	Node* tmp;
	if (front == NULL) cout << "Queue underflow" << endl;
	else {
	    tmp = front;
	    
    }
private:
    Node* front;
};
