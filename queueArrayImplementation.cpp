#include <iostream>

using namespace std;

template <class T>
class Queue {
private:
    T* _items;
    // number of items in queue
    int _size = 0;
    // index of first (oldest) item
    int _head = 0;
    // index of last (newest) item;
    int _tail = -1;
public:
    void enqueue(T item)
    {
	// if the array needs to grow
	if (_items.length() == _size) {
	    int newLength = (_size == 0) ? 4 : _size * 2;

	    T* newArray = new T[newLength];

	    if (_size > 0) {
		// copty contents...
		// if array has no wrapping, just copy the valid range
		// else copy from head to end of the array
		// then 0 to tail

		int targetIndex = 0;
		if (_tail < _head) {
		    // wrapped around
		    for (int i = _head; i < _items.length(); i++) {
			newArray[targetIndex] = _items[i];
			targetIndex++;
		    }

		    for (int i = 0; i <= _tail; i++) {
			newArray[targetIndex] = _items[i];
			targetIndex++;
		    }
		}
		else {
		    for (int i = _head; i <= _tail; i++) {
			newArray[targetIndex] = _items[i];
			targetIndex++;
		    }
		}
		_head = 0;
		_tail = targetIndex - 1;
	    }
	    else {
		head = 0;
		tail = -1;
	    }
	    _items = newArray;
	}

	// now have a properly sized array
	// take care of the wrapping issues
	if (_tails == items.size() - 1) {
	    _tail = 0;
	} else {
	    _tail++;
	}

	_items[_tail] = item;
	_size++;
    }

    T dequeue() {

	T value = _items[_head];

	if (_head == _items.size() - 1) {
	    _head = 0;
	}
	else {
	    _head++;
	}
	_size--;
	return value;
    }

    T peek()
    {
	return _items[head];
    }

    int count()
    {
	return _size;
    }

    void clear()
    {
	_size = _head = 0;
	_tail = -1;
    }
};

int main()
{
    queue<int> q;
    return 0;
}
