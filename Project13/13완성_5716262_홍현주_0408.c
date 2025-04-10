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

    printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n"); 

    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL)
            continue;

        // ���� ����
        if (strcmp(line, "\n") == 0) continue;

        // -1�� �Է��ϸ� ��� �Է� ����
        if (sscanf_s(line, "%d", &r) == 1 && r == -1)
            break;

        if (sscanf_s(line, "%d %d %d", &r, &c, &v) == 3) {
            insertOrUpdate(list, r, c, v);
        }
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }
}

void printList(List list) {
    printf("�� ����� ��\n");
    printf("List: size = 20, last = %d\n", list.size - 1);
    printf("Items:\n");
    for (int i = 0; i < list.size; i++) {
        printf("[%d] %d, %d, %d\n", i, list.data[i].row, list.data[i].col, list.data[i].val);
    }
}

int main() {
    List list;
    list.size = 0;

    inputMatrix(&list); // ù ��° ��� �Է�
    inputMatrix(&list); // �� ��° ��� �Է�

    printList(list);

    return 0;
}