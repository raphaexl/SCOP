#include "../inc/mat4.h"

t_vec4                  ft_mat4_mult_vec4(t_mat4 m, t_vec4 rhs)
{
        t_vec4  res;
        
        res.x = m.m[0] * rhs.v[0] + m.m[4] * rhs.v[1] + m.m[8] * rhs.v[2] + m.m[12] * rhs.v[3];
        res.y = m.m[1] * rhs.v[0] + m.m[5] * rhs.v[1] + m.m[9] * rhs.v[2] + m.m[13] * rhs.v[3];
        res.z = m.m[2] * rhs.v[0] + m.m[6] * rhs.v[1] + m.m[10] * rhs.v[2] + m.m[14] * rhs.v[3];
        res.w = m.m[3] * rhs.v[0] + m.m[7] * rhs.v[1] + m.m[11] * rhs.v[2] + m.m[15] * rhs.v[3];
        return (res);
}

t_mat4 ft_mat4_mult_mat4( t_mat4 m, t_mat4 rhs ) {
	t_mat4 res;
	int index;
        
    index = 0;
    res = ft_mat4_zero();
	for ( int col = 0; col < 4; col++ ) {
		for ( int row = 0; row < 4; row++ ) {
			float sum = 0.0f;
			for ( int i = 0; i < 4; i++ ) {
				sum += rhs.m[i + col * 4] * m.m[row + i * 4];
			}
			res.m[index] = sum;
			index++;
		}
	}
	return res;
}
/*
t_mat4 ft_mat4_mult_mat4(t_mat4 m1, t_mat4 m2)
{
  t_mat4 out = ft_mat4_identity();
  unsigned int row, column, row_offset;

  for (row = 0, row_offset = row * 4; row < 4; ++row, row_offset = row * 4)
    for (column = 0; column < 4; ++column)
      out.m[row_offset + column] =
        (m1.m[row_offset + 0] * m2.m[column + 0]) +
        (m1.m[row_offset + 1] * m2.m[column + 4]) +
        (m1.m[row_offset + 2] * m2.m[column + 8]) +
        (m1.m[row_offset + 3] * m2.m[column + 12]);

  return out;
}
*/
t_mat4 ft_mat4_translate( t_mat4 m, t_vec3 v ) {
	t_mat4 m_t;
    
    m_t = ft_mat4_identity();
	m_t.m[12] = v.v[0];
	m_t.m[13] = v.v[1];
	m_t.m[14] = v.v[2];
	return (ft_mat4_mult_mat4(m_t, m));
}

t_mat4 ft_mat4_rotate_x_deg(t_mat4 m, float deg ) {
	float rad;
    t_mat4 m_r;
    
    rad = DEG_TO_RAD(deg);
	m_r = ft_mat4_identity();
	m_r.m[5] = cos( rad );
	m_r.m[9] = -sin( rad );
	m_r.m[6] = sin( rad );
	m_r.m[10] = cos( rad );
	return (ft_mat4_mult_mat4(m_r , m));
}

t_mat4 ft_mat4_rotate_y_deg( t_mat4 m, float deg ) {
	
	float rad;
    t_mat4 m_r;
    
    rad = DEG_TO_RAD(deg);
	m_r = ft_mat4_identity();
	m_r.m[0] = cos( rad );
	m_r.m[8] = sin( rad );
	m_r.m[2] = -sin( rad );
	m_r.m[10] = cos( rad );
	return (ft_mat4_mult_mat4(m_r , m));
}

t_mat4 ft_mat4_rotate_z_deg(t_mat4 m, float deg ) {
	
	float rad;
    t_mat4 m_r;
    
    rad = DEG_TO_RAD(deg);
	m_r = ft_mat4_identity();
	m_r.m[0] = cos( rad );
	m_r.m[1] = -sin( rad );
	m_r.m[4] = sin( rad );
    m_r.m[5] = cos( rad );
	return (ft_mat4_mult_mat4(m_r , m));
}

t_mat4  ft_mat4_scale(t_mat4 m, t_vec3 v)
{
    t_mat4  m_s;

    m_s = ft_mat4_identity();
    m_s.m[0] = v.v[0];
	m_s.m[5] = v.v[1];
    m_s.m[10] = v.v[2];
    return (ft_mat4_mult_mat4(m_s , m));
}

