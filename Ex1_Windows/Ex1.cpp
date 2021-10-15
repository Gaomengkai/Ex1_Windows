#include "Ex1.h"

void initQueue(Queue* const p, int m)//初始化p指队列：最多申请m个元素
{
	if (m <= 0)//若m不合法
	{
		throw"Wrong argument";
	}
	if (p->elems)//若p已存在，释放原内存防止内存泄漏
	{
		*(int*)&p->max = 0;
		free(*(int**)&p->elems);
		*(int**)&p->elems = nullptr;
	}
	*(int**)&p->elems = (int*)malloc(m * sizeof(int));
	*(int*)&p->max = m;
	p->head = p->tail = 0;
}

void initQueue(Queue* const p, const Queue& s)//用s深拷贝初始化p指队列
{
	if (p->elems)//若p已存在，释放原内存防止内存泄漏
	{
		*(int*)&p->max = 0;
		free(*(int**)&p->elems);
		*(int**)&p->elems = nullptr;
	}
	*(int*)&p->max = s.max;
	*(int**)&p->elems = (int*)malloc(p->max * sizeof(int));
	p->head = s.head;
	p->tail = s.tail;
	int i;
	for (i = 0; i < p->max; i++)
	{
		p->elems[i] = s.elems[i];
	}
}

void initQueue(Queue* const p, Queue&& s)//用s移动初始化p指队列
{
	if (p->elems)//若p已存在，释放原内存防止内存泄漏
	{
		*(int*)&p->max = 0;
		free(*(int**)&p->elems);
		*(int**)&p->elems = nullptr;
	}
	*(int*)&p->max = s.max;
	*(int**)&p->elems = s.elems;
	p->head = s.head;
	p->tail = s.tail;
	*(int**)&s.elems = nullptr;
	*(int*)&s.max = 0;
	s.head = s.tail = 0;
}

int  number(const Queue* const p)//返回p指队列的实际元素个数
{
	return p->tail >= p->head ? p->tail - p->head : p->tail + p->max - p->head;
}

int  size(const Queue* const p)//返回p指队列申请的最大元素个数max
{
	return p->max;
}

Queue* const enter(Queue* const p, int e)//将e入队列尾部，并返回p
{
	if ((p->tail + 1) % p->max == p->head)//判满
	{
		throw "Queue is full!";
	}
	else
	{
		p->elems[p->tail] = e;
		p->tail = (p->tail + 1) % p->max;
		return p;
	}
}


Queue* const leave(Queue* const p, int& e)//从队首出元素到e，并返回p
{
	if (p->head == p->tail)//判空
	{
		throw "Queue is empty!";
	}
	else
	{
		e = p->elems[p->head];
		p->head = (p->head + 1) % p->max;
		return p;
	}
}


Queue* const assign(Queue* const p, const Queue& q)//深拷贝赋s给队列并返回p
{
	if (p->elems == q.elems)//若传入的两个参数是同一个队列
	{
		return p;
	}
	if (*(int**)&p->elems)//若p已存在，释放原内存防止内存泄漏
	{
		free(*(int**)&p->elems);
		*(int**)&p->elems = nullptr;
	}
	*(int**)&p->elems = (int*)malloc(q.max * sizeof(int));
	*(int*)&p->max = q.max;
	int i;
	for (i = 0; i < p->max; i++)
	{
		p->elems[i] = q.elems[i];
	}
	p->head = q.head;
	p->tail = q.tail;
	return p;
}


Queue* const assign(Queue* const p, Queue&& q)//移动赋s给队列并返回p
{
	if (p->elems == q.elems)//若传入的两个参数是同一个队列
	{
		return p;
	}
	if (*(int**)&p->elems)//若p已存在，释放原内存防止内存泄漏
	{
		free(*(int**)&p->elems);
		*(int**)&p->elems = nullptr;
	}
	*(int**)&p->elems = q.elems;
	*(int*)&p->max = q.max;
	p->head = q.head;
	p->tail = q.tail;
	*(int**)&q.elems = nullptr;
	*(int*)&q.max = 0;
	q.head = q.tail = 0;
	return p;
}

char* print(const struct Queue* const p, char* s)//打印p指队列至s并返回s
{
	int m = p->max;
	for (int i = p->head; i != p->tail; i = (i + 1) % m) {
		char* location = s + strlen(s);
		sprintf(location, "%d,", p->elems[i]);
	}
	return s;
}

void destroyQueue(Queue* const p)//销毁p指向的队列
{
	if (*(int**)&p->elems)//若p已存在，释放原内存防止内存泄漏，防止释放空指针
	{
		free(*(int**)&p->elems);
		*(int**)&p->elems = nullptr;
	}
	*(int*)&p->max = 0;
	p->head = p->tail = 0;
}