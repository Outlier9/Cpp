#pragma once
// 也可以用bit1命名，同样是内部的变量名称不能重复
namespace bit2
{
	struct LNode
	{
		int val;
		struct LNode* next;
		struct LNode* prev;
	};

	void Init(struct LNode* pq);
	void Push(struct LNode* pq, int x);

}