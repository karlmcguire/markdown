#include <stdio.h>
#include <sys/queue.h>

#include "markdown.h"

enum token_type
scan(char c) {
    switch (c) {
    case '_':
        return T_UNDERSCORE;
    case '*':
        return T_STAR;
    case '\n':
        return T_NEWLINE;
    case EOF:
        return T_EOF;
    default:
        return T_TEXT;
    }
}

int
main() {
    struct token *token; 
    enum token_type type;
    struct string *string;
    char c; 
    
    LIST_HEAD(token_list, tokne) head;
    LIST_INIT(&head);


    for (;;) {
        type = scan(getchar()); 
        
        if (type == T_TEXT) {
                
        }

        // finished reading the file
        if (type == T_EOF) break; 
    }
    
    /*
    LIST_HEAD(token_list, token) head;
    LIST_INIT(&head);

    struct token *first = token_new(T_TEXT, NULL);
    LIST_INSERT_HEAD(&head, first, list);

    struct token *prev = first;
    struct token *curr;

    unsigned int i = 0;

    for (;;) {
    }

    for (char c = getchar(); c != EOF; c = getchar()) {
        curr = token_new(scan(c), NULL);

        LIST_INSERT_AFTER(prev, curr, list);

        prev = curr;
    }

    LIST_FOREACH(curr, &head, list) {
        printf("%d\n", curr->type);
    }
    */

    return 0;
}
