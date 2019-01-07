#include <stdio.h>

/**
 * https://leetcode.com/problems/add-two-numbers/
 */

 struct ListNode 
 {
	ListNode(int x) 
		: val(x), 
		next(NULL) 
	{
	}

    int val;
    ListNode* next;
 };

class Solution
{
public:
	/**
	 * ��λ����Ҫ������λ��ֵ��������һ����ӵ�ʱ�����
	 * ���һλ����������н�λ��ֵ����Ҫ�ټ�һ���ڵ������
	 */
	ListNode* AddTwoNumbers(const ListNode* l1, const ListNode* l2)
	{
		if (l1 == NULL && l2 == NULL)
		{
			return new ListNode(0);
		}

		ListNode* head = NULL;
		ListNode* cur_node = NULL;
		int carry_add = 0;

		while (l1 || l2)
		{
			if (cur_node == NULL)
			{
				cur_node = new ListNode(0);
				head = cur_node;
			}
			else
			{
				cur_node->next = new ListNode(0);
				cur_node = cur_node->next;
			}

			int sum = 0;
			
			if (l1 && l2)
			{
				sum = l1->val + l2->val + carry_add;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 && l2 == NULL)
			{
				sum = l1->val + carry_add;
				l1 = l1->next;
			}
			else if (l2 && l1 == NULL)
			{
				sum = l2->val + carry_add;
				l2 = l2->next;
			}

			cur_node->val = sum % 10;
			carry_add = sum / 10;
		}

		if (carry_add != 0)
		{
			cur_node->next = new ListNode(carry_add);
		}

		return head;
	}

	/**
	 * �򻯴���ṹ������ 
	 */
	ListNode* AddTwoNumbersBetter(const ListNode* l1, const ListNode* l2)
	{
		ListNode head(0);
		ListNode* cur_node = &head;
		int carry_add = 0;

		while (l1 || l2 || carry_add)
		{
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry_add;

			cur_node->next = new ListNode(sum % 10);
			cur_node = cur_node->next;
			carry_add = sum / 10;

			if (l1)
			{
				l1 = l1->next;
			}

			if (l2)
			{
				l2 = l2->next;
			}
		}

		return head.next;
	}

};