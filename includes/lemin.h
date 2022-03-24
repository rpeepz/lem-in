/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:53:54 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/04 13:03:21 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/includes/libft.h"

# define START "##start"
# define END "##end"

/**
	* Edge data structure which connects nodes to eachother in the graph 
	*
	* @param	char* dest_id - identity of node that is being connected
	* @param	s_edge* next - pointer to an additional edge (if one exists)
**/
typedef struct s_edge
{
	char			*dest_id;
	struct s_edge	*next;
}					t_edge;

/**
	* Graph data structure as an adjacency list
	*
	* @param	char* node_id - identifier of the node
	* @param	t_point location - where in 2d space the node is located
	* @param	t_edge* edges - pointer to connecting edges of the node
	* @param	s_graph* next - pointer to the next node of the adjacency list
**/
typedef struct s_graph
{
	char			*node_id;
	t_point			location;
	t_edge			*edges;
	struct s_graph	*next;
}					t_graph;

/**
	* Program data structure to hold all necessary info to process the algorithm
	*
	* @param	int check_start - boolean trigger to indicate the starting node
	* @param	int check_end - boolean trigger to indicate the ending node
	* @param	int ants - the number of ants
	* @param	int count_nodes - the number of nodes in the graph
	* @param	int count_paths - the number of possible paths
	* @param	t_graph* adj_list - graph of nodes represented as adjacency list
	* @param	char* file - map data
	* @param	char* start_id - identity of the starting node
	* @param	char* end_id - identity of ending node
	* @param	char** visited - array of visited node identities
	* @param	char*** prev - array of identities of the followed paths
	* @param	char*** path - array of shortest paths
**/
typedef struct s_lem_in
{
	int			check_start;
	int			check_end;
	int			ants;
	int			count_nodes;
	int			count_paths;
	t_graph		*adj_list;
	char		*file;
	char		*start_id;
	char		*end_id;
	char		**visited;
	char		***prev;
	char		***path;
}				t_lem_in;

typedef struct s_solution
{
	int			**path_info;
	int			**farm;
	int			n;
}				t_solution;

char				**split_line(char *s, char c);
int					reverse_array(char **array, int n);
int					create_graph(char *line, t_lem_in *lem_in);
void				add_edge(char *line, t_lem_in *lem_in);
int					validate(t_lem_in *lem_in);
void				graph_undirected(t_lem_in *lem_in);
void				find_path(t_lem_in *lem_in);
void				unvisit_neighbors(t_lem_in *lem_in, int k);
void				run_ants(t_lem_in *lem_in);
int					**set_path_info(char ***path, int n);
int					set_ants_in_path(int **path_info, t_lem_in *lem_in);
void				print_file(char *s);
int					continue_movement(int **farm, int n);
void				print_movement(int a, char *s);

char				***path_matrix_init(int cells, int rows);
void				path_matrix_save(char ***path, char *neighbor, char *node);
void				path_matrix_reconstruct(t_lem_in *lem_in, int k);
void				path_matrix_destroy(char ***path, int cells);

t_queue				*queue_init(void);
int					queue_is_empty(t_queue *queue);
void				*queue_peek(t_queue *queue);
void				enqueue(t_queue *queue, void *content);
void				*dequeue(t_queue *queue);

#endif
