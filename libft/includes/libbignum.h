/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbignum.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:39:10 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 14:24:05 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBIGNUM_H
# define LIBBIGNUM_H

# include <stddef.h>
# include <stdlib.h>

/**
	* Custom data structure to handle whole numbers of arbitrary length
	*
	* @param	char* number - string form of value
	* @param	size_t alloc_size - size of memory allocated for 'number'
	* @param	size_t len - digit length of 'number'
	* @param	int sign - set to 1 if negative, 0 if positive
**/
typedef struct s_bignum
{
	char			*number;
	size_t			alloc_size;
	size_t			len;
	int				sign;
}					t_bignum;

/*
--------------------------------------------------------------------------------
	Contructors & Destructors
--------------------------------------------------------------------------------
*/

/**
	* Stores pasred 'number' into 'bignum' struct.
	* Error input will truncate to last valid digit, or 0.
	*
	* Must be matched with 'bignum_del' to properly free memory
	* @param 	number number represented as a string.
	* @returns 	An allocated pointer to struct 'bignum'.
**/
t_bignum			*bignum_init(char *number);

/**
	* Frees 'bignum' struct along with the data inside, and sets to 0.
	*
	* @param p	reference to a 'bignum' pointer
**/
void				bignum_del(t_bignum **p);

/*
--------------------------------------------------------------------------------
	Operators
--------------------------------------------------------------------------------
*/

/**
	* Adds a2 to a1.
	*
	* @param	a1 pointer to the first addend.
	* @param	a2 pointer to the second addend.
	* @returns	An allocated pointer to the sum.
**/
t_bignum			*bignum_add(t_bignum *a1, t_bignum *a2);

/**
	* Subtracts s from m.
	*
	* @param	m pointer to the minuend.
	* @param	s pointer to the subtrahend.
	* @returns	An allocated pointer to the difference.
**/
t_bignum			*bignum_minus(t_bignum *m, t_bignum *s);

/**
	* Multiplies m1 by m2.
	*
	* @param	m1 pointer to the multiplicand.
	* @param	m2 pointer to the multiplier.
	* @returns	An allocated pointer to the product.
**/
t_bignum			*bignum_multiply(t_bignum *m1, t_bignum *m2);

/**
	* Divides d1 by d2.
	*
	* @param	d1 pointer to the dividend.
	* @param	d2 pointer to the divisor.
	* @returns	An allocated pointer to the quotient.
**/
t_bignum			*bignum_divide(t_bignum *d1, t_bignum *d2);

/**
	* Finds the modulus after dividing d1 by d2.
	*
	* @param	d1 pointer to the dividend.
	* @param	d2 pointer to the divisor.
	* @returns	An allocated pointer to the modulus.
**/
t_bignum			*bignum_mod(t_bignum *d1, t_bignum *d2);

/*
--------------------------------------------------------------------------------
	Comparators
--------------------------------------------------------------------------------
*/

/**
	* Compares n1 to n2.
	*
	* @returns	0 if n1 is greater.
**/
int					bignum_gt(t_bignum *n1, t_bignum *n2);

/**
	* Compares n1 to n2.
	*
	* @returns	0 if n1 is lesser.
**/
int					bignum_lt(t_bignum *n1, t_bignum *n2);

/**
	* Compares n1 to n2.
	*
	* @returns	0 if n1 is equal to n2.
**/
int					bignum_eq(t_bignum *n1, t_bignum *n2);

/*
--------------------------------------------------------------------------------
	Utilities
--------------------------------------------------------------------------------
*/

/**
	* Removes excess of preceding zeros from given input.
	*
	* @returns	A pointer to the modified struct.
**/
t_bignum			*bignum_trunc(t_bignum *bignum);

/**
	* Swaps data of 'a' and 'b'.
**/
void				bignum_swap(t_bignum *a, t_bignum *b);

/**
	*  In place incrementation of bignum
	*
	* @param n bignum to increment
	* @return the same bignum with value +1
**/
t_bignum			*bignum_increment(t_bignum *n);

/**
	* In place decrementation of bignum
	*
	* @param n bignum to dencrement
	* @return the same bignum with value -1
**/
t_bignum			*bignum_decrement(t_bignum *n);

/**
	* Copys data from 'src' to 'dst'
	*
	* @param dst Number to be a copy
	* @param src Number to be coppied
	* @returns A pointer to 'dst'.
**/
t_bignum			*bignum_copy(t_bignum *dst, t_bignum *src);

/*
--------------------------------------------------------------------------------
	Helpers
--------------------------------------------------------------------------------
*/

/**
	* Helper Function for comparisons
**/
int					bignum_compare(t_bignum *n1, t_bignum *n2, int type);

/**
	* Helper Function for combining positives and negatives.
**/
t_bignum			*bignum_add_neg(t_bignum *n1, t_bignum *n2, \
									int type, int swap);

/**
	* Helper Function for finding the sum of 'bignum'
**/
char				do_sum(size_t *i, size_t *j, char *n1, char *n2);

/**
	* Helper Function for finding the difference of 'bignum'.
**/
char				do_dif(size_t *i, size_t *j, char *n1, char *n2);

/**
	* Helper Function for finding the quotient of 'bignum'.
**/
t_bignum			*do_quotient(t_bignum *dividend, t_bignum *divisor, \
								t_bignum *remainder, char *quotient);

/**
	* Helper Function for inititalizing a resulting string to use for bignum.
**/
void				init_result(char *result, size_t k, int sign);

/**
	* Helper Function for inititalizing the remainder to use for bignum_divide.
**/
t_bignum			*init_remainder(char *dividend, size_t size);

/**
	* Helper Function for carrying a digit to the next higher magnitude.
**/
void				carry(char *result, size_t k, int type);

#endif
