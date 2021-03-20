
#include<iostream> 
#include<climits> 
#include "BT.h"

using namespace std;
namespace Ex02
{
	void swap(BT& x, BT& y);

 
	class heapMin
	{
		BT* arr; 
		int capacity; 
		int heap_size; 
	public:
		heapMin(int capacity);

		void heapMinify(int);

		int parent(int i) { int one = 1;
		return (((i - 1) / 2) * one); }

		int left(int i) { int one = 1;
		return ((2 * i + 1) * one); }

		int right(int i) { int one = 1;
		return ((2 * i + 2) * one); }

		BT extractMin();

		void decreaseKey(int i, BT& new_val);

		BT& getMin() { return arr[0]; }

		void deleteKey(int i);

		void insertKey(BT& k);

		void printHeap();
        
        int getHeapSize(){return heap_size;}
	};



}
