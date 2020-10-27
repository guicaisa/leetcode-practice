#include <stdio.h>
#include <stdlib.h> 
#include <vector>

/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 */

class Solution 
{
public:
	// ����������ת�ˣ�������ȫ��������飬����ֱ��ʹ�ó�����ַ�
	// ��������ת������Ϊ�м�㣬�ж�Ŀ��ֵ������������߻����ұ�
	// ���ֲ��ҵ�ʱ�򣬸����м�ֵ��Ŀ��ֵ�Ƿ���һ�ߣ��ж��´��·ֵı߽�(����������)
	// ���м�ֵ��Ŀ��ֵ����ͬһ��ʱ��ʹ���������ֲ����жϴ�С����
	int Search(const std::vector<int>& nums, const int target) 
	{
		if (nums.size() == 0)
		{
			return -1;
		}

		int left_flag = 0;
		int right_flag = 0;

		if (target >= nums[0])
		{
			left_flag = 1;
		}
		else if (target <= nums[nums.size() - 1])
		{
			right_flag = 1;
		}
		else
		{
			return -1;
		}

		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;

		while (left <= right)
		{
			mid = (left + right) / 2;
			if (left_flag == 1 && nums[mid] < nums[0] && nums[mid] <= nums[nums.size() - 1])
			{
				right = mid - 1;
			}
			else if (right_flag == 1 && nums[mid] >= nums[0] && nums[mid] > nums[nums.size() - 1])
			{
				left = mid + 1;
			}
			else if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				return mid;
			}
		}

		return -1;
	}
};

//int main(int argc, char** argv)
//{
//	std::vector<int> vi = {3, 1};
//
//	Solution s;
//
//	int ret = s.Search(vi, 1);
//
//	return 0;
//}