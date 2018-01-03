template<class T>
ArrayList<T>::ArrayList(): size(0), capacity(0) {}

template<class T>
T ArrayList<T>::get(int position) const
{
    assert(position <= size && position >= 1);
    return items[position - 1];
}

template<class T>
bool ArrayList<T>::insert(int position, const T& item)
{
    if (position <= 1 || position >= size || size >= capacity) return false;
    // shift all entries from position - 1 down to add new item
    // 7 1 2 3 4 _ -> 7 _ 1 2 3 4
    for (int i = size; i >= position; i--) {
	items[i] = items[i - 1];
    }
    items[position - 1] = item;
    size++;
    return true;
}

template<class T>
bool ArrayList<T>::remove(int position)
{
    if (position < 1 || position >= size || size >= capacity) return false;
    // shift all entries upward to that position
    // 7 1 2 3 4 -> 7 2 3 4 _
    for (int i = position - 1; i < size - 1; i++) {
	items[i] = items[i + 1];
    }
    size--;
    return true;
}

template<class T>
void ArrayList<T>::set(int position, const T& item)
{
    if (position < 1 || position >= size) return;
    items[position - 1] = item;
}

template<class T>
void ArrayList<T>::clear()
{
    size = 0;
}

