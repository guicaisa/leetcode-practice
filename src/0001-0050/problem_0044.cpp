#include <stdio.h>
#include <vector>
#include <string>

/**
 * https://leetcode.com/problems/wildcard-matching/
 */

class Solution {
public:
	// �������ĺ��ĵ�������δ���'*'����֪'*'����ƥ��0�������ַ�
	// ��ͷ��ʼ����s��p��������'*'��ʱ�����ȼ���'*'ƥ�����0���ַ�
	// ���浱ǰ��s������λ�ú�'*'������λ�ã�p�����һλ
	// ���û����'*'�Ļ�����������Ƿ�ƥ�䣬p[j] == '?' ���� s[i] == p[j]
	// ƥ��Ļ���ͬ�������λ�������ƥ��Ļ������֮ǰ�Ƿ���������'*'
	// ���û�У�ֱ�ӷ���ʧ�ܣ�����еĻ�����֮ǰ�����s[start_index_i]����Ϊ��֮ǰ��'*'ƥ��
	// ���ñ���λ��Ϊ�ϴμ�¼ʱ��������s������ϴμ�¼��λ���Զ������ƶ�
	// p��λ����һ��'*'֮�������λ�ã����¿�ʼ����
	bool IsMatch(const std::string& s, const std::string& p) {
		int i = 0;
		int j = 0;
		int star_index_i = -1;
		int star_index_j = -1;

		for (; i < s.size(); ) {
			if (j < p.size() && p[j] == '*') {
				star_index_i = i;
				star_index_j = j++;
			}
			else if (j < p.size() && (p[j] == '?' || s[i] == p[j])) {
				++i;
				++j;
			}
			else {
				if (star_index_i >= 0) {
					i = ++star_index_i;
					j = star_index_j + 1;
				}
				else {
					return false;
				}
			}
		}

		while (j < p.size() && p[j] == '*') {
			++j;
		}

		return j == p.size();
	}
};

//int main(int argc, char** argv) {
//	Solution s;
//
//	std::string str = "abds";
//	std::string p = "*ac";
//
//	bool ret = s.IsMatch(str, p);
//
//	return 0;
//}