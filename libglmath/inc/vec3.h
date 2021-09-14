#ifndef VEC3_H
# define VEC3_H

# include "vec2.h"

typedef struct  s_vec3
{
   union { 
		struct {float x,y,z;};
		struct {float s,t,p;};
		struct {float r,g,b;};
		float v[3];
	};
}               t_vec3;

t_vec3              ft_vec3(void);
t_vec3              ft_vec3_new(float x, float y, float z);
t_vec3              ft_vec3_add(t_vec3  v1, t_vec3 v2);
t_vec3              ft_vec3_sub(t_vec3  v1, t_vec3 v2);
t_vec3              ft_vec3_mult(t_vec3  v1, t_vec3 v2);

t_vec3              ft_vec3_kmult(float k, t_vec3 v2);
t_vec3              ft_vec3_cross(t_vec3  v1, t_vec3 v2);
t_vec3     			ft_vec3_normalize(t_vec3  v);
float               ft_vec3_length(t_vec3  v);
float               ft_vec3_length2(t_vec3  v);
float               ft_vec3_dot(t_vec3 v1, t_vec3 v2);

void                ft_vec3_print(t_vec3 v);
float       		ft_vec3_to_heading(t_vec3 d);
t_vec3     			ft_heading_to_vec3(float angle);	
float   			ft_vec3_sqared_dist(t_vec3 from, t_vec3 to);	
#endif