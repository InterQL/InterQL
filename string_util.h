#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <stdio.h>
/**
 * @brief Duplicates a string.
 * @param s The string to duplicate.
 * @return char* A newly allocated copy of the string, or NULL if s is NULL or allocation fails.
 */
char *strdup(const char *s);

/**
 * @brief Converts a string to lowercase.
 * @param s The string to convert.
 * @return char* A newly allocated lowercase copy of the string, or NULL if s is NULL.
 */
char *strlower(const char *s);

/**
 * @brief Compares two strings case-insensitively.
 * @param s1 First string.
 * @param s2 Second string.
 * @return int 1 if strings are equal (ignoring case), 0 otherwise.
 */
int str_equals_ignore_case(const char *s1, const char *s2);

/**
 * @brief Splits a string into an array of substrings.
 * @param str The string to split.
 * @param delim The delimiter to split on.
 * @param count Pointer to store the number of substrings.
 * @return char** Array of substrings, must be freed with free_string_array().
 */
char **split_string(const char *str, const char *delim, int *count);

/**
 * @brief Frees an array of strings.
 * @param array The array to free.
 * @param count Number of strings in the array.
 */
void free_string_array(char **array, int count);

#endif