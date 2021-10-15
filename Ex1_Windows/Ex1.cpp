#include "Ex1.h"

void initQueue(Queue* const p, int m)//��ʼ��pָ���У��������m��Ԫ��
{
	if (m <= 0)//��m���Ϸ�
	{
		throw"Wrong argument";
	}
	if (p->elems)//��p�Ѵ��ڣ��ͷ�ԭ�ڴ��ֹ�ڴ�й©
	{
		*(int*)&p->max = 0;
		free(*(int**)&p->elems);
		*(int**)&p->elems = nullptr;
	}
	*(int**)&p->elems = (int*)malloc(m * sizeof(int));
	*(int*)&p->max = m;
	p->head = p->tail = 0;
}

void initQueue(Queue* const p, const Queue& s)//��s�����ʼ��pָ����
{
	if (p->elems)//��p�Ѵ��ڣ��ͷ�ԭ�ڴ��ֹ�ڴ�й©
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

void initQueue(Queue* const p, Queue&& s)//��s�ƶ���ʼ��pָ����
{
	if (p->elems)//��p�Ѵ��ڣ��ͷ�ԭ�ڴ��ֹ�ڴ�й©
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

int  number(const Queue* const p)//����pָ���е�ʵ��Ԫ�ظ���
{
	return p->tail >= p->head ? p->tail - p->head : p->tail + p->max - p->head;
}

int  size(const Queue* const p)//����pָ������������Ԫ�ظ���max
{
	return p->max;
}

Queue* const enter(Queue* const p, int e)//��e�����β����������p
{
	if ((p->tail + 1) % p->max == p->head)//����
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


Queue* const leave(Queue* const p, int& e)//�Ӷ��׳�Ԫ�ص�e��������p
{
	if (p->head == p->tail)//�п�
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


Queue* const assign(Queue* const p, const Queue& q)//�����s�����в�����p
{
	if (p->elems == q.elems)//�����������������ͬһ������
	{
		return p;
	}
	if (*(int**)&p->elems)//��p�Ѵ��ڣ��ͷ�ԭ�ڴ��ֹ�ڴ�й©
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


Queue* const assign(Queue* const p, Queue&& q)//�ƶ���s�����в�����p
{
	if (p->elems == q.elems)//�����������������ͬһ������
	{
		return p;
	}
	if (*(int**)&p->elems)//��p�Ѵ��ڣ��ͷ�ԭ�ڴ��ֹ�ڴ�й©
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

char* print(const struct Queue* const p, char* s)//��ӡpָ������s������s
{
	int m = p->max;
	for (int i = p->head; i != p->tail; i = (i + 1) % m) {
		char* location = s + strlen(s);
		sprintf(location, "%d,", p->elems[i]);
	}
	return s;
}

void destroyQueue(Queue* const p)//����pָ��Ķ���
{
	if (*(int**)&p->elems)//��p�Ѵ��ڣ��ͷ�ԭ�ڴ��ֹ�ڴ�й©����ֹ�ͷſ�ָ��
	{
		free(*(int**)&p->elems);
		*(int**)&p->elems = nullptr;
	}
	*(int*)&p->max = 0;
	p->head = p->tail = 0;
}