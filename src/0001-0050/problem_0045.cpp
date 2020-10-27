#include <stdio.h>
#include <vector>

/**
 * https://leetcode.com/problems/jump-game-ii/
 */

class Solution {
public:
	// ʹ����������start��end��ȷ��ÿ���ƶ��׶�ʱ���ƶ���Χ
	// ��[2,3,1,1,4]����ͷ��ʼ��ȷ����һ�ε��ƶ���ķ�ΧΪ1-2
	// ��һ�α���ʱ��������1��ʼ���ҵ�����ƶ��ķ�Χ������һ���ƶ���Χ�Ľ���λ��
	// ��һ���ƶ���Χ�Ŀ�ʼλ��Ϊ��ǰ�ƶ���Χ�Ŀ�ʼ����+1
	// ֱ���ƶ���Χ�������鳤�ȣ����������õ����
	int Jump(const std::vector<int>& nums) {
		int num = 0;
		int start = 0;
		int end = 0;

		for (; end < nums.size() - 1; ) {
			++num;
			int max_end = end + 1;

			for (int i = start; i <= end; ++i) {
				if (i + nums[i] >= nums.size() - 1) {
					return num;
				}

				if (i + nums[i] > max_end) {
					max_end = i + nums[i];
				}
			}

			start = end + 1;
			end = max_end;
		}

		return num;
	}
};

//int main(int argc, char** argv) {
//	Solution s;
//
//	std::vector<int> si = { 2, 3, 1, 1, 4, 2 };
//
//	int ret = s.Jump(si);
//
//	return 0;
//}