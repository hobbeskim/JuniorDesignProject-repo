/*2015112167 컴공 김동호*/
/*github:hobbeskim/JuniorDesignProject-repo.git*/

#include <stdio.h>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define x first
#define y second

vector<int> ans;

void valueInput(int *n, int *d, pair<int, int> dat[]);
void checkDistance(int n, pair<int, int> dat[], int d, int mat[][100], int deg[]);
void searchCluster(int n, int deg[], int mat[][100],int caseNum);
void valueInit(int mat[][100], int deg[], int n);


int main() 
{

	/*user's valueInput!*/
	int n, d, CASE;

	/*각 센서의 조합*/
	pair<int, int> dat[100];

	/*check able distance*/
	int mat[100][100];

	/* if start number i,count able distance's number*/
	int deg[100];

	printf("How many case? >>");
	scanf("%d", &CASE);

	for (int CaseNum = 0; CaseNum < CASE; CaseNum++) 
	{/*CASE의 값 만큼 반복합니다*/

		valueInit(mat, deg, 100);
		valueInput(&n, &d, dat);
		checkDistance(n, dat, d, mat, deg);
		searchCluster(n, deg, mat,CaseNum);

	}

	getchar();
	getchar();
	getchar();
	return 0;
}
/*사용자에게 데이터를 입력받는 함수 dat에 인자 전달하는 함수*/
void valueInput(int *n, int *d, pair<int, int> dat[])
{
	int i;
	printf("Please Input: n d=");
	scanf("%d %d", n, d);
	for (int i = 0; i < *n; i++)
	{
		printf("#%d.sensor's coordinate:",i+1);
		scanf("%d %d", &dat[i].x, &dat[i].y);
	}
}
/*본 함수는 인자로 전달된 두 점(페어)이 문제에서 주어진 Distance 범위 내에 드는지 확인하는 함수 */
void checkDistance(int n, pair<int, int> dat[], int d, int mat[][100], int deg[])
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			/*좌표 변수 체크 및 delta 값 확인*/
			int dx = dat[i].x - dat[j].x;
			int dy = dat[i].y - dat[j].y;

			if (dx*dx + dy*dy > d*d)
				continue;

			/*행렬 대응 및 deg 증가(+1)*/
			mat[i][j] = mat[j][i] = 1;
			deg[i]++; deg[j]++;
		}
	}
}
/*상호 통신 가능한 센서로 구성된 군을 탐색하는 함수, 클러스터에 포함될 가능성이 있는 노드들을 개별 순회 및 판단*/
void searchCluster(int n, int deg[], int mat[][100],int caseNum)
{
	int nodes[100];
	for (int i = 0; i < n; i++) nodes[i] = i;
	for (int magic = 0; magic < 30; magic++)
	{
		for (int i = 0; i < n; i++)
		{
			if (deg[i] < ans.size())
				continue;

			set<int> cand;
			cand.insert(i);

			for (;;)
			{
				bool updated = false;

				for (int jj = 0; jj < n; jj++)
				{
					int j = nodes[jj];

					if (deg[j] < ans.size())
						continue;
					/*i want sleep.... please save us....jogyonim...*/

					if (cand.count(j))
						continue;

					bool fail = false;


					for (auto prev : cand)
					{/*mat matching and check!*/
						if (mat[prev][j] == 0)
						{
							fail = true;
							break;
						}
					}


					if (!fail)
					{/*when gotcha*/
						updated = true;
						cand.insert(j);
					}
				}


				if (!updated) break;


			}

			if (cand.size() > ans.size())
			{
				ans = vector<int>(cand.begin(), cand.end());
			}/*쉬울꺼라 했잖아요...화요일 꺼보다.... */

		}
		/*new clustering*/
		random_shuffle(nodes, nodes + n);
	}
	
	printf("Case #%d : %d,",caseNum+1 , ans.size());

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d%c", ans[i] + 1, (i + 1 == ans.size()) ? ' ' : ' ');
	}/*모델 세우는데 딱 2배 걸렸습니다ㅜㅜ 너무해...*/printf("\n");
}
/* 선언된 2차원 거리 체크 결과가 저장 되는 배열 mat과 distace's number를 카운트 하는 배열 deg 을 초기화 합니다.*/
void valueInit(int mat[][100], int deg[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			mat[i][j] = 0;
		deg[i] = 0;
	}
}