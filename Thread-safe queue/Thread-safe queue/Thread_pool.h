#pragma once
#include <vector>
#include <thread>
#include <functional>
#include <future>
#include "Safe_queue.h"

class Thread_pool
{
	std::vector<std::thread> Workers;
	SafeQueue<std::function<void()>> Tasks_;
	bool Stop;
public:
	Thread_pool(size_t num_threads = std::thread::hardware_concurrency());
	
	void work();	
	std::future<void> submit(std::function<void()> task);
	~Thread_pool();
};