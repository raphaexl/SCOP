#include "../inc/vec4.h"

t_vec4      ft_vec4(void)
{
    return ((t_vec4){{{.0f, .0f, .0f, 0.0f}}});
}

t_vec4      ft_vec4_new(float x, float y, float z, float w)
{
    return ((t_vec4){{{x, y, z, w}}});
}

t_vec4      ft_vec4_vec2(t_vec2 v, float z, float w)
{
    return ((t_vec4){{{v.x, v.y, z, w}}});
}

t_vec4      ft_vec4_vec3(t_vec3 v, float w)
{
    return ((t_vec4){{{v.x, v.y, v.z, w}}});
}
