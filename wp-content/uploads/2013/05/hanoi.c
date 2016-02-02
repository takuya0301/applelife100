#include <stdio.h>

void hanoi(int n, char *src, char *tmp, char *dst);

int main(void)
{
    /* 1枚のハノイの塔の移動手順を表示 */
    printf("----- 1 -----\n");
    hanoi(1, "A", "B", "C");

    /* 2枚のハノイの塔の移動手順を表示 */
    printf("----- 2 -----\n");
    hanoi(2, "A", "B", "C");

    /* 3枚のハノイの塔の移動手順を表示 */
    printf("----- 3 -----\n");
    hanoi(3, "A", "B", "C");

    return 0;
}

void hanoi(int n, char *src, char *tmp, char *dst)
{
    /* 0 < n の場合 */
    if (0 < n) {
        /* (n - 1) 枚を移動元 (Source) から空き場所 (Temporary) に移動 */
        hanoi(n - 1, src, dst, tmp);

        /* 移動元 (Source) の1枚を移動先 (Destination) に移動 */
        printf("%s -> %s\n", src, dst);

        /* (n - 1) 枚を空き場所 (Temporary) から移動先 (Destination) に移動 */
        hanoi(n - 1, tmp, src, dst);
    }
}
