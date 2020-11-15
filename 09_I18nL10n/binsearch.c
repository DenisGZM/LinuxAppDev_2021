#include <stdio.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>

#define _(str) gettext(str)

int main()
{
    setlocale( LC_ALL, "");
    bindtextdomain("guess", "./");
    textdomain("guess");

    char answ[6];
    int l = 0, r = 100, m;
    while( l + 1 < r )
    {
        m = (l+r)/2;
        printf(_("Is your number more than %d? [y/[n]] "), m);
        gets(answ);
        if ( strcmp(answ, _("y")) == 0 )
        {
            l = m;
        } else
        {
            r = m;
        }
    }
    printf(_("Your number = %d\n"), r);
}