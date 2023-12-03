#include "priorityQueueItem.h"
#include <functional>
template <typename T>
class PriorityQueue
{
private:
	uint length;

	QueueItem<T>* head;
	QueueItem<T>* tail;
public:
	PriorityQueue<T>();
	~PriorityQueue<T>();

	uint GetLength();
	QueueItem<T>* GetHead();
	void SetHead(QueueItem<T>* head);
	QueueItem<T>* GetTail();
	void SetTail(QueueItem<T>* tail);

	void Insert(QueueItem<T>* newObj);
	void Insert(T value);
	bool Pull();
	QueueItem<T>* Peek();
	bool isEmpty();

	void ForEach(std::function<void(const T&)> action);

	__declspec(property(get = GetLength)) uint Length;
	__declspec(property(get = GetHead, put = SetHead)) QueueItem<T>* Head;
	__declspec(property(get = GetTail, put = SetTail)) QueueItem<T>* Tail;
};

template<typename T>
inline uint PriorityQueue<T>::GetLength()
{
	return this->length;
}

template<typename T>
inline QueueItem<T>* PriorityQueue<T>::GetHead()
{
	return this->head;
}

template<typename T>
inline void PriorityQueue<T>::SetHead(QueueItem<T>* head)
{
	this->head = head;
}

template<typename T>
inline QueueItem<T>* PriorityQueue<T>::GetTail()
{
	return this->tail;
}

template<typename T>
inline void PriorityQueue<T>::SetTail(QueueItem<T>* tail)
{
	this->tail = tail;
}

template<typename T>
inline void PriorityQueue<T>::Insert(QueueItem<T>* newObj)
{
	if (isEmpty())
	{
		this->head = this->tail = newObj;
		this->length++;
		return;
	}
	QueueItem<T>* current = this->head;
	QueueItem<T>* currentPriority = this->head;
	

	while (current)
	{
		if (newObj->Priority > current->Priority)
			currentPriority = current;
		current = current->Next;
	}
	if (currentPriority = this->tail)
	{
		this->tail->Next = newObj;
		newObj->Prev = this->tail;
		this->tail = newObj;
		this->length++;
		return;
	}
	newObj->Next = currentPriority;
	newObj->Prev = currentPriority->Prev;
	currentPriority->Prev->Next = newObj;
	currentPriority->Prev = newObj;
	this->length++;
}

template<typename T>
inline void PriorityQueue<T>::Insert(T value)
{
	QueueItem<T>* newObj = new QueueItem <T>;
	newObj->Value = value;
	if (isEmpty())
	{
		this->head = newObj;
		this->tail = newObj;
		this->length++;
		return;
	}
	this->Tail->Next = newObj;
	newObj->Prev = this->tail;
	this->tail = newObj;
	this->length++;
}

template<typename T>
inline bool PriorityQueue<T>::Pull()
{
	if (isEmpty())
		return false;
	QueueItem<T>* current = head;

	current->Next->Prev = nullptr;
	head = current->next;
	this->length--;

	delete[] current;
	
}

template<typename T>
inline QueueItem<T>* PriorityQueue<T>::Peek()
{
	if (isEmpty())
		return;
	return this->head;
}

template<typename T>
inline bool PriorityQueue<T>::isEmpty()
{
	if (this->head == nullptr)
		return true;
	return false;
}

template<typename T>
inline void PriorityQueue<T>::ForEach(std::function<void(const T&)> action)
{
	QueueItem<T>* current = this->head;
	while (current)
	{
		action(current->Value);
		current = current->Next;
	}
}

template<typename T>
inline PriorityQueue<T>::PriorityQueue()
{
	this->head = this->tail = nullptr;
	this->length = 0;
}

template<typename T>
inline PriorityQueue<T>::~PriorityQueue()
{
	QueueItem<T>* current = this->head;
	while (current)
	{
		QueueItem<T>* next = current->Next;
		delete current;
		current = next;
	}
}
