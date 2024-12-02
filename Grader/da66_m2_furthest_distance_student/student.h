#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &aux)
{
    // You MAY use this function
    if(n == NULL)
    {
        return 0;
    }
    int ls = 0 , rs = 0 ;
    if(n->left != NULL)
        ls = my_recur(n->left,aux) + 1;
    if(n->right != NULL)
        rs = my_recur(n->right,aux) + 1;
    aux = std::max(aux,ls+rs);
    return std::max(rs,ls);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance()
{
    // write your code here
    if (mSize == 0)
    {
        return -1;
    }
    if (mSize == 0)
    {
        return 0;
    }
    int ltd = 0;
    my_recur(mRoot,ltd);
    return ltd;
}

#endif
