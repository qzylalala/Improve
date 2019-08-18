#include"Dijkstra.h"


//������������Ͷ�������ֵ�Ƿ���Ч�������Լ�����Ϊɶ��
//�������ͱ����Ĺ�ϵ�ǣ�((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge) {
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
		return false;
	return true;
}
int main() {
	int v; int edge;

	cout << "����ͼ�Ķ�������ͱߵ�������" << endl;
	cin >> v >> edge;
	while (!check(v, edge)) {
		cout << "�������ֵ���Ϸ�������������" << endl;
		cin >> v >> edge;
	}
	Graph graph(v, edge);
	graph.CreateGraph();
	graph.print();
	graph.Dijkstra(1);
	graph.print_path(1);
	system("pause");
	return 0;
}
