#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line {
    char *s;
    struct line *next;
};

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("missing file name \n");
        return 1;
    }
    
    // TODO check file name
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error while opening file\n");
        return 1;
    }

    char buf[64];
    struct line *head = NULL;
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        struct line *l = malloc(sizeof(struct line));
        size_t linelen = strlen(buf);
        l->s = malloc(linelen + 1);
        for (size_t j = 0; j <= linelen; j++) {
            l->s[j] = buf[j];
        }
        l->next = head;
        head = l;
        printf("%ld\n", linelen);
    }

    while(head != NULL) {
        printf("%s", head->s);
        head = head -> next;
    }

    fclose(fp);
}
