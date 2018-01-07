#include <iostream>
#include "ArrayHeap.h"

using namespace std;

int main()
{
    ArrayHeap<int> heap;
    heap.add(1);
    heap.add(2);
    heap.add(3);
    heap.add(5);
    cout << heap.peekTop() << endl;
    cout << heap.getNumberOfNodes() << endl;
    heap.remove();
    cout << heap.peekTop() << endl;
    ArrayHeap<int> copied(heap);
    cout << copied.peekTop() << endl;
    return 0;
}
