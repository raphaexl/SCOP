# include "../incs/scop.h"

void    ft_opengl_print(void)
{
    char     *version;
    char    *renderer;

    version = (char *)glGetString(GL_VERSION);
    renderer = (char *)glGetString(GL_RENDERER);
    printf("OPENGL Version : %s\n", version);
    printf("OPENGL Renderer : %s\n", renderer);
    printf("OPENGL GLSL Version : %s\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("OPENGL GLEW Version : %s\n", (char *)glewGetString(GLEW_VERSION));
}

void    ft_opengl_fps(GLFWwindow    *win)
{
    static      double prev_time;
    static      int     frame_count;
    double      current_time;
    double      elapsed_time;
    char        tmp[128];
    
    prev_time = glfwGetTime();
    current_time = glfwGetTime();
    elapsed_time = current_time - prev_time;
    if (elapsed_time > 0.2f)
    {
        prev_time = current_time;
        sprintf(tmp, "FPS : %.2f",(double)frame_count / elapsed_time);
        glfwSetWindowTitle(win, tmp);
        frame_count = 0;
    }
    frame_count++;
}

GLFWwindow      *ft_opengl_window(void)
{
    GLFWwindow  *win;

    if (!glfwInit())
    {
        fprintf(stderr, "Error glfwInt()");
        return (NULL);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if (!(win = glfwCreateWindow(W_W, W_H, WIN_TILE, NULL, NULL)))
    {
        fprintf(stderr, "Error glfwCreatewindow()");
        return (NULL);
    }
    glfwMakeContextCurrent(win);
    glfwSetFramebufferSizeCallback(win, ft_frame_buffer_size_callback);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Error glewInt()");
        return (NULL);
    }
    glEnable(GL_DEPTH_TEST);
    return (win);
}

void    ft_opengl_clear(GLFWwindow **win)
{
    glfwDestroyWindow(*win);
    glfwTerminate();
}
