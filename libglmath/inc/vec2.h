#ifndef VEC2_H
#define VEC2_H

# include "defs.h"

typedef struct      s_vec2
{
    union
    {
        struct {float x, y;};
        struct {float s, t;};
        struct {float uv_u, uv_v;};
        float  v[2];
    };
}                   t_vec2;

t_vec2              ft_vec2(void);
t_vec2              ft_vec2_new(float x, float y);
#endif