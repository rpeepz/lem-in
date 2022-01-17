/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:53:54 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/12 12:17:41 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

# define START "##start"
# define END "##end"

/**
	* Edge data structure which connects nodes to eachother in the graph 
	*
	* @param	char* dest_id - identity of node that is being connected
	* @param	s_edge* next - pointer to an additional edge (if one exists)
**/
typedef struct 		s_edge
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
typedef struct		s_graph
{
	char			*node_id;
	t_point			location;
	t_edge			*edges;
	struct s_graph	*next;
}					t_graph;

/**
	* Nodes used within the queue data structure
	*
	* @param	t_graph* node - pointer to the node in the queue
	* @param	s_node* next - pointer to the next element in the queue
**/
typedef struct		s_node
{
	t_graph			*node;
	struct s_node	*next;
}					t_node;

/**
	* Queue data structure
	*
	* @param	t_node* fisrt - pointer to the first element in the queue
	* @param	t_node* last - pointer to the last element in the queue
**/
typedef struct		s_queue
{
	t_node			*first;
	t_node			*last;
}					t_queue;

/**
	* Program data structure to hold all necessary info to process the algorithm
	*
	* @param	int check_start - boolean trigger to indicate the starting node
	* @param	int check_end - boolean trigger to indicate the ending node
	* @param	size_t ants - the number of ants
	* @param	t_graph* adj_list - graph of nodes represented as adjacency list
	* @param	char* start_id - identity of the starting node
	* @param	char* end_id - identity of ending node
**/
typedef struct		s_lem_in
{
	int				check_start;
	int				check_end;
	size_t			ants;
	size_t			count_nodes;
	t_graph			*adj_list;
	t_queue			*queue;
	char			*start_id;
	char			*end_id;
	char			**visited;
	char			***prev;
	char			**path;
}					t_lem_in;


char				**split_line(char *s, char c);
int					create_graph(char *line, t_lem_in *lem_in);
void				add_edge(char *line, t_lem_in *lem_in);
int					validate(t_lem_in *lem_in);
void				graph_undirected(t_lem_in *lem_in);
void				find_path(t_lem_in *lem_in);
char				***path_matrix_init(size_t cells, size_t rows);
void				path_matrix_save(char ***path, char *neighbor, char *node);
void				path_matrix_reconstruct(t_lem_in *lem_in);
void				run_ants(t_lem_in *lem_in);

t_queue				*queue_init(void);
int 				queue_is_empty(t_queue *queue);
char 				*queue_peek(t_queue *queue);
void				enqueue(t_queue *queue, t_graph *node);
void				*dequeue(t_queue *queue);


#endif
