template<class T>
LinkedList::LinkedList()
{
    size = 0;
    head = nullptr;
}

template<class T>
T get(int position) const throw(PreCondViolatedExcept)
{
    if (position < 1 || position >= size) {
        string message = "Invalide position";
        throw(PreCondViolatedExcept(message));
    }
    return get_node_at(position);
}

/***** UTILITIES *******/
template<class T>
T get_node_at(int position) const
{
    int count = 0;
    while (head != nullptr) {
        if (count == position) break;
        count++;
        head = head->next;
    }
    return head->data;
}

