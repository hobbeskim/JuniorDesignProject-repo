
//Copyright �赿ȣ(hobbeskim) All Rights Reserved.
//Junior Design Project report-2
//https://github.com/hobbeskim


#include <stdio.h>
#include <stdlib.h>

/*fuction prototype*/
int *searchMaxInMatrix(int **nMatrix, int *n);
int a_0 = 0, b_0 = 0, a = 0, b = 0;      


int main(void)
{
	int x, y, N;
	int **nMatrix, *MAX;

	printf("N�� �Է�:");
	scanf("%d", &N);

	/*NbyN ����� �����ϴ� ���� 2���� �����Ҵ�*/
	/*�����Ͱ� �����ϴ� �迭�� ����������~�� ����~*/
	nMatrix = (int**)malloc(sizeof(int*)*N);
	nMatrix[0] = (int *)malloc(sizeof(int*)*N*N);
	for (int i = 1; i<N; i++) 
	{
		nMatrix[i] = nMatrix[i - 1] + N;
	}


	for (x = 0; x < N; x++) 
	{/* NbyN �迭 ���� �Է�*/
		for (y = 0; y < N; y++) 
		{
			printf("%d*%d�迭���� [%d][%d]���ڸ� �Է��ϼ���>>", N, N, x, y);
			scanf("%d", &nMatrix[x][y]);
		}
	}
	for (x = 0; x < N; x++) 
	{/*����ڿ��� �Է��� ��� ���*/
		for (y = 0; y < N; y++) 
		{
			printf(" %d", nMatrix[x][y]);
		}
		printf("\n");
	}


	/*MAX�� nMatrix�� �κ� �ִ� ����, �������� ó���� ��ǥ ���� ���*/
	MAX = searchMaxInMatrix(nMatrix, &N);
	printf("\n\nMAX VALUE = %d, POSITION = %d-%d,%d-%d\n", *MAX, (b_0), b, (a_0), a);

	/*memory releasing*/
	free(nMatrix[0]);
	free(nMatrix);

	getchar();
	getchar();
	getchar();
	return 0;
}
//�κ������ ���� �ִ��� ã���ִ� ����� �ϴ� �Լ�
/***********************************************************************/
/************�Է� parameter : integer ptr ptr(�����迭),integer ptr*******/
/************��� parameter : integer ptr********************************/
/*                                                                     */
// �� �Լ��� �� ���α׷����� �Էµ� NbyN ����� �κ� ���(1by1���� ����)�� �ִ�//
// ���� �˻��ϴ� ����� �Ѵ�. ���ڷ� ���޵� �迭���� �κ������ �پ��� ���·� �� //
// ��� ���ϰ� ��ǥ ������ �����Ѵ�.									   //
/*                                                                     */
/***********************************************************************/
int *searchMaxInMatrix(int **nMatrix, int *N)
{
	int n = *N;
	int sum = 0;
	int *result = (int*)malloc(1);      //��ȯ�� ���� result�� �����ϰ� 0���� �ʱ�ȭ��
	*result = 0;

	for (int s = 0; s < n; s++)
	{/*s,t�� �κ������ ����*/
		for (int t = 0; t < n; t++)
		{
			for (int i = 0; i < n; i++)
			{/*i,j�� �κ������ ��*/
				for (int j = 0; j < n; j++)
				{
					for (int x = s; x <= i; x++)
					{
						for (int y = t; y <= j; y++)
						{/*�κ������ ���� ����!! */
							sum += nMatrix[x][y];
						}
						if (*result == sum)
						{/*result==sum�� ���*/
							if ((a - a_0 + 1)*(b - b_0 + 1) > (i - s + 1)*(j - t + 1))
							{/*�κ������ ���̰� ������ ������� �κ������ �ִ񰪰� ����,�� ����*/
								*result = sum;
								a_0 = s;
								b_0 = t;
								a = i;
								b = j;
							}
						}
						else if (*result < sum)
						{/*result<sum�� ���,�κ������ ����, �� ����*/
							*result = sum;
							a_0 = s;
							b_0 = t;
							a = i;
							b = j;
						}
						sum = 0;
					}
				}
			}
		}
		return result;
	}
}