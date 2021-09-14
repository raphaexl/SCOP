#include "../inc/mat4.h"

t_mat4      ft_mat4_zero(void)
{
    t_mat4  m;
    int     i;

    i = -1;
    while (++i < MAT4_SIZE)
        m.m[i] = 0.0f;
    return (m);
}

t_mat4      ft_mat4_identity(void)
{
    t_mat4  m;
    int     i;

    i = -1;
    while (++i < MAT4_SIZE)
        m.m[i] = 0.0f;
    m.m[0] = 1.0f;
    m.m[5] = 1.0f;
    m.m[10] = 1.0f;
    m.m[15] = 1.0f;
    return (m);
}

t_mat4      ft_mat4_new(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d)
{
    t_mat4  m;
    
    m.m[0] = a.x;
    m.m[1] = a.y;
    m.m[2] = a.z;
    m.m[3] = a.w;
    m.m[4] = b.x;
    m.m[5] = b.y;
    m.m[6] = b.z;
    m.m[7] = b.w;
    m.m[8] = c.x;
    m.m[9] = c.y;
    m.m[10] = c.z;
    m.m[11] = c.w;
    m.m[12] = d.x;
    m.m[13] = d.y;
    m.m[14] = d.z;
    m.m[15] = d.w;
    return (m);
}

void ft_mat4_print( const t_mat4 m ) {
	printf( "\n" );
	printf( "[%.2f][%.2f][%.2f][%.2f]\n", m.m[0], m.m[4], m.m[8], m.m[12] );
	printf( "[%.2f][%.2f][%.2f][%.2f]\n", m.m[1], m.m[5], m.m[9], m.m[13] );
	printf( "[%.2f][%.2f][%.2f][%.2f]\n", m.m[2], m.m[6], m.m[10], m.m[14] );
	printf( "[%.2f][%.2f][%.2f][%.2f]\n", m.m[3], m.m[7], m.m[11], m.m[15] );
}