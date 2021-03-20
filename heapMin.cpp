#include "heapMin.h"

using namespace std;


namespace Ex02 {


	heapMin::heapMin(int cap)
	{
		heap_size = 0;
		capacity = cap;
		arr = new BT[cap];
	}

	void heapMin::insertKey(BT& k)
	{
		if (heap_size == capacity)
		{
			cout << "\nOverflow: Could not insertKey\n";
			return;
		}

		int one = 1;
		heap_size++;
		int j = (heap_size - 1)*one;
		arr[j] = k;


		while (j != 0 && arr[parent(j)].getRootKey() > arr[j].getRootKey())
		{
			swap(arr[j], arr[parent(j)]);
			j = parent(j);
		}
	}

	void heapMin::printHeap()
	{
		for (int i = 0; i < heap_size; i++)
		{
			cout << " root number: " << i <<"key/freq: "<< arr[i].getRootKey()<< " data: " << arr[i].getRootData() <<"|";
            cout<<endl;
            
		}
		cout << endl;
        
	}

	void heapMin::decreaseKey(int i, BT& new_val)
	{
		arr[i] = new_val;
		while (i != 0 && arr[parent(i)].getRootKey() > arr[i].getRootKey())
		{
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}


	BT heapMin::extractMin()
	{
		if (heap_size <= 0)
		{
			BT maxKeyTree;
			maxKeyTree.insert(INT_MAX, ' ');
			return maxKeyTree;
		}
		if (heap_size == 1)
		{
			heap_size--;
			return arr[0];
		}

		BT root = arr[0];
		arr[0] = arr[heap_size - 1];
		heap_size--;
		heapMinify(0);

		return root;
	}



	void heapMin::deleteKey(int i)
	{
		BT minKeyTree;
		minKeyTree.insert(INT_MIN, ' ');
		decreaseKey(i, minKeyTree);
		extractMin();
	}


	void heapMin::heapMinify(int i)
	{
		int one = 1;
		int l = left(i)*one;
		int r = right(i)*one;
		int smallest = i*one;
		if (l < heap_size && arr[l].getRootKey() < arr[i].getRootKey())
			smallest = l;
		if (r < heap_size && arr[r].getRootKey() < arr[smallest].getRootKey())
			smallest = r;
		if (smallest == i)
			int j = 0;
		else
		{
			swap(arr[i], arr[smallest]);
			heapMinify(smallest);
		}
	}

	void swap(BT& x, BT& y)
	{
		BT temp = x;
		x = y;
		y = temp;
	}
}
