#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *NODE;
void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d\t", root->info);
    inorder(root->rlink);
}

void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t", root->info);
}

NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    char direction[10];
    int i;
    temp = (NODE) malloc(sizeof(struct node));
    temp->info = item;
    temp->rlink = NULL;
    temp->llink = NULL;
    if (root == NULL)
        return temp;
    printf("\nEnter the direction where you want to insert:");
    scanf("%s", &direction);

    prev = NULL;
    cur = root;
    for (i = 0; i < strlen(direction); i++) {
        if (cur == NULL)
            break;
        prev = cur;
        if (direction[i] == 'L')
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (cur != NULL || i != strlen(direction)) {
        printf("Insertion not possible");
        free(temp);
        return root;
    }
    if (direction[i - 1] == 'L') {
        prev->llink = temp;
    } else {
        prev->rlink = temp;
    }
    return root;
}

int main()
{
    int n;
    NODE root;
    root = NULL;
    while (1) {
        printf
            ("\n1.INSERTION\n2.PRE-ORDER TRAVERSAL\n3.IN-ORDER TRAVERSAL\n4.POST-ORDER TRAVERSAL\n5.EXIT");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("\nEnter the element to be inserted");
                scanf("%d", &n);
                root = insert(n, root);
                break;
            case 2:
                printf("\nThe pre_order traversal is: ");
                preorder(root);
                break;
            case 3:
                printf("\nThe in_order traversal is: ");
                inorder(root);
                break;
            case 4:
                printf("\nThe post_order traversal is: ");
                postorder(root);
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
