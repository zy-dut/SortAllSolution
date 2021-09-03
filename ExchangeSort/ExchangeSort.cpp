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
void BubbleSort(vector<T>& nums)	// ��ֹͣ������˫��ѭ�� Ч�ʵ�
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
void BubbleSortGood(vector<T>& nums)	// ����ֹͣ������˫��ѭ��
{
	int flag = 1;	// ��ʾ��һ���������Ƿ��н������� 1--��
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
int QuickSortOnce(vector<T>& nums,int low,int high)		// һ�ο���
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
	return low;			// ����ÿ�ο��ŵ�����λ��
}
template <class T>
void QuickSort(vector<T>& nums, int low, int high)	// �ݹ�ʵ�ֿ���
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