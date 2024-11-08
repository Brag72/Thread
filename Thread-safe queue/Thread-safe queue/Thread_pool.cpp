#include "Thread_pool.h"
using namespace std;

Thread_pool::Thread_pool(size_t num_threads)
{
	Stop = false;
	for (int i = 0; i < num_threads; ++i)
	{
		Workers.emplace_back([this] {work(); });
	}
}

void Thread_pool::work()
{
	while (!Stop)
	{
		auto task = Tasks_.Pop();
		if (task)
		{
			task();
		}
	}
}

future<void> Thread_pool::submit(function<void()> task)
{
	using ResultType = decltype(task());
	auto TaskNew = make_shared<packaged_task<ResultType()>>(task);

	auto Future = TaskNew->get_future();
	Tasks_.Push([TaskNew]{ (*TaskNew)(); });
	return Future;
}

Thread_pool::~Thread_pool()
{
	Stop = true;
	for (auto& th : Workers)
	{
		if (th.joinable())
		{
			th.join();
		}
	}
}