
//Copyright 김동호(hobbeskim) All Rights Reserved.
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

	printf("N을 입력:");
	scanf("%d", &N);

	/*NbyN 행렬을 생성하는 선형 2차원 동적할당*/
	/*포인터가 지정하는 배열이 이중포인터~앙 기모띠~*/
	nMatrix = (int**)malloc(sizeof(int*)*N);
	nMatrix[0] = (int *)malloc(sizeof(int*)*N*N);
	for (int i = 1; i<N; i++) 
	{
		nMatrix[i] = nMatrix[i - 1] + N;
	}


	for (x = 0; x < N; x++) 
	{/* NbyN 배열 원소 입력*/
		for (y = 0; y < N; y++) 
		{
			printf("%d*%d배열에서 [%d][%d]인자를 입력하세요>>", N, N, x, y);
			scanf("%d", &nMatrix[x][y]);
		}
	}
	for (x = 0; x < N; x++) 
	{/*사용자에게 입력한 행렬 출력*/
		for (y = 0; y < N; y++) 
		{
			printf(" %d", nMatrix[x][y]);
		}
		printf("\n");
	}


	/*MAX에 nMatrix의 부분 최댓값 전달, 전역변수 처리한 좌표 정보 출력*/
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
//부분행렬의 합의 최댓값을 찾아주는 기능을 하는 함수
/***********************************************************************/
/************입력 parameter : integer ptr ptr(동적배열),integer ptr*******/
/************출력 parameter : integer ptr********************************/
/*                                                                     */
// 본 함수는 이 프로그램에서 입력된 NbyN 행렬의 부분 행렬(1by1형태 제외)의 최댓//
// 값을 검색하는 기능을 한다. 인자로 전달된 배열에서 부분행렬을 다양한 형태로 만 //
// 들어 비교하고 좌표 정보를 저장한다.									   //
/*                                                                     */
/***********************************************************************/
int *searchMaxInMatrix(int **nMatrix, int *N)
{
	int n = *N;
	int sum = 0;
	int *result = (int*)malloc(1);      //반환할 값인 result를 선언하고 0으로 초기화함
	*result = 0;

	for (int s = 0; s < n; s++)
	{/*s,t는 부분행렬의 시작*/
		for (int t = 0; t < n; t++)
		{
			for (int i = 0; i < n; i++)
			{/*i,j는 부분행렬의 끝*/
				for (int j = 0; j < n; j++)
				{
					for (int x = s; x <= i; x++)
					{
						for (int y = t; y <= j; y++)
						{/*부분행렬의 합을 저장!! */
							sum += nMatrix[x][y];
						}
						if (*result == sum)
						{/*result==sum인 경우*/
							if ((a - a_0 + 1)*(b - b_0 + 1) > (i - s + 1)*(j - t + 1))
							{/*부분행렬의 넓이가 전보다 작을경우 부분행렬의 최댓값과 시작,끝 저장*/
								*result = sum;
								a_0 = s;
								b_0 = t;
								a = i;
								b = j;
							}
						}
						else if (*result < sum)
						{/*result<sum인 경우,부분행렬의 시작, 끝 저장*/
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