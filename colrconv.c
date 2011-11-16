#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No input colors specified.\n");
        printf("Usage:\n");
        printf("\tcolrconv color1 color2 ... colorN\n");
        printf("where:\n");
        printf("\tcolor - hex rgb, prefixed by 0x. i.e.: 0xFF00FF).\n");
        exit(1);
    }

    int i;
    for (i = 1; i < argc; ++i) {
        char *s = argv[i];
        char *rgb888 = s;

        if (s[0] != '0' || s[1] != 'x' || strlen(s) != 8) {
            fprintf(stderr, "Incorrect color format.\n");
            exit(2);
        }

        char buf[2];

        // red
        buf[0] = s[2]; buf[1] = s[3];
        long int r8 = strtol(buf, NULL, 16);

        // green
        buf[0] = s[4]; buf[1] = s[5];
        long int g8 = strtol(buf, NULL, 16);

        // red
        buf[0] = s[6]; buf[1] = s[7];
        long int b8 = strtol(buf, NULL, 16);

        int r5 = r8 >> 3; // 5-bit red
        int g6 = g8 >> 2; // 6-bit green
        int b5 = b8 >> 3; // 5-bit blue
        unsigned short rgb565_b = b5 + (g6 << 5) + (r5 << (5 + 6));

        printf("%s -> 0x00%04X\n", rgb888, rgb565_b);
    }
}


