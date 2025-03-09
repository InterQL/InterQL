#include <stdio.h>
#include "parser.h"
#include "query.h"

/**
 * @brief Main entry point of the InterQL parser application.
 * 
 * Parses a hardcoded query and prints the result.
 * 
 * @return int Exit status (0 for success).
 */
int main() {
    const char *input = "verify ssl.cert.issuer contains \"Let's Encrypt\" in example.com;";
    Parser *parser = create_parser(input);
    Query *query = parse(parser);
    
    printf("Parsed Query: ");
    print_query(query);
    
    free_query(query);
    free_parser(parser);
    return 0;
}