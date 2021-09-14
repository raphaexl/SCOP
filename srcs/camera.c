#include "../incs/scop.h"


t_camera    ft_camera(void)
{
    t_camera   cam;

    cam.pos = (t_vec3){{{0.0, 0.0, 3.0}}};
    cam.at = (t_vec3){{{0.0, 0.0, -1.0}}};
    cam.up = (t_vec3){{{0.0, 1.0, 0.0}}};
    cam.u = cam.up;
    cam.yaw = YAW;
    cam.pitch = PITCH;
    cam.speed = SPEED;
    cam.mouse_sensitivity = SENSITIVITY;
    cam.zoom = ZOOM;
    cam.aspect_ratio = (float)W_W/(float)W_H;
    ft_camera_update_vecs(&cam);
    cam.view = ft_mat4_identity();
    cam.projection = ft_mat4_identity();
    return (cam);
}

void        ft_camera_update_vecs(t_camera *cam)
{
    t_vec3  at;

    at.x = cos(DEG_TO_RAD(cam->yaw)) *  cos(DEG_TO_RAD(cam->pitch));
    at.y = sin(DEG_TO_RAD(cam->pitch));
    at.z = sin(DEG_TO_RAD(cam->yaw)) * cos(DEG_TO_RAD(cam->pitch));
    cam->at = ft_vec3_normalize(at);
    cam->rt = ft_vec3_normalize(ft_vec3_cross(cam->at, cam->up));
    cam->u = ft_vec3_normalize(ft_vec3_cross(cam->rt, cam->at));
}

void        ft_camera_matrix(t_camera *cam)
{
    cam->view = ft_mat4_look_at(cam->pos, ft_vec3_add(cam->pos, cam->at), cam->u);
    cam->projection = ft_mat4_perspective(cam->zoom, cam->aspect_ratio, 0.01f, 1000.0f);
}

void    ft_camera_process_keyboard(t_camera *cam, t_camera_mvt direction, float delta_time)
{
    float       velocity;

    velocity = cam->speed * delta_time;
    if (direction == FORWARD)
        cam->pos = ft_vec3_add(cam->pos, ft_vec3_kmult(velocity, cam->at));
    else if (direction == BACKWARD)
        cam->pos = ft_vec3_sub(cam->pos, ft_vec3_kmult(velocity, cam->at));
    else if (direction == LEFT)
        cam->pos = ft_vec3_sub(cam->pos, ft_vec3_kmult(velocity, cam->rt));
    else if (direction == RIGHT)
        cam->pos = ft_vec3_add(cam->pos, ft_vec3_kmult(velocity, cam->rt));
    ft_camera_matrix(cam);
}

void        ft_camera_mouse_move(t_camera *cam, float xoffset, float yoffset)
{
    xoffset *= cam->mouse_sensitivity;
    yoffset *= cam->mouse_sensitivity;

    cam->yaw += xoffset;
    cam->pitch += yoffset;
    if (cam->pitch > 89.0f)
     cam->pitch = 89.0;
    else if(cam->pitch < -89.0f)
     cam->pitch = -89.0;
    ft_camera_update_vecs(cam);
}

void        ft_camera_mouse_wheel(t_camera *cam, float yoffset)
{
    if (cam->zoom > 1.0f && cam->zoom < 45.0f)
        cam->zoom -= yoffset;
    else if (cam->zoom <= 1.0f)
        cam->zoom = 1.0f;
    else if (cam->zoom >= 45.0f)
        cam->zoom = 45.0f;
}
