#include <stdio.h>
#include <stdlib.h>
#include <vector>

/**
 * https://leetcode.com/problems/trapping-rain-water/solution/
 */

class Solution 
{
public:
	/**
	 * ���ҷֱ�������õ������һ��д��ҵ������ʱÿ��λ���ϵ����ֵ 
	 * �������飬�������������е����ֵС��һ��λ��׼(ľͰ�̰�)
	 * ����뵱ǰλ�ø߶ȵĲ�ֵ���ۼƵ������
	 */
	int Trap(const std::vector<int>& height)
	{
		if (height.size() == 0)
		{
			return 0;
		}

		std::vector<int> left(height.size(), 0);
		std::vector<int> right(height.size(), 0);

		left[0] = height[0];
		right[height.size() - 1] = height[height.size() - 1];

		for (int i = 1; i < height.size(); ++i)
		{
			left[i] = height[i] > left[i - 1] ? height[i] : left[i - 1];
		}

		for (int i = height.size() - 2; i >= 0; --i)
		{
			right[i] = height[i] > right[i + 1] ? height[i] : right[i + 1];
		}

		int sum = 0;

		for (int i = 1; i < height.size() - 1; ++i)
		{
			sum += (left[i] < right[i] ? left[i] : right[i]) - height[i];
		}

		return sum;
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//
//	std::vector<int> vi = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
//
//	int ret = s.Trap(vi);
//
//	return 0;
//}