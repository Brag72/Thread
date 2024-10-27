#include <iostream>
#include <future>
#include <vector>
#include <thread>
#include <numeric>
#include <chrono>
#include <iterator>
#include <windows.h>

using namespace std;

const int MinBlockSize = 25000;

template <typename Iterator, typename Function>
void ParallelForEach(Iterator Left, Iterator Right, Function& F)
{
	auto Distance = distance(Left, Right);
	if (Distance <= 1)
	{
		if (Distance == 1)
		{
			F(*Left);
		}
	}
	ParallelForEachImpl(Left, Right, F, MinBlockSize);
}

template <typename Iterator, typename Function>
void ParallelForEachImpl(Iterator Left, Iterator Right, Function& F, int Block_Size)
{
	auto Distance = distance(Left, Right);
	if (Distance <= Block_Size)
	{
		for_each(Left, Right, F);
		return;
	}

	Iterator Middle = Left;
	advance(Middle, Distance / 2);
	
	auto As = async(launch::async, [&]() {
		ParallelForEachImpl(Left, Middle, F, Block_Size);
		});

	ParallelForEachImpl(Middle, Right, F, Block_Size);
	As.get();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "Russian");

	vector<int>Numbers(100000);
	iota(Numbers.begin(), Numbers.end(), 0);

	auto Sq = [](int& x)
		{
			x = x * x;
			this_thread::sleep_for(3ns);
		};

	auto Start_time = chrono::high_resolution_clock::now();
	for_each(Numbers.begin(), Numbers.end(), Sq);
	auto End_time = chrono::high_resolution_clock::now();
	auto Duration = chrono::duration_cast<chrono::milliseconds>(End_time - Start_time);

	auto Start_time_paral = chrono::high_resolution_clock::now();
	ParallelForEach(Numbers.begin(), Numbers.end(), Sq);
	auto End_time_paral = chrono::high_resolution_clock::now();
	auto Duration_paral = chrono::duration_cast<chrono::milliseconds>(End_time_paral - Start_time_paral);

	cout << "Время последовательного вычисления: " << Duration.count() << " ms\n";
	cout << "Время параллельного вычисления: " << Duration_paral.count() << " ms\n";
}