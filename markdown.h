struct string {
    unsigned int length;
    char *value;
};

enum token_type {
    T_SKIP, 
    T_EOF,
    T_UNDERSCORE,
    T_STAR,
    T_NEWLINE,
    T_TEXT
};

struct token {
    enum token_type type;
    struct string *value;

    LIST_ENTRY(token) list;
};

struct string   *string_new(char *);
void             string_print(struct string *);

struct token    *token_new(enum token_type, struct string *);
void             token_print(struct token *);
