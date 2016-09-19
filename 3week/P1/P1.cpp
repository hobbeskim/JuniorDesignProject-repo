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
	{/*TEST CASE ��ŭ �ݺ��ϴ� �ݺ���*/
	
		printf("Enter length of Case Sequence. >>");
		scanf("%d", &arraySize);

		int * originArr;
		originArr = (int *)malloc(sizeof(int)*arraySize);
		int * valueCopyArr;
		valueCopyArr = (int *)malloc(sizeof(int)*arraySize);
		for (int j = 0; j < arraySize; j++)
		{/*Array �Է�*/
			printf("array[%d]>>", j);
			scanf("%d", &originArr[j]);
		}
		
		for (int k = 0; k < arraySize; k++)
		{/*ũ�� ������ ������ ����Ʈ �˰����� ������ ���� �����Ѵ�. ���� ������ ���ÿ� ���*/
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
}
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