#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

#include "markdown.h"

struct token *
token_new(enum token_type type, struct string *value) {
    struct token *token = (struct token *) malloc(sizeof(struct token));

    token->type = type;
    token->value = value;

    return token;
}

void
token_print(struct token *token) {
    string_print(token->value);
};
