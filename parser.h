#ifndef PARSER_H
#define PARSER_H

#include "query.h"

/**
 * @brief Structure representing a parser for InterQL queries.
 */
typedef struct Parser {
    char **tokens;      ///< Array of tokens from the input string
    int token_count;    ///< Number of tokens
    int position;       ///< Current position in the token array
} Parser;

/**
 * @brief Creates a new parser instance from an input string.
 * @param input The query string to parse.
 * @return Parser* Pointer to the newly created parser, or NULL on failure.
 */
Parser *create_parser(const char *input);

/**
 * @brief Frees the memory allocated for a parser.
 * @param parser The parser to free.
 */
void free_parser(Parser *parser);

/**
 * @brief Parses the input string into a Query object.
 * @param parser The parser instance to use.
 * @return Query* Pointer to the parsed query, or NULL on error.
 */
Query *parse(Parser *parser);

#endif