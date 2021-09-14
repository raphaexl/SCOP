#include "../inc/mat3.h"

t_mat3      ft_mat3_zero(void)
{
    t_mat3  m;
    int     i;

    i = -1;
    while (++i < MAT3_SIZE)
        m.m[i] = 0.0f;
    return (m);
}

t_mat3      ft_mat3_identity(void)
{
    t_mat3  m;
    int     i;

    i = -1;
    while (++i < MAT3_SIZE)
        m.m[i] = 0.0f;
    m.m[0] = 1.0f;
    m.m[4] = 1.0f;
    m.m[8] = 1.0f;
    return (m);
}

t_mat3      ft_mat3_new(t_vec3 a, t_vec3 b, t_vec3 c)
{
    t_mat3  m;
    
    m.m[0] = a.x;
    m.m[1] = a.y;
    m.m[2] = a.z;
    m.m[3] = b.x;
    m.m[4] = b.y;
    m.m[5] = b.z;
    m.m[6] = c.x;
    m.m[7] = c.y;
    m.m[8] = c.z;
    return (m);
}

void ft_mat3_print( const t_mat3 m ) {
	printf( "\n" );
	printf( "[%.2f][%.2f][%.2f]\n", m.m[0], m.m[3], m.m[6] );
	printf( "[%.2f][%.2f][%.2f]\n", m.m[1], m.m[4], m.m[7] );
	printf( "[%.2f][%.2f][%.2f]\n", m.m[2], m.m[5], m.m[8] );
}