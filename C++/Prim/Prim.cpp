/*Prim�㷨ʵ����С��������O(n * n), �ʺϳ���ͼ�� ֻ������йء�������ֻ����������ͼ*/

#include<iostream>
#include<string>
#include<vector>
using  namespace std;

//������ʹ���ڽӾ������Prim�㷨
struct Graph {
	int vexnum;  //�������
	int edge;   //�ߵ�����
	int ** arc; //�ڽӾ���
	string *information; //��¼ÿ����������
};

//����ͼ
void createGraph(Graph & g) {
	cout << "�����붥����������ߵ�����" << endl;
	cin >> g.vexnum;
	cin >> g.edge;  //����ߵ�����

	g.information = new string[g.vexnum];
	g.arc = new int*[g.vexnum];
	int i = 0;

	//���ٿռ��ͬʱ���������Ƶĳ�ʼ��
	for (i = 0; i < g.vexnum; i++) {
		g.arc[i] = new int[g.vexnum];
		g.information[i] = "v" + std::to_string(i + 1);//��ÿ�������������
		for (int k = 0; k < g.vexnum; k++) {
			g.arc[i][k] = INT_MAX;          //��ʼ�����ǵ��ڽӾ���
		}
	}

	cout << "������ÿ����֮��Ķ�����(�����Ŵ�1��ʼ),�Լ��ñߵ�Ȩ�أ�" << endl;
	for (i = 0; i < g.edge; i++) {
		int start;
		int end;
		cin >> start;   //����ÿ���ߵ����
		cin >> end;     //����ÿ���ߵ��յ�
		int weight;
		cin >> weight;
		g.arc[start - 1][end - 1] = weight;//����ͼ�ı����෴��
		g.arc[end - 1][start - 1] = weight;
	}
}

//��ӡͼ
void print(Graph g) {
	int i;
	for (i = 0; i < g.vexnum; i++) {
		//cout << g.information[i] << " ";
		for (int j = 0; j < g.vexnum; j++) {
			if (g.arc[i][j] == INT_MAX)
				cout << "��" << " ";
			else
				cout << g.arc[i][j] << " ";
		}
		cout << endl;
	}
}

//��Ϊ��¼�ߵ���Ϣ����Щ�߶��Ǵﵽend�����б��У�Ȩ����С���Ǹ�
struct Assis_array {
	int start; //�ߵ��յ�
	int end;  //�ߵ����
	int weight;  //�ߵ�Ȩ��
};
//����prim�㷨ʵ�֣�ʹ�õ��ڽӾ���ķ���ʵ�֡�
void Prim(Graph g, int begin) {

	//close_edge��������¼����ĳ������ĸ������е�Ȩ�������Ǹ���
	Assis_array *close_edge = new Assis_array[g.vexnum];

	int j;

	//����close_edge�ĳ�ʼ�������ӿ�ʼ�����г�ʼ��
	for (j = 0; j < g.vexnum; j++) {
		if (j != begin - 1) {
			close_edge[j].start = begin - 1;
			close_edge[j].end = j;
			close_edge[j].weight = g.arc[begin - 1][j];
		}
	}
	//������close_edge�е�ֵ����Ϊ-1�������Ѿ����뵽����U��
	close_edge[begin - 1].weight = -1;
	//����ʣ�µĶ��㣬���������μ��뵽����U
	for (j = 1; j < g.vexnum; j++) {

		int min = INT_MAX;
		int k;
		int index;
		//Ѱ������close_edge��Ȩ����С���Ǹ���
		for (k = 0; k < g.vexnum; k++) {
			if (close_edge[k].weight != -1) {
				if (close_edge[k].weight < min) {
					min = close_edge[k].weight;
					index = k;
				}
			}
		}
		//��Ȩ����С�������ߵ��յ�Ҳ���뵽����U
		close_edge[index].weight = -1;
		//�����Ӧ�ıߵ���Ϣ
		cout << g.information[close_edge[index].start]
			<< "-----"
			<< g.information[close_edge[index].end]
			<< "="
			<< g.arc[close_edge[index].start][close_edge[index].end]
			<< endl;

		//����close_edge���顣
		for (k = 0; k < g.vexnum; k++) {
			if (g.arc[close_edge[index].end][k] < close_edge[k].weight) {
				close_edge[k].weight = g.arc[close_edge[index].end][k];
				close_edge[k].start = close_edge[index].end;
				close_edge[k].end = k;
			}
		}
	}
}



int main()
{
	Graph g;
	createGraph(g);
	print(g);
	Prim(g, 1);
	system("pause");
	return 0;
}
