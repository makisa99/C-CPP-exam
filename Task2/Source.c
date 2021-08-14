#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

void prebroj(int A[], int m, int *brB, int* brC) { //Funkcija koja sluzi za brojanje koliko ima elemenata u kom nizu, da bih mogao samo jednom malloc a ne vise puta realloc
	double temp = 0;
	int tempint = 0;
	for (int i = 0; i < m; i++) {
		temp = sqrt(A[i]);
		tempint = sqrt(A[i]);
		if (temp == tempint) {
			*brB = *brB + 1;
		}
		else {
			*brC = *brC + 1;
		}
	}
}

void formiraj(int A[], int* B, int* C, int m) { 
	int brojacB = 0;
	int brojacC = 0;
	double temp = 0;
	int tempint = 0;

	for (int i = 0; i < m; i++) { 
		temp = sqrt(A[i]);
		tempint = sqrt(A[i]);
		if (temp == tempint) { 
			*(B + brojacB) = *(A + i);
			brojacB = brojacB + 1;
		}
		else {
			*(C + brojacC) = *(A + i);
			brojacC++;
		}
	}
}


int main() {
	const int M = 30;
	srand(time(0));
	int A[30];
	printf("A: ");
	for (int i = 0; i < M; i++)
	{
		A[i] = rand() % 200;
		printf("%d ", A[i]);
	}
	int brB = 0;
	int brC = 0;
	prebroj(A, M, &brB, &brC);

	int* B = malloc(sizeof(int)*brB+sizeof(int));
	int* C = malloc(sizeof(int)*brC+sizeof(int));

	formiraj(A,B,C,M);
	printf("\nDimenzija B: %d Dimenzija C: %d\n",brB,brC);
	FILE* out;
	out = fopen("Zadatak2.txt", "w");
	int upisao = 0;
	printf("\nB: ");
	fprintf(out, "B: \n");
	for (int i = 0; i < brB; i++) {
		if (upisao == 5) {
			fprintf(out,"\n");
			upisao = 0;
		}
		printf("%d ", *(B + i));
		fprintf(out, "%5d", *(B + i));
		upisao++;
	}
	upisao = 0;
	printf("\nC: ");
	fprintf(out, "\nC: \n");
	for (int i = 0; i < brC; i++) {
		if (upisao == 5) {
			fprintf(out, "\n");
			upisao = 0;
		}
		printf("%d ", *(C + i));
		fprintf(out, "%5d", *(C + i));
		upisao++;
	}

	

	return 0;
}