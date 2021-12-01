#include <stdio.h>
#include <stdlib.h>
#include "linked_quene.c"

typedef int bst_dt;

typedef struct BST
{
    bst_dt data;
    struct BST *lchild;
    struct BST *rchild;
} bst_t;

static inline bst_t *__bst_create(bst_dt data)
{
    bst_t *node = (bst_t *)malloc(sizeof(bst_t));
    node->data = data;
    node->lchild = node->rchild = NULL;
    return node;
}

bst_t *bst_init(bst_dt data)
{
    return __bst_create(data);
}

/**
 * 将node插入到root节点中
 * root作为第一次判断时的根节点 递归调用
 * */
bst_t *bst_insert(bst_t *root, bst_t *node)
{
    if (root == NULL)
    {
        return node;
    }
    // 新节点小于root 放在root左侧
    if (node->data < root->data)
    {
        root->lchild = bst_insert(root->lchild, node);
    }
    else
    {
        root->rchild = bst_insert(root->rchild, node);
    }
    return root;
}

/**
 * 从root中删除data
 * root作为第一次判断时的root 递归调用
 * */
bst_t *bst_remove(bst_t *root, bst_dt data)
{
    if (root == NULL)
    {
        return NULL;
    }
    // data小于root 待删除的节点在root左侧
    if (data < root->data)
    {
        root->lchild = bst_remove(root->lchild, data);
    }
    //  data大于root 待删除的节点在root右侧
    else if (data > root->data)
    {
        root->rchild = bst_remove(root->rchild, data);
    }
    // 当前正好是待删除的节点
    else
    {
        bst_t *tmp;
        // 待删除节点还有左节点
        if (root->lchild != NULL)
        {
            // 先找到左子树中最大的节点即最右边的节点
            for (tmp = root->lchild; tmp->rchild != NULL; tmp = tmp->rchild)
                ;
            // 用最大节点替换待删除节点
            root->data = tmp->data;
            // 删除最右边的节点
            root->lchild = bst_remove(root->lchild, tmp->data);
        }
        // 待删除节点还有右节点
        else if (root->rchild != NULL)
        {
            // 先找到右子树中最小的节点即最左边的节点
            for (tmp = root->rchild; tmp->lchild != NULL; tmp = tmp->lchild)
                ;
            // 用最大节点替换待删除节点
            root->data = tmp->data;
            // 删除最右边的节点
            root->rchild = bst_remove(root->rchild, tmp->data);
        }
        // 待删除节点没有后继节点 直接删除
        else
        {
            free(root);
            return NULL;
        }
        return root;
    }
}