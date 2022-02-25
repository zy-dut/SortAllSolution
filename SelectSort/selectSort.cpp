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
void simpleSelectSort(vector<T>& nums) {
	T spynum;

	for (int i = 0; i < nums.size(); i++) {
		int index = -1;
		T spynum = nums[i];
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] < spynum) {
				index = j;
				spynum = nums[j];
			}
		}
		if (index != -1)
			mySwap<T>(nums[i], nums[index]);
	}
}

template <class T>
void heapAdjust(vector<T>& nums, int index, int len) {	// 调整 index~ index+len为小顶堆
	for (int i = index; i < len;) {
		int left = 2 * i + 1;
		int right = left + 1;

		int minId = i;
		if (left < len && nums[left] < nums[minId])	minId = left;
		if (right < len && nums[right] < nums[minId]) minId = right;

		if (minId != i) {
			mySwap(nums[i], nums[minId]);
			i = minId;
		}
		else
			break;
	}

}
template <class T>
void heapSort(vector<T>& nums) {
	int i = nums.size() / 2 - 1;	// 从最后一个非叶子节点开始调整（初建堆）
	for (i; i >= 0; i--) {
		heapAdjust(nums, i, nums.size());	// 初建堆
	}
	for (int k = 0; k < nums.size(); k++)
		cout << nums[k] << " ";
	cout << endl;
	for (i = nums.size()-1; i > 0; i--) {
		mySwap(nums[i], nums[0]);	// 堆顶为nums[0]
		heapAdjust(nums, 0, i-1);
	}
}


void test01()
{
	vector<int> nums = { 13,25,7,13,18 };
	simpleSelectSort<int>(nums);
	cout << "Result: " << endl;
}


void test02()
{
	vector<int> nums = { 49,38,65,97,76,13,27,50 };
	heapSort(nums);
	for (int k = 0; k < nums.size(); k++)
		cout << nums[k] << " ";
	cout << endl;
}

int main() {
	//test01();
	test02();
	return 0;
}