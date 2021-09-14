#include "../inc/vec3.h"


t_vec3      ft_vec3_add(t_vec3  v1, t_vec3 v2)
{
    t_vec3  res;

    res = (t_vec3){{{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z}}};
    return (res);
}

t_vec3      ft_vec3_sub(t_vec3  v1, t_vec3 v2)
{
    t_vec3  res;

    res = (t_vec3){{{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z}}};
    return (res);
}

t_vec3      ft_vec3_mult(t_vec3  v1, t_vec3 v2)
{
    t_vec3  res;

    res = (t_vec3){{{v1.x * v2.x, v1.y * v2.y, v1.z * v2.z}}};
    return (res);
}

t_vec3      ft_vec3_cross(t_vec3  v1, t_vec3 v2)
{
    t_vec3  res;

    res.x = v1.y * v2.z - v1.z * v2.y;
    res.y = v1.z * v2.x - v1.x * v2.z;
    res.z = v1.x * v2.y - v1.y * v2.x;
    return (res);
}

