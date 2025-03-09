#ifndef QUERY_H
#define QUERY_H

/**
 * @brief A list of strings.
 */
typedef struct StringList
{
    char **items; ///< Array of strings
    int count;    ///< Number of strings in the list
} StringList;

/**
 * @brief Structure for a REQUEST query.
 */
typedef struct RequestQuery
{
    StringList fields;  ///< Fields to request
    StringList targets; ///< Targets to query from
    char *condition;    ///< Optional WHERE condition
    int limit;          ///< Optional LIMIT value
    int has_limit;      ///< Flag indicating if limit is set
} RequestQuery;

/**
 * @brief Structure for an EXTRACT query.
 */
typedef struct ExtractQuery
{
    char *target;    ///< Target to extract from
    char *condition; ///< Optional WHERE condition
} ExtractQuery;

/**
 * @brief Structure for a VERIFY query.
 */
typedef struct VerifyQuery
{
    char *condition;    ///< Condition to verify
    StringList targets; ///< Targets to verify against
} VerifyQuery;

/**
 * @brief Enum for query types.
 */
typedef enum QueryType
{
    QUERY_REQUEST, ///< Request query type
    QUERY_EXTRACT, ///< Extract query type
    QUERY_VERIFY   ///< Verify query type
} QueryType;

/**
 * @brief Union structure representing a query.
 */
typedef struct Query
{
    QueryType type; ///< Type of the query
    union
    {
        RequestQuery request; ///< Request query data
        ExtractQuery extract; ///< Extract query data
        VerifyQuery verify;   ///< Verify query data
    } data;                   ///< Union of query data
} Query;

/**
 * @brief Creates a new REQUEST query.
 */
Query *create_request_query(StringList fields, StringList targets, char *condition, int limit, int has_limit);

/**
 * @brief Creates a new EXTRACT query.
 */
Query *create_extract_query(char *target, char *condition);

/**
 * @brief Creates a new VERIFY query.
 */
Query *create_verify_query(char *condition, StringList targets);

/**
 * @brief Frees the memory allocated for a query.
 */
void free_query(Query *query);

/**
 * @brief Prints the query to stdout.
 */
void print_query(Query *query);

#endif