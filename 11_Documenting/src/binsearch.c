#include <stdio.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include <argp.h>

/**
 * Convert roman num to decimal
 * Domain: 1..100
 * @rom - roman num string
 */
int fromRoman( char *rom)
{
    int n = 1;
    if ( strcmp("I", rom ) == 0 ) return n;
    n++;
    if ( strcmp("II", rom ) == 0 ) return n;
    n++;
    if ( strcmp("III", rom ) == 0 ) return n;
    n++;
    if ( strcmp("IV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("V", rom ) == 0 ) return n;
    n++;
    if ( strcmp("VI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("VII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("VIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("IX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("X", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XIV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XVI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XVII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XVIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XIX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXIV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXVI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXVII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXVIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXIX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXXI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXXII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXXIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXXIV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXXV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXXVI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXXVII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXXVIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XXXIX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XL", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XLI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XLII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XLIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XLIV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XLV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XLVI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XLVII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XLVIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XLIX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("L", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LIV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LVI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LVII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LVIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LIX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXIV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXVI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXVII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXVIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXIX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXIV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXVI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXVII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXVIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXIX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXXI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXXII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXXIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXXIV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXXV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXXVI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXXVII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXXVIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("LXXXIX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XC", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XCI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XCII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XCIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XCIV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XCV", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XCVI", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XCVII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XCVIII", rom ) == 0 ) return n;
    n++;
    if ( strcmp("XCIX", rom ) == 0 ) return n;
    n++;
    if ( strcmp("C", rom ) == 0 ) return n;
    
    return 0;
}

/**
 * Convert decimal num to roman num
 * @num - decimal num
 */
char *toRoman( int num)
{
    switch ( num )
    {
        case 1   : return "I";
        case 2   : return "II";
        case 3   : return "III";
        case 4   : return "IV";
        case 5   : return "V";
        case 6   : return "VI";
        case 7   : return "VII";
        case 8   : return "VIII";
        case 9   : return "IX";
        case 10  : return "X";
        case 11  : return "XI";
        case 12  : return "XII";
        case 13  : return "XIII";
        case 14  : return "XIV";
        case 15  : return "XV";
        case 16  : return "XVI";
        case 17  : return "XVII";
        case 18  : return "XVIII";
        case 19  : return "XIX";
        case 20  : return "XX";
        case 21  : return "XXI";
        case 22  : return "XXII";
        case 23  : return "XXIII";
        case 24  : return "XXIV";
        case 25  : return "XXV";
        case 26  : return "XXVI";
        case 27  : return "XXVII";
        case 28  : return "XXVIII";
        case 29  : return "XXIX";
        case 30  : return "XXX";
        case 31  : return "XXXI";
        case 32  : return "XXXII";
        case 33  : return "XXXIII";
        case 34  : return "XXXIV";
        case 35  : return "XXXV";
        case 36  : return "XXXVI";
        case 37  : return "XXXVII";
        case 38  : return "XXXVIII";
        case 39  : return "XXXIX";
        case 40  : return "XL";
        case 41  : return "XLI";
        case 42  : return "XLII";
        case 43  : return "XLIII";
        case 44  : return "XLIV";
        case 45  : return "XLV";
        case 46  : return "XLVI";
        case 47  : return "XLVII";
        case 48  : return "XLVIII";
        case 49  : return "XLIX";
        case 50  : return "L";
        case 51  : return "LI";
        case 52  : return "LII";
        case 53  : return "LIII";
        case 54  : return "LIV";
        case 55  : return "LV";
        case 56  : return "LVI";
        case 57  : return "LVII";
        case 58  : return "LVIII";
        case 59  : return "LIX";
        case 60  : return "LX";
        case 61  : return "LXI";
        case 62  : return "LXII";
        case 63  : return "LXIII";
        case 64  : return "LXIV";
        case 65  : return "LXV";
        case 66  : return "LXVI";
        case 67  : return "LXVII";
        case 68  : return "LXVIII";
        case 69  : return "LXIX";
        case 70  : return "LXX";
        case 71  : return "LXXI";
        case 72  : return "LXXII";
        case 73  : return "LXXIII";
        case 74  : return "LXXIV";
        case 75  : return "LXXV";
        case 76  : return "LXXVI";
        case 77  : return "LXXVII";
        case 78  : return "LXXVIII";
        case 79  : return "LXXIX";
        case 80  : return "LXXX";
        case 81  : return "LXXXI";
        case 82  : return "LXXXII";
        case 83  : return "LXXXIII";
        case 84  : return "LXXXIV";
        case 85  : return "LXXXV";
        case 86  : return "LXXXVI";
        case 87  : return "LXXXVII";
        case 88  : return "LXXXVIII";
        case 89  : return "LXXXIX";
        case 90  : return "XC";
        case 91  : return "XCI";
        case 92  : return "XCII";
        case 93  : return "XCIII";
        case 94  : return "XCIV";
        case 95  : return "XCV";
        case 96  : return "XCVI";
        case 97  : return "XCVII";
        case 98  : return "XCVIII";
        case 99  : return "XCIX";
        case 100 : return "C";
        default  : return NULL;
    }
    return NULL;
}

/* Helper define for l18n */
#define _(str) gettext(str)

const char *argp_program_version = "1.0";
const char *argp_program_bug_address = "dengzmm@gmail.com";

/* Program documentation. */
static char *doc;

/* The options we understand. */
static struct argp_option options[2];
 
/* Used by main to communicate with parse_opt. */
struct arguments
{
  int is_roman;
};

/**
 * Parse a single option.
 * @key   - parsed key
 * @arg   - argument
 * @state - current state
 */
static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
    /* Get the input argument from argp_parse, which we
       know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    switch (key)
    {
      case 'r':
        arguments->is_roman = 1;
        break;

      default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

/* Our argp parser. */
static struct argp argp;

/**
 * Entry point for program
 * @argc - argument count
 * @argv - array of arguments strings
 */
int main(int argc, char **argv)
{
    setlocale( LC_ALL, "");
    bindtextdomain("guess", "./");
    textdomain("guess");

    doc = _("Binary-search-guess-num game!");
    options[0].name = "roman";
    options[0].key = 'r';
    options[0].doc = _("Use roman numbers");
    options[1].name = 0;

    argp.options = options;
    argp.parser = parse_opt;
    argp.args_doc = 0;
    argp.doc = doc;

    struct arguments arguments;

    /* Default values. */
    arguments.is_roman = 0;

    /* Parse our arguments; every option seen by parse_opt will
     be reflected in arguments. */
    argp_help( &argp, stderr, 0, "What?");
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    char answ[8];
    int l = 0, r = 100, m;
    while( l + 1 < r  )
    {
        m = (l+r)/2;
        sprintf( answ, "%d", m);
        
        printf(_("Is your number more than %s? [y/[n]] "), arguments.is_roman ? toRoman(m) : answ);
        gets(answ);
        if ( strcmp(answ, _("y")) == 0 )
        {
            l = m;
        } else
        {
            r = m;
        }
    }
    sprintf( answ, "%d", r);
    printf(_("Your number = %s\n"), arguments.is_roman ? toRoman(r) : answ);
}