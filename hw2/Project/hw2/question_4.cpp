///*
//find_bridge 알고리즘 설명
// 목표 v -> w 브릿지를 잡은다음 깊이 우선 탐색을 통하여
//목표 였던 w->v 가 아닌 어떤 vertex에서 v로 이동이 가능한지 visted[v] 변수를
//이용하여 알고리즘을 구성
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
////그래프 초기화
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
////점 삽입
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
////선 삽입
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
////깊이 우선 탐색 v->w로 가는 걸 탐색
//void dfs_mat(GraphType* g, int v, int w, int target_v, int target_w)
//{
//	//도착 지점 true
//	visited[w] = true;
//	//cout << "Vertex " << v << " -> ";
//	
//	for (int i = 0; i < g->n; i++)
//		//w->i가 연결되어있고 i를 방문하지 않았을 때
//		//target_w가 w와 같지 않고 target_v가 i와 같지 않는 조건은 0->1이 bridge인지 아닌지 확인할 때 1->0으로 가서 0을 방문하여 무효가 되어 버리는 것을 방지
//		if (g->adj_mat[w][i] && !visited[i] && !(w == target_w && i == target_v))
//			dfs_mat(g, w, i, target_v, target_w);
//	
//	return;
//}
//
//void find_bridge(GraphType* g)
//{
//	//bridge 저장 하는 변수
//	int(*bridge)[2] = new int[(g->n) * 2][2];
//	int bridge_index = 0;
//	int bridge_num = 0;
//
//	//v->w가는 모든 것을 탐색
//	for (int v = 0; v < g->n; v++)
//	{
//		for (int w = 0; w < g->n; w++)
//		{
//			//연결 되어있지않으면 뒤로 w++
//			if (!g->adj_mat[v][w]) continue;
//
//			//깊이 우선 탐색
//			dfs_mat(g, v, w, v, w);
//			//깊이 우선 탐색 후 v를 방문 하지 않았으면 v->w는 bridge
//			if (!visited[v])
//			{
//				bridge[bridge_index][0] = v;
//				bridge[bridge_index++][1] = w;
//			}
//
//			//방문하였던 것을 초기화
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
//	//점 삽입
//	for (int i = 0; i < 10; i++)
//		insert_vertex(g, i);
//
//	//선 삽입
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
//	//bridge 찾기
//	find_bridge(g);
//
//	delete g;
//
//	return 0;
//}