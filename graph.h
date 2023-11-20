#pragma once

#include<iostream>
#include <string>
#include<stack>
#include<queue>
#define INT_MAX 1000000
using namespace std;


struct Edge
{
	char block;
	string BlockName;
	int Weight;
	Edge* DestBlock;
};

struct ShortestPath
{
	char StartBlock, DestBlock;
	string StartBlockString, DestBlockString;
	bool Visit;
	int Distance;
};

class Graph
{
private:
	Edge** Vertex;
	int Size;

public:
	//Constructor
	Graph(int S)
	{
		Vertex = new Edge * [S];
		Size = S;
		for (int i = 0; i < S; i++)
		{
			Vertex[i] = new Edge();
			Vertex[i]->block = NULL;
			Vertex[i]->Weight = 0;
			Vertex[i]->DestBlock = NULL;
		}
	}

	void AddVertex(char R1, string Name)
	{
		int i = R1 % 65;
		Vertex[i]->block = R1;
		Vertex[i]->BlockName = Name;
	}

	void AddEdge(char R2, char R3, int W)
	{
		Edge* EA;
		int i = R2 % 65;
		EA = new Edge();
		EA->block = R3;
		EA->Weight = W;
		EA->DestBlock = NULL;
		Edge* EB;
		EB = Vertex[i];

		while (EB->DestBlock)
			EB = EB->DestBlock;
		EB->DestBlock = EA;
	}

	int ShortestPath1(char c, char D2)
	{
		ShortestPath* Check, Pre;
		queue<Edge*>* Queue;
		Queue = new queue<Edge*>();
		Edge* ED;
		Check = new ShortestPath[Size];

		for (int i = 0; i < Size; i++)
		{
			Check[i].DestBlock = NULL;
			Check[i].StartBlock = Vertex[i]->block;
			Check[i].StartBlockString = Vertex[i]->BlockName;
			Check[i].Distance = INT_MAX;
			Check[i].Visit = 0;
		}

		int j = c % 65;
		Check[j].Visit = 1;
		Check[j].Distance = 0;
		Queue->push(Vertex[j]);

		while (!Queue->empty())
		{
			ED = Queue->front();
			Queue->pop();
			int V = ED->block % 65;
			Pre = Check[V];
			while (ED)
			{
				ED = ED->DestBlock;
				if (ED)
				{
					int i = ED->block % 65;
					if (!Check[i].Visit)
					{
						Queue->push(Vertex[ED->block % 65]);
						Check[i].Visit = 1;
					}
					if (Pre.Distance + ED->Weight < Check[i].Distance)
					{
						Check[i].Distance = Pre.Distance + ED->Weight;
						Check[i].DestBlock = Pre.StartBlock;
						Check[i].DestBlockString = Pre.StartBlockString;
					}
				}
			}
		}

		stack<ShortestPath> ST1;
		int Distance1;
		while (D2)
		{
			ST1.push(Check[D2 % 65]);
			D2 = Check[D2 % 65].DestBlock;
		}

		cout << ST1.top().StartBlockString;
		Distance1 = ST1.top().Distance;
		ST1.pop();

		
		while (!ST1.empty())
		{
			cout << " -> " << ST1.top().StartBlockString;
			Distance1 = ST1.top().Distance;
			ST1.pop();
		}

		cout << endl;
		
		return Distance1;
	}

	~Graph()
	{
		Edge* E1, * E2;
		for (int i = 0; i < Size; i++)
		{
			while (Vertex[i]->DestBlock != NULL)
			{
				E1 = Vertex[i];
				E2 = Vertex[i]->DestBlock;
				while (E2->DestBlock)
				{
					E1 = E2;
					E2 = E2->DestBlock;
				}
				E1->DestBlock = NULL;
				delete E2;
			}
			delete Vertex[i];
		}
		delete[] Vertex;
		Size = 0;
		Vertex = NULL;
	}
};