
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

	/*TEST Ƚ�� �Է�*/
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

		/*INTERFACE MESSAGE*/
		printf("please insert edge info, ex) 1 2\n\n");
		printf("if you insert -1 -1, edge insertion will end\n\n\n");


		/*NODE EDGE �Է¹޴� while �� ����ڰ� -1 -1 �Է½� Ż��*/
		while (1)
		{
			int i, j = 1;
			printf("(%d)insert edge information:",++count);
			scanf("%d %d", &i, &j);
			if (i == -1 && j == -1)
				break;

			graphMatrix[i-1][j-1] = 1;
			graphMatrix[j-1][i-1] = 1;
			/*e.g. 1��° ���� 3��° ����� ����->�׷�����Ʈ�������� (0,2)/(2,0)*/
		}
		
		/*����ڰ� �Է��� ��������� ���� �����*/
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				printf("%d ", graphMatrix[i][j]);
			printf("\n");
		}



		/*CUTNODE STATUS PRINT*/
		printf("\ncase#%d : Cutnodes = ", i + 1);
		for (int i = 0; i < N; i++)
		{/*��� ��ȸ*/

			/*judgeCutNode���� �Ǵ��Ͽ�, �ش� ��尡 cutNode�� ��� 1��ȯ*/
			currentCutNode = 0;
			currentCutNode=judgeCutNode(i,N, graphMatrix);
			
			
			/*�ش� Node�� CutNode �̴�!!!!*/
			if (currentCutNode > 0)
			{
				printf("%d ", i + 1);
				thereIsCutNode++;
			}

		}

		/*cutNode�� ���� ���*/
		if (thereIsCutNode == 0)
			printf("NONE");


		/*�����Ҵ�Ǿ��� �޸� ��ȯ!*/
		free(graphMatrix[0]);
		free(graphMatrix);

	}

	return 0;

}

/*NbyN ���� ����� �� ����� ���ϱ� ���� �Լ�*/
int ** graphMultiplier(int N, int ** A, int ** B)
{

	/* �� ����� ������ ������ �� ����� �����ϰ� �ʱ�ȭ �մϴ�.*/
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

	/*����� ���� ���ϴ� ���� 3�� for�� ��� */
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
			valueCopyMatrix[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			valueCopyMatrix[i][j] = originGraphMatrix[i][j];
			valueCopyMatrix[i][j];
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




	/*����ڰ� �Է��� ��������� ���� �����*/
	printf("\n\n\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ",valueCopyMatrix[i][j]);
		printf("\n");
	}printf("\n\n\n");

	for (int l = 2; l < size; l++)
	{
		

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				judgeMatrix[i][j] += valueCopyMatrix[i][j];
			}
		}
		valueCopyMatrix = graphMultiplier(size, valueCopyMatrix, valueCopyMatrix);

		/*Ž�� ��� node�� ��/�� 0���� ���� ��� ����*/
		/*for (int i = 0; i < size; i++)
			judgeMatrix[nodeNum][i] = 0;
		for (int i = 0; i < size; i++)
			judgeMatrix[i][nodeNum] = 0;*/

		/*Ž�� ��� node�� ��/�� 0���� ���� ��� ����*/
		/*for (int i = 0; i < size; i++)
			valueCopyMatrix[nodeNum][i] = 0;
		for (int i = 0; i < size; i++)
			valueCopyMatrix[i][nodeNum] = 0;*/
		/*����ڰ� �Է��� ��������� ���� �����*/
		printf("\n\n\n");
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				printf("%d ", valueCopyMatrix[i][j]);
			printf("\n");
		}printf("\n\n\n");

	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i != nodeNum&&j != nodeNum)
			{
				if (judgeMatrix[i][j] == 0)
				{
					return 1;
				}
			}
		
		}
	}
	return 0;
	
}