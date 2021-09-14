#ifndef STRUCTS_H
# define STRUCTS_H

# include "defines.h"

typedef struct  s_shader
{
    GLuint      id;
}               t_shader;

typedef struct  s_camera
{
    float       yaw;
    float       pitch;
    float       speed;
    float       sensitivity;
    float       mouse_sensitivity;
    float       zoom;
    float       aspect_ratio;
    t_vec3      pos;
    t_vec3      at;
    t_vec3      up;
    t_vec3      u;
    t_vec3      rt;

    t_mat4      projection;
    t_mat4      view;
}               t_camera;

typedef     enum    e_camera_mvt
{
    FORWARD, BACKWARD, RIGHT, LEFT
}                   t_camera_mvt;

typedef struct      s_obj
{
    t_vector	vertices;
     t_vector	colors;
    t_vector	normals;
	t_vector	uvs;
	t_vector	v_indices;
    t_vector    n_indices;
	t_vector	uv_indices;
    t_vec3      offset;
    int         has_vertices;
    int         has_normals;
    int         has_uvs;
    int         has_texture;
    char        *texture_file_name;
}                   t_obj;
#endif
