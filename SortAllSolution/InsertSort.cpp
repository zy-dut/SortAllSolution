#include <iostream>
#include <vector>

using namespace std;
template <class T>
void DirectInsertSort(vector<T>& nums)		// 直接插入排序
{
	T spynum;		// 监视哨元素
	for (int i = 0; i < nums.size() - 1; i++)
	{	
		if (nums[i] > nums[i + 1])
		{
			spynum = nums[i + 1];
			int j = i;
			for (j = i; nums[j] > spynum; j--)		// 顺序后移
				nums[j + 1] = nums[j];
			nums[j + 1] = spynum;
		}
	}
}
void test01()
{
	vector<int> nums = { 13,30,26,85,13 };
	DirectInsertSort<int>(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
}

template <class T>
void BinaryInsertSort(vector<T>& nums)		// 折半插入排序
{
	T spynum;
	int low, high, mid;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] > nums[i + 1])
		{
			spynum = nums[i + 1];
			low = 0; high = i;
			mid = (low + high) / 2;
			while (low <= high)
			{
				if (nums[mid] > spynum)
					high = mid - 1;
				else
					low = mid + 1;
				mid = (low + high) / 2;
			}
			int j = i + 1;
			for (j = i + 1; j > low; j--)
				nums[j] = nums[j - 1];
			nums[low] = spynum;
		}
	}
}
void test02()
{
	vector<int> nums = { 30,13,26,85,15 };
	BinaryInsertSort<int>(nums);
	cout << "折半插入排序结果为：";
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
}

template <class T>
void ShellInsert(vector<T>& nums,int dt)		// 希尔（插入）排序
{
	T spynum;
	for (int i = dt; i < nums.size(); ++i)
	{
		if (nums[i] < nums[i - dt])
		{
			spynum = nums[i];
			int j = i-dt;
			for (j = i - dt; j >= 0; j -= dt)
			{
				if (nums[j] > spynum)
					nums[j + dt] = nums[j];
				else
					break;
			}
			nums[j + dt] = spynum;
		}
	}
}
void test03()
{
	vector<int> nums = { 49,38,65,97,76,13,27,48,55,4 };
	vector<int> delta = { 5,3,1 };	//	希尔增量
	for(int k = 0;k<delta.size();k++)
	{
		ShellInsert<int>(nums, delta[k]);
		cout << "希尔排序第" << k + 1 << "次结果为：";
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
	}	
}

int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}