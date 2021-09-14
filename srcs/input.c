
# include "../incs/scop.h"

void        ft_process_mouse_move(GLFWwindow *window, t_camera *cam, float delta)
{
    static  int             first_time = 1;
    static  t_vec2          last = {{{W_W / 2.0, W_H / 2.0}}};
    static  t_vec2          pos;
    double  pos_x, pos_y;
    t_vec2                  offset;

    glfwGetCursorPos(window, &pos_x, &pos_y);
    pos.x = pos_x;
    pos.y = pos_y;
    if (first_time)
    {
        pos.x = last.x;
        pos.y = last.y;
        first_time = 0;
 	glfwSetCursorPos(window, pos_x, pos_y);
    }
    offset.x = pos.x - last.x;
    offset.y = last.y - pos.y;
    last.x = pos.x;
    last.y = pos.y;
    (void)delta;
    ft_camera_mouse_move(cam, offset.x, offset.y);
}

void    ft_process_input(GLFWwindow *win, t_camera *cam, float delta)
{
    int       w;
    int       h;
    t_camera_mvt direction;


    direction = (t_camera_mvt){-1};
    glfwGetFramebufferSize(win, &w, &h);
    w = w > 1 ? w : 1;
    h = h > 1 ? h : 1;
    cam->aspect_ratio = (float)w / (float)h;
    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(win, GLFW_TRUE);
    else if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS)
    direction = FORWARD;
    else if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS)
    direction = BACKWARD;
    else if (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS)
    direction = RIGHT;
    else if (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS)
    direction = LEFT;
     else if (glfwGetKey(win, GLFW_KEY_KP_ADD) == GLFW_PRESS)
    {
        cam->zoom += 0.1;
    }
    else if (glfwGetKey(win, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
    {
        cam->zoom -= 0.1;
    }
    ft_camera_process_keyboard(cam, direction, delta);
     //ft_process_mouse_move(win, cam, delta);
}

