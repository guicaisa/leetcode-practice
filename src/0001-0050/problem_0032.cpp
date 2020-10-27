#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <map>

/**
 * https://leetcode.com/problems/longest-valid-parentheses/
 */

class Solution {
public:
	// ��̬�滮 dp������dp[i]����s[0...i]���ִ��������Ч���ų���
	// �������ŵ����ԣ���2�����
	// 1. ��s[i] == ')' ���� s[i - 1] == '('ʱ��s[i-1...i]֮�����Ч���ų���Ϊ2
	// ��ʱ�ж�s[0...s-2]֮�����Ч���ų��ȣ���dp[i - 2]���ڴ˻�����+2�����õ���ʽ
	// dp[i] = dp[i - 2] + 2
	// 2. ��s[i] == ')' ���� s[i - 1] == ')'ʱ����ǰѰ�Ҷ�Ӧ��'('�����һ��s[i]��')'ƥ��
	// �������ֻ�ܳ�����ǰ���'('������')'֮����Ӵ�����Ч���Ų��У����Ը���s[i - 1]��Ӧ��dp[i - 1]
	// �õ���Ч���ų��Ⱥ���ǰѰ���⴮�Ӵ�֮ǰ��һ���ַ��Ƿ�Ϊ'('����s[i - dp[i - 1] - 1] == '('
	// �����������s[i - dp[i - 1] - 1] �� s[i]֮�䶼����Ч�����ţ���ʱdp[i] = dp[i - 1] + 2
	// ���������s[i - dp[i - 1] - 1]֮ǰ��������Ч�������Ӵ��Ļ�������Ҫ�ټ����ⲿ�ֵĳ���
	// ������dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2
	int LongestValidParentheses(const std::string& s) 
	{
		if (s == "")
		{
			return 0;
		}

		int max_len = 0;
		std::vector<int> dp = std::vector<int>(s.size(), 0);

		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				dp[i] = 0;
			}
			else if (s[i] == ')' && s[i - 1] == '(')
			{
				dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
			}
			else if (s[i] == ')' && s[i - 1] == ')' && (i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(')
			{
				dp[i] = i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] + dp[i - 1] + 2 : dp[i - 1] + 2;
			}

			if (dp[i] > max_len)
			{
				max_len = dp[i];
			}
		}

		return max_len;
	}

	// ջ�ķ���
	// ����ջ��һֱ��һ����ʶ��ʼλ��������ֵ��'('��ջ��')'��ջ
	// ��ջʱ���ݸ�����������Ч���ŵĳ���
	int LongestValidParenthesesStack(const std::string& s)
	{
		int max_len = 0;
		std::stack<int> st;
		st.push(-1);

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				st.push(i);
			}
			else if (s[i] == ')')
			{
				if (st.empty())
				{
					st.push(i);
				}
				else
				{
					st.pop();
					if (st.empty())
					{
						st.push(i);
					}
					else
					{
						int offset = i - st.top();
						max_len = offset > max_len ? offset : max_len;
					}
				}
			}
		}

		return max_len;
	}

	// ���ұ���������'('��')'������Ե���������ж�
	int LongestValidParenthesesThrough(const std::string& s)
	{
		int max_len = 0;
		int left_count = 0;
		int right_count = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				++left_count;
			}
			else if (s[i] == ')')
			{
				++right_count;
			}

			if (left_count == right_count)
			{
				max_len = left_count + right_count > max_len ? left_count + right_count : max_len;
			}
			else if (right_count > left_count)
			{
				left_count = 0;
				right_count = 0;
			}
		}

		left_count = 0;
		right_count = 0;

		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (s[i] == '(')
			{
				++left_count;
			}
			else if (s[i] == ')')
			{
				++right_count;
			}

			if (left_count == right_count)
			{
				max_len = left_count + right_count > max_len ? left_count + right_count : max_len;
			}
			else if (left_count > right_count)
			{
				left_count = 0;
				right_count = 0;
			}
		}
		
		return max_len;
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//
//	std::string ss = "())((())";
//
//	int ret = s.LongestValidParenthesesStack(ss);
//
//
//	return 0;
//}
















