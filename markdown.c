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
    struct token *prev; 
    struct token *curr;
    struct token *next;   

    LIST_HEAD(token_list, token) head;
    LIST_INIT(&head);

    // empty first token for the list head
    prev = token_new(T_SKIP, NULL);
    LIST_INSERT_HEAD(&head, prev, list);

    for (;;) {
        // create current token 
        curr = token_new(scan(getchar()), NULL);
      
        // insert new token
        LIST_INSERT_AFTER(prev, curr, list);

        // set the previous element for next iteration
        prev = curr;

        // finished reading the file
        if (curr->type == T_EOF) break; 
    }
    
    LIST_FOREACH(curr, &head, list) {
        next = LIST_NEXT(prev, list);

        if (curr->type == T_TEXT) {
            
        }

        prev = curr;
    }

    return 0;
}
