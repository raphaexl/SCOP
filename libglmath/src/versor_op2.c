#include "../inc/versor.h"

t_versor      ft_versor_kmult(float k, t_versor v)
{
    t_versor  res;

    res = (t_versor){{{k * v.x, k * v.y, k * v.z, k * v.w}}};
    return (res);
}

t_versor      ft_versor_kdiv(float div, t_versor v)
{
    t_versor    res;
    float       k;

    k = 1.0 / div;
    res = (t_versor){{{k * v.x, k * v.y, k * v.z, k * v.w}}};
    return (res);
}


float       ft_versor_dot(t_versor v1, t_versor v2)
{
    return ((v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w));
}

t_versor     ft_versor_slerp(t_versor  q, t_versor r, float t)
{
    float cos_half_theta = ft_versor_dot( q, r );

    if ( cos_half_theta < 0.0f ) {
		for ( int i = 0; i < 4; i++ ) {
			q.q[i] *= -1.0f;
		}
		cos_half_theta = ft_versor_dot( q, r );
	}
	// if qa=qb or qa=-qb then theta = 0 and we can return qa
	if ( fabs( cos_half_theta ) >= 1.0f ) {
		return q;
	}
	// Calculate temporary values
	float sin_half_theta = sqrt( 1.0f - cos_half_theta * cos_half_theta );
	// if theta = 180 degrees then result is not fully defined
	// we could rotate around any axis normal to qa or qb
    t_versor result;
	if ( fabs( sin_half_theta ) < 0.001f ) {
		for ( int i = 0; i < 4; i++ ) {
			result.q[i] = ( 1.0f - t ) * q.q[i] + t * r.q[i];
		}
		return result;
	}
	float half_theta = acos( cos_half_theta );
	float a = sin( ( 1.0f - t ) * half_theta ) / sin_half_theta;
	float b = sin( t * half_theta ) / sin_half_theta;
	for ( int i = 0; i < 4; i++ ) {
		result.q[i] = q.q[i] * a + r.q[i] * b;
	}
return result;
}

t_versor     ft_versor_normalize(t_versor  v)
{
    float   norm2;
    float   norm;

    norm2 = v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
    if (fabs(1.0f - norm2) < 0.0001f)
        return (v);
    norm = sqrt(norm2);
    v.x /= norm;
    v.y /= norm;
    v.z /= norm;
    v.w /= norm;
    return (v);
}
