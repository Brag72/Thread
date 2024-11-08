#include "Safe_queue.h"

using namespace std;

template<typename T>
void SafeQueue<T>::push(const T& value)
{
	lock_guard<mutex> lock(m);
	_Queue.push(value);
	cond_var.notify_one();
}

template<typename T>
T* SafeQueue<T>::pop()
{
	unique_lock<mutex> lock(m);
	cond_var.wait(lock, [this] {return !_Queue.empty(); });
	auto task = _Queue.front();
	_Queue.pop();
	return task;
}