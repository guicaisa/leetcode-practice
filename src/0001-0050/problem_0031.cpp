#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

// https://leetcode-cn.com/problems/next-permutation/

class Solution
{
public:
	// �������۹۲죬Ѱ����һ���������У���Ҫ��������ұ߿�ʼѰ�ҵ�һ��
	// ��������ʽ��2�����֣�������н�������ʹ����һ�ε����������п����Ǹ����
	// ����1��2��3��4�������ұ߿�ʼ�ҵ��ĵ�һ���������е�2��������3��4������3��4
	// �����һ���������У�1��2��4��3
	// �������һ�ָ��ӵ����������1��4��3��2�����ҿ�ʼ�ҵ���һ���������е�������1��4
	// ���ﲻ��ֱ�ӽ���1��4��λ�ã���Ϊ4���滹��������4С�����֣������4��1��3��2�Ļ�����
	// ����ǲ��Եģ���Ϊ�м仹�кܶ�δ�һ�������û���оٳ���
	// �������������Ӧ�ô�β������1֮ǰ���������֣�������һ����1������֣��ͽ���������ֺ�1��λ��
	// ��Ϊ1��������ֶ�����ȷ���ǽ������еģ�������ν������Ա�֤��1�����С��һ�����ֻ������1��λ����
	// ��֤����һ���������е���ȷ��
	// �ٽ�������3�����ֵ�˳���ã���֤����3�����ֵ�����˳������С��ԭʼ������״̬
	void NextPermutation(std::vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return;
		}

		for (int i = nums.size() - 2; i >= 0; --i)
		{
			if (nums[i] < nums[i + 1])
			{
				for (int j = nums.size() - 1; j > i; --j)
				{
					if (nums[j] > nums[i])
					{
						int temp = nums[j];
						nums[j] = nums[i];
						nums[i] = temp;
						std::reverse(nums.begin() + i + 1, nums.end());
						return;
					}
				}
			}
		}

		std::reverse(nums.begin(), nums.end());
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//
//	std::vector<int> vi = {1,4,3,2};
//	// 
//
//	s.NextPermutation(vi);
//
//	std::cout << vi[0] << vi[1] << vi[2] << vi[3] << std::endl;
//
//	return 0;
//}