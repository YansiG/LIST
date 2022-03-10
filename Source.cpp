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
	binarytree<int> one;
	one.Push(10);
	one.Push(12);
	one.Push(8);
	one.Push(9);
	one.show_info(10);
	//one.removeAt(10);
}