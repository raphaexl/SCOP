
#include "../incs/scop.h"

int     main(int argc, char *argv[])
{
    t_obj   obj;

    if (argc > 1)
        obj = ft_parse_file(argv[1], argc > 2 ? argv[2] : NULL);
    else
        ft_make_default_object(&obj);
    ft_run(&obj);
    ft_obj_clean(&obj);
    return (0);
}