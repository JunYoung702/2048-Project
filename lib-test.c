#include <stdio.h>

#include "./lib-cross.h"

int main() {
    change_text_color(YELLOW);
    printf("color changed!\n");
    printf("it counts time by 1s. press any key to stop\n");
    printf("doesn't need to press enter\n");
    printf("and cursor removed!\n");
    hide_cursor();
    int t = 0;
    while (1) {
        msleep(1000);
        if (kbhit()) {
            int key = getch();
            printf("\nyou pressed %d %c\n", key, key);
            break;
        }
        printf("%d\n", ++t);
    }
    printf("restore cursor\n");
    show_cursor();
    printf("after 2s, screen will be cleared\n");
    msleep(2000);
    screen_clear();
    printf("print 1 2 3 4 5 diagonally by using gotoxy");
    for (int i = 0; i < 5; i++) {
        gotoxy(i, i + 1);
        printf("%d", i + 1);
    }
    printf("\n");
    change_text_color(GRAY);
}
