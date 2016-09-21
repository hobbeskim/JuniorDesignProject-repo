/*hobbeskim*/
#include <stdio.h>
#include <stdlib.h>  

/*����� ���� ���� ��Ŀ��� �Ǵ��ϴ� ������, ����*/
int a_0 = 0, b_0 = 0, a = 0, b = 0;

/*fuction prototype*/
int *searchMax(int **mat, int *n);  
      //����� �κ��Լ��� ó���� ������ �������� ����
int main(void)
{
	int x, y, N;
	int **ma, *MAX;

	/*��� ������ �Է� �� �����Ҵ����� ��� ����!*/
	printf("N�� �Է��ϼ���>>");
	scanf_s("%d", &N);
	ma = (int**)malloc(sizeof(int)*N);     
	for (x = 0; x < N; x++) 
	{
		ma[x] = (int*)malloc(sizeof(int)*N);
	}

	/*���� ����*/
	for (x = 0; x < N; x++) 
	{    
		for (y = 0; y < N; y++) 
		{
			printf("[%d][%d]���ڸ� �Է��ϼ���>>",x, y);
			scanf("%d", &ma[x][y]);
		}
	}


	/*printing user's insert matrix*/
	printf("�Է¹��� ���\n");      
	for (x = 0; x < N; x++) 
	{
		for (y = 0; y < N; y++) 
		{
			printf("%2d", ma[x][y]);
		}
		printf("\n");
	}
	printf("\n");


	/*marMAX �Լ� ȣ�� �� �ִ� ����, ��� ���*/
	MAX = searchMax(ma, &N);      
	printf("Max value = %d, position = %d-%d,%d-%d\n", *MAX, (b_0), b, (a_0), a);
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}
//�κ������ ���� �ִ��� ã���ִ� ����� �ϴ� �Լ�
int *searchMax(int **mat, int *N)
{
	int x, y, s, t, i, j;
	int n = *N;
	int sum = 0;
	int *result = (int*)malloc(1);      
	*result = 0;

	/*������ ��� �κ� ����� ���� ���ϴ� 6�� for*/
	/*s,t�� ����, i,j�� ��*/
	for (s = 0; s < n; s++) {      
		for (t = 0; t < n; t++) {
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					for (x = s; x <= i; x++) {
						for (y = t; y <= j; y++) {
							sum += mat[x][y];   
						}
					}
					/*sum ����*/
					if (*result == sum) 
					{	
						/*�� �κ������ ���̰� �� �κ� ����� ��Ϻ��� ���� ��� ����~*/
						if ((a - a_0 + 1)*(b - b_0 + 1) >(i - s + 1)*(j - t + 1))
						{
							*result = sum;
							a_0 = s;
							b_0 = t;
							a = i;
							b = j;
						}            
					}
					/*���ھ� ����*/
					else if (*result < sum) 
					{   
						*result = sum;
						a_0 = s;
						b_0 = t;
						a = i;
						b = j;      //�κ������ ������, ���� ����
					}
					sum = 0;      //���ο� �κ������ ����ϱ� ���� sum�� �ʱ�ȭ����
				}
			}
		}
	}
	return result;
}