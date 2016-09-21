/*2015112167 �İ� �赿ȣ*/
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

	/*�� ������ ����*/
	pair<int, int> dat[100];

	/*check able distance*/
	int mat[100][100];

	/* if start number i,count able distance's number*/
	int deg[100];

	printf("How many case? >>");
	scanf("%d", &CASE);

	for (int CaseNum = 0; CaseNum < CASE; CaseNum++) 
	{/*CASE�� �� ��ŭ �ݺ��մϴ�*/

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
/*����ڿ��� �����͸� �Է¹޴� �Լ� dat�� ���� �����ϴ� �Լ�*/
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
/*�� �Լ��� ���ڷ� ���޵� �� ��(���)�� �������� �־��� Distance ���� ���� ����� Ȯ���ϴ� �Լ� */
void checkDistance(int n, pair<int, int> dat[], int d, int mat[][100], int deg[])
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			/*��ǥ ���� üũ �� delta �� Ȯ��*/
			int dx = dat[i].x - dat[j].x;
			int dy = dat[i].y - dat[j].y;

			if (dx*dx + dy*dy > d*d)
				continue;

			/*��� ���� �� deg ����(+1)*/
			mat[i][j] = mat[j][i] = 1;
			deg[i]++; deg[j]++;
		}
	}
}
/*��ȣ ��� ������ ������ ������ ���� Ž���ϴ� �Լ�, Ŭ�����Ϳ� ���Ե� ���ɼ��� �ִ� ������ ���� ��ȸ �� �Ǵ�*/
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
			}/*���ﲨ�� ���ݾƿ�...ȭ���� ������.... */

		}
		/*new clustering*/
		random_shuffle(nodes, nodes + n);
	}
	
	printf("Case #%d : %d,",caseNum+1 , ans.size());

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d%c", ans[i] + 1, (i + 1 == ans.size()) ? ' ' : ' ');
	}/*�� ����µ� �� 2�� �ɷȽ��ϴ٤̤� �ʹ���...*/printf("\n");
}
/* ����� 2���� �Ÿ� üũ ����� ���� �Ǵ� �迭 mat�� distace's number�� ī��Ʈ �ϴ� �迭 deg �� �ʱ�ȭ �մϴ�.*/
void valueInit(int mat[][100], int deg[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			mat[i][j] = 0;
		deg[i] = 0;
	}
}