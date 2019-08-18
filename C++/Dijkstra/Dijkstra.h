#pragma once

#include<iostream>
#include<string>
using namespace std;

struct Dis {
	string path;
	int value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};//��¼��㵽ÿ����������·������Ϣ

class Graph
{
private:
	int v;
	int edge;
	int **adj;
	Dis * dis;

public:
	Graph(int v, int edge);
	~Graph();
	bool check_edge_value(int start, int end, int weight);
	void CreateGraph();
	void print();
	void Dijkstra(int begin);
	void print_path(int arc);
};

//���캯��
Graph::Graph(int v, int edge)
{
	this->v = v;
	this->edge = edge;

	adj = new int*[this->v];
	dis = new Dis[this->v];

	for (int i = 0; i < this->v; i++)
	{
		adj[i] = new int[this->v];
		for (int k = 0; k < this-> v; k++)
		{
			adj[i][k] = INT_MAX;
		}
	}
}


//��������
Graph::~Graph() {
	delete[] dis;
	for (int i = 0; i < this->v; i++) {
		delete this->adj[i];
	}
	delete adj;
}

// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
//�����1��ʼ���
bool Graph::check_edge_value(int start, int end, int weight) {
	if (start<1 || end<1 || start>v || end>v || weight < 0) {
		return false;
	}
	return true;
}


void Graph::CreateGraph() {
	cout << "������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��" << endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count != this->edge) {
		cin >> start >> end >> weight;
		//�����жϱߵ���Ϣ�Ƿ�Ϸ�
		while (!this->check_edge_value(start, end, weight)) {
			cout << "����ıߵ���Ϣ���Ϸ�������������" << endl;
			cin >> start >> end >> weight;
		}
		//���ڽӾ����Ӧ�ϵĵ㸳ֵ
		adj[start - 1][end - 1] = weight;
		//����ͼ��������д���
		//adj[end - 1][start - 1] = weight;
		++count;
	}
}

void Graph::print() {
	cout << "ͼ���ڽӾ���Ϊ��" << endl;
	int count_row = 0; //��ӡ�еı�ǩ
	int count_col = 0; //��ӡ�еı�ǩ
	//��ʼ��ӡ
	while (count_row != this->v) {
		count_col = 0;
		while (count_col != this->v) {
			if (adj[count_row][count_col] == INT_MAX)
				cout << "��" << " ";
			else
				cout << adj[count_row][count_col] << " ";
			++count_col;
		}
		cout << endl;
		++count_row;
	}
}


void Graph::Dijkstra(int begin) {
	//���ȳ�ʼ�����ǵ�dis����
	for (int i = 0; i < this->v; i++) {
		//���õ�ǰ��·��
		dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
		dis[i].value = adj[begin - 1][i];
	}
	//�������ĵ�����·��Ϊ0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;

	int count = 1;
	//����ʣ��Ķ�������·����ʣ��this->vexnum-1�����㣩
	while (count != this->v) {
		//temp���ڱ��浱ǰdis��������С���Ǹ��±�
		//min��¼�ĵ�ǰ����Сֵ
		int temp = 0;
		int min = INT_MAX;
		for (int i = 0; i < this->v; i++) {
			if (!dis[i].visit && dis[i].value < min) {
				min = dis[i].value;
				temp = i;
			}
		}
		//cout << temp + 1 << "  "<<min << endl;
		//��temp��Ӧ�Ķ�����뵽�Ѿ��ҵ������·���ļ�����
		dis[temp].visit = true;
		++count;
		for (int i = 0; i < this->v; i++) {
			//ע�����������arc[temp][i]!=INT_MAX����ӣ���Ȼ�����������Ӷ���ɳ����쳣
			if (!dis[i].visit && adj[temp][i] != INT_MAX && (dis[temp].value + adj[temp][i]) < dis[i].value) {
				//����µõ��ı߿���Ӱ������Ϊ���ʵĶ��㣬�Ǿ;͸����������·���ͳ���
				dis[i].value = dis[temp].value + adj[temp][i];
				dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);
			}
		}
	}

}


void Graph::print_path(int begin) {
	string str;
	str = "v" + to_string(begin);
	cout << "��" << str << "Ϊ����ͼ�����·��Ϊ��" << endl;
	for (int i = 0; i != this->v; i++) {
		if (dis[i].value != INT_MAX)
			cout << dis[i].path << "=" << dis[i].value << endl;
		else {
			cout << dis[i].path << "�������·����" << endl;
		}
	}
}