
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

	/*TEST 횟수 입력*/
	printf("How many Case? >>");
	scanf("%d", &numOfTestCase);


	
	for (int i = 0; i < numOfTestCase; i++)
	{/*사용자가 입력한 테스트 케이스만큼 실행합니다.*/
		printf("CASE#%d\n", i+1);

		int N;

		/*graphMatrix는 그래프의 인접행렬화 정보를 저장하는 행렬*/
		int ** graphMatrix;

		printf("How Many Node? >>");
		scanf("%d", &N);
		
		/*graphMatrix를 사용자의 입력에 따라 동적 생성 및 초기화*/
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


		/*NODE EDGE 입력받는 while 문 사용자가 -1 -1 입력시 탈출*/
		while (1)
		{
			int i, j = 1;
			printf("(%d)insert edge information:",++count);
			scanf("%d %d", &i, &j);
			if (i == -1 && j == -1)
				break;

			graphMatrix[i-1][j-1] = 1;
			graphMatrix[j-1][i-1] = 1;
			/*e.g. 1번째 노드와 3번째 노드의 간선->그래프매트릭스에선 (0,2)/(2,0)*/
		}
		
		/*사용자가 입력한 정방행렬의 정보 띄워줌*/
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				printf("%d ", graphMatrix[i][j]);
			printf("\n");
		}



		/*CUTNODE STATUS PRINT*/
		printf("\ncase#%d : Cutnodes = ", i + 1);
		for (int i = 0; i < N; i++)
		{/*노드 순회*/

			/*judgeCutNode에서 판단하여, 해당 노드가 cutNode일 경우 1반환*/
			currentCutNode = 0;
			currentCutNode=judgeCutNode(i,N, graphMatrix);
			
			
			/*해당 Node가 CutNode 이다!!!!*/
			if (currentCutNode > 0)
			{
				printf("%d ", i + 1);
				thereIsCutNode++;
			}

		}

		/*cutNode가 없을 경우*/
		if (thereIsCutNode == 0)
			printf("NONE");


		/*동적할당되었던 메모리 반환!*/
		free(graphMatrix[0]);
		free(graphMatrix);

	}

	return 0;

}

/*NbyN 정방 행렬의 곱 행렬을 구하기 위한 함수*/
int ** graphMultiplier(int N, int ** A, int ** B)
{

	/* 곱 행렬의 정보를 저장한 새 행렬을 생성하고 초기화 합니다.*/
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

	/*행렬의 곱을 구하는 과정 3중 for문 사용 */
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
	/*n행과 n열은 싹-다 0으로 만들어버리갔으-*/
	/*graphMatrix를 활용하쟝 룰루 최대 edge의 길이는 node-1 개징 */
	/*행렬의 2승은 엣지 2개를 거치는 경로의 수이므로 A^2+...+A^(node-1)를 해주면*/
	/*노드로 가능한 모든 접근 경로의 숫자가 나올 것이여, 만약 노드 제거로 인해 당 노드 외에 섬 노드가 만들어지면!!*/
	/*당 노드는 컷 노드란 말씀 ! 후후후 섬 노드는 어떻게 판단하느냐? 결과 행렬에서 n행과 n열을 제외한 구간에서 0이 나타나면!!*/
	/*#그것이바로 #컷노드의길*/

	/*origin행렬로부터 값을 전달받는 과정 value copy*/
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


	/*sigma(A^n)을 축적하고 계산하기 위한 공배열 */
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




	/*사용자가 입력한 정방행렬의 정보 띄워줌*/
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

		/*탐색 대상 node의 행/렬 0으로 만듬 노드 컷팅*/
		/*for (int i = 0; i < size; i++)
			judgeMatrix[nodeNum][i] = 0;
		for (int i = 0; i < size; i++)
			judgeMatrix[i][nodeNum] = 0;*/

		/*탐색 대상 node의 행/렬 0으로 만듬 노드 컷팅*/
		/*for (int i = 0; i < size; i++)
			valueCopyMatrix[nodeNum][i] = 0;
		for (int i = 0; i < size; i++)
			valueCopyMatrix[i][nodeNum] = 0;*/
		/*사용자가 입력한 정방행렬의 정보 띄워줌*/
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