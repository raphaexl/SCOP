#include "../incs/scop.h"

void        ft_shader_set_bool(t_shader *s, const char *name, GLboolean value)
{
    glUniform1i(glGetUniformLocation(s->id, name), (int )value);
}

void        ft_shader_set_int(t_shader *s, const char *name, int value)
{
    glUniform1i(glGetUniformLocation(s->id, name), value);
}

void        ft_shader_set_float(t_shader *s, const char *name, float value)
{
    glUniform1f(glGetUniformLocation(s->id, name), value);
}

void        ft_shader_set_vec3(t_shader *s, const char *name, t_vec3 v)
{
    glUniform3f(glGetUniformLocation(s->id, name), v.x, v.y, v.z);
}
void        ft_shader_set_mat4f(t_shader *s, const char *name, t_mat4 m)
{
    glUniformMatrix4fv(glGetUniformLocation(s->id, name), 1, GL_FALSE, m.m);
}