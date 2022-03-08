#include <iostream>
#include <string>
#include <ctime>
#include "List.h"
#include "DoubleList.h"
#include "BinaryTree.h"
#include "Queue.h"
#include "Steck.h"

using namespace std;

int main()
{
	srand(time(0));
	system("chcp 1251");
	doublelist<int> one;
	one.push_back(9);
	one.push_front(3);
	one.push_back(1);
	one.push_back(4);
	for (int i = 0; i < one.GetSize(); i++)
	{
		cout << one[i] << " ";
	}
	cout << endl;
	one.insert(7, 3);
	for (int i = 0; i < one.GetSize(); i++)
	{
		cout << one[i] << " ";
	}
	cout << endl;
	one.removeAt(2);
	for (int i = 0; i < one.GetSize(); i++)
	{
		cout << one[i] << " ";
	}
	cout << endl;
	one.pop_front();
	for (int i = 0; i < one.GetSize(); i++)
	{
		cout << one[i] << " ";
	}
	cout << endl;
}