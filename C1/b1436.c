// �ٸ���� �ڵ� ����
#include <stdio.h>

int main(void) {

    int i, temp, check, cnt = 1;
    int series;

    scanf("%d", &series);

    if (series == 1) {
        printf("666");
        return 0;
    }
    // 667���� �ݺ��� ������
    for (i = 667;; i++) {
        temp = i;
        check = 0;
        while (temp) {
            if (temp % 1000 == 666) {
                check = 1;
            }
            temp /= 10;
        }
        // check == series �� �ϸ� �ð��ʰ�
        if (check) {
            cnt++;
            if (cnt == series) {
                break;
            }
        }
    }
    printf("%d", i);

    return 0;
}