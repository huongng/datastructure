#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

void print(int& item)
{
    cout << item << endl;
}
int main()
{
    BST<int> tree;
    tree.insert(1);
    tree.insert(0);
    tree.insert(3);
    tree.insert(2);
    return 0;
}