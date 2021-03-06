#include "../inc/vector.h"

void			ft_vector_init(t_vector *v, int size)
{
	if (!v)
		return ;
	v->type_size = size;
	v->size = &ft_vector_size;
	v->push_back = &ft_vector_push_back;
	v->insert = &ft_vector_set;
	v->set = &ft_vector_set;
	v->at = &ft_vector_get;
	v->remove = &ft_vector_remove;
	v->delete = &ft_vector_delete;
	v->clear = &ft_vector_free;
	v->capacity = VECTOR_INIT_CAPACITY;
	v->length = 0;
	if (!(v->items = malloc(sizeof(void *) * v->capacity)))
	{
		fprintf(stderr, "Error vector memory allocation, no ENOUGH SPACE");
		exit(EXIT_FAILURE);
	}
}

int			ft_vector_size(t_vector *v)
{
	if (!v)
		return (-1);
	return (v->length);
}

void			ft_vector_set(t_vector *v, int index, void *value)
{
	void	*new;

	if (!v)
		return ;
	if (index >= 0 && index < v->length)
	{
		new = malloc(v->type_size);
		v->items[index] = memcpy(new, value, v->type_size);
	}
}

void			*ft_vector_get(t_vector *v, int index)
{
	if (v && index >= 0 && index < v->length)
		return (v->items[index]);
	return (NULL);
}

void			ft_vector_free(t_vector *v)
{
	int	i;
	int	size;

	i = 0;
	size = v->length;
	if (!v)
		return ;
	while (i < size)
	{
		free(v->items[i]);
		i++;
	}
	free(v->items);
}