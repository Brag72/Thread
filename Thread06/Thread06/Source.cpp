#include <iostream>
#include <vector>
#include <future>

using namespace std;

int find_min(vector<int>& MyVec, int Start, int Size)
{
	int min_index = Start;
	int min_value = MyVec[Start];
	for (int i = Start; i < Size; ++i)
	{
		if (MyVec[i] < min_value)
		{
			min_index = i;
			min_value = MyVec[i];
		}
	}
	return min_index;
}

void sort_vec(vector<int>& MyVec)
{	
	for (int i = 0; i < MyVec.size() - 1; ++i)
	{
		auto future = async(launch::async,find_min,ref(MyVec),i,MyVec.size());
		auto new_index = future.get();
		
		if (new_index > i)
		{
			swap(MyVec[i], MyVec[new_index]);
		}
	}
}

int main()
{
	vector<int> My_Vec{ 1,3,7,54,2,78,23,7354 };

	for (int i : My_Vec)
	{
		cout << i << " ";
	}
	cout << endl;

	sort_vec(My_Vec);

	for (int i : My_Vec)
	{
		cout << i << " ";
	}
}