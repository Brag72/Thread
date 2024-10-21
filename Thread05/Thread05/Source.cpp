#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
class Data
{
public:
	int scalar;
	mutex m;

	Data(int value)
	{
		scalar = value;
	}
};


void swap_lock(Data& left, Data& right)
{
	lock_guard<mutex> lk(left.m, adopt_lock);
	lock_guard<mutex> rk(right.m, adopt_lock);
	swap(left.scalar, right.scalar);
}

void swap_scoped_lock(Data& left, Data& right)
{
	scoped_lock lk(left.m,right.m);
	swap(left.scalar, right.scalar);
}

void swap_unique_lock(Data& left, Data& right)
{
	unique_lock<mutex> lk(left.m, defer_lock);
	unique_lock<mutex> rk(right.m, defer_lock);
	lock(lk, rk);
	swap(left.scalar, right.scalar);
}

int main()
{
	Data Left(5);
	Data Right(10);
	cout << Left.scalar << " " << Right.scalar << endl;
	swap_scoped_lock(Left, Right);
	cout << Left.scalar << " " << Right.scalar << endl;
	//swap_unique_lock(Left, Right);
	//swap_lock(Left, Right);
}