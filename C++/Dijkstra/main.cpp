#include"Dijkstra.h"


//检验输入边数和顶点数的值是否有效，可以自己推算为啥：
//顶点数和边数的关系是：((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge) {
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
		return false;
	return true;
}
int main() {
	int v; int edge;

	cout << "输入图的顶点个数和边的条数：" << endl;
	cin >> v >> edge;
	while (!check(v, edge)) {
		cout << "输入的数值不合法，请重新输入" << endl;
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
