template<class T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
ArrayHeap<T>::ArrayHeap(): size(0), capacity(DEFAULT_CAPACITY)
{
    items = new T;
}
template<class T>
ArrayHeap<T>::ArrayHeap(const T array[], const int size): size(size), capacity(size * 2)
{
    items = new T[size];
    for (int i = 0; i < size; i++) {
	items[i] = array[i];
    }
    createHeap();
}
template<class T>
ArrayHeap<T>::ArrayHeap(const ArrayHeap& oHeap)
{
    size = oHeap.size;
    capacity = oHeap.capacity;
    items = new T[size];
    for (int i = 0; i < size; i++) {
	items[i] = oHeap.items[i];
    }
}

template<class T>
ArrayHeap<T>::~ArrayHeap()
{
    delete [] items;
}

template<class T>
bool ArrayHeap<T>::isEmpty() const
{
    return size == 0;
}

template<class T>
int ArrayHeap<T>::getNumberOfNodes() const
{
    return size;
}

template<class T>
int ArrayHeap<T>::getHeight() const
{
    // TODO
    return 0;
}

template<class T>
T ArrayHeap<T>::peekTop() const
{
    return items[0];
}

template<class T>
bool ArrayHeap<T>::add(const T& item)
{
    // TODO: when size reaches its capacity
    items[size] = item;
    if (size == 0) {
	size++;
	return true;
    }
    int index = size++;
    bool inPlace = false;
    while (!inPlace && index > 0) {
	int parentIndex = getParentIndex(index);
	if (items[parentIndex] > items[index]) inPlace = true;
	else {
	    swap(items[parentIndex], items[index]);
	    index = parentIndex;
	}
    }
    return inPlace;
}

template<class T>
bool ArrayHeap<T>::remove()
{
    swap(items[0], items[size - 1]);
    size--;
    heapRebuild(0);
    return true;
}

template<class T>
void ArrayHeap<T>::clear()
{
    delete[] items;
    size = 0;
}

/*** UTILITIES ***/
template<class T>
void ArrayHeap<T>::heapRebuild(const int rootIndex)
{
    /** 4            9
       / \    ->    / \
      5   9        5   4
    **/
    // check if root is not a leaf, if it's a leaf, you are done
    if (isLeaf(rootIndex)) return;
    // get left, assuming it's larger child
    int largerIndex = getLeftChildIndex(rootIndex);
    if (largerIndex + 1 < size) {
	// if has right child
	if (items[largerIndex] < items[largerIndex + 1]) largerIndex++;
    }
    if (items[rootIndex] < items[largerIndex]) {
	swap(items[largerIndex], items[rootIndex]);
	heapRebuild(rootIndex);
    }
    return;
}

template<class T>
void ArrayHeap<T>::createHeap()
{
    // start in the last non-leaf
    // do heapRebuild
    // move up (by decrementing) until reach root
    for (int i = (size - 1) / 2; i >= 0; i--) {
	heapRebuild(i);
    }
    return;
}

template<class T>
bool ArrayHeap<T>::isLeaf(const int index) const
{
    return (index > (size - 2) / 2);
}

template<class T>
int ArrayHeap<T>::getLeftChildIndex(const int index) const
{
    return index * 2 + 1;
}

template<class T>
int ArrayHeap<T>::getRightChildIndex(const int index) const
{
    return index * 2 + 2;
}

template<class T>
int ArrayHeap<T>::getParentIndex(const int index) const
{
    return (index > 0) ? (index - 1) / 2 : 0;
}
