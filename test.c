#include <stdio.h>

int     valid_char(char line)
{
	return (line == 'N' || line == 'E' || line == 'W' || \
	line == 'S' || line == '0' || line == '1');
}

int parse_line(char *line, int *off, int *last)
{
    int bol;
    int i;
    
    bol = 0;
    i = 0;
    while (line[i] && line[i] == ' ')
        i++;
    *off = i;
    while (line[i])
    {
        while (line[i] && valid_char(line[i]) && line[i] != ' ')
        {
            if (line[i] != '1' && line[i] != '0')
                cubbol++;
            i++;
        }
        if (bol > 1 || (line[i] && line[i] != ' ' && !valid_char(line[i])))
            return (printf("we cant have 2 player"), 0);
        *last = i - 1;
        while (line[i] && line[i] == ' ')
            i++;
    }
    return (1);
}

int main()
{
        int a, b;
        parse_line(" 01W000N 110   ", &a, &b);
        printf("f %d -- l %d\n",a, b);
        return 0;
}