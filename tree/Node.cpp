template<class T>
Node<T>::Node() : leftPtr(nullptr), rightPtr(nullptr) {}

template<class T>
Node<T>::Node(const T& item): item(item), leftPtr(nullptr), rightPtr(nullptr) {}

template<class T>
Node<T>::Node(const T& item, Node<T>* left, Node<T>* right) :
    item(item), leftPtr(left), rightPtr(rightPtr) {}

template<class T>
void Node<T>::setItem(const T& item)
{
    this->item = item;
}

template<class T>
T Node<T>::getItem() const
{
    return item;
}

template<class T>
bool Node<T>::isLeaf() const
{
    return leftPtr == rightPtr == nullptr;
}

template<class T>
Node<T>* Node<T>::getLeftPtr() const
{
    return leftPtr;
}

template<class T>
Node<T>* Node<T>::getRightPtr() const
{
    return rightPtr;
}

template<class T>
void Node<T>::setLeftPtr(Node<T>* left)
{
    leftPtr = left;
}

template<class T>
void Node<T>::setRightPtr(Node<T>* right)
{
    rightPtr = right;
}