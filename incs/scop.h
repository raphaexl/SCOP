#ifndef SCOP_H
# define SCOP_H

# include "utils.h"


void            ft_process_input(GLFWwindow *win, t_camera *cam, float time);
void            ft_run(t_obj *obj);
GLFWwindow      *ft_opengl_window(void);
void            ft_opengl_print(void);
void            ft_opengl_fps(GLFWwindow    *win);  
void            ft_opengl_clear(GLFWwindow **win);

void            ft_frame_buffer_size_callback(GLFWwindow *window, int w, int h);
#endif