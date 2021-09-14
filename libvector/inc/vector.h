
#ifndef     VECTOR_H
# define VECTOR_H
# define VECTOR_INIT_CAPACITY 4

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_vector
{
	void		**items;
	int			capacity;
	int			length;
	size_t		type_size;
	int			(*size)(struct s_vector *);
	void		(*push_back)(struct s_vector *, void *);
	void		(*insert)(struct s_vector *, int, void *);
	void		(*set)(struct s_vector *, int, void *);
	void		*(*at)(struct s_vector *, int);
	void		(*remove)(struct s_vector *, int);
	void		(*delete)(struct s_vector *, void *value);
	void		(*clear)(struct s_vector *);
}               t_vector;

void				ft_vector_init(t_vector *vec, int size);
int					ft_vector_size(t_vector *vec);
void				ft_vector_push_back(t_vector *vec, void *value);
void				ft_vector_set(t_vector *vec, int id, void *value);
void				*ft_vector_get(t_vector	*vec, int id);
void				ft_vector_delete(t_vector *vec, void *value);
void				ft_vector_remove(t_vector *vec, int id);
void				ft_vector_free(t_vector *vec);


#endif