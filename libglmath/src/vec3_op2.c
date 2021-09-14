#include "../inc/vec3.h"

t_vec3      ft_vec3_kmult(float k, t_vec3 v)
{
    t_vec3  res;

    res = (t_vec3){{{k * v.x, k * v.y, k * v.z}}};
    return (res);
}

float       ft_vec3_dot(t_vec3 v1, t_vec3 v2)
{
    return ((v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

float      ft_vec3_length(t_vec3  v)
{
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

float      ft_vec3_length2(t_vec3  v)
{
    return ((v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3     ft_vec3_normalize(t_vec3  v)
{
    float   norm;

    norm = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (norm == 0.0f)
        return ((t_vec3){{{0.0f, 0.0f, 0.0f}}});
    v.x /= norm;
    v.y /= norm;
    v.z /= norm;
    return (v);
}

float   ft_vec3_sqared_dist(t_vec3 from, t_vec3 to)
{
    float x = ( to.v[0] - from.v[0] ) * ( to.v[0] - from.v[0] );
	float y = ( to.v[1] - from.v[1] ) * ( to.v[1] - from.v[1] );
	float z = ( to.v[2] - from.v[2] ) * ( to.v[2] - from.v[2] );
    return (x + y + z);
}