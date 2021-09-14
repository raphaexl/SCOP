#ifndef VEC4_H
# define VEC4_H

# include "vec3.h"

typedef struct      s_vec4
{
    union
    {
        struct  {float x, y, z, w;};
        struct  {float s, t, p, q;};
        struct  {float r, g, b, a;};
        float   v[4];
    };
}                   t_vec4;
t_vec4              ft_vec4(void);
t_vec4              ft_vec4_new(float x, float y, float z, float w);
t_vec4              ft_vec4_vec2(t_vec2 v, float z, float w);
t_vec4              ft_vec4_vec3(t_vec3 v, float w);
#endif
