/*hobbeskim*/
#include <stdio.h>
#include <stdlib.h>  

/*사용할 전역 변수 행렬에서 판단하는 시작점, 끝점*/
int a_0 = 0, b_0 = 0, a = 0, b = 0;

/*fuction prototype*/
int *searchMax(int **mat, int *n);  
      //출력할 부분함수의 처음과 끝점의 전역변수 선언
int main(void)
{
	int x, y, N;
	int **ma, *MAX;

	/*행렬 사이즈 입력 및 동적할당으로 행렬 생성!*/
	printf("N을 입력하세요>>");
	scanf_s("%d", &N);
	ma = (int**)malloc(sizeof(int)*N);     
	for (x = 0; x < N; x++) 
	{
		ma[x] = (int*)malloc(sizeof(int)*N);
	}

	/*원소 저장*/
	for (x = 0; x < N; x++) 
	{    
		for (y = 0; y < N; y++) 
		{
			printf("[%d][%d]인자를 입력하세요>>",x, y);
			scanf("%d", &ma[x][y]);
		}
	}


	/*printing user's insert matrix*/
	printf("입력받은 행렬\n");      
	for (x = 0; x < N; x++) 
	{
		for (y = 0; y < N; y++) 
		{
			printf("%2d", ma[x][y]);
		}
		printf("\n");
	}
	printf("\n");


	/*marMAX 함수 호출 및 최댓값 전달, 결과 출력*/
	MAX = searchMax(ma, &N);      
	printf("Max value = %d, position = %d-%d,%d-%d\n", *MAX, (b_0), b, (a_0), a);
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}
//부분행렬의 합의 최댓값을 찾아주는 기능을 하는 함수
int *searchMax(int **mat, int *N)
{
	int x, y, s, t, i, j;
	int n = *N;
	int sum = 0;
	int *result = (int*)malloc(1);      
	*result = 0;

	/*가능한 모든 부분 행렬의 합을 구하는 6중 for*/
	/*s,t는 시작, i,j는 끝*/
	for (s = 0; s < n; s++) {      
		for (t = 0; t < n; t++) {
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					for (x = s; x <= i; x++) {
						for (y = t; y <= j; y++) {
							sum += mat[x][y];   
						}
					}
					/*sum 갱신*/
					if (*result == sum) 
					{	
						/*현 부분행렬의 넓이가 전 부분 행렬의 기록보다 작을 경우 갱신~*/
						if ((a - a_0 + 1)*(b - b_0 + 1) >(i - s + 1)*(j - t + 1))
						{
							*result = sum;
							a_0 = s;
							b_0 = t;
							a = i;
							b = j;
						}            
					}
					/*스코어 갱신*/
					else if (*result < sum) 
					{   
						*result = sum;
						a_0 = s;
						b_0 = t;
						a = i;
						b = j;      //부분행렬의 시작점, 끝점 저장
					}
					sum = 0;      //새로운 부분행렬을 계산하기 위해 sum값 초기화해줌
				}
			}
		}
	}
	return result;
}