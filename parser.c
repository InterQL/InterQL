#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "string_util.h"

/** @brief Creates a new parser instance from an input string. */
Parser *create_parser(const char *input) {
    Parser *p = malloc(sizeof(Parser));
    p->tokens = split_string(input, " \t\n", &p->token_count);
    p->position = 0;
    return p;
}

/** @brief Frees the memory allocated for a parser. */
void free_parser(Parser *parser) {
    if (!parser) return;
    free_string_array(parser->tokens, parser->token_count);
    free(parser);
}

/** @brief Consumes and returns the next token from the parser. */
char *consume(Parser *p) {
    return p->position < p->token_count ? p->tokens[p->position++] : NULL;
}

/** @brief Peeks at the next token without consuming it. */
char *peek(Parser *p) {
    return p->position < p->token_count ? p->tokens[p->position] : NULL;
}

/** @brief Consumes tokens until a stop word or end is reached. */
char *consume_until(Parser *p, const char *stop_word) {
    char *current;
    char *result = NULL;
    size_t len = 0;
    
    while ((current = peek(p)) != NULL && 
           (stop_word == NULL || !str_equals_ignore_case(current, stop_word))) {
        char *token = consume(p);
        size_t token_len = strlen(token);
        result = realloc(result, len + token_len + 2);
        if (len > 0) {
            result[len++] = ' ';
        }
        strcpy(result + len, token);
        len += token_len;
    }
    if (result) result[len] = '\0';
    return result ? result : strdup("");
}

/** @brief Parses a list of strings until a stop word is encountered. */
StringList parse_string_list(Parser *p, const char **stop_words, int stop_count) {
    StringList list = { .items = NULL, .count = 0 };
    int capacity = 10;
    list.items = malloc(capacity * sizeof(char *));
    
    while (peek(p)) {
        int is_stop = 0;
        for (int i = 0; i < stop_count; i++) {
            if (str_equals_ignore_case(peek(p), stop_words[i])) {
                is_stop = 1;
                break;
            }
        }
        if (is_stop) break;
        
        char *token = consume(p);
        char *cleaned = strdup(token);
        for (int i = 0; cleaned[i]; i++) {
            if (cleaned[i] == ',') cleaned[i] = '\0';
        }
        
        if (list.count >= capacity) {
            capacity *= 2;
            list.items = realloc(list.items, capacity * sizeof(char *));
        }
        list.items[list.count++] = cleaned;
    }
    return list;
}

/** @brief Parses a REQUEST query. */
Query *parse_request(Parser *p) {
    const char *stop_words[] = {"from"};
    StringList fields = parse_string_list(p, stop_words, 1);
    consume(p); // "from"
    
    const char *stop_words2[] = {"where", "limit"};
    StringList targets = parse_string_list(p, stop_words2, 2);
    
    char *condition = NULL;
    int limit = 0;
    int has_limit = 0;
    
    if (peek(p) && str_equals_ignore_case(peek(p), "where")) {
        consume(p);
        condition = consume_until(p, "limit");
    }
    if (peek(p) && str_equals_ignore_case(peek(p), "limit")) {
        consume(p);
        char *limit_str = consume(p);
        if (limit_str) {
            limit = atoi(limit_str);
            has_limit = 1;
        }
    }
    return create_request_query(fields, targets, condition, limit, has_limit);
}

/** @brief Parses an EXTRACT query. */
Query *parse_extract(Parser *p) {
    consume(p); // "text"
    consume(p); // "from"
    char *target = consume(p);
    char *condition = NULL;
    if (peek(p) && str_equals_ignore_case(peek(p), "where")) {
        consume(p);
        condition = consume_until(p, NULL);
    }
    return create_extract_query(target, condition);
}

/** @brief Parses a VERIFY query. */
Query *parse_verify(Parser *p) {
    char *condition = consume_until(p, "in");
    consume(p); // "in"
    const char *stop_words[] = {};
    StringList targets = parse_string_list(p, stop_words, 0);
    return create_verify_query(condition, targets);
}

/** @brief Parses the input string into a Query object. */
Query *parse(Parser *p) {
    char *first = consume(p);
    if (!first) return NULL;
    
    char *lower_first = strlower(first);
    Query *result;
    
    if (strcmp(lower_first, "request") == 0) {
        result = parse_request(p);
    } else if (strcmp(lower_first, "extract") == 0) {
        result = parse_extract(p);
    } else if (strcmp(lower_first, "verify") == 0) {
        result = parse_verify(p);
    } else {
        fprintf(stderr, "Unknown command: %s\n", first);
        free(lower_first);
        return NULL;
    }
    
    free(lower_first);
    return result;
}