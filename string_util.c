#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string_util.h"

/** @brief Duplicates a string. */
char *strdup(const char *s) {
    if (!s) return NULL;
    char *d = malloc(strlen(s) + 1);
    if (d) strcpy(d, s);
    return d;
}

/** @brief Converts a string to lowercase. */
char *strlower(const char *s) {
    if (!s) return NULL;
    char *lower = strdup(s);
    for (int i = 0; lower[i]; i++) {
        lower[i] = tolower(lower[i]);
    }
    return lower;
}

/** @brief Compares two strings case-insensitively. */
int str_equals_ignore_case(const char *s1, const char *s2) {
    if (!s1 || !s2) return s1 == s2;
    char *lower1 = strlower(s1);
    char *lower2 = strlower(s2);
    int result = strcmp(lower1, lower2) == 0;
    free(lower1);
    free(lower2);
    return result;
}

/** @brief Splits a string into an array of substrings. */
char **split_string(const char *str, const char *delim, int *count) {
    char *copy = strdup(str);
    char *token;
    int capacity = 10;
    int n = 0;
    char **result = malloc(capacity * sizeof(char *));

    token = strtok(copy, delim);
    while (token) {
        if (n >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(char *));
        }
        result[n++] = strdup(token);
        token = strtok(NULL, delim);
    }
    free(copy);
    *count = n;
    return result;
}

/** @brief Frees an array of strings. */
void free_string_array(char **array, int count) {
    for (int i = 0; i < count; i++) {
        free(array[i]);
    }
    free(array);
}