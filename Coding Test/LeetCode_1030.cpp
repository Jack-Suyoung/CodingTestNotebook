#include <iostream>
#include <queue>

// BFS Solution
// Use Queue
// Use STL -> Easy

typedef struct myStruct
{
	int RowIdx;
	int ColumnIdx;
	int depth;
}myStruct;

using namespace std;

void BFS(int row, int column, queue<myStruct>* pmy_queue, vector<vector<int>>* pmyvector);

int gArr[100][100] = { 0 };

int main()
{
	queue<myStruct> my_queue;
	vector<vector<int>> myvector;

	int rows = 3;
	int cols = 3;
	int rCenter = 0;
	int cCenter = 2;

	myStruct stStartSpace = { rCenter, cCenter, 0 };
	my_queue.push(stStartSpace);

	gArr[rCenter][cCenter] = 1;

	vector<int> tmp;
	tmp.push_back(stStartSpace.RowIdx);
	tmp.push_back(stStartSpace.ColumnIdx);
	myvector.push_back(tmp);

	BFS(rows, cols, &my_queue, &myvector);


	return 0;
}

void BFS(int row, int column, queue<myStruct>* pmy_queue, vector<vector<int>>* pmyvector)
{
	myStruct stCurSpace = pmy_queue->front();
	pmy_queue->pop();
	myStruct SearchSpace = { 0 };


	if (((stCurSpace.RowIdx - 1) > -1) && (gArr[stCurSpace.RowIdx - 1][stCurSpace.ColumnIdx] == 0))
	{
		SearchSpace.RowIdx = stCurSpace.RowIdx - 1;
		SearchSpace.ColumnIdx = stCurSpace.ColumnIdx;
		SearchSpace.depth = stCurSpace.depth + 1;

		pmy_queue->push(SearchSpace);

		vector<int> tmp;
		tmp.push_back(SearchSpace.RowIdx);
		tmp.push_back(SearchSpace.ColumnIdx);
		pmyvector->push_back(tmp);

		gArr[SearchSpace.RowIdx][SearchSpace.ColumnIdx] = 1;

	}
	else
	{
		// Do Nothing
	}

	if (((stCurSpace.RowIdx + 1) < row) && (gArr[stCurSpace.RowIdx + 1][stCurSpace.ColumnIdx] == 0))
	{
		SearchSpace.RowIdx = stCurSpace.RowIdx + 1;
		SearchSpace.ColumnIdx = stCurSpace.ColumnIdx;
		SearchSpace.depth = stCurSpace.depth + 1;

		pmy_queue->push(SearchSpace);

		vector<int> tmp;
		tmp.push_back(SearchSpace.RowIdx);
		tmp.push_back(SearchSpace.ColumnIdx);
		pmyvector->push_back(tmp);

		gArr[SearchSpace.RowIdx][SearchSpace.ColumnIdx] = 1;

	}
	else
	{
		// Do Nothing
	}

	if (((stCurSpace.ColumnIdx - 1) > -1) && (gArr[stCurSpace.RowIdx][stCurSpace.ColumnIdx - 1] == 0))
	{
		SearchSpace.RowIdx = stCurSpace.RowIdx;
		SearchSpace.ColumnIdx = stCurSpace.ColumnIdx - 1;
		SearchSpace.depth = stCurSpace.depth + 1;

		pmy_queue->push(SearchSpace);

		vector<int> tmp;
		tmp.push_back(SearchSpace.RowIdx);
		tmp.push_back(SearchSpace.ColumnIdx);
		pmyvector->push_back(tmp);

		gArr[SearchSpace.RowIdx][SearchSpace.ColumnIdx] = 1;

	}
	else
	{
		// Do Nothing
	}

	if (((stCurSpace.ColumnIdx + 1) < column) && (gArr[stCurSpace.RowIdx][stCurSpace.ColumnIdx + 1] == 0))
	{
		SearchSpace.RowIdx = stCurSpace.RowIdx;
		SearchSpace.ColumnIdx = stCurSpace.ColumnIdx + 1;
		SearchSpace.depth = stCurSpace.depth + 1;

		pmy_queue->push(SearchSpace);

		vector<int> tmp;
		tmp.push_back(SearchSpace.RowIdx);
		tmp.push_back(SearchSpace.ColumnIdx);
		pmyvector->push_back(tmp);

		gArr[SearchSpace.RowIdx][SearchSpace.ColumnIdx] = 1;

	}
	else
	{
		// Do Nothing
	}


	if (pmy_queue->size() != 0)
	{
		BFS(row, column, pmy_queue, pmyvector);
	}
	else
	{
		// Do Nothing
	}

}