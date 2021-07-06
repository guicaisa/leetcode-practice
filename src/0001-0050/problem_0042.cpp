#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>

// https://leetcode-cn.com/problems/trapping-rain-water/

class Solution 
{
public:
	// �����ƽ⣬����ÿһ��Ԫ�أ��ֱ����λ�������������α���
	// �ҵ���Ӧ��left_max��right_max�ֱ������ߵ����ֵ���ұߵ����ֵ
	// ���ڻ�ˮ���ɶ̰����������ȡmin(left_max, right_max)
	// ������λ�����ܻ�ˮ������Ϊmin(left_max, right_max) - height[i]
	// ���˱������ۼӽ��
	int Trap(const std::vector<int>& height)
	{
		int sum = 0;

		for (int i = 1; i < int(height.size()) - 1; ++i)
		{
			int left_max = 0;
			int right_max = 0;

			for (int j = i; j >= 0; --j)
			{
				left_max = std::max(left_max, height[j]);
			}

			for (int j = i; j < height.size(); ++j)
			{
				right_max = std::max(right_max, height[j]);
			}
			
			sum += std::min(left_max, right_max) - height[i];
		}

		return sum;
	}

	// �����ƽ�ķ�ʽЧ��̫�ͣ����Կ���ʹ�ö�̬�滮�ķ�ʽ
	// �ö�������ķ�ʽ����left_max��left_right������left_dp��right_dp��
	// left_dp[i]�����i������ʼ����ߵ����߶�
	// right_dp[i]�����i������ʼ���ұߵ����߶�
	// �ֱ����ұ�����һ�Σ����2��dp����
	// �������飬�������������е����ֵС��һ��Ϊ��׼(ľͰ�̰�)
	// ����뵱ǰλ�ø߶ȵĲ�ֵ���ۼƵ������
	int TrapDp(const std::vector<int>& height)
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

	// ʹ��ջ�ķ�ʽ�������Ĺ����н������������ջ
	// ջ�е�������Ӧ��ֵ�ǵݼ��ģ����Ե�������һ��������ջ��������Ӧ����ʱ
	// �����������һ�����ݴ�����ʱ����ջ��Ԫ�أ���Ϊ��ǰ��Ҫ�����ֵ
	// ��ʱ���ջ��û��Ԫ���ˣ�����������ݣ���Ϊû����߽��޷���ˮ
	// ���ջ�л���Ԫ�أ����Գ�֮Ϊleft���жϸ�������Ӧ��ֵ�͵�ǰ��������ֵ�Ĵ�С
	// ��С��ֵ��ȥ��ǰ�����������Ӧ��ֵ��Ϊ�߶ȣ�left�����͵�ǰ����������֮��ĲΪ��
	// ��˸ߵõ����Ի�ˮ����ֵ�ۼӵ������
	int TrapStack(const std::vector<int>& height)
	{
		if (height.size() == 0)
		{
			return 0;
		}

		int sum = 0;
		std::stack<int> si;
		for (size_t i = 0; i < height.size(); ++i)
		{
			while (!si.empty() && height[i] > height[si.top()])
			{
				int top = si.top();
				si.pop();
				if (si.empty())
				{
					break;
				}
				int pre = si.top();
				int w = i - pre - 1;
				int h = std::min(height[i], height[pre]) - height[top];
				sum += w * h;
			}

			si.push(i);
		}

		return sum;
	}
	
	//ʹ��˫ָ��ķ�����ȷ������2������ָ��
	//���������У��жϵ�ǰ����2��ָ���Ӧ��ֵС���ʹ���һ�����
	//��ʵ���Ǽ�����һ���߽磬����͵���һ��(�̰�)
	//2��max����������¼���������У����ҳ��ֹ������ֵ
	//�����ǰֵ�����ֵ�󣬿϶���û���ֵ��ݣ��޷���ˮ
	//�����ǰֵ�����ֵС���˿̵��ݳ��֣�ͬ���һ�������ֵ
	//��һ���б��Լ��ߵ�ֵ���Լ����λ�þ��γ��˵���
	//��ʱ��ǰ������ֵ�϶�����һ��ı߽�ֵС�����̰�
	//���ֵ��ȥ��ǰ����λ��ֵ������λ�õĻ�ˮ�����ۼƽ��
	int TrapTwoPointers(const std::vector<int>& height)
	{
		if (height.size() == 0)
		{
			return 0;
		}

		int max_left = 0;
		int max_right = 0;
		int left = 0;
		int right = height.size() - 1;
		int sum = 0;
		while (left < right)
		{
			if (height[left] < height[right])
			{
				if (height[left] > max_left)
				{
					max_left = height[left];
				}
				else
				{
					sum += max_left - height[left];
				}
				++left;
			}
			else
			{
				if (height[right] > max_right)
				{
					max_right = height[right];
				}
				else
				{
					sum += max_right - height[right];
				}
				++right;
			}
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