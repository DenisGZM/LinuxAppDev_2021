#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_BUF_LEN (128)
#define EXPR_FLAGS (REG_EXTENDED | REG_NOTEOL)

typedef struct 
{
    char *regexp;
    char *substitution;
    char *string;
} input_t;

void parceArgv( int argc, char **argv, input_t *inp)
{
    if ( argc != 4 )
    {
        fprintf( stderr, "Wrong args num!\nHelp:\n%s <regexp> <substitution> <string>\n", argv[0]);
        exit( 1);
    }

    inp->regexp = argv[1];
    inp->substitution = argv[2];
    inp->string = argv[3];
}

int main( int argc, char **argv)
{
    input_t in;
    parceArgv( argc, argv, &in);
    char error_buf[ERROR_BUF_LEN];
    regex_t rexpr;
    int res;

    res = regcomp( &rexpr, in.regexp, EXPR_FLAGS);
    if ( res )
    {
        regerror( res, &rexpr, error_buf, ERROR_BUF_LEN);
    }

    size_t match_num = rexpr.re_nsub + 1;
    regmatch_t *expr_parts = malloc(sizeof(regmatch_t)*(match_num));

    res = regexec( &rexpr, in.string, match_num, expr_parts, EXPR_FLAGS);
    if ( res )
    {
        regerror( res, &rexpr, error_buf, ERROR_BUF_LEN);
    }

    size_t cur_size = 0;
    size_t res_size = 128;
    char *result = malloc( res_size);
    if ( !result )
    {
        perror("Couldn't alloc memory, bb\n");
        return 1;
    }

    char *token;
    size_t token_size;

    // Copy begin before match.
    token = in.string;
    token_size = expr_parts[0].rm_so;
    if ( token && token_size > 0 )
    {
        while ( token_size + cur_size > res_size )
        {
            res_size *= 2;
            result = realloc( result, res_size);
            if ( !result )
            {
                perror("Couldn't realloc memory, bb\n");
                return 1;
            }
        }
        strncpy( result + cur_size, token, token_size);
        cur_size += token_size;
    }

    char *handle = in.substitution;
    do
    {
        int sub_expr = 0;
        if ( handle[0] == '\\' )
        {
            if ( '0' <= handle[1] && handle[1] <= '9' )
            {
                int i = handle[1] - '0';
                if ( i >= match_num )
                {
                    fprintf( stderr, "Error during substitution, no such subexpr!\n");
                    return 1;
                }
                token_size = expr_parts[i].rm_eo - expr_parts[i].rm_so;
                token = in.string + expr_parts[i].rm_so;
                sub_expr = 1;
                handle += 2;
            } else if ( handle[1] == '\\' )
            {
                handle += 1;
                token_size = 1;
                token = handle;
            } else
            {
                handle += 2;
                continue;
            }
        } else
        {
            token = strchr( handle, '\\');
            token_size = token ? token - handle : strlen( handle);
            token = handle;
        }

        while ( token_size + cur_size > res_size )
        {
            res_size *= 2;
            result = realloc( result, res_size);
            if ( !result )
            {
                perror("Couldn't realloc memory, bb\n");
                return 1;
            }
        }

        if ( token_size > 0 )
        {
            strncpy( result + cur_size, token, token_size);
            cur_size += token_size;
        }

        if ( !sub_expr )
        {
            handle += token_size;
        }
    } while ( handle[0] != 0);

    // Copy end after match.
    token = in.string + expr_parts[0].rm_eo;
    token_size = strlen(in.string) - expr_parts[0].rm_eo;

    if ( token && token_size > 0 )
    {
        while ( token_size + cur_size > res_size )
        {
            res_size *= 2;
            result = realloc( result, res_size);
            if ( !result )
            {
                perror("Couldn't realloc memory, bb\n");
                return 1;
            }
        }
        strncpy( result + cur_size, token, token_size);
        cur_size += token_size;
    }

    puts( result);
    return 0;
}