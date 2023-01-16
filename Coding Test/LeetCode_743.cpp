#include <queue>
#include <vector>
#include <algorithm>

#define pairInt pair<int, int>
#define MaxNodeSize 105


using namespace  std;

int main()
{


	return 0;
}

class Solution {
public:
	vector<pairInt>Graph[MaxNodeSize];
	int ArrDistance[MaxNodeSize];


	void DijkstraAlgorithm(int SrcNode)
	{
		int CurrentNode;
		int i = 0;
		int DstNode = 0;
		int DelayTime = 0;

		priority_queue<pairInt, vector<pairInt>, greater<pairInt>> Queue;

		for (i = 0; i < MaxNodeSize; ++i) ArrDistance[i] = INT32_MAX;
		ArrDistance[SrcNode] = 0;
		Queue.push({ 0, SrcNode });

		while (!Queue.empty())
		{
			CurrentNode = Queue.top().second;
			Queue.pop();

			for (i = 0; i < Graph[CurrentNode].size(); ++i) // Search Neighbors
			{
				DstNode = Graph[CurrentNode][i].first;
				DelayTime = Graph[CurrentNode][i].second;

				if (ArrDistance[DstNode] > ArrDistance[CurrentNode] + DelayTime)
				{
					ArrDistance[DstNode] = ArrDistance[CurrentNode] + DelayTime;
					Queue.push({ ArrDistance[DstNode], DstNode });
				}
				else
				{
					// Do Nothing
				}
			}
		}
	}

	int networkDelayTIme(vector<vector<int>>& times, int N, int K)
	{
		for (auto x : times)
		{
			int SrcNode = x[0];
			int DstNode = x[1];
			int DelayTime = x[2];
			
			Graph[SrcNode].push_back({ DstNode, DelayTime });
		}

		DijkstraAlgorithm(K);

		int ans = 0;
		for (int i = 1; i <= N; ++i)
		{
			ans = max(ans, ArrDistance[i]);
		}

		if (ans == INT32_MAX)
		{
			ans = -1;
		}
		else
		{
			// Do NOthing
		}

		return ans;
	}
};