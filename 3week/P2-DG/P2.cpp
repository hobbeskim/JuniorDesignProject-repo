#include <vector>
#include <iostream>
using namespace std;


/* judgeCutNode : map 행렬로 전달된 judgeCutNode 인자가 커트 노드인지 판단하는 함수*/
bool judgeCutNode(vector<vector<int>> map, const int _judgeCutNode)
{

	/*list : 개별 루트에서 갈라져 나온 노드들의 집합*/
	vector<bool> list;
	list.resize(map.size());


	/* 선택된 노드의 연결을 끊어버림 노트 컷팅-요시!*/
	for (int i = 0; i < map.size(); ++i)
		map[i][_judgeCutNode] = map[_judgeCutNode][i] = 0;

	/* 루트 노드 1 or 2 선택 및 루트 연결 노드 전달*/
	list[1] = list[_judgeCutNode] = true;
	if (_judgeCutNode == 1) 
		list[2] = true;


	/* 플래그를 인식자로 하여 멤버를 추가할 때 반복하도록 한당 룰루*/
	bool new_flag = true;
	while (new_flag)
	{
		new_flag = false;
		for (int i = 1; i < list.size(); ++i) 
		{
			if (list[i] == true)
			{
				for (int sub = 1; sub < list.size(); ++sub)
				{
					/*리스트에 멤버를 추가할 때*/
					if (map[i][sub] == 1 && list[sub] != true)
						list[sub] = new_flag = true;
				}
			}
		}
	}

	/*특정 멤버가 리스트에 해당하지 않을 때: 커트 노드*/
	for (int i = 1; i < list.size(); ++i) 
	{
		if (list[i] == false)
			return true;
	}

	
	return false;
}
void main()
{
	/*노드 간 연결 상태를 저장하는 행렬*/
	vector<vector<int>> map;         

	int num, x, y, count = 0;
	cout << "Case #1 Input\nnumber :";
	cin >> num;                      // 행렬의 크기를 입력 (num x num)                
	map.resize(num + 1);             // map 행렬 초기화
	for (int i = 0; i < map.size(); ++i)
		map[i].resize(num + 1);

	/* Edge inputting*/
	while (true)
	{
		cout << "간선을 입력해주세요 " << ++count << "(x,y==0 to break) :";
		cin >> x >> y;
		if (x < 1 || x >= map.size() || y < 1 || y >= map.size())
			break;
		map[x][y] = map[y][x] = 1; // map 행렬에서 대칭되는 점 찍기
	}

	/* 함수로 값 전달 및 커트 노드 찾기*/
	vector<int> result;
	for (int i = 1; i < map.size(); ++i) 
	{
		/*i의 값에 해당하는 노드가 커트 노드인지 탐색합니다.*/
		if (judgeCutNode(map, i)) 
			result.push_back(i);
	}

	/*Result printing*/
	cout << "Case #1 : Cut nodes = ";
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
	cout << endl;

	getchar();
	getchar();
	getchar();
}