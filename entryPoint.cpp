#include "entryPoint.h"


void main()
{
	PriorityQueue<int>* a = new PriorityQueue<int>;
	a->Insert(4);
	a->Insert(3);
	a->ForEach([](int value)
		{ std::cout << value << " "; });
	std::cout << std::endl;
}