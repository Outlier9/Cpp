#pragma once

namespace bit1
{
	struct QNode
	{
		int val;
		struct QNode* next;
	};
	struct Queue
	{
		struct QNode* head;
		struct QNode* tail;
		int size;
	};

	void Init(struct Queue* pq);
	void Push(struct Queue* pq, int x);

}