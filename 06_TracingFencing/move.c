#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct 
{
    char *in_name;
    char *out_name;
    FILE *in_file;
    FILE *out_file;
} input_t;

void parceArgv( int argc, char **argv, input_t *inp)
{
    if ( argc != 3 )
    {
        fprintf( stderr, "Wrong args num!\nHelp:\n./move <in> <out>\n");
        exit( 123);
    }

    if ( !strcmp( argv[1], argv[2]) )
    {
        fprintf( stderr, "%s and %s are the same file!\n", argv[1], argv[2]);
        exit( 1);
    }

    inp->in_name = argv[1];
    inp->out_name = argv[2];
}

void cleanup( input_t *inp, int mode)
{
    if ( mode == 0 )
    {
        fclose( inp->in_file);
        if ( fclose( inp->out_file) == 0 )
        {
            unlink( inp->in_name);
        } else
        {
            fprintf( stderr, "Epic fail!\nCouldn't close outfile! Leaving...\n");
            exit( 66);
        }
    }
    if ( mode == 1 )
    {
        fclose( inp->in_file);
        fclose( inp->out_file);
        unlink( inp->out_name);
    }
}

int open_files( input_t *inp)
{
    inp->in_file = fopen( inp->in_name, "rb");
    if ( !inp->in_file )
    {
        fprintf( stderr, "Couldn't open infile!\n");
        return -1;
    }

    inp->out_file = fopen( inp->out_name, "wb");
    if ( !inp->out_file )
    {
        fprintf( stderr, "Couldn't open outfile!\n");
        return -1;
    }
}

int move_files( input_t *inp)
{
    char buf[512];
    int readed = 0;
    while ( 1 )
    {
        if ( (readed = fread( buf, 1, sizeof(buf), inp->in_file)) != sizeof(buf)
             && !feof( inp->in_file) )
        {
            fprintf( stderr, "Error on read infile\n");
            return -1;
        }

        if ( fwrite( buf, 1, readed, inp->out_file) != readed )
        {
            fprintf( stderr, "Error on write outfile\n");
            return -1;
        }

        if ( feof( inp->in_file) )
        {
            break;
        }
    }
}

int main( int argc, char **argv)
{
    input_t inp;
    parceArgv( argc, argv, &inp);

    if ( -1 == open_files( &inp) )
    {
        return 20;
    }
    if ( -1 == move_files( &inp) )
    {
        cleanup( &inp, 1);
        return 30;
    }
    cleanup( &inp, 0);
    return 0;
}