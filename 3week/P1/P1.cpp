#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*fucntion prototype*/
int * sorting(int * arr,int arraySize);
int newSort(int randElement, int * arr,int arraySize);

int main()
{
	int numOfTestCase=0;
	int arraySize=0;
	int roundCount=0;
	int randElement;

	printf("How many Case? >> ");
	scanf("%d", &numOfTestCase);
	

	for (int i = 0; i < numOfTestCase; i++)
	{/*TEST CASE 만큼 반복하는 반복문*/
	
		printf("Enter length of Case Sequence. >>");
		scanf("%d", &arraySize);

		int * originArr;
		originArr = (int *)malloc(sizeof(int)*arraySize);
		int * valueCopyArr;
		valueCopyArr = (int *)malloc(sizeof(int)*arraySize);
		for (int j = 0; j < arraySize; j++)
		{/*Array 입력*/
			printf("array[%d]>>", j);
			scanf("%d", &originArr[j]);
		}
		
		for (int k = 0; k < arraySize; k++)
		{/*크기 순으로 정렬해 뉴소트 알고리즘을 돌리기 위해 생성한다. 선택 대상원소 선택에 사용*/
			valueCopyArr[k] = originArr[k];
		}
		valueCopyArr = sorting(valueCopyArr, arraySize);

		for (int l = 0; l < arraySize; l++)
		{
			randElement = valueCopyArr[l];
			roundCount += newSort(randElement, originArr, arraySize);
		}
		printf("CASE#%d : number of rounds = %d\n", i + 1, roundCount);
		roundCount = 0;
	}

	getchar();
	getchar();
	getchar();
	return 0;
}
/*sorting 함수는 newSort에 인자를 넘겨 주기 위해 사용하는 값을 크기 순서대로 정렬해서 비교합니다.*/
int *sorting(int * arr, int arraySize)
{
	int temp = 0;
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}
	}
	return arr;

}
/*newSort는 선택된 랜덤 원소를 입력 받아, 스왑이 발생하면 1을 전달하고 카운트 하는 함수입니다.*/
int newSort(int randElement, int * arr, int arraySize)
{
	int temp = 0;
	int isDoSwap = 0;
	
	for (int i = 0; i < arraySize-1; i++)
	{
		if (arr[i] == randElement)
		{
			if (arr[i] > arr[i + 1]) 
			{
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				isDoSwap++;
			}
		}
	}
	if (isDoSwap > 0)
		return 1;
	else
		return 0;
}