# include "../incs/scop.h"

void    ft_shader_error(GLuint shader, GLenum type)
{
    int     info_log_length;
    char    *res;

    res = NULL;
    if (type == GL_VERTEX_SHADER || type == GL_FRAGMENT_SHADER)
    {
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
    if (info_log_length)
    {
        res = malloc(info_log_length + 1);
        glGetShaderInfoLog(shader, info_log_length, NULL, res);
        fprintf(stderr, "Error %s compilation : %s", type == GL_VERTEX_SHADER ? 
        "VERTEX_SHADER" : "FRAGMENT_SHADER", res);
        free(res);
    }
    }
     else if (type == GL_PROGRAM)
    {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
        if (info_log_length)
    {
        res = malloc(info_log_length + 1);
        glGetShaderInfoLog(shader, info_log_length, NULL, res);
        fprintf(stderr, "Error Program linking : %s",  res);
        free(res);
    }
    }
}

GLuint   ft_shader_create(const char *file_name, GLenum type)
{
    GLchar          *code;
    const GLchar    **source_code;
    GLuint          shader;
    int             ret;
    GLint           len;


    if (type == GL_VERTEX_SHADER)
        shader = glCreateShader(GL_VERTEX_SHADER);
    else if (type == GL_FRAGMENT_SHADER)
        shader = glCreateShader(GL_FRAGMENT_SHADER);
    else
        return (0);
    code = (char *)ft_file_content(file_name, &len);
    source_code = (const GLchar **)&code;
    glShaderSource(shader, 1, source_code, &len);
    free(code);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ret);
    if (!ret)
    {
        ft_shader_error(shader, type);
        return (0);
    }
    return (shader);
}

GLuint      ft_shader_program(const char *v_file, const char *f_file)
{
    GLuint  v_shader;
    GLuint  f_shader;
    GLuint  program;
    int     ret;

    v_shader = ft_shader_create(v_file, GL_VERTEX_SHADER);
    f_shader = ft_shader_create(f_file, GL_FRAGMENT_SHADER);
    program = glCreateProgram();
    glAttachShader(program, v_shader);
    glAttachShader(program, f_shader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &ret);
    if (!ret)
    {
        ft_shader_error(program, GL_PROGRAM);
        return (0);
    }
    glDetachShader(program, f_shader);
    glDetachShader(program, v_shader);
    glDeleteShader(f_shader);
    glDeleteShader(v_shader);
    return (program);
}