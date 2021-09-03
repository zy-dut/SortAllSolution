#include <iostream>
#include <vector>

using namespace std;

template <class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void BubbleSort(vector<T>& nums)	// 无停止条件的双重循环 效率低
{
	for (int i = 0; i < nums.size() - 1; i++)
	{
		for (int j = 1; j < nums.size() - i; j++)
		{
			if (nums[j] < nums[j - 1])
				mySwap<T>(nums[j], nums[j - 1]);
		}
		for (int k = 0; k < nums.size(); k++)
			cout << nums[k] << " ";
		cout << endl;
	}
}
template <class T>
void BubbleSortGood(vector<T>& nums)	// 带有停止条件的双重循环
{
	int flag = 1;	// 表示上一趟排序中是否有交换操作 1--有
	int len = nums.size() - 1;
	while (len > 0 && flag == 1)
	{
		flag = 0;
		for (int j = 1; j <= len; j++)
		{
			if (nums[j] < nums[j - 1])
			{
				flag = 1;
				mySwap<T>(nums[j], nums[j - 1]);
			}
		
		}
		len--;
		for (int k = 0; k < nums.size(); k++)
			cout << nums[k] << " ";
		cout << endl;
	}
}
void test01()
{
	vector<int> nums = { 13,25,7,13,18 };
	BubbleSortGood<int>(nums);
}

template <class T>
int QuickSortOnce(vector<T>& nums,int low,int high)		// 一次快排
{
	T spynum = nums[low];
	while (low < high)
	{
		while (nums[high] >= spynum && low < high)
			high--;
		if (low < high)
		{
			nums[low] = nums[high];
			low++;
		}
		while (nums[low] <= spynum && low < high)
			low++;
		if (low < high)
		{
			nums[high] = nums[low];
			high--;
		}		
	}
	nums[low] = spynum;
	return low;			// 返回每次快排的枢轴位置
}
template <class T>
void QuickSort(vector<T>& nums, int low, int high)	// 递归实现快排
{
	int pivotloc;
	if (low < high)
	{
		pivotloc = QuickSortOnce(nums, low, high);
		QuickSort(nums, low, pivotloc - 1);
		QuickSort(nums, pivotloc + 1, high);
	}
}
void test02()
{
	vector<int> nums = { 49,38,65,97,76,13,27,49 };
	QuickSort(nums, 0, nums.size() - 1);
	for (int k = 0; k < nums.size(); k++)
		cout << nums[k] << " ";
	cout << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}