/*
Author : Divyansh Shrivastava (divxvid)
Will add increase_key and decrease_key functionality later on.
*/

#include <iostream>
#include <cstdio>
using namespace std ;

class max_heap
{
	int *arr ;
	int size ;
	void float_up(int) ;
	void sink_down(int) ;
public:
	max_heap(int *A, int size)
	{
		arr = A ;
		this->size = size ;
	}
	void build_heap() ;
	void display() ;
	void insert(int) ;
	int top();
	void pop() ;
	void heap_sort();
};

void max_heap::heap_sort()
{
	const int lim = size ;
	for(int i = 0 ; i < lim ; ++i)
	{
		int e = arr[0] ;
		pop();
		arr[size] = e ;
	}
	size = lim ;
}

void max_heap::pop()
{
	if(size <= 0) return ;
	--size ;
	int temp = arr[size] ;
	arr[size] = arr[0] ;
	arr[0] = temp ;
	sink_down(0);
}

int max_heap::top()
{
	return arr[0] ;
}

void max_heap::float_up(int idx)
{
	int parent = ((idx+1) >> 1) - 1 ;
	if(parent < 0) return ;
	if(arr[idx] > arr[parent])
	{
		int temp = arr[idx] ;
		arr[idx] = arr[parent] ;
		arr[parent] = temp ;
		float_up(parent);
	}
}

void max_heap::insert(int value)
{
	arr[size] = value ;
	float_up(size++); 
}

void max_heap::display()
{
	for(int i = 0 ; i < size ; ++i)
		cout << arr[i] << ' ' ;
	cout << '\n' ;
}

void max_heap::sink_down(int idx)
{
	int left = (idx << 1) + 1 ;
	if(left >= size) return ;
	int right = left + 1 ;
	bool right_chosen = (right < size) && (arr[right] > arr[left]);

	if(right_chosen && arr[idx] < arr[right]) 
	{
		int temp = arr[right] ;
		arr[right] = arr[idx] ;
		arr[idx] = temp ;
		sink_down(right);
	} else if(arr[idx] < arr[left])
	{
		int temp = arr[left] ;
		arr[left] = arr[idx] ;
		arr[idx] = temp ;
		sink_down(left) ;
	}
}

void max_heap::build_heap()
{
	for(int i = size/2 ; i >= 0 ; --i)
	{
		sink_down(i);
	}
}

int main()
{
	int A[100] = {1, 3, 2 ,4 ,5 };
	max_heap hp(A, 5) ;
	hp.build_heap();
	hp.heap_sort();
	hp.display();
	return 0;
}
