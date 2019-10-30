#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

/**
 * https://leetcode.com/problems/first-missing-positive/
 */

class Solution 
{
public:
	/**
	 * �����Ĳ����е㿴������ʵ������Ŀ����˼��һ�����飬���賤��Ϊ4
	 * ��ô������������е�Ԫ��Ӧ����1��2��3��4
	 * ��ʵ�����������1��5��3��4���ҳ���С����ʧ������������Ϊ2
	 * ������������������(1��2��3��4)�и��ص㣬��nums[i] = i + 1
	 * һ������£���Ҫ������������򣬵�����Ŀ�в�����ʹ�ö���Ŀռ�
	 * ����nums[i] = i + 1��ʽ��ʹ�����鱾����Ϊ�洢����
	 * �ڱ��������и��ݹ�ʽ�����������Ԫ�طŵ�ԭ����λ����
	 * ��3��4��-1��1 ����Ԫ�ص�ֵ�ҵ����Ӧ������λ�ã���nums[0] = 3
	 * ֵΪ3����λ��Ӧ����nums[2],�Ա�nums[0]��nums[0]����ֵ�������
	 * �Ե�λ�ã���3�Żص�nums[2]��λ���ϣ����˱������õ����1��-1��3��4
	 * ���շ���ȱ�ٵ���С����Ϊ2
	 */
	int FirstMissingPositive(std::vector<int>& nums) 
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
			{
				std::swap(nums[i], nums[nums[i] - 1]);
			}
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] - 1 != i)
			{
				return i + 1;
			}
		}

		return nums.size() + 1;
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//
//	std::vector<int> vi = {7, 8, 9, 11, 12};
//
//	int ret = s.FirstMissingPositive(vi);
//
//	return 0;
//}