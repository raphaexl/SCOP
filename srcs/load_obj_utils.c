#include "../incs/scop.h"

void	ft_parse_obj_vertex(t_vector *v, char *line)
{
	char		**tab;
	t_vec3		vec;

	vec = (t_vec3){{{.0, 0.0, 0.0}}};
	if ((tab = ft_strsplit(line, ' ')) && ft_tab_len(tab) == 4)
	{
		vec.x = ft_atof(tab[1]);
		vec.y = ft_atof(tab[2]);
		vec.z = ft_atof(tab[3]);
	}
	ft_tab_free(&tab);
	v->push_back(v, &vec);
}

void	ft_parse_obj_uv(t_vector *v, char *line)
{
	char		**tab;
	t_vec2		vec;

	vec = (t_vec2){{{.0, 0.0}}};
	if ((tab = ft_strsplit(line, ' ')) && ft_tab_len(tab) == 3)
	{
		vec.x = ft_atof(tab[1]);
		vec.y = ft_atof(tab[2]);
	}
	ft_tab_free(&tab);
	v->push_back(v, &vec);
}

void	ft_parse_obj_normal(t_vector *v, char *line)
{
	char		**tab;
	t_vec3		vec;

	vec = (t_vec3){{{.0, 0.0, 0.0}}};
	if ((tab = ft_strsplit(line, ' ')) && ft_tab_len(tab) == 4)
	{
		vec.x = ft_atof(tab[1]);
		vec.y = ft_atof(tab[2]);
		vec.z = ft_atof(tab[3]);
	}
	ft_tab_free(&tab);
	v->push_back(v, &vec);
}

void		ft_bizzare(t_obj *obj, char **tab)
{
	int index[3];

	index[0] = ft_atoi(tab[0]);
	index[1] = ft_atoi(tab[1]);
	index[2] = ft_atoi(tab[2]);
	ft_vector_push_back(&obj->v_indices, &index[0]);
	ft_vector_push_back(&obj->uv_indices, &index[1]);
	ft_vector_push_back(&obj->n_indices, &index[2]);
}

void		ft_read_face(t_obj *obj, char *tab)
{
	int index[3] = {0, 0, 0};
	int	i;
	int	k;

	i = -1;
	k = 1;
	index[0] = ft_atoi(tab);
	while (tab[++i])
	{
		if (tab[i] == '/')
		 {
			 int	n = ft_atoi(tab + i + 1);
			 index[k] = n;
			 k++;
		 }
	}
	ft_vector_push_back(&obj->v_indices, &index[0]);
	ft_vector_push_back(&obj->uv_indices, &index[1]);
	ft_vector_push_back(&obj->n_indices, &index[2]);
}

void	ft_parse_obj_faces(t_obj *obj, char *line)
{
	char		**tab1;
	char		**tab;
	int			i;

	i = 0;
	if ((tab1 = ft_strsplit(line, ' ')) && ft_tab_len(tab1) == 4)
	{
		while (i < 3 && (tab = ft_strsplit(tab1[i + 1], '/')))
		{
			ft_read_face(obj, tab1[ i + 1]);
			ft_tab_free(&tab);
			i = i + 1;
		}
	}
	else if ((tab1 = ft_strsplit(line, ' ')) && ft_tab_len(tab1) > 4)
	{
		i = 0;
		while (i < 3 && (tab = ft_strsplit(tab1[i + 1], '/')))
		{
			ft_read_face(obj, tab1[ i + 1]);
			ft_tab_free(&tab);
			i = i + 1;
		}
		i = 0;
		if ((tab = ft_strsplit(tab1[i + 1], '/')))
		{
			ft_read_face(obj, tab1[i + 1]);
			ft_tab_free(&tab);
		}
		i = 2;
		while (i < 5 && (tab = ft_strsplit(tab1[i + 1], '/')))
		{
			ft_read_face(obj, tab1[i + 1]);
			ft_tab_free(&tab);
			i = i + 1;
		}
	}
	else
	{
		ft_putendl("An error occured");
		ft_tab_free(&tab1);
		ft_obj_clean(obj);
		exit(0);
	}
	ft_tab_free(&tab1);
}