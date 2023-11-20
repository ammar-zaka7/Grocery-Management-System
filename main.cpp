#include <iostream>
#include <fstream>
#include <string>
#include "customerclass.h"
#include "BST.h"
#include "hashtable.h"
#include "graph.h"
using namespace std;

BinarySearchTree inputCustomers()
{
	ifstream in;
	in.open("Customer.txt");
	char name[11][25], address[11][25];
	double bal[11];
	int phone[11];
	int count = 0;

	while (in.good() && count < 11)
	{
		in.get(name[count], 14);
		in >> phone[count];
		in.seekg(count * 55 + 28);
		in.get(address[count], 15);
		in >> bal[count];

		count++;
		in.seekg(count * 55);
	}
	in.close();

	BinarySearchTree tree;
	Customer* c1, * c2, * c3, * c4, * c5, *c6;
	Customer* c7, * c8, * c9, * c10, * c11;

	c1 = new Customer(name[0], phone[0], address[0], bal[0]);
	c2 = new Customer(name[1], phone[1], address[1], bal[1]);
	c3 = new Customer(name[2], phone[2], address[2], bal[2]);
	c4 = new Customer(name[3], phone[3], address[3], bal[3]);
	c5 = new Customer(name[4], phone[4], address[4], bal[4]);
	c6 = new Customer(name[5], phone[5], address[5], bal[5]);
	c7 = new Customer(name[6], phone[6], address[6], bal[6]);
	c8 = new Customer(name[7], phone[7], address[7], bal[7]);
	c9 = new Customer(name[8], phone[8], address[8], bal[8]);
	c10 = new Customer(name[9], phone[9], address[9], bal[9]);
	c11 = new Customer(name[10], phone[10], address[10], bal[10]);


	tree.insert(c1);
	tree.insert(c2);
	tree.insert(c3);
	tree.insert(c4);
	tree.insert(c5);
	tree.insert(c6);
	tree.insert(c7);
	tree.insert(c8);
	tree.insert(c9);
	tree.insert(c10);
	tree.insert(c11);

	return tree;
}

void input(Graph& Map)
{
	//Adding Verticies
	Map.AddVertex('A', "Block A");
	Map.AddVertex('B', "Block B");
	Map.AddVertex('C', "Block C");
	Map.AddVertex('D', "Block D");
	Map.AddVertex('E', "Block E");
	Map.AddVertex('F', "Block F");
	Map.AddVertex('G', "Block G");
	Map.AddVertex('H', "Block H");
	Map.AddVertex('I', "Block I");
	Map.AddVertex('J', "Block J");
	Map.AddVertex('K', "Block K");
	Map.AddVertex('L', "Block L");

	// Block A
	Map.AddEdge('A', 'I', 9); Map.AddEdge('I', 'A', 9);
	Map.AddEdge('A', 'E', 11); Map.AddEdge('E', 'A', 11);
	// Block B
	Map.AddEdge('B', 'D', 13); Map.AddEdge('D', 'B', 13);
	Map.AddEdge('B', 'H', 14); Map.AddEdge('H', 'B', 14);
	Map.AddEdge('B', 'C', 8); Map.AddEdge('C', 'B', 8);
	Map.AddEdge('B', 'J', 4); Map.AddEdge('J', 'B', 4);
	// Block C
	Map.AddEdge('C', 'K', 10); Map.AddEdge('K', 'C', 10);
	Map.AddEdge('C', 'H', 7); Map.AddEdge('H', 'C', 7);
	// Block D
	Map.AddEdge('D', 'K', 17); Map.AddEdge('K', 'D', 17);
	// Block E
	Map.AddEdge('E', 'I', 2); Map.AddEdge('I', 'E', 2);
	// Block F
	Map.AddEdge('F', 'J', 4); Map.AddEdge('J', 'F', 4);
	Map.AddEdge('F', 'I', 7); Map.AddEdge('I', 'F', 7);
	Map.AddEdge('F', 'L', 3); Map.AddEdge('L', 'F', 3);
	// Block G
	Map.AddEdge('G', 'K', 12); Map.AddEdge('K', 'G', 12);
	// Block H
	Map.AddEdge('H', 'K', 3); Map.AddEdge('K', 'H', 3);
	Map.AddEdge('H', 'J', 19); Map.AddEdge('J', 'H', 19);
	Map.AddEdge('H', 'I', 29); Map.AddEdge('I', 'H', 29);
	// Block I
	Map.AddEdge('I', 'J', 19); Map.AddEdge('J', 'I', 19);
	Map.AddEdge('I', 'L', 8); Map.AddEdge('L', 'I', 8);
	// Block J
	Map.AddEdge('J', 'L', 5); Map.AddEdge('L', 'J', 5);

	// Block K & Block L covered automatically


}

void Mainmenu(int& number)
{
	cout << " -------------------------------------------------------" << endl;
	cout << "\t\t" << "WELCOME!!! Grocery Store System" << endl;
	cout << " -------------------------------------------------------\n\n" << endl;
	cout << " \t\t\tMAIN MENU\n";
	cout << " ________________________________________________________\n";
	cout << " Press 1: To see all the products" << endl;
	cout << " Press 2: To see all customers and their details" << endl;
	cout << " Press 3: To search a customer" << endl;
	cout << " Press 4: To check the details of Products." << endl;
	cout << " Press 5: To generate shortest path" << endl;
	cout << " Press 6: To buy products" << endl;
	cout << " Press 7: To get remaining balance" << endl;
	cout << " Press 0: To exit." << endl;
	cout << " ________________________________________________________\n\n";
	cout << " Enter the desired number to perform desired task: ";

	cin >> number;
	cout << endl;

	system("CLS");
}

void generatepath(Graph& Map)
{
	char d;
	cout << "Enter block of customer: ";
	cin >> d;
	d = toupper(d);

	cout << "\nDisplaying... " << endl;
	cout << "The shortest path available between block G " << " and block " << d << " is: \n";
	int dist = Map.ShortestPath1('G', d);
	cout << "\nTotal Distance: " << dist << endl;
	if (!dist)
		cout << "You enetered an invalid block." << endl;

}

void bill(BinarySearchTree& t, HashTable& i, Graph& m)
{
	i.print();

	int total = 0, opt, quantity, tq = 0;
	int itemsbought = 0, price = 0;
	int input = 1;

	while (input)
	{
		cout << "Enter the code of product you want to buy: ";
		cin >> opt;

		do {
			cout << "Enter the quantity: ";
			cin >> quantity;

			if (i.getQ(opt)- quantity < 0)
				cout << "Available quantity is low." << endl;
			else
				break;
		} while (1);
		price = quantity * i.getP(opt);
		total += price; tq += quantity;
		i.setQ(opt, quantity);

		cout << "Do you want to exit purchasing? " << endl;
		cout << "Enter 0 if Yes: ";
		cin >> input;
	}

	cout << endl;
	system("PAUSE");
	system("CLS");
	cout << "BILL" << endl;
	cout << "Total quantity of items bought: " << tq << endl;
	cout << "Total bill: " << total << endl;

	t.LevelOrder();


	bool flag;
	do{
		int num;
		cout << "\nEnter the number of the user you want to search: ";
		cin >> num;
		flag = t.setPrice(num, total);
	}while (!flag);

	cout << endl;
	system("PAUSE");
	system("CLS");

	cout << "Updated customers list..." << endl;
	t.LevelOrder();
	cout << "\n\n --------------------------------------------------" << endl;
	cout << "Updated products list..." << endl;
	i.print();
}
void balance(BinarySearchTree& t)
{
	int num;
	cout << "Enter the number of the user you want to search: ";
	cin >> num;

	int b = t.remainingbal(num);

	cout << "Balance is: " << b << endl;
}
int main()
{
	system("COLOR 70");

	int option = 10;
	BinarySearchTree tree;
	tree = inputCustomers();

	Graph Map(12);
	input(Map);

	HashTable inventory;
	inventory.loadFromFile("items.txt");

	while (option != 0)
	{
		Mainmenu(option);
		switch (option)
		{
		case 1:
			inventory.print();
			break;
		case 2:
			tree.LevelOrder();
			break;
		case 3:
			tree.search();
			break;
		case 4:
			inventory.search();
			break;
		case 5:
			generatepath(Map);
			break;
		case 6:
			bill(tree, inventory, Map);
			break;
		case 7:
			balance(tree);
			break;
		default:
			break;
		}
		cout << endl;
		system("PAUSE");
		system("CLS");
	}

	cout << " Thank you for using Grocery Store System Software :)" << endl;

	return 0;
}