#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/

class Solution
{
public:
	// words�е������ַ������ǵȳ��ģ����Ե�������s��Ѱ�Ҵ������Ӵ���ʱ��
	// ����ʹ��һ���̶��Ĳ���single_len�������ַ���
	// ����ʹ��һ��map������words�������ַ����ֵĴ���
	// total_len����words�������ַ����ɵ��Ӵ����ܳ���
	// ����s�ַ�������ÿ���ַ�Ϊ��㣬��single_len�ĳ��Ȼ�ȡÿ���ַ�
	// ʹ����ʱ��map��������Щ�ַ����ֵĴ�����������֮ǰ��map���ѱ�����ַ����ֵĴ������жԱ�
	// ���������������ҵ����ʵ��Ӵ���ʼλ�ã��粻������������һ��ѭ������
	std::vector<int> FindSubString(const std::string& s, const std::vector<std::string>& words) 
	{
		std::vector<int> vi;
		
		if (s == "" || words.size() == 0)
		{
			return vi;
		}

		size_t single_len = words[0].size();
		size_t total_len = single_len * words.size();
		size_t s_len = s.size();
		std::unordered_map<std::string, int> words_map;

		for (size_t i = 0; i < words.size(); ++i)
		{
			words_map[words[i]] += 1;
		}

		for (size_t i = 0; i < s_len && s_len - i >= total_len; ++i)
		{
			bool flag = true;
			std::unordered_map<std::string, int> temp_words_map;
			for (size_t j = 0; j < words.size(); ++j)
			{
				std::string word = s.substr(i + j * single_len, single_len);
				if (temp_words_map[word] < words_map[word])
				{
					temp_words_map[word] += 1;
				}
				else
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				vi.emplace_back(i);
			}
		}

		return vi;
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//
//	std::string str = "wordgoodgoodgoodbestword";
//	std::vector<std::string> vs = { "word", "good", "best", "word" };
//
//	std::vector<int> vi = s.FindSubString(str, vs);
//
//	return 0;
//}


