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

template<class T>
BinaryNodeTree<T>::BinaryNodeTree(const BinaryNodeTree<T>& tree)
{
    rootPtr = copyTree(tree.rootPtr);
}

//------------------------------------------------------------
// Protected Helper Methods
//------------------------------------------------------------
template<class T>
int BinaryNodeTree<T>::getHeightHelper(const Node<T>* subTree) const
{
    // the height of a node is 1 (for itself) and the maximum height
    // of its subTree
    if (subTree == nullptr) return 0;
    return 1 + max(getHeightHelper(subTree->getLeftPtr(),
                getHeightHelper(subTree->getRightPtr()));)
}

template<class T>
int BinaryNodeTree<T>::getNumberOfNodes(const Node<T>* subTree) const
{
    // the number of nodes in subtree is the subtree root itself
    // and the number of nodes on the left subtree and right subtree
    if (subTree == nullptr) return 0;
    return 1 + getNumberOfNodes(subTree->getLeftPtr()) +
            getNumberOfNodes(subTree->getRightPtr());
}

template<class T>
void BinaryNodeTree<T>::destroyTree(Node<T>* subTree)
{
    if (subTree != nullptr)
    {
        destroyTree(subTree->getLeftPtr());
        destroyTree(subTree->getRightPtr());
        delete subTree;
    }
    return;
}

template<class T>
Node<T>* BinaryNodeTree<T>::balanceAdd(Node<T>* subTree, Node<T>* newNodePtr)
{
    if (subTree == nullptr) return newNodePtr;
    Node<T>* left = subTree->getLeftPtr();
    Node<T>* right = subTree->getRightPtr();
    if (getHeightHelper(left) > getHeightHelper(right)) {
        // right subtree is shorter
        // will start to add there
        right = balanceAdd(right, newNodePtr);
        subTree->setRightPtr(right);
    }
    else {
        left = balanceAdd(left, newNodePtr);
        subTree->setLeftPtr(left);
    }
    return subTree;
}

template<class T>
Node<T>* BinaryNodeTree<T>::copyTree(const Node<T>* treePtr) const
{
    Node<T>* newNodePtr = new Node(treePtr->getItem());
    if (treePtr != nullptr)
    {
        newNodePtr->setLeftPtr(copyTree(treePtr->getLeftPtr()));
        newNodePtr->setRightPtr(copyTree(treePtr->getRightPtr()));
    }
    return newNodePtr;
}


template<class T>
void BinaryNodeTree<T>::preorder(void visit(T&), Node<T>* treePtr) const
{
    if (treePtr == nullptr) return;
    item = treePtr->getItem();
    visit(item);
    preorder(visit, treePtr->getLeftPtr());
    preorder(visit, treePtr->getRightPtr());
}
template<class T>
void BinaryNodeTree<T>::preorder_it(void visit(T&), Node<T>* treePtr) const
{
    if (treePtr == nullptr) return;
    stack< Node<T>* > sNodes;
    sNodes.push(treePtr);
    while (!sNodes.empty())
    {
        Node<T>* curPtr = sNodes.top();
        T item = curPtr->getItem();
        visit(item);
        right = curPtr->getRightPtr();
        left = curPtr->getLeftPtr();
        if (right) sNodes.push(right);
        if (left) sNodes.push(left);
    }
}
template<class T>
void BinaryNodeTree<T>::inorder(void visit(T&), Node<T>* treePtr) const
{
    if (treePtr == nullptr) return;
    inorder(visit, treePtr->getLeftPtr());
    // visit(T&) takes a reference so we need a lvalue
    T item = treePtr->getItem();
    visit(item);
    inorder(visit, treePtr->getRightPtr());
}
template<class T>
void BinaryNodeTree<T>::inorder_it(void visit(T&), Node<T>* treePtr) const
{
    // ITERATIVE VERSION
    stack< Node<T>* > sNodes;
    Node<T>* curPtr = treePtr;
    bool isDone = false;
    while (!isDone) {
        if (curPtr != nullptr) {
            curPtr = treePtr->getLeftPtr();
            sNodes.push(curPtr);
        }
        else {
            if (!sNodes.empty()) {
                curPtr = sNodes.peek();
                T item = curPtr->getItem();
                visit(T);
                sNodes.pop();
                curPtr = curPtr->getRightPtr();
            }
            else {
                isDone = true;
            }
        }
    }
}

template<class T>
void BinaryNodeTree<T>::postorder(void visit(T&), Node<T>* treePtr) const
{
    if (treePtr == nullptr) return;
    postorder(visit, treePtr->getLeftPtr());
    postorder(visit, treePtr->getRightPtr());
    item = treePtr->getItem()
    visit(item);

    // ITERATIVE VERSION
    stack< Node<T>* > sNodes;
    Node<T>* curPtr = treePtr;
    bool isDone = false;
    while (!isDone) {
        if (curPtr != nullptr) {
            curPtr = treePtr->getLeftPtr();
            sNodes.push(curPtr);
        }
        else {
            if (!sNodes.empty()) {
                curPtr = sNodes.peek();
                curPtr = curPtr->getRightPtr();
                sNodes.push();
            }
        }
    }
}