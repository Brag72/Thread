#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <thread>
#include <windows.h>

using namespace std;

void sum_vec(const vector<int>& V1, const vector<int>& V2, int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		int sum = V1[i] + V2[i];
	}
}

double threading(int count_thread, const vector<int>& V1, const vector<int>& V2)
{
	vector<thread> threads;

	auto start_time = chrono::high_resolution_clock::now();
	int chunk = V1.size() / count_thread;
	
	for (int i = 0; i < count_thread; ++i)
	{
		int start = chunk * i;
		int end = start + chunk;
		threads.push_back(thread(sum_vec, ref(V1), ref(V2), start, end));
	}
	for (auto& th : threads)
	{
		th.join();
	}
	auto end_time = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_seconds = end_time - start_time;
	
	return elapsed_seconds.count();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "Russian");

	unsigned int n = thread::hardware_concurrency();
	cout << n << " concurrent threads are supported.\n";

	vector<int> sizes = { 1000, 10000, 100000, 1000000 };
	vector<int> thread_counts = { 2, 4, 8, 16 };
	cout << setw(20) << "1000" << setw(10) << "10000" << setw(10) << "100000" << setw(10) << "1000000" << endl;

	int count = 0;
	for(int size : sizes)
	{
		vector<int> v1(size, 1);
		vector<int> v2(size, 1);

		cout << thread_counts[count] << " потоков ";
		for (int j = 0; j < 4; ++j)
		{
			cout << setw(10) << threading(thread_counts[j],v1,v2);
		}
		cout << endl;
		count++;
	}
}