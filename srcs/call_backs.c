#include "../incs/scop.h"

void    ft_frame_buffer_size_callback(GLFWwindow *window, int w, int h)
{
    (void)window;
    glViewport(0, 0, w, h);
}