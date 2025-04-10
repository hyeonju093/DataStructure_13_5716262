#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int val;
} Element;

typedef struct {
    Element data[MAX];
    int size;
} List;

void insertOrUpdate(List* list, int r, int c, int v) {
    for (int i = 0; i < list->size; i++) {
        if (list->data[i].row == r && list->data[i].col == c) {
            list->data[i].val += v;
            return;
        }
    }
    list->data[list->size].row = r;
    list->data[list->size].col = c;
    list->data[list->size].val = v;
    list->size++;
}

void inputMatrix(List* list) {
    char line[100];
    int r, c, v;

    printf("행렬을 입력하시요? (-1입력 시 행렬의 입력이 종료됨)\n"); 

    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL)
            continue;

        // 엔터 무시
        if (strcmp(line, "\n") == 0) continue;

        // -1을 입력하면 행렬 입력 종료
        if (sscanf_s(line, "%d", &r) == 1 && r == -1)
            break;

        if (sscanf_s(line, "%d %d %d", &r, &c, &v) == 3) {
            insertOrUpdate(list, r, c, v);
        }
        else {
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
        }
    }
}

void printList(List list) {
    printf("두 행렬의 합\n");
    printf("List: size = 20, last = %d\n", list.size - 1);
    printf("Items:\n");
    for (int i = 0; i < list.size; i++) {
        printf("[%d] %d, %d, %d\n", i, list.data[i].row, list.data[i].col, list.data[i].val);
    }
}

int main() {
    List list;
    list.size = 0;

    inputMatrix(&list); // 첫 번째 행렬 입력
    inputMatrix(&list); // 두 번째 행렬 입력

    printList(list);

    return 0;
}