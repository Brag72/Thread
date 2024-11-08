#include <iostream>
#include "Safe_queue.h"
#include "Thread_pool.h"
#include <string>

void test_func(std::string name)
{
	std::cout << "Executing task: " << name << " on thread " << std::this_thread::get_id() << std::endl;
}
int main()
{
	Thread_pool* TH = new Thread_pool;

	for (int i = 0; i < 14; ++i)
	{
		TH->submit([i] {test_func("Task " + std::to_string(i)); });
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Completed";
}