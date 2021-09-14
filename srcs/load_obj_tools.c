#include "../incs/scop.h"

float	ft_rand48(void)
{
	static int	initialized = 0;

	if (!initialized)
	{
		initialized = 1;
		srand(time(NULL));
	}
	return ((float)(rand() % RAND_MAX) / ((float)(RAND_MAX + 1.0)));
}

t_vec3 ft_random_color(){
	return ft_vec3_new(ft_rand48(), ft_rand48(), ft_rand48());
}

void	ft_make_obj(t_obj *obj, t_vector *v, t_vector *uvs, t_vector *normals)
{
	int		i;
	int		size;

	obj->has_vertices = v->size(v) > 0;
	obj->has_normals = normals->size(normals) > 0;
	obj->has_uvs = uvs->size(uvs) > 0;
	if (!obj->has_vertices)
		return;
	int level = 0;
	i = -1;
	size = obj->v_indices.size(&obj->v_indices);
	while (++i < size)
	{
		obj->vertices.push_back(&obj->vertices,
				(t_vec3 *)v->items[*(int *)obj->v_indices.items[i] - 1]);
		if (level > 8){
			level = 0;
		}
		t_vec3 rd_color = (t_vec3){{{0}}};
		if (level < 3){
			rd_color = ft_random_color();
		}else if (level > 2 && level < 6){
			rd_color = ft_random_color();
		}else if (level > 5 &&  level < 9){
			rd_color = ft_random_color();
		}
		obj->colors.push_back(&obj->colors, &rd_color);
		level++;
	}
	i = -1;
	size = obj->has_uvs ? obj->uv_indices.size(&obj->uv_indices) : -1;
	while (++i < size)
			obj->uvs.push_back(&obj->uvs,
				(t_vec2 *)uvs->items[*(int *)obj->uv_indices.items[i] - 1]);
	i = -1;
	size = obj->has_normals ? obj->n_indices.size(&obj->n_indices) : -1;
	while (++i < size)
		obj->normals.push_back(&obj->normals,
				(t_vec3 *)normals->items[*(int *)obj->n_indices.items[i] - 1]);
}

void	ft_print_obj(t_obj *obj)
{
	ft_putendl("VERTICES");
	for (int i = 0; i < obj->vertices.length; i++)
	printf("indice : %d x : %.2f y : %.2f z : %.2f\n", i, ((t_vec3 *)obj->vertices.items[i])->x,
			((t_vec3 *)obj->vertices.items[i])->y, ((t_vec3 *)obj->vertices.items[i])->z);
	ft_putendl("UV");
	for (int i = 0; i < obj->uvs.length; i++)
	printf("indice : %d x : %.2f y : %.2f\n", i, ((t_vec2 *)obj->uvs.items[i])->x, ((t_vec2 *)obj->uvs.items[i])->y);
	ft_putendl("NORMALS");
	for (int i = 0; i < obj->normals.length; i++)
	printf("indice : %d x : %.2f y : %.2f z : %.2f\n", i, ((t_vec3 *)obj->normals.items[i])->x,
			((t_vec3 *)obj->normals.items[i])->y, ((t_vec3 *)obj->normals.items[i])->z);
}

void	ft_obj_init(t_obj *obj)
{
	ft_vector_init(&obj->vertices, sizeof(t_vec3));
	ft_vector_init(&obj->colors, sizeof(t_vec3));
	ft_vector_init(&obj->uvs, sizeof(t_vec2));
	ft_vector_init(&obj->normals, sizeof(t_vec3));
	ft_vector_init(&obj->v_indices, sizeof(int));
	ft_vector_init(&obj->uv_indices, sizeof(int));
	ft_vector_init(&obj->n_indices, sizeof(int));
	obj->texture_file_name = NULL;
}

void	ft_obj_clean(t_obj *obj)
{
	ft_vector_free(&obj->vertices);
	ft_vector_free(&obj->colors);
	ft_vector_free(&obj->uvs);
	ft_vector_free(&obj->normals);
	ft_vector_free(&obj->v_indices);
	ft_vector_free(&obj->uv_indices);
	ft_vector_free(&obj->n_indices);
	if (obj->texture_file_name){
		free(obj->texture_file_name);
	}
}
