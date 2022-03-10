#pragma once
#include<iostream>
#include<string>

using namespace std;

class warehouse
{
public:
	friend void SetP(warehouse &data)
	{
		SetDefault(data);
		/*cout << "Введите наименование: ";
		cin >> data.name;
		cout << "Введите кол-во: ";
		cin >> data.num;
		cout << "Введите цену: ";
		cin >> data.price;
		cout << "Введите дату поступления: ";
		cin >> data.date;*/
	}
	friend void ShowP(warehouse &data)
	{
		cout << "Наименование - " << data.name << endl;
		cout << "Кол-во - " << data.num << endl;
		cout << "Цена - " << data.price << endl;
		cout << "Дата поступления - " << data.date << endl;
	}
	friend void SetDefault(warehouse &data)
	{
		data.name = to_string(rand() % 10);
		data.num = rand() % 10;
		data.price = rand() % 10;
		data.date = to_string(rand() % 10);
	}
	string name;
	int num;
	double price;
	string date;
};

template<typename T>
class binarytree
{
public:
	binarytree()
	{
		size = 0;
		root = nullptr;
	}
	~binarytree()
	{
		deleteTree(root->value);
	}
	void Push(T value)
	{
		if (root == nullptr)
		{
			root = new node<T>(value);
			size++;
		}
		else
		{
			node<T>* temp = root;
			while (root->left != nullptr && root->right != nullptr)
			{
				if (value > temp->value)
				{
					temp = temp->right;
				}
				else
				{
					temp = temp->left;
				}
			}
			if (value > temp->value)
			{
				root->right = new node<T>(value);
			}
			else
			{
				root->left = new node<T>(value);
			}
			size++;
		}
	}
	void show_info(T value)
	{
		
			node<T>* temp = root;
			while (temp->value != value)
			{
				if (temp->left != nullptr || temp->right != nullptr) 
				{
					if (value > temp->value && temp->right != nullptr)
					{
						temp = temp->right;
					}
					else if (value < temp->value && temp->right != nullptr)
					{
						temp = temp->left;
					}
				}
				else
				{
					break;
				}
			}
			if (temp->value == value)
			{
				ShowP(temp->data);
			}
			else
			{
				cout << "Такого значения нету в дереве." << endl;
			}
	}
	void GetSize() { return size; }
	void change(T value)
	{
		node<T>* temp = root;
		while (temp->value != value)
		{
			if (temp->left != nullptr || temp->right != nullptr)
			{
				if (temp->left->value == value || temp->right->value == value)
				{
					break;
				}
				if (value > temp->value && temp->right != nullptr)
				{
					temp = temp->right;
				}
				else if (value < temp->value && temp->right != nullptr)
				{
					temp = temp->left;
				}
			}
			else
			{
				break;
			}
		}
		if (temp->left != nullptr && temp->left->value == value)
		{
			node<T>* tempDel = temp->left;
			temp->left = new node<T>(value, tempDel->left, tempDel->right);
			delete tempDel;
		}
		else if (temp->right != nullptr && temp->right->value == value)
		{
			node<T>* tempDel = temp->right;
			temp->right = new node<T>(value, tempDel->left, tempDel->right);
			delete tempDel;
		}
		else
		{
			cout << "Такого значения нету в дереве." << endl;
		}
	}
	void deleteTree(T value)
	{
		removeAt(value);
	}
	void removeAt(T value)
	{
		node<T>* temp = root;
		while (temp->value != value || temp->left != nullptr && temp->right != nullptr)
		{
			if (temp->left->value == value || temp->right->value == value)//Находим предыдущий элемент.
			{
				break;
			}
			if (value > temp->value)
			{
				temp = temp->right;
			}
			else if (value < temp->value)
			{
				temp = temp->left;
			}
		}
		if (temp->left == nullptr && temp->right == nullptr)
		{

		}
		if (temp->left != nullptr && temp->left->value == value)//Реализовать удаление.
		{
			node<T>* tempDel = temp->left;
			if (tempDel->right != nullptr)
			{
				node<T>* donor = tempDel->right;
				while (tempDel->left != nullptr)
				{
					donor = tempDel->left;
				}
				temp->left = donor;
				donor->left = tempDel->left;
				donor->right = tempDel->right;
				delete tempDel;
				size--;
				tempDel = nullptr;
				donor = donor->right;
				while (tempDel->left != donor)
				{
					donor = donor->left;
				}
				donor->left = nullptr;
			}
			else if (tempDel->left != nullptr)
			{
				node<T>* donor = tempDel->left;
				temp->left = donor;
				delete tempDel;
				size--;
				tempDel = nullptr;
			}
			else
			{
				temp->left = nullptr;
				delete tempDel;
				size--;
				tempDel = nullptr;
			}
		}
		else if (temp->right != nullptr && temp->right->value == value)
		{
			node<T>* tempDel = temp->right;
			if (tempDel->right != nullptr)
			{
				node<T>* donor = tempDel->right;
				while (tempDel->left != nullptr)
				{
					donor = tempDel->left;
				}
				temp->left = donor;
				donor->left = tempDel->left;
				donor->right = tempDel->right;
				delete tempDel;
				size--;
				tempDel = nullptr;
				donor = donor->right;
				while (tempDel->left != donor)
				{
					donor = donor->left;
				}
				donor->left = nullptr;
			}
			else if (tempDel->left != nullptr)
			{
				node<T>* donor = tempDel->left;
				temp->right = donor;
				delete tempDel;
				size--;
				tempDel = nullptr;
			}
			else
			{
				temp->right = nullptr;
				delete tempDel;
				size--;
				tempDel = nullptr;
			}
		}
		else
		{
			cout << "Невозможно удалить." << endl;
		}
	}
private:
	template<typename T>
	class node
	{
	public:
		node(T value, node* left = nullptr, node* right = nullptr)
		{
			SetP(data);
			this->left = left;
			this->right = right;
			this->value = value;
		}
		T value;
		node* left;
		node* right;
		warehouse data;
	};
	int size;
	node<T>* root;
	
};