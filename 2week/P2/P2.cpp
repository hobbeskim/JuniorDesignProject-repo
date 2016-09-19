//Copyright 김동호(hobbeskim) All Rights Reserved.
//Junior Design Project report-2
//https://github.com/hobbeskim

#include<stdio.h>
#include<stdlib.h>

/*분수의 기능을 하는 구조체 선언, 구조체는 분자에 해당하는 값과 분모에 해당하는 값을 가진다.*/
typedef struct fraction
{
	int numerator=0;//분자에 해당하는 값.
	int denominator=0;//분모에 해당하는 값.

}fraction;

/*fuction prototype*/
int getGCD(int A, int B);
fraction reductFrac(fraction Frac);
fraction multiFrac(fraction FracA,fraction FracB);

int main(void)
{
	fraction A, B, afterOperation;

	printf("곱하려는 분수 1을 분자 분모 형태로 분수를 입력해주세요.\n");
	scanf("%d %d",&(A.numerator),&(A.denominator));

	printf("곱하려는 분수 2을 분자 분모 형태로 분수를 입력해주세요.\n");
	scanf("%d %d",&(B.numerator), &(B.denominator));

	afterOperation = multiFrac(A, B);
	printf("%d/%d", afterOperation.numerator, afterOperation.denominator);
	
	getchar();
	getchar();
	return 0;

}
/***********************************************************************/
/************입력 parameter : integer,integer ***************************/
/************출력 parameter : integer ***********************************/
/*                                                                     */
// 본 함수는 분수 구조체의 약분을 위해 최대공약수를 구하는 함수이다. 유클리드    //
// 호제법의 알고리즘을 사용했다. 연산 대상이 되는 정수를 받아, 재귀적으로 함수를 //
// 실행한다.															   //
/*                                                                     */
/***********************************************************************/
int getGCD(int A, int B)
{
	if (A >= B)
	{
		if (A%B == 0)
			return B;
		else
			return getGCD(B, A%B);//재귀 호출
	}
	else
	{	
		if (B%A == 0)
			return A;
		else
			return getGCD(A, B%A);//재귀 호출
	}
}
/***********************************************************************/
/************입력 parameter : fraction **********************************/
/************출력 parameter : fraction **********************************/
/*                                                                     */
//	본 함수는 이 프로그램에서 약분의 기능을 수행합니다. fraction 자료형의 구성 //
//	원소인 분자, 분모에 각각 접근하여 getGCD 프로그램을 수행해 최대공약수를 구  //
//	하고 나눠줍니다.													   //
/*                                                                     */
/***********************************************************************/
fraction reductFrac(fraction Frac)
{
	int GCD=getGCD(Frac.numerator, Frac.denominator);
	Frac.numerator = (Frac.numerator) / GCD;
	Frac.denominator = (Frac.denominator) / GCD;

	return Frac;
}
/***********************************************************************/
/************입력 parameter : fraction, fraction*************************/
/************출력 parameter : fraction **********************************/
/*                                                                     */
//	본 함수는 이 프로그램에서 fraction간의 연산을 담당하고 있습니다.		   //
//	함수 내부에서 reductFrac을 호출하여, 약분 기능을 내장하고 있습니다.
/*                                                                     */
/***********************************************************************/
fraction multiFrac(fraction FracA,fraction FracB)
{
	fraction afterMultiFrac;

	afterMultiFrac.numerator = FracA.numerator*FracB.numerator;
	afterMultiFrac.denominator = FracA.denominator*FracB.denominator;
	
	return reductFrac(afterMultiFrac);
}