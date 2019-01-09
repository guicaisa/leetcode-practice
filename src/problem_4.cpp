#include <stdio.h>
#include <vector>
#include <algorithm>

/**
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

class Solution
{
public:
	/**
	 * ����2������ĳ�������м�ֵ��������������ֱ��2��������ȡֵ����������
	 * ֱ���ҵ��м�ֵ��Ч�ʵ��£������ڱ������
	 */
	double FindMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) 
	{
		int even_flag = (nums1.size() + nums2.size()) % 2 == 0 ? 1 : 0;
		int previous_num = 0;
		int current_num = 0;
		size_t middle_index = (nums1.size() + nums2.size()) / 2;
		int index = -1;

		for (size_t i = 0, j = 0; ; )
		{
			if (i < nums1.size() && j < nums2.size())
			{
				if (nums1[i] < nums2[j])
				{
					current_num = nums1[i++];
				}
				else
				{
					current_num = nums2[j++];
				}
			}
			else if (i < nums1.size())
			{
				current_num = nums1[i++];
			}
			else if (j < nums2.size())
			{
				current_num = nums2[j++];
			}
			else
			{
				break;
			}

			if (++index == middle_index)
			{
				return even_flag == 1 ? (previous_num + current_num) / 2.0f : current_num;
			}
			previous_num = current_num;
		}

		return 0;
	}

	/**
	 * ������λ����ԭ��������2��������õ�����A��B���ȷֱ�Ϊm��n����һ����ĳ�����ָ������i��j
	 * ��A��B�У���A��B�ֱ��Ϊ2�����飬A�� + B�󹹳����������벿�֣�A�� + B�ҹ�����������Ұ벿��
	 * ���ұ�֤A���B��������һ������Զ <= A�Һ�B���е�����һ��������A[i - 1] <= B[j] && B[j - 1] <= A[i]������
	 * A: 1 4 5 9 11 iΪ3(��0��ʼ)��A��Ϊ 1 4 5��A��Ϊ9 11 
	 * B: 2 3 6 8 10 jΪ2(��0��ʼ)��B��Ϊ 2 3��A��Ϊ6 8 10
	 * ������ɵ�����Ϊ 1 2 3 4 5 6 8 9 10 11����λ��λΪ (5 + 6) / 2 = 5.5
	 *
	 * �ɴ˽������ǿ����Ƶ���һ����ʽ i + j = m - i + n - j����j = (m + n + 1) / 2 - i������+1��Ϊ�˴���m+nΪ����ʱ�����
	 * �����ʽ��һ��Ҫ��m <= n����Ϊ 0 <= i <= m�����m > n�����ܻᵼ��jΪ����
	 * ֮��Ϳ��Զ�����A���ж��ֲ����ˣ��ҵ����ʵ�i����ͨ����ʽ�õ���Ӧ��j�����ݽ���ƶ���һ�ζ��ֲ��ҵķ�����ǵó����
	 * ���ֲ�����ֻ�������������
	 *
	 * 1: (i == 0 || j == n || A[i - 1] <= B[j]) && (j == 0 || i == m || B[j - 1] <= A[i])����ʾ�ҵ���ȷ���
	 * ���ǵ��߽������������i - 1��i��j - 1��j������ֵ��Ч�����϶����ж�����
	 * 2: i > 0 && j < len2 && A[i - 1] > B[j]����ǰ��iֵ����i��Ҫ�����ƶ����ҵ���С��ֵ(�����ǰ���������)��������j��ʽ��Ӧ��j������ҵ������ֵ
	 * ����һ�ζ��ֲ��ҵ����䶨λ���������ͬ����Ҫ���Ǳ߽�
	 * 3: j > 0 && i < len1 && B[j - 1] > A[i]����ǰ��iֵ��С��i��Ҫ�����ƶ����ҵ������ֵ��������j��ʽ��Ӧ��j���С���ҵ���С��ֵ
	 * ����һ�ζ��ֲ��ҵ����䶨λ���Ұ�����ͬ����Ҫ���Ǳ߽�
	 *
	 * ���Ͻ��ж��ֲ��ң�ֱ���ҵ��������ѭ���������õ���Ӧ��i��j�����m + nΪ����������λ��λmax(A[i - 1], B[j - 1])����ʱҲ��Ҫע��߽�
	 * ���i == 0��j == 0��Ҫȡ����һ��ֵ�����m + nΪż������ȡ(max(A[i - 1], B[j - 1]) + min(A[i], B[j])) / 2��ͬ������б߽�����Ļ���ȡ��һ��ֵ
	 */
	double FindMedianSortedArraysBetter(const std::vector<int>& nums1, const std::vector<int>& nums2)
	{
		if (nums1.size() > nums2.size())
		{
			return FindMedianSortedArraysBetter(nums2, nums1);
		}

		size_t len1 = nums1.size();
		size_t len2 = nums2.size();

		int low = 0;
		int high = len1;
		//i����mid
		int i = 0;
		int j = 0;

		while (low <= high)
		{
			i = (low + high) / 2;
			//�ɹ�ʽ i + j = (len1 - i + len2 - j)�Ƶ�����
			j = (len1 + len2 + 1) / 2 - i;
			
			if ((i == 0 || j == len2 || nums1[i - 1] <= nums2[j]) &&
				(i == len1 || j == 0 || nums2[j - 1] <= nums1[i]))
			{
				break;
			}
			else if (i > 0 && j < len2 && nums1[i - 1] > nums2[j])
			{
				high = i - 1;
			}
			else if (j > 0 && i < len1 && nums2[j - 1] > nums1[i])
			{
				low = i + 1;
			}
		}

		int left_max = 0;
		if (i == 0)
		{
			left_max = nums2[j - 1];
		}
		else if (j == 0)
		{
			left_max = nums1[i - 1];
		}
		else
		{
			left_max = std::max(nums1[i - 1], nums2[j - 1]);
		}

		if ((len1 + len2) % 2 == 1)
		{
			return left_max;
		}

		int right_min = 0;
		if (i == len1)
		{
			right_min = nums2[j];
		}
		else if (j == len2)
		{
			right_min = nums1[i];
		}
		else
		{
			right_min = std::min(nums1[i], nums2[j]);
		}

		return (left_max + right_min) / 2.0f;
	}
};

int main(int argc, char** argv)
{
	Solution s;
	std::vector<int> nums1;
	std::vector<int> nums2 = {1};

	double ret = s.FindMedianSortedArraysBetter(nums1, nums2);

	return 0;
}