#include <stdio.h>
#include <stdlib.h>
#include "query.h"
#include "string_util.h"

/** @brief Creates a new REQUEST query. */
Query *create_request_query(StringList fields, StringList targets, char *condition, int limit, int has_limit) {
    Query *q = malloc(sizeof(Query));
    q->type = QUERY_REQUEST;
    q->data.request.fields = fields;
    q->data.request.targets = targets;
    q->data.request.condition = condition ? strdup(condition) : NULL;
    q->data.request.limit = limit;
    q->data.request.has_limit = has_limit;
    return q;
}

/** @brief Creates a new EXTRACT query. */
Query *create_extract_query(char *target, char *condition) {
    Query *q = malloc(sizeof(Query));
    q->type = QUERY_EXTRACT;
    q->data.extract.target = target ? strdup(target) : NULL;
    q->data.extract.condition = condition ? strdup(condition) : NULL;
    return q;
}

/** @brief Creates a new VERIFY query. */
Query *create_verify_query(char *condition, StringList targets) {
    Query *q = malloc(sizeof(Query));
    q->type = QUERY_VERIFY;
    q->data.verify.condition = condition ? strdup(condition) : NULL;
    q->data.verify.targets = targets;
    return q;
}

/** @brief Frees a StringList structure. */
void free_string_list(StringList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->items[i]);
    }
    free(list->items);
}

/** @brief Frees the memory allocated for a query. */
void free_query(Query *query) {
    if (!query) return;
    switch (query->type) {
        case QUERY_REQUEST:
            free_string_list(&query->data.request.fields);
            free_string_list(&query->data.request.targets);
            free(query->data.request.condition);
            break;
        case QUERY_EXTRACT:
            free(query->data.extract.target);
            free(query->data.extract.condition);
            break;
        case QUERY_VERIFY:
            free(query->data.verify.condition);
            free_string_list(&query->data.verify.targets);
            break;
    }
    free(query);
}

/** @brief Prints a StringList to stdout. */
void print_string_list(StringList list) {
    printf("[");
    for (int i = 0; i < list.count; i++) {
        printf("%s%s", list.items[i], i < list.count - 1 ? ", " : "");
    }
    printf("]");
}

/** @brief Prints the query to stdout. */
void print_query(Query *query) {
    if (!query) {
        printf("NULL\n");
        return;
    }
    switch (query->type) {
        case QUERY_REQUEST:
            printf("RequestQuery { fields=");
            print_string_list(query->data.request.fields);
            printf(", targets=");
            print_string_list(query->data.request.targets);
            printf(", condition=%s", query->data.request.condition ? query->data.request.condition : "null");
            if (query->data.request.has_limit) {
                printf(", limit=%d", query->data.request.limit);
            }
            printf(" }\n");
            break;
        case QUERY_EXTRACT:
            printf("ExtractQuery { target=%s, condition=%s }\n",
                   query->data.extract.target ? query->data.extract.target : "null",
                   query->data.extract.condition ? query->data.extract.condition : "null");
            break;
        case QUERY_VERIFY:
            printf("VerifyQuery { condition=%s, targets=", 
                   query->data.verify.condition ? query->data.verify.condition : "null");
            print_string_list(query->data.verify.targets);
            printf(" }\n");
            break;
    }
}