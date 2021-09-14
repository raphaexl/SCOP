#include "../inc/versor.h"

t_versor      ft_versor(void)
{
    return ((t_versor){{{.0f, .0f, .0f, 0.0f}}});
}

t_versor      ft_versor_new(float x, float y, float z, float w)
{
    return ((t_versor){{{x, y, z, w}}});
}

t_versor      ft_versor_add(t_versor  v1, t_versor v2)
{
    t_versor  res;

    res = (t_versor){{{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w}}};
    return (res);
}

t_versor      ft_versor_sub(t_versor  v1, t_versor v2)
{
    t_versor  res;

    res = (t_versor){{{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w}}};
    return (res);
}

t_versor      ft_versor_mult(t_versor  v1, t_versor v2)
{
    t_versor  res;

    res = (t_versor){{{v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w}}};
    return (res);
}

t_versor      ft_versor_from_axis_rad(float rad, float x, float y, float z)
{
    t_versor  res;

    res.x = cos(rad / 2.0);
    res.y = sin(rad / 2.0) * x;
    res.z = sin(rad / 2.0) * y;
    res.w = sin(rad / 2.0) * z;
    return (res);
}

t_versor      ft_versor_from_axis_deg(float deg, float x, float y, float z)
{
    t_versor  res;
    float       rad;

    rad = DEG_TO_RAD(deg);
    res.x = cos(rad / 2.0);
    res.y = sin(rad / 2.0) * x;
    res.z = sin(rad / 2.0) * y;
    res.w = sin(rad / 2.0) * z;
    return (res);
}

