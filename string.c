#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>

#include "markdown.h"

struct string *
string_new(char *value) {
    struct string *string = (struct string *) malloc(sizeof(struct string));
    
    string->length = strlen(value);
    string->value = value;

    return string;
}

void
string_add(struct string *string, char letter) {
    string->value[string->length++] = letter;
}

void
string_print(struct string *string) {
    printf("%s\n", string->value);
}
