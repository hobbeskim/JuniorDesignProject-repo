
//Copyright 김동호(hobbeskim) All Rights Reserved.
//Junior Design Project report-2
//https://github.com/hobbeskim


#include<stdio.h>
#include<stdlib.h>
int combiIndex[3] = { 0 };//조합 탐색에 성공시 인덱스를 저장할 배열

/*funtion prototype*/
int searchCombi(int * arr, int num);
int * makeDynamicArr(int num);

int main()
{
	int num=0;
	printf("검색 대상 배열의 길이를 입력해 주세요.\n");
	scanf("%d", &num);
	int * arr = makeDynamicArr(num);

	printf("\n검색 대상 배열을 입력해 주세요.\n\n");
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	if (searchCombi(arr, num) == 1)
	{
		printf("만족하는 조합이 없네요 ㅠㅠㅠ\n");
	}
	else
	{
		searchCombi(arr, num);
		printf("index를 찾았습니다.\n");
		printf("INDEX:%d  %d  %d", combiIndex[0], combiIndex[1], combiIndex[2]);
		//printf("VALUE:%d  %d  %d", arr[combiIndex[0]], arr[combiIndex[1]], arr[combiIndex[2]]);
	}
	free(arr);

	getchar();
	getchar();
	return 0;
}
/***********************************************************************/
/************입력 parameter : integer pointer(배열),integer******	********/
/************출력 parameter : integer ***********************************/
/*                                                                     */
// 본 함수는 이 프로그램에서 array에 저장된 값을 접근해 조합을 탐색하고,       //
// 문제의 조건을 만족하는 함수를 찾을 경우 전역 배열에 Index를 저장한다.       // 
//본 함수는 탐색 대상 배열의 주소(int *)와 길이(num)을 필요로 합니다.         //
/*                                                                     */
/***********************************************************************/
int searchCombi(int * arr, int num)
{
	for (int i = 0; i < num - 2; i++)
	{/*i는 입력받은 배열의 시작점부터 순회하며, 끝에서 세번째 점까지 이동할 수 있다.*/
		for (int j = i + 1; j < num - 1; j++)
		{/*j는 입력받은 배열의 시작점+1부터 순회하며, 끝에서 두번째 점까지 이동할 수 있다.*/
			for (int k = j + 1; k < num; k++)
			{/*k는 입력받은 배열의 시작점+2부터 순회하며, 끝에서 첫번째 점까지 이동할 수 있다.*/
				if (arr[i] + arr[j] + arr[k] == 0)
				{/*조건을 만족하는 조합 검색 성공 시*/
					combiIndex[0] = i;
					combiIndex[1] = j;
					combiIndex[2] = k;

					return 0;//배열 전달 
				}
				else if (i == num - 3 && j == num - 2 && k == num - 1)
				{/*모든 인덱스 검색 결과 조합을 만족하는 값이 없을 경우*/
					return 1;//값 전달
				}
			}
		}
	}
}
/***********************************************************************/
/************입력 parameter : integer ***********************************/
/************출력 parameter : integer pointer(동적배열)*******************/
/*                                                                     */
// 본 함수는 이 프로그램에서 사용자가 입력하는 정수(num)으로 받아 길이가 num인  //
// 배열을 동적 할당 형태로 만듭니다. 만든 배열의 주소값(int *)을 전달합니다.    //
/*                                                                     */
/***********************************************************************/
int * makeDynamicArr(int num)
{
	int * arr;
	arr = (int *)malloc(sizeof(int)*num);//integer 사이즈의 동적 배열 전달
	return arr;
}