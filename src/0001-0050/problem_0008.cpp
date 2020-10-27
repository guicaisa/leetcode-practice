#include <stdio.h>
#include <vector>
#include <string>
#include <cctype>

/**
 * https://leetcode.com/problems/string-to-integer-atoi/
 */

class Solution
{
public:
	/**
	 * �����ַ�������������һ�������ַ�����'+'����'-'Ϊ���ˣ�֮����������κη������ַ���ֱ��break
	 * �������֮ǰ����������������ַ�����ֱ�ӷ���0�����ջ��һ���������飬����ÿһλ������
	 * �������飬ÿ�ν�λ���������ս������ÿ�ε�ǰ��λ����֮ǰ�ж�Խ��Ŀ���
	 */
	int MyAtoi(const std::string& str) 
	{
		int character_flag = 0;
		bool positive = true;
		std::vector<int> digit_vec;

		for (size_t i = 0; i < str.size(); ++i)
		{
			if (character_flag == 0)
			{
				if (str[i] != ' ' && str[i] != '-' && str[i] != '+' && !isdigit(str[i]))
				{
					return 0;
				}

				if (str[i] != ' ')
				{
					character_flag = 1;
				}

				if (str[i] == '-')
				{
					positive = false;
				}
				else if (isdigit(str[i]))
				{
					digit_vec.emplace_back((str[i] - '0') * (positive ? 1 : -1));
				}
			}
			else
			{
				if (!isdigit(str[i]))
				{
					break;
				}

				digit_vec.emplace_back((str[i] - '0') * (positive ? 1 : -1));
			}
		}

		int result = 0;
		for (size_t i = 0; i < digit_vec.size(); ++i)
		{
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit_vec[i] > 7))
			{
				return INT_MAX;
			}
			
			if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit_vec[i] < -8))
			{
				return INT_MIN;
			}

			result = result * 10 + digit_vec[i];
		}

		return result;
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//	std::string str = "42";
//
//	int ret = s.MyAtoi(str);
//
//
//	return 0;
//}