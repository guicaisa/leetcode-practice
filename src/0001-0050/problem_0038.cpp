#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>

// https://leetcode-cn.com/problems/count-and-say/

class Solution 
{
public:
	// �ҵ����ɣ���"11"Ϊ��
	// ��������һ���ַ�����ʱ�򣬸��������ַ����е����֣�������ظ��ı���'11'
	// ����һ���ַ����оͱ��'21'�����ֻ��һ��'1'���ͱ��'11'����������������ͬ�ַ��������
	// ǰ��һ�����ִ����������ַ��ĸ��������ֻ��һ���Ļ�����ǰ��ֻ��1
	// ���� '2211' ��� '2221'��'2221' ��� '3211'��
	std::string CountAndSay(const int n) 
	{
		if (n == 0)
		{
			return "";
		}

		std::string s = "1";

		for (int i = n - 1; i > 0; --i)
		{
			std::string t;
			for (int j = 0; j < s.size(); ++j)
			{
				int count = 1;
				for (int k = j + 1; k < s.size() && s[j] == s[k]; ++k, ++j, ++count)
				{
					;
				}

				char buf[100];
				sprintf(buf, "%d", count);

				t += buf + std::string(1, s[j]);
			}

			s = t;
		}

		return s;
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//
//	std::string t = s.CountAndSay(6);
//
//	return 0;
//}