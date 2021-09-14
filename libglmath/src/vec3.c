#include "../inc/vec3.h"

t_vec3      ft_vec3(void)
{
    return ((t_vec3){{{.0f, .0f, .0f}}});
}

t_vec3      ft_vec3_new(float x, float y, float z)
{
    return ((t_vec3){{{x, y, z}}});
}

float       ft_vec3_to_heading(t_vec3 d)
{
    return (RAD_TO_DEG(atan2(-d.x, -d.z)));
}

t_vec3      ft_heading_to_vec3(float angle)
{
    float   rad;

    rad = DEG_TO_RAD(angle);
    return ((t_vec3){{{-sin(rad), 0.0f, -cos(rad)}}});
}

void    ft_vec3_print(t_vec3 v)
{
    printf("xyz : x = %.2f\t y = %.2f\t z = %.2f\n", v.x, v.y, v.z);
}