#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

struct List {
    List *next;
    /* データ型 */
    int data;
};

int main(void) {
    int i;

    /* リストを作成 */
    List *list = NULL;

    /* リストの先頭に要素を追加 */
    for (i = 0; i < 5; i++) {
        List *e = (List *)malloc(sizeof(List));
        if (!e) {
            /* エラー処理 */
            fprintf(stderr, "%s:%d: cannot allocate memory", __FILE__, __LINE__);
            exit(EXIT_FAILURE);
        }
        e->next = NULL;
        /* データ */
        e->data = i;

        if (list)
            e->next = list;
        list = e;
    }

    /* リストの要素を反復 */
    {
        List *p;
        for (p = list; p; p = p->next)
            printf("%d ", p->data);
        printf("\n");
    }

    /* リストの先頭の要素を削除 */
    for (i = 0; i < 6; i++) {
        if (list) {
            List *p = list;
            list = list->next;
            free(p);
        }
    }

    /* リストの末尾に要素を追加 */
    for (i = 0; i < 5; i++) {
        List *e = (List *)malloc(sizeof(List));
        if (!e) {
            /* エラー処理 */
            fprintf(stderr, "%s:%d: cannot allocate memory", __FILE__, __LINE__);
            exit(EXIT_FAILURE);
        }
        e->next = NULL;
        /* データ */
        e->data = i;

        if (list) {
            List *p;
            for (p = list; p->next; p = p->next)
                ;
            p->next = e;
        }
        else {
            list = e;
        }
    }

    /* リストの要素を反復 */
    {
        List *p;
        for (p = list; p; p = p->next)
            printf("%d ", p->data);
        printf("\n");
    }

    /* リストの末尾の要素を削除 */
    for (i = 0; i < 6; i++) {
        if (list) {
            List *p;
            if (list->next) {
                List *q;
                for (q = list; q->next->next; q = q->next)
                    ;
                p = q->next;
                q->next = NULL;
            }
            else {
                p = list;
                list = p->next;
            }
            free(p);
        }
    }

    return 0;
}
