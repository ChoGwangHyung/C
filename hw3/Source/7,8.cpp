#include <iostream>

using namespace std;

#define MAX_VERTICES 100
#define INF 1000000

//가중치 행렬 그래프
class GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
	int distance[MAX_VERTICES];
	bool found[MAX_VERTICES];
	int path[MAX_VERTICES];

	int mst_array[MAX_VERTICES][MAX_VERTICES];

public:
	GraphType(int n) : n(n)
	{}
	~GraphType()
	{}

	void Insert(int value[MAX_VERTICES][MAX_VERTICES])
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				weight[i][j] = value[i][j];
	}

	//Dijkstra
	int Choose()
	{
		int min = INT_MAX;
		int min_pos = -1;
		for (int i = 0; i < n; i++)
		{
			if (distance[i] < min && !found[i])
			{
				min = distance[i];
				min_pos = i;
			}
		}

		return min_pos;
	}

	void PrintStatus()
	{
		static int step = 1;
		cout << "STEP " << step++ << "\ndistance: ";
		for (int i = 0; i < n; i++)
		{
			if (distance[i] == INF)
				cout << " * ";
			else
			{
				cout.width(2);
				cout << distance[i] << " ";
			}
		}
		cout << "\nfound   : ";
		for (int i = 0; i < n; i++)
		{
			cout.width(2);
			cout << found[i] << " ";
		}
		cout << endl;
		PrintPath();
		cout << endl << endl;
	}

	void PrintPath()
	{
		cout << "shortest path : ";
		int i;

		for (i = 0; i < n - 1; i++)
			if (path[i] != INF)
				cout << path[i] << " ";
	}

	void ShortestPath(int start)
	{
		//초기화
		for (int i = 0; i < n; i++)
		{
			distance[i] = weight[start][i];
			found[i] = false;
			path[i] = INF;
		}
		found[start] = true;
		distance[start] = 0;
		path[0] = start;

		int u;
		for (int i = 0; i < n - 1; i++)
		{
			PrintStatus();

			//제일 최저 가중치의 정점으로 이동
			u = Choose();
			found[u] = true;
			path[i + 1] = u;

			//distance값 변경
			for (int w = 0; w < n; w++)
			{
				if (!found[w])
					//최소 거리 찾아서 distance에 삽입
					if (distance[u] + weight[u][w] < distance[w])
						distance[w] = distance[u] + weight[u][w];
			}
		}
	}

	//Floyd
	void PrintA()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mst_array[i][j] == INF)
					cout << "  * ";
				else
				{
					cout.width(3);
					cout << mst_array[i][j] << " ";
				}
			}
			cout << endl;
		}

		cout << "=============================" << endl;
	}

	void Floyd()
	{
		//초기화
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mst_array[i][j] = weight[i][j];
		PrintA();

		//i->j로 가는 경로에서 k를 거쳐서 가는 경로 찾기
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (mst_array[i][k] + mst_array[k][j] < mst_array[i][j])
						mst_array[i][j] = mst_array[i][k] + mst_array[k][j];

			cout << k << " pass" << endl;
			PrintA();
		}
	}
};

int main()
{
	GraphType g(6);

	int A[MAX_VERTICES][MAX_VERTICES] = {
	{0,50,45,10,INF,INF},
	{INF,0,10,15,INF,INF},
	{INF, INF, 0,INF,30,INF},
	{20,INF,INF,0,15,INF},
	{INF,20,35,INF,0,INF},
	{INF,INF,INF,INF,3,0}
	};

	g.Insert(A);

	g.ShortestPath(0);

	return 0;
}
