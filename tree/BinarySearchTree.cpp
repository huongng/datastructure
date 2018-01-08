//----------------------------------------------------
// HELPER METHODS FOR PUBLIC OPERATIONS
//----------------------------------------------------
template<class T>
Node<T>* BST<T>::find(const T& item, Node<T>* treePtr) const
{
    if (treePtr != nullptr) {
        if (item == treePtr->getItem()) return treePtr;
        if (item < treePtr->getItem()) return find(item, treePtr->getLeftPtr());
        else return find(item, treePtr->getRightPtr());
    }
    return treePtr;
}

template<class T>
void BST<T>::destroy_tree(Node<T>* treePtr)
{
    if (treePtr != nullptr) {
        destroy_tree(treePtr->getLeftPtr());
        destroy_tree(treePtr->getRightPtr());
        delete treePtr;
    }
}

template<class T>
void BST<T>::insert(const T& item, Node<T>* treePtr)
{
    if (item < treePtr->getItem()) {
        if (treePtr->getLeftPtr() != nullptr) insert(item, treePtr->getLeftPtr());
        else treePtr->setLeftPtr(new Node<T>(item));
    }
    else {
        if (treePtr->getRightPtr() != nullptr) insert(item, treePtr->getRightPtr());
        else treePtr->setRightPtr(new Node<T>(item));
    }
    return;
}
template<class T>
void BST<T>::inorder(void visit(T&), Node<T>* treePtr) const
{
    //cout << "here" <<endl;
    if (treePtr == nullptr) return;
    inorder(visit, treePtr->getLeftPtr());
    T item = treePtr->getItem();
    visit(item);
    inorder(visit, treePtr->getRightPtr());
    return;
}

template<class T>
void BST<T>::postorder(void visit(T&), Node<T>* treePtr) const
{
    if (treePtr == nullptr) return;
    postorder(visit, treePtr->getLeftPtr());
    postorder(visit, treePtr->getRightPtr());
    T item = treePtr->getItem();
    visit(item);
    return;
}

template<class T>
void BST<T>::preorder(void visit(T&), Node<T>* treePtr) const
{
    if (treePtr == nullptr) return;
    T item = treePtr->getItem();
    visit(item);
    preorder(visit, treePtr->getLeftPtr());
    preorder(visit, treePtr->getRightPtr());
    return;
}
//----------------------------------------------------
// PUBLIC OPERATIONS
//----------------------------------------------------
template<class T>
void BST<T>::destroy_tree()
{
    destroy_tree(root);
}
template<class T>
Node<T>* BST<T>::find(const T& item) const
{
    return find(item, root);
}

template<class T>
void BST<T>::insert(const T& item)
{
    if (root != nullptr) insert(item, root);
    else root = new Node<T>(item);
    return;
}

template<class T>
void BST<T>::inorder(void visit(T&)) const
{
    inorder(visit, root);
}

template<class T>
void BST<T>::postorder(void visit(T&)) const
{
    postorder(visit, root);
}

template<class T>
void BST<T>::preorder(void visit(T&)) const
{
    preorder(visit, root);
}

template<class T>
void BST<T>::inorder_it(void visit(T&)) const
{
    inorder_it(visit, root);
}

template<class T>
void BST<T>::postorder_it(void visit(T&)) const
{
    postorder_it(visit, root);
}

template<class T>
void BST<T>::preorder_it(void visit(T&)) const
{
    preorder_it(visit, root);
}