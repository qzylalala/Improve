//ͼ��ɫ���⣬ �ο�����  https ://www.cnblogs.com/JiePro/p/Metaheuristics_1.html

#include<time.h>
#include<fstream>
#include<stdlib.h>
#include<stack>
#include<vector>
#include<climits>
#include<string>
#include<iostream>
using namespace std;

int maxC = 60;//�����ɫ��
int N;//ͼ�Ķ�����Ŀ
int **g;//�ڽ�ͼ
int *v_edge;//ÿ������ı���

//---
//��ȡͼ

//���ո��з�ÿ��(��ȡ���ݵĺ���)
void split(const string& src, const string& delim, vector<string>& dest)
{
	dest.clear();
	string str = src;
	string::size_type start = 0, index;
	string substr;
	index = str.find(delim, start);    //��str�в���(��ʼ��start) delim�������ַ��ĵ�һ�γ��ֵ�λ��  
	while (index != string::npos)
	{
		substr = str.substr(start, index - start);
		dest.push_back(substr);
		start = index + 1;
		index = str.find(delim, start);    //��str�в���(��ʼ��index) ��һ��������delim���ַ����ֵ�λ��  
	}
	substr = str.substr(start, index);
	dest.push_back(substr);
}

//��ʼ��ͼ
void init_graph() {
	try {
		g = new int*[N];
		v_edge = new int[N];
		for (int i = 0; i < N; i++) {
			g[i] = new int[N];
			v_edge[i] = 0;
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				g[i][j] = 0;
	}//��ʼ���ڽӾ����ÿ������ı���
	catch (const bad_alloc & e) {
		std::cout << "ͼ�ڴ����ʧ��" << e.what() << endl;
		init_graph();//����ʧ�����·���
	}
}

//��ȡ�ļ����ݣ�����ͼ
void create_graph() {
	ifstream infile("C:\\Users\\qzylalala\\Desktop\\Lab\\DSJC\\DSJC500.5.col.txt", ios::in);
	vector<string> data;
	string delim(" ");
	string textline;
	bool start = false;
	int v1, v2;
	int tmp;
	if (infile.good())
	{
		while (!infile.fail())
		{
			getline(infile, textline);
			if (start && textline.find("e", 0) != string::npos) {
				split(textline, delim, data);
				v1 = stoi(data[1]) - 1;
				v2 = stoi(data[2]) - 1;
				tmp = ++v_edge[v1];
				g[v1][tmp - 1] = v2;
				tmp = ++v_edge[v2];
				g[v2][tmp - 1] = v1;

			}
			else {
				if (textline.find("p edge", 0) != string::npos) {
					split(textline, delim, data);
					N = stoi(data[2]);
					init_graph();
					start = true;
				}
			}
		}
	}
	infile.close();
}


//---
//�����㷨
int *sol;//����Ӧ��ɫ
int f;//��ͻֵ
int **tabutenure;//���ɱ�
int **adj_color_table;//�ڽ���ɫ��
int K;//��ɫ����
int delt;//�ƶ�����
int best_f;//��ʷ��õĳ�ͻֵ
int node;//ÿ���ƶ��Ľ��
int color;//ÿ���ƶ�����ɫ
int iter;//��������

		 //��ʼ���ڴ����

void initalloc() {
	try {
		sol = new int[N];
		adj_color_table = new int*[N];
		tabutenure = new int*[N];

		for (int i = 0; i < N; i++) {
			adj_color_table[i] = new int[K];
			tabutenure[i] = new int[K];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < K; j++) {
				adj_color_table[i][j] = 0;
				tabutenure[i][j] = 0;
			}
		}
	}//��ʼ������(�ڵ��Ӧ��ɫ�Ĵ洢���飬���ɱ��ڽ���ɫ����ֵΪ 0)
	catch (const bad_alloc &e) {
		std::cout << "��ʼ���ڴ����ʧ��:" << e.what() << endl;
		initalloc();
	}
}

//�ͷ��ڴ�
void delete_alloc() {
	for (int i = 0; i < N; i++) {
		delete[]tabutenure[i];
		delete[]adj_color_table[i];
		delete[]g[i];
	}
	delete[]sol;
	delete[]tabutenure;
	delete[]adj_color_table;
	delete[]g;
}

//��ʼ�������鶥����ɫ�������ʼ��ͻֵ����ʼ���ڽ���ɫ��
void initialization(int numofcolor) {
	K = numofcolor;
	f = 0;
	initalloc();//��ʼ���ڴ����
	for (int i = 0; i < N; i++)
		sol[i] = rand() % K;//��ʼ����ɫ(������������ʼ����ʼ��ɫ)
	int num_edge;
	int *h_graph;
	int adj_color;
	int c_color;
	for (int i = 0; i < N; i++) {
		num_edge = v_edge[i];
		h_graph = g[i];
		c_color = sol[i];
		for (int u = 0; u < num_edge; u++) {
			adj_color = sol[h_graph[u]];
			if (c_color == adj_color)
				f++;
			adj_color_table[i][adj_color]++;//��ʼ���ڽ���ɫ��(��i���ڵ��������ڽӾ����У����ڲ�ͬ��ɫ��ֵΪ����ɫ���ֵĴ���)
		}
	}
	f = f / 2;
	best_f = f;
	std::cout << "init number of confilcts:" << f << endl;
}


int equ_delt[2000][2];//�ǽ�����ͬdeltֵ
int equ_tabudelt[2000][2];//������ͬdeltֵ

//����ѽ��ɻ��߷ǽ����ƶ�
void findmove() {
	delt = 10000;//��ʼΪ�������
	int tmp;//��ʱ����
	int tabu_delt = 10000;
	int count = 0, tabu_count = 0;
	int A = best_f - f;
	int c_color;//��ǰ�����ɫ
	int *h_color;//�ڽ���ɫ������ָ��
	int *h_tabu;//���ɱ�����ָ��
	int c_color_table;//��ǰ�����ɫ���ֵ
	for (int i = 0; i < N; i++) {
		c_color = sol[i];
		h_color = adj_color_table[i];
		c_color_table = h_color[c_color];//��i������c_color���ֵĴ���(����c_color���ǵ�i���������ɫ���룬 ���c_color_table��ͬɫ�Ķ�����)
		if (h_color[c_color] > 0) {
			h_tabu = tabutenure[i];
			for (int j = 0; j < K; j++) {
				if (c_color != j) {
					//�ǽ����ƶ�
					tmp = h_color[j] - c_color_table;//tmp��ʾ����i�ڽӶ�������ɫj���ֵĴ����� ���Լ�ͬɫ�Ķ������� ��ֵ
					if (h_tabu[j] <= iter) {
						if (tmp <= delt) {//��֧Ԥ�гͷ�
							if (tmp < delt) {
								count = 0;
								delt = tmp;
							}
							count++;
							equ_delt[count - 1][0] = i;
							equ_delt[count - 1][1] = j;
						}
					}
					else {//�����ƶ�
						if (tmp <= tabu_delt) {
							if (tmp < tabu_delt) {
								tabu_delt = tmp;
								tabu_count = 0;
							}
							tabu_count++;
							equ_tabudelt[tabu_count - 1][0] = i;
							equ_tabudelt[tabu_count - 1][1] = j;
						}
					}
				}
			}
		}
	}
	tmp = 0;
	if (tabu_delt < A && tabu_delt < delt) {
		delt = tabu_delt;
		tmp = rand() % tabu_count;//���delt���ѡ��
		node = equ_tabudelt[tmp][0];
		color = equ_tabudelt[tmp][1];
	}
	else {
		tmp = rand() % count;//���delt���ѡ��
		node = equ_delt[tmp][0];
		color = equ_delt[tmp][1];
	}
}


//����ֵ
void makemove() {
	f = delt + f;//���³�ͻֵ
	if (f < best_f) best_f = f;//������ʷ��ó�ͻ
	int old_color = sol[node];
	sol[node] = color;
	tabutenure[node][old_color] = iter + f + rand() % 10 + 1;//���½��ɱ�
	int *h_graph = g[node];
	int num_edge = v_edge[node];
	int tmp;
	for (int i = 0; i < num_edge; i++) {//�����ڽ���ɫ��
		tmp = h_graph[i];
		adj_color_table[tmp][old_color]--;//�붥��i���ڵ����ж��㣬 ��ɫΪold_color���ֵĴ�����һ
		adj_color_table[tmp][color]++;//�붥��i���ڵ����ж��㣬 ��ɫΪ��color���ֵĴ�����һ
	}
}

//��������
void tabusearch() {
	create_graph();
	int numofcolor = 13;
	ofstream ofile("C:\\Users\\qzylalala\\Desktop\\500.5_48.txt", ios::out);
	double start_time, end_time;
	double elapsed_time;
	while (cin >> numofcolor)
	{
		srand(clock());
		initialization(numofcolor);
		start_time = clock();
		iter = 0;
		while (f > 0) {
			iter++;
			if ((iter % 100000) == 0) ofile << iter << " " << f << " " << K << " " << delt << " " << best_f << endl;
			findmove();
			makemove();
		}
		end_time = clock();
		elapsed_time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
		ofile << "��������" << iter << "  ����ʱ��(s)" << elapsed_time << "����Ƶ��" << double(iter / elapsed_time) << endl;
		std::cout << "success,iterations:" << iter << "  elapsed_time(s):" << elapsed_time << "frequency:" << double(iter / elapsed_time) << endl;

	}
	ofile.close();
}


int main() {
	tabusearch();
	system("pause");
	return 0;
}