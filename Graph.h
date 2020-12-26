#pragma once
#include <list>
#include <queue>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

class Graph
{
	int V;
	vector<pair<int, int>>* vrtx;
public:
	Graph(int V)
	{
		this->V = V;
		vrtx = new vector<pair<int, int>>[V];//массив состоящий из элементов list
	}
	void addEdge(int u, int v, int w)
	{
		vrtx[u].push_back(make_pair(v, w));//добавляем в лист новую пару связности
		vrtx[v].push_back(make_pair(u, w));
	}

	void shortest(int vrtx)
	{
		vector<int> dist(V, 1000);
		dist[vrtx] = 0;

		vector<int> visited_vertex;
		//queue<int> vertex;
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> vertex;//<тип, тип контейнера для реалищации, равенсто(нужно по возрастанию)>

		//vertex.push(vrtx);
		vertex.push(make_pair(0, vrtx));

		while (!vertex.empty())
		{
			//int x = vertex.front();
			int x = vertex.top().second;
			//cout << "THATS x" << x << "\n";
			if (find(begin(visited_vertex), end(visited_vertex), x) != end(visited_vertex)) vertex.pop();//если уже через этот элемент проходили
			else//если еще не прошли
			{
				//cout << "we didnt meet it before\n";
				vector<pair<int, int>>::iterator i;
				for (i = this->vrtx[x].begin(); i != this->vrtx[x].end(); ++i)//сравниваем длину путей
				{
					int v = (*i).first;
					int weight = (*i).second;
					if (dist[v] > (dist[x] + weight))
					{
						dist[v] = dist[x] + weight;
					}
				}
				//cout << "children are:\n";
				for (int i = 0;i < this->vrtx[x].size();i++)//закидываем все следующие вершины в список
				{
					vertex.push(make_pair(this->vrtx[x][i].second, this->vrtx[x][i].first));
					//cout << this->vrtx[x][i].first << "\n";
				}
				visited_vertex.push_back(x);
				vertex.pop();
				//cout << "\n";
			}
		}

		for (int i = 0; i < V; i++)
		{
			cout << i << " " << dist[i] << "\n";
		}
	}

	
};