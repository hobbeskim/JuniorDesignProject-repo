//Copyright �赿ȣ(hobbeskim) All Rights Reserved.
//Junior Design Project report-2
//https://github.com/hobbeskim

#include<stdio.h>
#include<stdlib.h>

/*�м��� ����� �ϴ� ����ü ����, ����ü�� ���ڿ� �ش��ϴ� ���� �и� �ش��ϴ� ���� ������.*/
typedef struct fraction
{
	int numerator=0;//���ڿ� �ش��ϴ� ��.
	int denominator=0;//�и� �ش��ϴ� ��.

}fraction;

/*fuction prototype*/
int getGCD(int A, int B);
fraction reductFrac(fraction Frac);
fraction multiFrac(fraction FracA,fraction FracB);

int main(void)
{
	fraction A, B, afterOperation;

	printf("���Ϸ��� �м� 1�� ���� �и� ���·� �м��� �Է����ּ���.\n");
	scanf("%d %d",&(A.numerator),&(A.denominator));

	printf("���Ϸ��� �м� 2�� ���� �и� ���·� �м��� �Է����ּ���.\n");
	scanf("%d %d",&(B.numerator), &(B.denominator));

	afterOperation = multiFrac(A, B);
	printf("%d/%d", afterOperation.numerator, afterOperation.denominator);
	
	getchar();
	getchar();
	return 0;

}
/***********************************************************************/
/************�Է� parameter : integer,integer ***************************/
/************��� parameter : integer ***********************************/
/*                                                                     */
// �� �Լ��� �м� ����ü�� ����� ���� �ִ������� ���ϴ� �Լ��̴�. ��Ŭ����    //
// ȣ������ �˰����� ����ߴ�. ���� ����� �Ǵ� ������ �޾�, ��������� �Լ��� //
// �����Ѵ�.															   //
/*                                                                     */
/***********************************************************************/
int getGCD(int A, int B)
{
	if (A >= B)
	{
		if (A%B == 0)
			return B;
		else
			return getGCD(B, A%B);//��� ȣ��
	}
	else
	{	
		if (B%A == 0)
			return A;
		else
			return getGCD(A, B%A);//��� ȣ��
	}
}
/***********************************************************************/
/************�Է� parameter : fraction **********************************/
/************��� parameter : fraction **********************************/
/*                                                                     */
//	�� �Լ��� �� ���α׷����� ����� ����� �����մϴ�. fraction �ڷ����� ���� //
//	������ ����, �и� ���� �����Ͽ� getGCD ���α׷��� ������ �ִ������� ��  //
//	�ϰ� �����ݴϴ�.													   //
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
/************�Է� parameter : fraction, fraction*************************/
/************��� parameter : fraction **********************************/
/*                                                                     */
//	�� �Լ��� �� ���α׷����� fraction���� ������ ����ϰ� �ֽ��ϴ�.		   //
//	�Լ� ���ο��� reductFrac�� ȣ���Ͽ�, ��� ����� �����ϰ� �ֽ��ϴ�.
/*                                                                     */
/***********************************************************************/
fraction multiFrac(fraction FracA,fraction FracB)
{
	fraction afterMultiFrac;

	afterMultiFrac.numerator = FracA.numerator*FracB.numerator;
	afterMultiFrac.denominator = FracA.denominator*FracB.denominator;
	
	return reductFrac(afterMultiFrac);
}