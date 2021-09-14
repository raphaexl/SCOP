#include "../incs/scop.h"

void    *ft_file_content(const char *file_name, int *len)
{
    FILE    *fp;
    void    *buffer;

    if (!(fp = fopen(file_name, "r")))
    {
        fprintf(stderr, "Could not open : %s", file_name);
        return (NULL);
    }
    fseek(fp, 0, SEEK_END);
    *len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = malloc(*len + 1);
    *len = fread(buffer, 1, *len, fp);
    ((char *)buffer)[*len] = '\0';
    fclose(fp);
    return (buffer);
}