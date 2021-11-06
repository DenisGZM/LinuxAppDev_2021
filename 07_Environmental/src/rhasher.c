#include <rhash.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include "../config.h"
#ifdef HAVE_LIBREADLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

#define bool int
#define true (1)
#define false (0)

static bool
processHashName( char *hash_name, bool *is_b64_out, enum rhash_ids *id)
{
    *is_b64_out = true;
    if ( hash_name[0] == toupper( hash_name[0]) )
    {
        *is_b64_out = false;
    }

    size_t len = strlen( hash_name);
    for ( size_t i = 0; i < len; ++i )
    {
        hash_name[i] = tolower((unsigned char)hash_name[i]);
    }

    if ( strcmp( hash_name, "md5" ) == 0 )
    {
        *id = RHASH_MD5;
    } else if ( strcmp( hash_name, "sha1" ) == 0 )
    {
        *id = RHASH_SHA1;
    } else if ( strcmp( hash_name, "tth" ) == 0 )
    {
        *id = RHASH_TTH;
    } else
    {
        *id = 0;
        return false;
    }

    return true;
}

int main(void)
{
    rhash_library_init();
    char *line = NULL;
    char space[] = " ";
    char newline[] = "\n";
    char *hash_name;
    char *hash_input;
    size_t len = 0;
    size_t read;
    char digest[64];
    char output[256];

#if defined( NO_READLINE ) || !defined( HAVE_LIBREADLINE )
    while ( (read = getline(&line, &len, stdin)) != -1 )
#else
    while ( line = readline( NULL) )
#endif
    {
        hash_name = strtok( line, space);
        hash_input = strtok( NULL, space);
        hash_input = strtok( hash_input, newline);

        if ( !hash_input )
        {
            fprintf( stderr, "No input for hash!\n");
            continue;
        }

        bool is_b64_out;
        enum rhash_ids hash_id;
        if ( !processHashName( hash_name, &is_b64_out, &hash_id) )
        {
            fprintf( stderr, "Do not supported such hash!\n");
            continue;
        }

        bool is_file = true;
        if ( hash_input[0] == '\"' )
        {
            is_file = false;
            hash_input = hash_input + 1;
        }

        if ( is_file )
        {
            int res = rhash_file( hash_id, hash_input, digest);
            if ( res < 0 )
            {
                fprintf( stderr, "LibRHash error: %s: %s\n", hash_input, strerror(errno));
                continue;
            }
        } else
        {
            int res = rhash_msg( hash_id, hash_input, strlen(hash_input), digest);
            if ( res < 0 )
            {
                fprintf( stderr, "Message digest calculation error\n");
                continue;
            }
        }

        rhash_print_bytes( output, digest, rhash_get_digest_size( hash_id),
                           (is_b64_out ? RHPR_BASE64 : RHPR_HEX));
        
        printf("%s  %s\n", output, hash_input);
#if defined( NO_READLINE ) || !defined( HAVE_LIBREADLINE )
        if ( line )
        {
            free( line);
        }
#endif
    }

    return 0;
}