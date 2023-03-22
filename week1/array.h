#include <iostream>
using namespace std;

class Array
{
private:
	int* arr;
	int arrSize;
public:
	Array(int sz)
	{
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < sz; i++)
			arr[i] = 0;
	}

	int at(int idx)
	{
		return arr[idx];
	}

	void add(int idx, int value)
	{
		for (int i = arrSize - 2; i >= idx; i--)
			arr[i + 1] = arr[i];
		arr[idx] = value;
	}

	void set(int idx, int value)
	{
		arr[idx] = value;
	}

	void print()
	{
		for (int i{ 0 }; i < arrSize; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	}

	void remove(int idx)
	{
		for (int i{ idx + 1 }; i < arrSize - 2; i++)
		{
			arr[i-1] = arr[i];
		}
		arr[arrSize - 1] = 0;
	}

	int find(int value)
	{
		for (int i{ 0 }; i < arrSize; i++)
		{
			if (value == arr[i])
			{
				return i;
				break;
			}
		}

		return -1;
	}

	void rightShift(int d)
	{
		int shift = d % arrSize;
		if (shift == 0)
			return;
		while (shift > 0)
		{
			int tail = arr[arrSize - 1];
			add(0, tail);
			shift--;
		}
	}

	void reverse(int start, int end)
	{
		if (start == end)
			return;
		
		int sum = start + end;
		int sub = end - start;
		for (int i{ start }; i <= (start + sub / 2); i++)
		{
			int copy = arr[sum - i];
			arr[sum - i] = arr[i];
			arr[i] = copy;
		}
	}
};