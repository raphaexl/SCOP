#ifndef MAT4_H
# define MAT4_H

# include "mat3.h"

typedef struct      s_mat4
{
        float m[MAT4_SIZE];
}                   t_mat4;

/// to avoid norm do vec4 * 4 -->for params

t_mat4                  ft_mat4_zero(void);
t_mat4                  ft_mat4_identity(void);
t_mat4                  ft_mat4_new(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d);
t_mat4                  ft_quat_to_mat4( t_versor q );
void                    ft_mat4_print(t_mat4 m );

t_vec4                  ft_mat4_mult_vec4(t_mat4 m, t_vec4 rhs);
t_mat4                  ft_mat4_mult_mat4( t_mat4 m, t_mat4 rhs );
t_mat4                  ft_mat4_translate( t_mat4 m,  t_vec3 v );
t_mat4                  ft_mat4_scale(t_mat4 m, t_vec3 v);
t_mat4                  ft_mat4_rotate_x_deg( t_mat4 m, float deg );
t_mat4                  ft_mat4_rotate_y_deg(t_mat4 m, float deg );
t_mat4                  ft_mat4_rotate_z_deg(t_mat4 m, float deg );
t_mat4                  ft_mat4_rotate(t_mat4 m, float angle, t_vec3 axis);

float                   ft_mat4_determinant(t_mat4 mm);
t_mat4                  ft_mat4_inverse(t_mat4 mm);
t_mat4                  ft_mat4_transpose(t_mat4 mm);
t_mat4                  ft_mat4_look_at(t_vec3 cam_pos, t_vec3 targ_pos, t_vec3 up) ;
t_mat4                  ft_mat4_perspective(float fovy, float aspect, float near, float far);
# endif