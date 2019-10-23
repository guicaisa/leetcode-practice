#include <stdio.h>
#include <stdlib.h>
#include <vector>

/**
 * https://leetcode.com/problems/sudoku-solver/
 */

class Solution 
{
public:
	/**
	 * ���Ƚ��Ѿ����ڵ�ֵ��ص��У��У���Ĳ��ֽ�������
	 * Ȼ�����ҵ�һ��Ϊ'.'������λ��Ϊ��ʼ�����еݹ����
	 * ����'1' - '9'���ж��Ƿ���ͬ�У�ͬ�У�ͬ���м���ڸ�ֵ
	 * ���û�еĻ������������λ���Լ��У��У����е����ֵ��������
	 * ����һ����'.'��λ�ÿ�ʼ�����������жϲ���
	 * �������չ���ĵݹ����ʧ�ܣ�˵����ǰ����ڵ��ֵѡ���������
	 * ����ǰѡ���ֵ������У��У����е�ֵ���ã���������'1' - '9'��ʣ�µĿ�ѡֵ
	 * ֱ������չ���ĵݹ�����ɹ������ؽ���
	 */
	void SolveSudoku(std::vector<std::vector<char>>& board)
	{
		int vr[9][9] = { 0 };
		int vc[9][9] = { 0 };
		int vs[9][9] = { 0 };

		int x = 0;
		int y = 0;
		int first = 0;

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (board[i][j] != '.')
				{
					int t = board[i][j] - '0' - 1;
					int n = (i / 3 * 3) + (j / 3);

					vr[i][t] = vc[j][t] = vs[n][t] = 1;
				}
				else
				{
					if (first == 0)
					{
						first = 1;
						x = i;
						y = j;
					}
				}
			}
		}

		Recursive(board, vr, vc, vs, x, y);
	}

	bool Recursive(std::vector<std::vector<char> >& board, int(*vr)[9], int(*vc)[9], int(*vs)[9], int x, int y)
	{
		int n = (x / 3 * 3) + (y / 3);

		for (char i = '1'; i <= '9'; ++i)
		{
			int t = i - '0' - 1;
			if (vr[x][t] == 0 && vc[y][t] == 0 && vs[n][t] == 0)
			{
				vr[x][t] = vc[y][t] = vs[n][t] = 1;
				board[x][y] = i;

				int n_x = 0;
				int n_y = 0;
				int first = 0;

				for (int i = y == 8 ? x + 1 : x; i < board.size(); ++i)
				{
					for (int j = i == x ? y + 1 : 0; j < board[i].size(); ++j)
					{
						if (board[i][j] == '.')
						{
							first = 1;
							n_x = i;
							n_y = j;
							break;
						}
					}

					if (first == 1)
					{
						break;
					}
				}

				if (n_x == 0 && n_y == 0)
				{
					return true;
				}

				bool flag = Recursive(board, vr, vc, vs, n_x, n_y);

				if (flag)
				{
					return true;
				}

				vr[x][t] = vc[y][t] = vs[n][t] = 0;
				board[x][y] = '.';
			}
		}

		return false;
	}
};

//int main(int argc, char** argv)
//{
//	Solution s;
//
//	std::vector<std::vector<char> > board;
//	board.emplace_back(std::vector<char>{'5', '3', '.', '.', '7', '.', '.', '.', '.'});
//	board.emplace_back(std::vector<char>{'6', '.', '.', '1', '9', '5', '.', '.', '.'});
//	board.emplace_back(std::vector<char>{'.', '9', '8', '.', '.', '.', '.', '6', '.'});
//	board.emplace_back(std::vector<char>{'8', '.', '.', '.', '6', '.', '.', '.', '3'});
//	board.emplace_back(std::vector<char>{'4', '.', '.', '8', '.', '3', '.', '.', '1'});
//	board.emplace_back(std::vector<char>{'7', '.', '.', '.', '2', '.', '.', '.', '6'});
//	board.emplace_back(std::vector<char>{'.', '6', '.', '.', '.', '.', '2', '8', '.'});
//	board.emplace_back(std::vector<char>{'.', '.', '.', '4', '1', '9', '.', '.', '5'});
//	board.emplace_back(std::vector<char>{'.', '.', '.', '.', '8', '.', '.', '7', '9'});
//
//	s.SolveSudoku(board);
//
//	for (int i = 0; i < board.size(); ++i)
//	{
//		for (int j = 0; j < board[i].size(); ++j)
//		{
//			printf("%c ", board[i][j]);
//		}
//
//		printf("\n");
//	}
//
//	return 0;
//}