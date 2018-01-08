//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template<class T>
BinaryNodeTree<T>::BinaryNodeTree(): rootPtr(nullptr) {}
template<class T>
BinaryNodeTree<T>::BinaryNodeTree(const T& rootItem) {
    rootPtr = new Node(T, nullptr, nullptr);
}
template<class T>
BinaryNodeTree<T>::BinaryNodeTree(const T& rootItem,
    const BinaryNodeTree<T>* l, const BinaryNodeTree<T>* r)
{
    rootPtr = new Node(T, copyTree(l->rootPtr), copyTree(r->rootPtr));
}