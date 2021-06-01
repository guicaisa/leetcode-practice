#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

// https://leetcode-cn.com/problems/valid-sudoku/

class Solution 
{
public:
	// ����һ���У��У��Ź���Ķ�ά���飬������ʾ��ĳ�У�ĳ�У�ĳ�Ź�����
	// 1-9�������Ƿ��Ѿ����ڣ��Ź�������n = i / 3 * 3 + j / 3
	bool IsValidSudoku(const std::vector<std::vector<char> >& board)
	{
		int vr[9][9] = { 0 };
		int vc[9][9] = { 0 };
		int vs[9][9] = { 0 };

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (board[i][j] != '.')
				{
					int t = board[i][j] - '0' - 1;
					int n = (i / 3 * 3) + (j / 3);

					if (vr[i][t] == 1 || vc[j][t] == 1 || vs[n][t] == 1)
					{
						return false;
					}

					vr[i][t] = 1;
					vc[j][t] = 1;
					vs[n][t] = 1;
				}
			}
		}

		return true;
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//
//	std::vector<std::vector<char> > board;
//	board.emplace_back(std::vector<char>{'8', '3', '.', '.', '7', '.', '.', '.', '.'});
//	board.emplace_back(std::vector<char>{'6', '.', '.', '1', '9', '5', '.', '.', '.'});
//	board.emplace_back(std::vector<char>{'.', '9', '8', '.', '.', '.', '.', '6', '.'});
//	board.emplace_back(std::vector<char>{'8', '.', '.', '.', '6', '.', '.', '.', '3'});
//	board.emplace_back(std::vector<char>{'4', '.', '.', '8', '.', '3', '.', '.', '1'});
//	board.emplace_back(std::vector<char>{'7', '.', '.', '.', '2', '.', '.', '.', '6'});
//	board.emplace_back(std::vector<char>{'.', '6', '.', '.', '.', '.', '2', '8', '.'});
//	board.emplace_back(std::vector<char>{'.', '.', '.', '4', '1', '9', '.', '.', '5'});
//	board.emplace_back(std::vector<char>{'.', '.', '.', '.', '8', '.', '.', '7', '9'});
//
//	bool ret = s.IsValidSudoku(board);
//
//	return 0;
//}