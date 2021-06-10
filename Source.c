#include <stdio.h>
#include <stdint.h>
#include <locale.h>


#define N (3)



int getSqrt2(double precision, double* value) {
	
	
	if (value == NULL)
		return -1;

	
	double a = 1;
	double curPrecision = 0.5;

	
	while (curPrecision >= precision) {
		a = a / 2 + 1 / a;
		curPrecision /= 10;
	}

	
	*value = a;


	
	return 0;

}

int main() {


	
	setlocale(LC_CTYPE, "Russian");


	
	double precisions[N] = { 0.1, 0.01, 0.001 };

	
	double values[N];
	

	
	for (size_t i = 0; i < N; ++i) {

		
		if (getSqrt2(precisions[i], values + i) == -1) {

			printf("Ошибка записи по нулевому адресу!\n");
			return -1;

		}

		
		printf("Значение корня из двух с точностью %f: %1.10f!\n", precisions[i], values[i]);

	}


	
	return 0;

}
