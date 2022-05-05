#include<stdio.h>
#include<stdlib.h>

typedef struct Btree{

int value;
struct Btree *left, *right;
}Btree;

Btree *insert(Btree *root, int value){

    if (root==NULL){
        Btree *new_node=(Btree*)malloc(sizeof(Btree));
        new_node->value=value;
        new_node->left=new_node->right =NULL;
        return new_node;
    }

    if (value<root->value){

        root->left =insert(root->left,value);
        }

        else if (value>root->value){
            root->right=insert(root->right,value);
        }
        else {

        }
        return root;

}

//destroying a binary tree

void release(Btree *root)
{

    if(root!=NULL){
        release(root->right);
        release(root->left);
        free(root);
    }
    }



//in order traversal

void inorder (Btree *root){
if (root!=NULL){

    inorder (root->left);
    printf("%d\n", root->value);
    inorder(root->right);
}
}

int numofnodes (Btree *root){
if (root==NULL)
    return 0;
else return numofnodes(root->left)+numofnodes(root->right)+1;

}


int sumofnodes (Btree *root){
if (root==NULL)
    return 0;
else return sumofnodes(root->left)+sumofnodes(root->right)+ root->value;
}

Btree* search(Btree* root, int what){
if (root!=NULL){
    if (root->value==what)
        return root;
if(root->value>what)
return search(root->left,what);
    if (root->value<what)
    return search(root->right,what);

}return NULL;
}
void print_smith(Contact *root) {
    if (root == NULL) return;

    print_smith(root->left);
    /* 5 = strlen("Smith") */
    if (strncmp("Smith", root->name, 5) == 0)
        printf("%s %s\n", root->name, root->phone);
    print_smith(root->right);
}

int height(Btree *root) {
    int left, right, max;

    if (root == NULL) return 0;    /* 1 */

    left  = height(root->left);    /* 2 */
    right = height(root->right);
    /* which side is higher? */
    max  = left > right ? left : right;  /* 3 */

    return max + 1;                  /* 4 */
}

int height(BinTree *root) {
    int left, right, max;

    if (root == NULL) return 0;    /* 1 */

    left  = height(root->left);    /* 2 */
    right = height(root->right);
    /* which side is higher? */
    max  = left > right ? left : right;  /* 3 */

    return max + 1;                  /* 4 */
}
bool equal(BinTree *first, BinTree *second) {
   if (first == NULL && second == NULL)  /* two empty trees are equal */
      return true;
   if (first != NULL && second == NULL)  /* empty vs. non-empty -> not equal */
      return false;
   if (first == NULL && second != NULL)  /* same here */
      return false;

   return first->data == second->data           /* the data is the same in the root */
       && equal(first->left, second->left)      /* and the left sub-tree is the same */
       && equal(first->right, second->right);   /* and the right sub-tree is the same */
}
int main(void){
    int sample[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    Btree *root=NULL;
    Btree *hit;

    for(int i=0;sample[i]>0;i++)
        root=insert(root, sample[i]);
    inorder(root);

    printf("Number of nodes:%d\n", numofnodes(root));
    printf("Sum of the values: %d\n", sumofnodes(root));

    hit=search(root,56);
    if(hit!=NULL)
        printf("Result of the search:%d\n", hit->value);

        printf("%d\n",height(root));
    release(root);
    return 0;
}




