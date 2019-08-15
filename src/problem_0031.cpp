#include <stdio.h>
#include <vector>
#include <map>

/**
 * https://leetcode.com/problems/next-permutation/
 */

class Solution
{
public:
	void NextPermutation(std::vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return;
		}

		std::map<int, int> greater;
		std::map<int, int> less;

		// �Ӻ���ǰ���ҵ���һ����������֣���Ϊ�滻�ڵ�
		// �Ӹ����ֵĺ�һ�����ֿ�ʼֱ����β������һ���ִ���������ֺ�һ����С���������
		// ���ҽ��ò��ֵ��������ִ��������޳�
		// �Ӵ��ڸ����ֵļ������ҵ���С��һ���滻����λ����ȥ
		// ʣ�µ�����ȫ������һ�������У����ݴ�С�������β�λ��ԭ������
		for (int i = nums.size() - 1; i >= 1; --i)
		{
			if (nums[i] > nums[i - 1]) 
			{
				int t = nums[i - 1];
				for (int j = i; j < nums.size(); ++j)
				{
					if (nums[j] > t)
					{
						++greater[nums[j]];
					}
					else
					{
						++less[nums[j]];
					}
				}

				nums.erase(nums.begin() + i - 1, nums.end());

				nums.emplace_back(greater.begin()->first);
				if (--(greater.begin()->second) == 0)
				{
					greater.erase(greater.begin()->first);
				}
			
				++greater[t];
				for (std::map<int, int>::iterator it = less.begin(); it != less.end(); ++it)
				{
					greater[it->first] += it->second;
				}

				for (std::map<int, int>::iterator it = greater.begin(); it != greater.end(); ++it)
				{
					for (int j = 0; j < it->second; ++j)
					{
						nums.emplace_back(it->first);
					}
				}

				return;
			}
		}

		std::reverse(nums.begin(), nums.end());
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//
//	std::vector<int> vi = {1, 3, 2};
//	// 
//
//	s.NextPermutation(vi);
//
//	return 0;
//}