/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:16:32 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/22 13:21:20 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void swap_str_ptrs(char **arg1, char **arg2)
{
    char *tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

void qsort_tab(char **list, int len, int (*f)(const char *, const char *))
{
    int i;
	int pvt;

    if (len <= 1)
        return;
	pvt = 0;
    // swap a randomly selected value to the last node
    swap_str_ptrs(list+((int)rand() % len), list+len-1);

    // reset the pivot index to zero, then scan
    for (i=0;i<len-1;++i)
    {
        if (f(list[i], list[len-1]) < 0)
            swap_str_ptrs(list+i, list+pvt++);
    }

    // move the pivot value into its place
    swap_str_ptrs(list+pvt, list+len-1);

    // and invoke on the subsequences. does NOT include the pivot-slot
    qsort_tab(list, pvt++, f);
    qsort_tab(list+pvt, len - pvt, f);
}