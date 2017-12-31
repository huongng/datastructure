/******************** LRU CACHE ********************/
/* Memory has capacity C
 * Store key-value pairs
 * get(key): get the value of given key (-1 if not key not exists)
 * put(key, value): set or insert k-v pair. If memory reaches its capacity
   remove least recently used item
 * O(1) time complexity for get and put method
 */
/* DATA STRUCTURES USED */
/* Queue: most recentyly used items are in front and least are in rear
 * Doubly Linked List: to implement Queue
 * HashMap: hash the key values to the location where item is stored
 */
#include <iostream>
using namespace std;

struct Node
{
    int key, value;
    Node* next, prev;
    Node(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
};
class DoublyLinkedList
{
public:
    DoublyLinkedList(): front(NULL), rear(NULL) {}
    void move_page_to_head(Node* page);
    void remove_rear_page();
    Node* get_rear_page();
    Node* add_page_to_head(int key, int value);
private:
    Node* front, rear;
};
Node* get_rear_page()
{
    return rear;
}
void DoublyLinkedList::remove_rear_page()
{
    // Only one item
    if (rear == front) {
	delete rear;
	rear = front = NULL;
    }
    else {
	Node* temp = rear;
	rear = rear->prev;
	rear->next = NULL;
	delete temp;
    }
    if (rear == NULL) return;
    return;
}
void DoublyLinkedList::move_page_to_head(Node* page)
{
    if (page == front) return;
    if (page == rear) {
	rear->prev->next = NULL;
	rear = rear->prev;
    }
    else {
	page->prev->next = page->next;
	page->next->prev = page->prev;
    }
    page->prev = NULL;
    page->next = front;
    front->prev = page;
    front = page;
}
Node* DoublyLinkedList::add_page_to_head(int key, int value)
{
    Node* page = new Node(key, value);
    // Empty Queue
    if (!front && !rear) {
	front = rear = page;
    }
    else {
	page->next = front;
	front->prev = page;
	front = page;
    }
    return page;
}

/**************************** LRUCache ********************/
class LRUCache
{
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
private:
    int capacity;
    int size;
    DoublyLinkedList* pageList;
    map<int, Node*> pageMap;
};
LRUCache:::LRUCache(int capacity)
{
    this->capacity = capacity;
    size = 0;
    pageList = new DoublyLinkedList();
    pageMap = map<int, Node*>();
}
int LRUCache::get(int key)
{
    if (pageMap.find(key) == pageMap.end()) return -1;
    int v = pageMap[key]->value;
    pageList->move_page_to_head(pageMap[key]);
    return v;
}
void LRUCache::put(int k, int v)
{
    if (pageMap.find(k) != pageMap.end()) {
	// key already present
	pageMap[key]->value = v;
	pageList->move_page_to_head(pageMap[key]);
	return;
    }
    // New page
    // check if we have sufficient capacity
    if (size == capacity) {
	// runs out of memory
	// remove the Least Recently Used page
	// from 1) pageMap
	int k = pageList->get_rear_page()->key;
	pageMap.erase(k);
	// from 2) pageList
	pageList->remove_rear_page();
	size--;
    }
    // add new Page to head
    pageMap[k] = pageList->add_page_to_head(k, v);
    size++;
}
    
