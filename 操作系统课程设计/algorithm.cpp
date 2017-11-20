#include"algorithm.h"
bool FCFS(Process  *p1, Process  *p2)
{
	return p1->get().ArriveTime < p2->get().ArriveTime;
}

bool PS(Process  *p1, Process  *p2)
{
	return (p1->get().Priority) >(p2->get().Priority);
}

bool SJF(Process  *p1, Process  *p2)
{
	return (p1->get().NeedTime - p1->get().PlayTime) < (p2->get().NeedTime - p2->get().PlayTime);
}