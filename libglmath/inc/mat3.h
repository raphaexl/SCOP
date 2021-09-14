#ifndef MAT3_H
# define MAT3_H

# include "versor.h"

typedef     struct      s_mat3
{
    float               m[MAT3_SIZE];
}                       t_mat3;


t_mat3                  ft_mat3_zero(void);
t_mat3                  ft_mat3_identity(void);
t_mat3                  ft_mat3_new(t_vec3 a, t_vec3 b, t_vec3 c);
void                    ft_mat3_print( const t_mat3 m );
# endif