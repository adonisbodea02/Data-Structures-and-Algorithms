#include <iostream>
#include "PriorityQueue.h"
#include <crtdbg.h>
#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

bool r(int a, int b)
{
	return (a < b);
}

void test()
{
	PriorityQueue p(r);
	int value;
	int priority;
	p.push(100, 4);
	p.push(5, 6);
	p.push(23, 3);
	p.push(10, 7);
	p.push(11, 5);
	p.push(13, 8);
	p.pop(value, priority);
	assert(value == 13);
	assert(priority == 8);
	p.top(value, priority);
	assert(value == 10);
	assert(priority == 7);
	p.pop(value, priority);
	assert(value == 10);
	assert(priority == 7);
	p.pop(value, priority);
	p.pop(value, priority);
	p.pop(value, priority);
	p.pop(value, priority);

	try {
		p.pop(value, priority);
	}
	catch (std::string msj)
	{
		assert(msj == "Priority queue is empty!\n");
	}

	try {
		p.top(value, priority);
	}
	catch (std::string msj)
	{
		assert(msj == "Priority queue is empty!\n");
	}

	p.push(100, 4);
	p.push(5, 6);
	p.push(23, 3);
	p.push(10, 7);
	p.push(11, 5);
	p.push(13, 8);
	p.destroy();
}

void construct_pq(PriorityQueue& pq)
{
	cout << "Give the numbers of rows: \n";
	int m,a;
	cin >> m;
	cin.ignore();

	for (int i = 0; i < m; i++)
	{
		cout << "Give the capacity of the " << i << " row: \n";
		cin >> a;
		cin.ignore();
		for (int j = 1; j <= a; j++)
			pq.push(j, j);
	}
}

int compute_total_income(PriorityQueue &pq)
{
	cout << "Give the number of fans: \n";
	int n;
	cin >> n;
	cin.ignore();
	int value;
	int priority;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		pq.pop(value, priority);
		s += value;
	}
	return s;
}

void show_menu()
{
	cout << "1. Help Arsenal F.C. compute its maximum income\n";
	cout << "0. Exit\n";
}

int main()
{
	
	while (true)
	{
		show_menu();
		cout << "Choose your option: \n";
		int option;
		cin >> option;
		cin.ignore();
		if (option == 1)
		{
			PriorityQueue pq(r);
			construct_pq(pq);
			try {
				cout << "\nThe total income is: " << compute_total_income(pq) << " pounds\n\n";
				cout << "caca\n";
			}
			catch (std::string msj)
			{
				cout << "\nFans left outside :( \n\n";
			}
		}
		else
			break;
	}
	
	
	
	/*
	{
		test();
	}
	*/

	_CrtDumpMemoryLeaks();
}