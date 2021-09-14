#include "../incs/scop.h"

t_shader    ft_shader_init(const char *v_file, const char *f_file)
{
    t_shader    shader;

    shader.id = ft_shader_program(v_file, f_file);
    return (shader);
}

void        ft_shader_use(t_shader *s)
{
    glUseProgram(s->id);
}

void        ft_shader_clear(t_shader *s)
{
    glDeleteProgram(s->id);
}
