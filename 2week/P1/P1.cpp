
//Copyright �赿ȣ(hobbeskim) All Rights Reserved.
//Junior Design Project report-2
//https://github.com/hobbeskim


#include<stdio.h>
#include<stdlib.h>
int combiIndex[3] = { 0 };//���� Ž���� ������ �ε����� ������ �迭

/*funtion prototype*/
int searchCombi(int * arr, int num);
int * makeDynamicArr(int num);

int main()
{
	int num=0;
	printf("�˻� ��� �迭�� ���̸� �Է��� �ּ���.\n");
	scanf("%d", &num);
	int * arr = makeDynamicArr(num);

	printf("\n�˻� ��� �迭�� �Է��� �ּ���.\n\n");
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	if (searchCombi(arr, num) == 1)
	{
		printf("�����ϴ� ������ ���׿� �ФФ�\n");
	}
	else
	{
		searchCombi(arr, num);
		printf("index�� ã�ҽ��ϴ�.\n");
		printf("INDEX:%d  %d  %d", combiIndex[0], combiIndex[1], combiIndex[2]);
		//printf("VALUE:%d  %d  %d", arr[combiIndex[0]], arr[combiIndex[1]], arr[combiIndex[2]]);
	}
	free(arr);

	getchar();
	getchar();
	return 0;
}
/***********************************************************************/
/************�Է� parameter : integer pointer(�迭),integer******	********/
/************��� parameter : integer ***********************************/
/*                                                                     */
// �� �Լ��� �� ���α׷����� array�� ����� ���� ������ ������ Ž���ϰ�,       //
// ������ ������ �����ϴ� �Լ��� ã�� ��� ���� �迭�� Index�� �����Ѵ�.       // 
//�� �Լ��� Ž�� ��� �迭�� �ּ�(int *)�� ����(num)�� �ʿ�� �մϴ�.         //
/*                                                                     */
/***********************************************************************/
int searchCombi(int * arr, int num)
{
	for (int i = 0; i < num - 2; i++)
	{/*i�� �Է¹��� �迭�� ���������� ��ȸ�ϸ�, ������ ����° ������ �̵��� �� �ִ�.*/
		for (int j = i + 1; j < num - 1; j++)
		{/*j�� �Է¹��� �迭�� ������+1���� ��ȸ�ϸ�, ������ �ι�° ������ �̵��� �� �ִ�.*/
			for (int k = j + 1; k < num; k++)
			{/*k�� �Է¹��� �迭�� ������+2���� ��ȸ�ϸ�, ������ ù��° ������ �̵��� �� �ִ�.*/
				if (arr[i] + arr[j] + arr[k] == 0)
				{/*������ �����ϴ� ���� �˻� ���� ��*/
					combiIndex[0] = i;
					combiIndex[1] = j;
					combiIndex[2] = k;

					return 0;//�迭 ���� 
				}
				else if (i == num - 3 && j == num - 2 && k == num - 1)
				{/*��� �ε��� �˻� ��� ������ �����ϴ� ���� ���� ���*/
					return 1;//�� ����
				}
			}
		}
	}
}
/***********************************************************************/
/************�Է� parameter : integer ***********************************/
/************��� parameter : integer pointer(�����迭)*******************/
/*                                                                     */
// �� �Լ��� �� ���α׷����� ����ڰ� �Է��ϴ� ����(num)���� �޾� ���̰� num��  //
// �迭�� ���� �Ҵ� ���·� ����ϴ�. ���� �迭�� �ּҰ�(int *)�� �����մϴ�.    //
/*                                                                     */
/***********************************************************************/
int * makeDynamicArr(int num)
{
	int * arr;
	arr = (int *)malloc(sizeof(int)*num);//integer �������� ���� �迭 ����
	return arr;
}