#include <vector>
#include <iostream>
using namespace std;


/* judgeCutNode : map ��ķ� ���޵� judgeCutNode ���ڰ� ĿƮ ������� �Ǵ��ϴ� �Լ�*/
bool judgeCutNode(vector<vector<int>> map, const int _judgeCutNode)
{

	/*list : ���� ��Ʈ���� ������ ���� ������ ����*/
	vector<bool> list;
	list.resize(map.size());


	/* ���õ� ����� ������ ������� ��Ʈ ����-���!*/
	for (int i = 0; i < map.size(); ++i)
		map[i][_judgeCutNode] = map[_judgeCutNode][i] = 0;

	/* ��Ʈ ��� 1 or 2 ���� �� ��Ʈ ���� ��� ����*/
	list[1] = list[_judgeCutNode] = true;
	if (_judgeCutNode == 1) 
		list[2] = true;


	/* �÷��׸� �ν��ڷ� �Ͽ� ����� �߰��� �� �ݺ��ϵ��� �Ѵ� ���*/
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
					/*����Ʈ�� ����� �߰��� ��*/
					if (map[i][sub] == 1 && list[sub] != true)
						list[sub] = new_flag = true;
				}
			}
		}
	}

	/*Ư�� ����� ����Ʈ�� �ش����� ���� ��: ĿƮ ���*/
	for (int i = 1; i < list.size(); ++i) 
	{
		if (list[i] == false)
			return true;
	}

	
	return false;
}
void main()
{
	/*��� �� ���� ���¸� �����ϴ� ���*/
	vector<vector<int>> map;         

	int num, x, y, count = 0;
	cout << "Case #1 Input\nnumber :";
	cin >> num;                      // ����� ũ�⸦ �Է� (num x num)                
	map.resize(num + 1);             // map ��� �ʱ�ȭ
	for (int i = 0; i < map.size(); ++i)
		map[i].resize(num + 1);

	/* Edge inputting*/
	while (true)
	{
		cout << "������ �Է����ּ��� " << ++count << "(x,y==0 to break) :";
		cin >> x >> y;
		if (x < 1 || x >= map.size() || y < 1 || y >= map.size())
			break;
		map[x][y] = map[y][x] = 1; // map ��Ŀ��� ��Ī�Ǵ� �� ���
	}

	/* �Լ��� �� ���� �� ĿƮ ��� ã��*/
	vector<int> result;
	for (int i = 1; i < map.size(); ++i) 
	{
		/*i�� ���� �ش��ϴ� ��尡 ĿƮ ������� Ž���մϴ�.*/
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