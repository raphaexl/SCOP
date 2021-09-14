#ifndef VERSOR_H
# define VERSOR_H

# include "vec4.h"

typedef struct  s_versor
{
   union { 
		struct {float x,y,z, w;};
		struct {float s,t,p, u;};
		struct {float r,g,b, a;};
		float q[4];
	};
}               t_versor;

t_versor              ft_versor(void);
t_versor              ft_versor_new(float x, float y, float z, float w);
t_versor              ft_versor_add(t_versor  v1, t_versor v2);
t_versor              ft_versor_sub(t_versor  v1, t_versor v2);
t_versor              ft_versor_mult(t_versor  v1, t_versor v2);

t_versor              ft_versor_kdiv(float div, t_versor v);
t_versor              ft_versor_kmult(float k, t_versor v2);
t_versor              ft_versor_slerp(t_versor  q, t_versor r, float t);
float                 ft_versor_dot(t_versor v1, t_versor v2);

void                ft_versor_print(t_versor v);
# endif
