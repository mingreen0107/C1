#include <stdio.h>

int main() {

	int N;
	int sum = 0, sum_copy;

	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		sum = i;
		sum_copy = sum;
		while (sum_copy) {
			sum += sum_copy % 10;
			sum_copy /= 10;
		}
		if (sum == N) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");

	return 0;
}