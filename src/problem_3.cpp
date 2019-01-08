#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution
{
public:
	/**
	 * ������⣬�������п��ܳ��ֵ��Ӵ�����Ч
	 */
	int LengthOfLongestSubstring(const std::string& s)
	{
		if (s == "")
		{
			return 0;
		}

		std::unordered_map<char, int> char_to_index;
		int max_length = 1;

		for (size_t i = 0; i < s.size(); )
		{
			if (char_to_index.find(s[i]) == char_to_index.end())
			{
				char_to_index[s[i]] = i;
				++i;

				if (i == s.size())
				{
					max_length = char_to_index.size() > max_length ? char_to_index.size() : max_length;
				}
			}
			else
			{
				if (char_to_index.size() > 1)
				{
					max_length = char_to_index.size() > max_length ? char_to_index.size() : max_length;
					i = char_to_index[s[i]] + 1;
					char_to_index.clear();
				}
				else
				{
					char_to_index[s[i]] = i;
					++i;
				}
			}
		}

		return max_length;
	}

	/**
	 * ʹ�û�������ά��һ���������ظ��ַ����ִ�����������
	 * ������չ�������ظ����ַ��;�����ӣ������ظ����ַ��������߽粻ͣ���ƣ�ֱ��ȥ���ظ��ַ�Ϊֹ
	 */
	int LengthOfLongestSubstringBetter(const std::string& s)
	{
		std::unordered_set<int> char_set;
		int max_length = 0;

		for (size_t i = 0, j = 0; i < s.size() && j < s.size(); )
		{
			if (char_set.find(s[j]) == char_set.end())
			{
				char_set.insert(s[j++]);
				max_length = char_set.size() > max_length ? char_set.size() : max_length;
			}
			else
			{
				char_set.erase(s[i++]);
			}
		}

		return max_length;
	}

	/**
	 * �������ڵĸ����׷�ʽ����������չ�����ظ��ַ�ʱ
	 * ֱ�ӽ�����������ַ���һ�γ��ֵ�λ��֮��ʡȥ�ಽ����
	 * ����"abba"�����Ĳ����������������ظ���bʱ������i�����Ѿ����µ��ڶ���b���ڵ�λ��
	 * �����ڽ�β�����ڶ���a��ʱ������֮ǰ���ֵ�a������С��i�����Բ��迼��
	 */
	int LengthOfLongestSubstringBetter2(const std::string& s)
	{
		std::unordered_map<char, int> char_to_index;
		int max_length = 0;

		for (size_t i = 0, j = 0; i < s.size() && j < s.size(); ++j)
		{
			if (char_to_index.find(s[j]) != char_to_index.end())
			{
				i = char_to_index[s[j]] + 1 > i ? char_to_index[s[j]] + 1 : i;
			}

			char_to_index[s[j]] = j;
			max_length = j - i + 1 > max_length ? j - i + 1 : max_length;
		}

		return max_length;
	}

	/**
	 * ԭ���뻬��������ͬ��Ҳ���������ظ��ַ���ʱ�򣬽���߽��ƶ����ϴγ��ָ��ַ���λ��
	 * ����ASCIIֻ��256λ��ʹ��256ά�ȵ���������ϣ�����Ӽ�
	 */
	int LengthOfLongestSubstringBetter3(const std::string& s)
	{
		std::vector<int> char_to_index(256, -1);
		int start = -1;
		int max_length = 0;

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (char_to_index[s[i]] > start)
			{
				start = char_to_index[s[i]];
			}

			max_length = i - start > max_length ? i - start : max_length;
			char_to_index[s[i]] = i;
		}

		return max_length;
	}
	
};

int main(int argc, char** argv)
{
	Solution s;
	std::string str = "abba";

	int len = s.LengthOfLongestSubstringBetter2(str);


	return 0;
}