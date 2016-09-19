#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Function prototype*/
int ** graphMultiplier(int N, int ** A, int **B);
int judgeCutNode(int nodeNum,int size, int ** originGraphMatrix);


int main() 
{	
	int numOfTestCase;
	int numOfCutNode;
	int currentCutNode;
	int thereIsCutNode = 0;
	int count=0;
	int N;
	int ** graphMatrix;

	printf("How many Case? >>");
	scanf("%d", &numOfTestCase);

	
	for (int i = 0; i < numOfTestCase; i++)
	{/*����ڰ� �Է��� �׽�Ʈ ���̽���ŭ �����մϴ�.*/
		printf("CASE#%d\n", i+1);

		int N;

		/*graphMatrix�� �׷����� �������ȭ ������ �����ϴ� ���*/
		int ** graphMatrix;

		printf("How Many Node? >>");
		scanf("%d", &N);
		
		/*graphMatrix�� ������� �Է¿� ���� ���� ���� �� �ʱ�ȭ*/
		graphMatrix = (int**)malloc(sizeof(int*)*N);
		graphMatrix[0] = (int*)malloc(sizeof(int*)*N*N);
		for (int i = 1; i < N; i++)
		{
			graphMatrix[i] = graphMatrix[i - 1] + N;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				graphMatrix[i][j] = 0;
			}
		}

		printf("please insert edge info, ex) 1 2\n");
		printf("if you insert -1 -1, edge insertion will end\n");
		while (1)
		{
			int i, j = 1;
			printf("(%d)insert edge information:",++count);
			scanf("%d %d", &i, &j);
			if (i == -1 && j == -1)
				break;

			graphMatrix[i][j] = 1;
			graphMatrix[j][i] = 1;


		}
		printf("case#%d : Cutnodes = ", i + 1);
		for (int i = 0; i < N; i++)
		{
			currentCutNode=judgeCutNode(i,N, graphMatrix);

			if (currentCutNode > 0)
			{
				printf("%d ", currentCutNode + 1);
				thereIsCutNode++;
			}
		}
		if (thereIsCutNode == 0)
			printf("NONE");

		free(graphMatrix[0]);
		free(graphMatrix);

		
		
	}

	return 0;

}

int ** graphMultiplier(int N, int ** A, int ** B)
{
	int ** newGraphMatrix;
	newGraphMatrix = (int**)malloc(sizeof(int*)*N);
	newGraphMatrix[0] = (int*)malloc(sizeof(int*)*N*N);
	for (int i = 1; i < N; i++)
	{
		newGraphMatrix[i] = newGraphMatrix[i - 1] + N;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			newGraphMatrix[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				newGraphMatrix[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return newGraphMatrix;
}
int judgeCutNode(int nodeNum,int size, int **originGraphMatrix)
{
	/*n��� n���� ��-�� 0���� ������������-*/
	/*graphMatrix�� Ȱ������ ��� �ִ� edge�� ���̴� node-1 ��¡ */
	/*����� 2���� ���� 2���� ��ġ�� ����� ���̹Ƿ� A^2+...+A^(node-1)�� ���ָ�*/
	/*���� ������ ��� ���� ����� ���ڰ� ���� ���̿�, ���� ��� ���ŷ� ���� �� ��� �ܿ� �� ��尡 ���������!!*/
	/*�� ���� �� ���� ���� ! ������ �� ���� ��� �Ǵ��ϴ���? ��� ��Ŀ��� n��� n���� ������ �������� 0�� ��Ÿ����!!*/
	/*#�װ��̹ٷ� #�Ƴ���Ǳ�*/

	/*origin��ķκ��� ���� ���޹޴� ���� value copy*/
	int ** valueCopyMatrix;
	valueCopyMatrix = (int**)malloc(sizeof(int*)*size);
	valueCopyMatrix[0] = (int*)malloc(sizeof(int*)*size*size);
	for (int i = 1; i < size; i++)
	{
		valueCopyMatrix[i] = valueCopyMatrix[i - 1] + size;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			valueCopyMatrix[i][j] = originGraphMatrix[i][j];
		}
	}


	/*sigma(A^n)�� �����ϰ� ����ϱ� ���� ���迭 */
	int ** judgeMatrix;
	judgeMatrix = (int**)malloc(sizeof(int*)*size);
	judgeMatrix[0] = (int*)malloc(sizeof(int*)*size*size);
	for (int i = 1; i < size; i++)
	{
		judgeMatrix[i] = judgeMatrix[i - 1] + size;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			judgeMatrix[i][j] = 0;
		}
	}


	/*Ž�� ��� node�� ��/�� 0���� ���� ��� ����*/
	for (int i = 0; i < size; i++)
		valueCopyMatrix[nodeNum][i] = 0;
	for (int i = 0; i < size; i++)
		valueCopyMatrix[i][nodeNum] = 0;


	for (int i = 2; i < size; i++)
	{
		valueCopyMatrix = graphMultiplier(size, valueCopyMatrix, valueCopyMatrix);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				judgeMatrix[i][j] += valueCopyMatrix[i][j];
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (judgeMatrix[i][j] == 0) 
			{
				if (i == nodeNum || j == nodeNum)
				{
					
				}
				else
				{
					return nodeNum;
				}
			}
		}
	}
	return 0;
	
}