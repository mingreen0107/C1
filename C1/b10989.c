// 오름차순으로 정렬하기
#include <stdio.h>

int main() {
    int N;
    int count[10001] = { 0 }; 

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        count[num]++;
    }

    for (int i = 1; i <= 10000; i++) {
        while (count[i] > 0) {
            printf("%d\n", i);
            count[i]--;
        }
    }

    return 0;
}

