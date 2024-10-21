#include <iostream>
#include <thread>
#include <windows.h>
#include <atomic>
#include <chrono>

using namespace std;

atomic<int> queue = 0;
const int max_client = 10;
bool is_done = false;

void client()
{
	while (queue < max_client)
	{
		this_thread::sleep_for(0.1ms);
		++queue;
		cout << "Обнаружен новый клиент! Клиентов в очереди: " << queue << endl;
	}
	is_done = true;
}

void oper()
{
	while (!is_done || queue > 0)
	{
		this_thread::sleep_for(1ms);

		if (queue == 0)
		{
			continue;
		}
		--queue;
		if (queue != 0)
		{
			cout << "Клиент обслужен! Клиентов в очереди: " << queue << endl;
		}
	}
	cout << "Клиентов не осталось!" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "Russian");

	thread t1(client);
	thread t2(oper);

	t1.join();
	t2.join();
}