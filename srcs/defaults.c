
#include "../incs/scop.h"

void    ft_make_default_object(t_obj *obj)
{
    static const GLfloat g_v_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f
   };
   static const GLfloat g_c_data[] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f
    };
    ft_memset(obj, 0, sizeof(t_obj));	
    ft_obj_init(obj);
    for (int i = 0; i < 3 ; i++){
        t_vec3		vec;
        vec = (t_vec3){{{g_v_data[ i + 0], g_v_data[ i + 1], g_v_data[ i + 2]}}};
        obj->vertices.push_back(&obj->vertices, &vec);
        t_vec3 rd_color = (t_vec3){{{g_c_data[ i + 0], g_c_data[ i + 1], g_c_data[ i + 2]}}};
        obj->colors.push_back(&obj->colors, &rd_color);
    }
    ft_set_obj_offset(obj, &obj->vertices);
    obj->has_vertices = 1;
    obj->has_normals = 0;
    obj->has_uvs = 0;
    obj->has_texture = 0;
}