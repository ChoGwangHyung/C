///*
//find_bridge �˰��� ����
// ��ǥ v -> w �긴���� �������� ���� �켱 Ž���� ���Ͽ�
//��ǥ ���� w->v �� �ƴ� � vertex���� v�� �̵��� �������� visted[v] ������
//�̿��Ͽ� �˰����� ����
//*/
//
//
//#include <iostream>
//
//using namespace std;
//
//#define MAX_VERTICES 50
//
//typedef struct graphType
//{
//	int n;
//	bool adj_mat[MAX_VERTICES][MAX_VERTICES];
//}GraphType;
//
//int visited[MAX_VERTICES];
//
//void print_array(int arr[][2], int size)
//{
//	for (int i = 0; i < size; i++)
//		cout << arr[i][0] << "->" << arr[i][1] << endl;
//
//	return;
//}
//
////�׷��� �ʱ�ȭ
//void init(GraphType* g)
//{
//	g->n = 0;
//
//	for (int r = 0; r < MAX_VERTICES; r++)
//		for (int c = 0; c < MAX_VERTICES; c++)
//			g->adj_mat[r][c] = false;
//
//	return;
//}
//
////�� ����
//void insert_vertex(GraphType* g, int v)
//{
//	if (((g->n) + 1) > MAX_VERTICES)
//	{
//		fprintf(stderr, "Graph: Too many vertices!");
//		return;
//	}
//	g->n++;
//
//	return;
//}
//
////�� ����
//void insert_edge(GraphType* g, int start, int end)
//{
//	if (start >= g->n || end >= g->n)
//	{
//		fprintf(stderr, "Graph: Vertex number error!");
//		return;
//	}
//
//	g->adj_mat[start][end] = true;
//	g->adj_mat[end][start] = true;
//
//	return;
//}
//
////���� �켱 Ž�� v->w�� ���� �� Ž��
//void dfs_mat(GraphType* g, int v, int w, int target_v, int target_w)
//{
//	//���� ���� true
//	visited[w] = true;
//	//cout << "Vertex " << v << " -> ";
//	
//	for (int i = 0; i < g->n; i++)
//		//w->i�� ����Ǿ��ְ� i�� �湮���� �ʾ��� ��
//		//target_w�� w�� ���� �ʰ� target_v�� i�� ���� �ʴ� ������ 0->1�� bridge���� �ƴ��� Ȯ���� �� 1->0���� ���� 0�� �湮�Ͽ� ��ȿ�� �Ǿ� ������ ���� ����
//		if (g->adj_mat[w][i] && !visited[i] && !(w == target_w && i == target_v))
//			dfs_mat(g, w, i, target_v, target_w);
//	
//	return;
//}
//
//void find_bridge(GraphType* g)
//{
//	//bridge ���� �ϴ� ����
//	int(*bridge)[2] = new int[(g->n) * 2][2];
//	int bridge_index = 0;
//	int bridge_num = 0;
//
//	//v->w���� ��� ���� Ž��
//	for (int v = 0; v < g->n; v++)
//	{
//		for (int w = 0; w < g->n; w++)
//		{
//			//���� �Ǿ����������� �ڷ� w++
//			if (!g->adj_mat[v][w]) continue;
//
//			//���� �켱 Ž��
//			dfs_mat(g, v, w, v, w);
//			//���� �켱 Ž�� �� v�� �湮 ���� �ʾ����� v->w�� bridge
//			if (!visited[v])
//			{
//				bridge[bridge_index][0] = v;
//				bridge[bridge_index++][1] = w;
//			}
//
//			//�湮�Ͽ��� ���� �ʱ�ȭ
//			for (int j = 0; j < g->n; j++)
//				visited[j] = false;
//		}		
//	}
//
//	print_array(bridge, bridge_index);
//	cout << "bridge num : " << bridge_index/2 << endl;
//
//	delete bridge;
//
//	return;
//}
//
//
//int main()
//{
//	GraphType *g;
//	g = new GraphType;
//	init(g);
//
//	//�� ����
//	for (int i = 0; i < 10; i++)
//		insert_vertex(g, i);
//
//	//�� ����
//	insert_edge(g, 0, 1);
//	insert_edge(g, 1, 2);
//	insert_edge(g, 1, 3);
//	insert_edge(g, 2, 4);
//	insert_edge(g, 3, 4);
//	insert_edge(g, 3, 5);
//	insert_edge(g, 5, 6);
//	insert_edge(g, 5, 7);
//	insert_edge(g, 6, 7);
//	insert_edge(g, 7, 8);
//	insert_edge(g, 7, 9);
//
//	//bridge ã��
//	find_bridge(g);
//
//	delete g;
//
//	return 0;
//}