#include <stdio.h>
#include <stdlib.h> 
#include <vector>

// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

class Solution 
{
public:
	// ����������ת�ˣ�������ȫ��������飬����ֱ��ʹ�ó�����ַ�
	// ÿ�ζ��ֵ�ʱ����Ҫ�ж�����������һ������ȫ��һ�ߵ�(����û�п�Խ�м����ת��)
	// �����ж�û�п���һ�Σ��ж�target�Ƿ����������ڣ�����ڣ���һ�ξ�����һ����Ϊ���ֲ��ҵ����䣬���ǳ���Ķ��ֲ����� 
	// ���targe����û�п�����һ���У���ѡʣ��һ�Σ����������ֲ��ң�ֱ���ҳ����
	int Search(const std::vector<int>& nums, const int target)
	{
		if (nums.size() == 0)
		{
			return -1;
		}

		if (target < nums[0] && target > nums[nums.size() - 1])
		{
			return -1;
		}

		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;

		while (left <= right)
		{
			mid = (left + right) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}

			if (nums[left] <= nums[mid])
			{
				if (nums[left] <= target && target <= nums[mid])
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else
			{
				if (nums[mid] <= target && target <= nums[right])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
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