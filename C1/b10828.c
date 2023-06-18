// 스택 연습
#include <stdio.h>

int stack[10000];
int topN = -1;

void push(int data) {
    stack[++topN] = data;
}
int pop() {
    if (topN != -1) {
        int data = stack[topN--];
        printf("%d\n", data);
        return data;
    }
    else {
        printf("-1\n");
        return -1;
    }
}
int size() {
    printf("%d\n", topN + 1);
    return 0;
}
int empty() {
    if (topN == -1) {
        printf("1\n");
        return 1;
    }
    else {
        printf("0\n");
        return 0;
    }
}
int top() {
    if (topN == -1) {
        printf("-1\n");
        return -1;
    }
    else {
        printf("%d\n", stack[topN]);
        return stack[topN];
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int i = 0;
    char command[6] = { 0 };

    while (i != N) {
        scanf("%s", command);  
        if (command[1] == 'u') {
            int num = 0;
            scanf("%d", &num);
            push(num);
        }
        else if (command[0] == 'p' && command[1] == 'o') pop();
        else if (command[0] == 's') size();
        else if (command[0] == 'e') empty();
        else top();
        i++;
    }
    return 0;
}
