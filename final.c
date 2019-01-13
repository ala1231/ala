#include<stdio.h>
struct
{
	int k[20][20];
	int r1, c1;
}m1;
struct
{
	int l[20][20];
	int r2, c2;
}m2;
struct
{
	int m[20][20];

}R;


int main()
{

	char choose;

menutop:

	printf("welcome \n");
	printf("1. Addition of two matrices \n");
	printf("2. Multiplication of two matrices \n");
	printf("3. Inverse of 3x3 matrix \n");
	printf("4. exit \n");
	printf("choose your calculation");
	scanf("%s", &choose);
	
	switch (choose)
	{
	case '1': {
		int i, j;
		printf("enter no. of rows of first matrix:\n");
		scanf("%d", &m1.r1);
		printf("enter no. of columns of first matrix:\n");
		scanf("%d", &m1.c1);
		printf("enter no. of rows of second matrix:\n");
		scanf("%d", &m2.r2);
		printf("enter no. of columns of second matrix:\n");
		scanf("%d", &m2.c2);
		if (m1.r1 == m2.r2 && m1.c1 == m2.c2)
		{
			printf("\n enter the elements for the firs matrix:\n");
			for (i = 0; i < m1.r1; i++)
			{
				for (j = 0; j < m1.c1; j++)
				{
					scanf("%d", &m1.k[i][j]);
				}
			}
			printf("\n-The first array that you enter is: \n");

			for (i = 0; i < m1.r1; i++)
			{
				for (j = 0; j < m1.c1; j++)
				{
					printf("\t%d", m1.k[i][j]);
				}
				printf("\n");
			}
			printf("\n enter the elements for the second matrix:\n");
			for (i = 0; i < m2.r2; i++)
			{
				for (j = 0; j < m2.c2; j++)
				{

					{
						scanf("%d", &m2.l[i][j]);
					}

				}
			}
			printf("\n-The second array that you enter is: \n");
			for (i = 0; i < m2.r2; i++)
			{
				for (j = 0; j < m2.c2; j++)
				{
					printf("\t%d", m2.l[i][j]);;
				}
				printf("\n");
			}
			for (i = 0; i < m2.r2; i++)
			{
				for (j = 0; j < m2.c2; j++)
				{
					R.m[i][j] = m1.k[i][j] + m2.l[i][j];
				}
			}
			printf("\n resultant matrix is : \n");
			for (i = 0; i < m2.r2; i++)
			{
				for (j = 0; j < m2.c2; j++)
				{
					printf("\t%d", R.m[i][j]);
				}

				printf("\n");
			}
		}
		else
		{
			printf("\n sorry addittion is not possible");
		}
		goto menutop;
		break;

	}
	case '2': {
		int i, j, X, sum = 0;
		printf("enter no. of rows of first matrix:\n");
		scanf("%d", &m1.r1);
		printf("enter no. of columns of first matrix:\n");
		scanf("%d", &m1.c1);
		printf("enter no. of rows of second matrix:\n");
		scanf("%d", &m2.r2);
		printf("enter no. of columns of second matrix:\n");
		scanf("%d", &m2.c2);
		if (m1.c1 != m2.r2)

			printf("The matrices can't be multiplied with each other.\n");
		else
		{
		printf("Enter elements of first matrix\n");

		for (i = 0; i < m1.r1; i++)
			for (j = 0; j < m1.c1; j++)
				scanf("%d", &m1.k[i][j]);
		printf("\n-The first matrix that you entered is: \n");

		for (i = 0; i < m1.r1; i++)
		{
			for (j = 0; j < m1.c1; j++)
			{
				printf("\t%d", m1.k[i][j]);
			}
			printf("\n");
		}


		
			printf("Enter elements of second matrix\n");

			for (i = 0; i < m2.r2; i++) 
				for (j = 0; j < m2.c2; j++)
					scanf("%d", &m2.l[i][j]);
			printf("\n-The second matrix that you entered is: \n");
			for (i = 0; i < m2.r2; i++)
			{
				for (j = 0; j < m2.c2; j++)
				{
					printf("\t%d", m2.l[i][j]);
				}
				printf("\n");
			}


			for (i = 0; i < m1.r1; i++) {
				for (j = 0; j < m2.c2; j++) {
					for (X = 0; X < m2.r2; X++) {
						sum = sum + m1.k[i][X] * m2.l[X][j];
					}

					R.m[i][j] = sum;
					sum = 0;
				}
			}

			printf("Product of the matrices:\n");

			for (i = 0; i < m1.r1; i++) {
				for (j = 0; j < m2.c2; j++)
					printf("%d\t", R.m[i][j]);

				printf("\n");
			}
		}
		goto menutop;
		break;

	}
	case '3':
	{
		printf("welcome to inverse\n");

		int a[3][3], i, j;
		float determinant = 0;

		printf("Enter the 9 elements of matrix: ");
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				scanf("%d", &a[i][j]);

		printf("\nThe matrix is\n");
		for (i = 0; i < 3; i++) {
			printf("\n");
			for (j = 0; j < 3; j++)
				printf("%d\t", a[i][j]);
		}

		for (i = 0; i < 3; i++)
			determinant = determinant + (a[0][i] * (a[1][(i + 1) % 3] * a[2][(i + 2) % 3] - a[1][(i + 2) % 3] * a[2][(i + 1) % 3]));

		printf("\nInverse of matrix is: \n\n");
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++)
				printf("%.2f\t", ((a[(i + 1) % 3][(j + 1) % 3] * a[(i + 2) % 3][(j + 2) % 3]) - (a[(i + 1) % 3][(j + 2) % 3] * a[(i + 2) % 3][(j + 1) % 3])) / determinant);
			printf("\n");
		}
		break;
	}
	default:
		printf("ops you have entered a wrong input \n");
		goto menutop;

		break;
	}

	getch();
	return 0;
}