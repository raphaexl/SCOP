#include "../inc/mat4.h"

float   ft_mat4_determinant(t_mat4 mm)
{
    float   value;
    
    value = mm.m[12] * mm.m[9] * mm.m[6] * mm.m[3] -\
    mm.m[8] * mm.m[13] * mm.m[6] * mm.m[3] -\
    mm.m[12] * mm.m[5] * mm.m[10] * mm.m[3] +\
    mm.m[4] * mm.m[13] * mm.m[10] * mm.m[3] +\
    mm.m[8] * mm.m[5] * mm.m[14] * mm.m[3] -\
    mm.m[4] * mm.m[9] * mm.m[14] * mm.m[3] -\
    mm.m[12] * mm.m[9] * mm.m[2] * mm.m[7] +\
    mm.m[8] * mm.m[13] * mm.m[2] * mm.m[7] +\
    mm.m[12] * mm.m[1] * mm.m[10] * mm.m[7] -\
    mm.m[0] * mm.m[13] * mm.m[10] * mm.m[7] -\
    mm.m[8] * mm.m[1] * mm.m[14] * mm.m[7] +\
    mm.m[0] * mm.m[9] * mm.m[14] * mm.m[7] +\
    mm.m[12] * mm.m[5] * mm.m[2] * mm.m[11] -\
    mm.m[4] * mm.m[13] * mm.m[2] * mm.m[11] -\
    mm.m[12] * mm.m[1] * mm.m[6] * mm.m[11] +\
    mm.m[0] * mm.m[13] * mm.m[6] * mm.m[11] +\
    mm.m[4] * mm.m[1] * mm.m[14] * mm.m[11] -\
    mm.m[0] * mm.m[5] * mm.m[14] * mm.m[11] -\
    mm.m[8] * mm.m[5] * mm.m[2] * mm.m[15] +\
    mm.m[4] * mm.m[9] * mm.m[2] * mm.m[15] +\
    mm.m[8] * mm.m[1] * mm.m[6] * mm.m[15] -\
    mm.m[0] * mm.m[9] * mm.m[6] * mm.m[15] -\
    mm.m[4] * mm.m[1] * mm.m[10] * mm.m[15] +\
    mm.m[0] * mm.m[5] * mm.m[10] * mm.m[15];
    return (value);
}



t_mat4   ft_mat4_inverse(t_mat4 mm)
{
float det = ft_mat4_determinant(mm);
	if ( 0.0f == det ) {
		fprintf( stderr, "WARNING. matrix has no determinant. can not invert\n" );
		return mm;
	}
	float inv_det = 1.0f / det;

    t_vec4 v[4];

    v[0] = ft_vec4_new(inv_det * ( mm.m[9] * mm.m[14] * mm.m[7] - mm.m[13] * mm.m[10] * mm.m[7] +
								mm.m[13] * mm.m[6] * mm.m[11] - mm.m[5] * mm.m[14] * mm.m[11] -
								mm.m[9] * mm.m[6] * mm.m[15] + mm.m[5] * mm.m[10] * mm.m[15] ),
		inv_det * ( mm.m[13] * mm.m[10] * mm.m[3] - mm.m[9] * mm.m[14] * mm.m[3] -
								mm.m[13] * mm.m[2] * mm.m[11] + mm.m[1] * mm.m[14] * mm.m[11] +
								mm.m[9] * mm.m[2] * mm.m[15] - mm.m[1] * mm.m[10] * mm.m[15] ),
		inv_det * ( mm.m[5] * mm.m[14] * mm.m[3] - mm.m[13] * mm.m[6] * mm.m[3] +
								mm.m[13] * mm.m[2] * mm.m[7] - mm.m[1] * mm.m[14] * mm.m[7] -
								mm.m[5] * mm.m[2] * mm.m[15] + mm.m[1] * mm.m[6] * mm.m[15] ),
		inv_det * ( mm.m[9] * mm.m[6] * mm.m[3] - mm.m[5] * mm.m[10] * mm.m[3] -
								mm.m[9] * mm.m[2] * mm.m[7] + mm.m[1] * mm.m[10] * mm.m[7] +
								mm.m[5] * mm.m[2] * mm.m[11] - mm.m[1] * mm.m[6] * mm.m[11] ));
    v[1] = ft_vec4_new(inv_det * ( mm.m[12] * mm.m[10] * mm.m[7] - mm.m[8] * mm.m[14] * mm.m[7] -
								mm.m[12] * mm.m[6] * mm.m[11] + mm.m[4] * mm.m[14] * mm.m[11] +
								mm.m[8] * mm.m[6] * mm.m[15] - mm.m[4] * mm.m[10] * mm.m[15] ),
		inv_det * ( mm.m[8] * mm.m[14] * mm.m[3] - mm.m[12] * mm.m[10] * mm.m[3] +
								mm.m[12] * mm.m[2] * mm.m[11] - mm.m[0] * mm.m[14] * mm.m[11] -
								mm.m[8] * mm.m[2] * mm.m[15] + mm.m[0] * mm.m[10] * mm.m[15] ),
		inv_det * ( mm.m[12] * mm.m[6] * mm.m[3] - mm.m[4] * mm.m[14] * mm.m[3] -
								mm.m[12] * mm.m[2] * mm.m[7] + mm.m[0] * mm.m[14] * mm.m[7] +
								mm.m[4] * mm.m[2] * mm.m[15] - mm.m[0] * mm.m[6] * mm.m[15] ),
		inv_det * ( mm.m[4] * mm.m[10] * mm.m[3] - mm.m[8] * mm.m[6] * mm.m[3] +
								mm.m[8] * mm.m[2] * mm.m[7] - mm.m[0] * mm.m[10] * mm.m[7] -
								mm.m[4] * mm.m[2] * mm.m[11] + mm.m[0] * mm.m[6] * mm.m[11] ));
    v[2] = ft_vec4_new(inv_det * ( mm.m[8] * mm.m[13] * mm.m[7] - mm.m[12] * mm.m[9] * mm.m[7] +
								mm.m[12] * mm.m[5] * mm.m[11] - mm.m[4] * mm.m[13] * mm.m[11] -
								mm.m[8] * mm.m[5] * mm.m[15] + mm.m[4] * mm.m[9] * mm.m[15] ),
		inv_det * ( mm.m[12] * mm.m[9] * mm.m[3] - mm.m[8] * mm.m[13] * mm.m[3] -
								mm.m[12] * mm.m[1] * mm.m[11] + mm.m[0] * mm.m[13] * mm.m[11] +
								mm.m[8] * mm.m[1] * mm.m[15] - mm.m[0] * mm.m[9] * mm.m[15] ),
		inv_det * ( mm.m[4] * mm.m[13] * mm.m[3] - mm.m[12] * mm.m[5] * mm.m[3] +
								mm.m[12] * mm.m[1] * mm.m[7] - mm.m[0] * mm.m[13] * mm.m[7] -
								mm.m[4] * mm.m[1] * mm.m[15] + mm.m[0] * mm.m[5] * mm.m[15] ),
		inv_det * ( mm.m[8] * mm.m[5] * mm.m[3] - mm.m[4] * mm.m[9] * mm.m[3] -
								mm.m[8] * mm.m[1] * mm.m[7] + mm.m[0] * mm.m[9] * mm.m[7] +
								mm.m[4] * mm.m[1] * mm.m[11] - mm.m[0] * mm.m[5] * mm.m[11] ));
    v[3] = ft_vec4_new(	inv_det * ( mm.m[12] * mm.m[9] * mm.m[6] - mm.m[8] * mm.m[13] * mm.m[6] -
								mm.m[12] * mm.m[5] * mm.m[10] + mm.m[4] * mm.m[13] * mm.m[10] +
								mm.m[8] * mm.m[5] * mm.m[14] - mm.m[4] * mm.m[9] * mm.m[14] ),
		inv_det * ( mm.m[8] * mm.m[13] * mm.m[2] - mm.m[12] * mm.m[9] * mm.m[2] +
								mm.m[12] * mm.m[1] * mm.m[10] - mm.m[0] * mm.m[13] * mm.m[10] -
								mm.m[8] * mm.m[1] * mm.m[14] + mm.m[0] * mm.m[9] * mm.m[14] ),
		inv_det * ( mm.m[12] * mm.m[5] * mm.m[2] - mm.m[4] * mm.m[13] * mm.m[2] -
								mm.m[12] * mm.m[1] * mm.m[6] + mm.m[0] * mm.m[13] * mm.m[6] +
								mm.m[4] * mm.m[1] * mm.m[14] - mm.m[0] * mm.m[5] * mm.m[14] ),
		inv_det * ( mm.m[4] * mm.m[9] * mm.m[2] - mm.m[8] * mm.m[5] * mm.m[2] +
								mm.m[8] * mm.m[1] * mm.m[6] - mm.m[0] * mm.m[9] * mm.m[6] -
                                mm.m[4] * mm.m[1] * mm.m[10] + mm.m[0] * mm.m[5] * mm.m[10] ) );

	return (ft_mat4_new(v[0], v[1], v[2], v[3]));
}

t_mat4   ft_mat4_transpose(t_mat4 mm)
{
    t_vec4 v[4];

    v[0] = ft_vec4_new(mm.m[0], mm.m[4], mm.m[8], mm.m[12]);
    v[1] = ft_vec4_new(mm.m[1], mm.m[5], mm.m[9], mm.m[13]);
    v[2] = ft_vec4_new(mm.m[2], mm.m[6], mm.m[10], mm.m[14]);
    v[3] = ft_vec4_new(mm.m[3], mm.m[7], mm.m[11], mm.m[15]);
    return (ft_mat4_new(v[0], v[1], v[2], v[3]));
}

