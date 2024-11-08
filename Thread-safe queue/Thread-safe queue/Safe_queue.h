#pragma once
#include <queue>
#include <mutex>

template<typename T>
class SafeQueue
{
	std::queue<T> Queue_;
	std::mutex m;
	std::condition_variable cond_var;

public:
	
	void Push(const T& value)
	{
		std::lock_guard<std::mutex> lock(m);
		Queue_.push(value);
		cond_var.notify_one();
	}
	
	T Pop()
	{
		std::unique_lock<std::mutex> lock(m);
		cond_var.wait(lock, [this] {return !Queue_.empty(); });
		auto task = Queue_.front();
		Queue_.pop();
		return task;
	}

	bool Empty()
	{
		std::lock_guard<std::mutex> lock(m);
		return Queue_.empty();
	}
};