// many_check부분 코드 보고 코딩 함
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
	// +4000을 해주어 인덱스 확보
	int ar[8001] = { 0 };
	int i, idx, max = 0, cnt = 0;

	for (i = 0; i < N; i++) {
		idx = arr[i] + 4000;
		ar[idx] += 1;

		// 많이 나온 값 max에 넣기
		if (ar[idx] > max)
			max = ar[idx];
	}
	for (i = 0, idx = 0; i < 8001; i++) {
		// 현재 값과 많이 나온 값이 같으면
		if (ar[i] == max) {
			// 처음 나온 값이면
			if (cnt == 0) {
				// idx값은 i
				idx = i;
				// cnt값은 증가
				cnt++;
			}
			// 처음 나온 값이 아니면
			else if (cnt == 1) {
				// 두번째로 낮은 값 인덱스에 넣은 후
				idx = i;
				// 반복문 나옴
				break;
			}
		}
	}
	// idx값은 원래 값의 +4000이었기 때문에
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