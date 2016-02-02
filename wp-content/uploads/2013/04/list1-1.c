#include <stdio.h>
#include <stdlib.h>

typedef struct LIST {
    /* データ型 */
    int data;
    struct LIST *next;
} LIST;

int main(void) {
    int i;

    /* リストを作成 */
    LIST *list = NULL;

    /* リストの先頭に要素を追加 */
    for (i = 0; i < 5; i++) {
        LIST *e = (LIST *)malloc(sizeof(LIST));
        if (!e) {
            /* エラー処理 */
            fprintf(stderr, "%s:%d: cannot allocate memory", __FILE__, __LINE__);
            exit(EXIT_FAILURE);
        }
        /* データ */
        e->data = i;
        e->next = NULL;

        if (list)
            e->next = list;
        list = e;
    }

    /* リストの要素を反復 */
    {
        LIST *p;
        for (p = list; p; p = p->next)
            printf("%d ", p->data);
        printf("\n");
    }

    /* リストの先頭の要素を削除 */
    for (i = 0; i < 6; i++) {
        if (list) {
            LIST *p = list;
            list = list->next;
            free(p);
        }
    }

    /* リストの末尾に要素を追加 */
    for (i = 0; i < 5; i++) {
        LIST *e = (LIST *)malloc(sizeof(LIST));
        if (!e) {
            /* エラー処理 */
            fprintf(stderr, "%s:%d: cannot allocate memory", __FILE__, __LINE__);
            exit(EXIT_FAILURE);
        }
        /* データ */
        e->data = i;
        e->next = NULL;

        if (list) {
            LIST *p;
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
        LIST *p;
        for (p = list; p; p = p->next)
            printf("%d ", p->data);
        printf("\n");
    }

    /* リストの末尾の要素を削除 */
    for (i = 0; i < 6; i++) {
        if (list) {
            LIST *p;
            if (list->next) {
                LIST *q;
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

