#ifndef DEFS_H
# define DEFS_H

#include <stdlib.h>
# include <stdio.h>
# include <math.h>

# ifndef M_PI 
# define M_PI (3.14159265358979323846)
# endif
# define TWO_PI (2.0 * M_PI)
# define DEG_TO_RAD(x) ((x * M_PI) / 180.0f)
# define RAD_TO_DEG(x) ((x * 180.0f) / M_PI)
# define MAT4_SIZE (16)
# define MAT3_SIZE (9)

#endif 