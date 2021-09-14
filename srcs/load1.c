#include "../incs/scop.h"

void ft_get_bounding_box(t_vector *v_list, t_vec3 *vmin, t_vec3 *vmax);

int		ft_load_obj_file(t_obj *obj, const char *file_name)
{
	int			fd;
	char		*line;
	t_vector	v_list;
	t_vector	uv_list;
	t_vector	n_list;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || fd > 4096)
		return (-1);
	ft_vector_init(&v_list, sizeof(t_vec3));
	ft_vector_init(&uv_list, sizeof(t_vec2));
	ft_vector_init(&n_list, sizeof(t_vec3));
	while (ft_get_next_line(fd, &line) == 1 && line)
	{
		if (line[0] == 'v' && line[1] == ' ')
			ft_parse_obj_vertex(&v_list, line);
		else if (line[0] == 'v' && line[1] == 't')
			ft_parse_obj_uv(&uv_list, line);
		else if (line[0] == 'v' && line[1] == 'n')
			ft_parse_obj_normal(&n_list, line);
		else if (line[0] == 'f' && line[1] == ' ')
                ft_parse_obj_faces(obj, line);
		free(line);
	}
	ft_make_obj(obj, &v_list, &uv_list, &n_list);
	ft_set_obj_offset(obj, &v_list);
	ft_vector_free(&v_list);
	ft_vector_free(&uv_list);
	ft_vector_free(&n_list);
	close(fd);
	return (0);
}

void ft_set_obj_offset(t_obj *obj, t_vector *v_list){
	t_vec3 vmin;
	t_vec3 vmax;

    ft_get_bounding_box(v_list, &vmin, &vmax);
	obj->offset.x = -(vmin.x + vmax.x) / 2.0;
	obj->offset.y = -(vmin.y + vmax.y) / 2.0;
	obj->offset.z = -(vmin.z + vmax.z) / 2.0;
}

void ft_get_bounding_box(t_vector *v_list, t_vec3 *vmin, t_vec3 *vmax){
	int		i;
	int		size;
	t_vec3  minvec;
	t_vec3  maxvec;

	minvec = (t_vec3){{{INFINITY, INFINITY, INFINITY}}};
	maxvec = (t_vec3){{{-INFINITY, -INFINITY, -INFINITY}}};
	i = -1;
	size = v_list->size(v_list);
	while (++i < size)
	{
		if (minvec.x > ((t_vec3 *)v_list->items[i])->x){
		 minvec.x = ((t_vec3 *)v_list->items[i])->x;
		}
		if (minvec.y > ((t_vec3 *)v_list->items[i])->y){
		 minvec.y = ((t_vec3 *)v_list->items[i])->y;
		}
		if (minvec.z > ((t_vec3 *)v_list->items[i])->z){
		 minvec.z = ((t_vec3 *)v_list->items[i])->z;
		}
		if (maxvec.x < ((t_vec3 *)v_list->items[i])->x){
			maxvec.x = ((t_vec3 *)v_list->items[i])->x;
		}
		if (maxvec.y < ((t_vec3 *)v_list->items[i])->y){
			maxvec.y = ((t_vec3 *)v_list->items[i])->y;
		}
		if (maxvec.z < ((t_vec3 *)v_list->items[i])->z){
			maxvec.z = ((t_vec3 *)v_list->items[i])->z;
		}
	}
	*vmin = minvec;
	*vmax = maxvec;
}

t_obj	ft_parse_file(const char *file_name, const char *texture_file_name)
{
	t_obj obj;

	ft_memset(&obj, 0, sizeof(t_obj));	
	ft_obj_init(&obj);
	if (texture_file_name)
	{
		obj.texture_file_name = ft_strdup(texture_file_name);
	}
	ft_load_obj_file(&obj, file_name);
    return (obj);
}


void    ft_process_obj(const char *file_name, const char *texture_name)
{
    t_obj   obj;

    obj = ft_parse_file(file_name, texture_name);
    ft_print_obj(&obj);
	ft_obj_clean(&obj);
}
