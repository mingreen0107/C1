// many_check�κ� �ڵ� ���� �ڵ� ��
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int aver(int arr[], int N) {
	double sum = 0;
	int i;
	for (i = 0; i < N; i++) {
		sum += arr[i];
	}
	return round(sum / N);
}

int compare(const void* arr1, const void* arr2) {
    int num1 = *(int*)arr1;
    int num2 = *(int*)arr2;

    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
    else return 0;
}

int many_check(int arr[], int N) {
	// +4000�� ���־� �ε��� Ȯ��
	int ar[8001] = { 0 };
	int i, idx, max = 0, cnt = 0;

	for (i = 0; i < N; i++) {
		idx = arr[i] + 4000;
		ar[idx] += 1;

		// ���� ���� �� max�� �ֱ�
		if (ar[idx] > max)
			max = ar[idx];
	}
	for (i = 0, idx = 0; i < 8001; i++) {
		// ���� ���� ���� ���� ���� ������
		if (ar[i] == max) {
			// ó�� ���� ���̸�
			if (cnt == 0) {
				// idx���� i
				idx = i;
				// cnt���� ����
				cnt++;
			}
			// ó�� ���� ���� �ƴϸ�
			else if (cnt == 1) {
				// �ι�°�� ���� �� �ε����� ���� ��
				idx = i;
				// �ݺ��� ����
				break;
			}
		}
	}
	// idx���� ���� ���� +4000�̾��� ������
	return idx - 4000;
}

int main() {

    int N;
    int i;
    int median = 0, many = 0, range = 0;

    scanf("%d", &N);

    int* arr = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    median = arr[N / 2];
    many = many_check(arr, N);
    range = arr[N - 1] - arr[0];

    printf("%d\n", aver(arr, N));
	printf("%d\n", median);
	printf("%d\n", many);
	printf("%d\n", abs(range));

    free(arr);
    return 0;
}