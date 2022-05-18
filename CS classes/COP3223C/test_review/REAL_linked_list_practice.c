#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    double data;
    struct node_s *nextptr;
}node_t;

typedef struct node_x {
    double data;
    struct node_x * leftchild;
    struct node_x * rightchild;
}node_bst;

node_bst * createBSTnode(double data);
node_t * createNode(double data);
node_bst * insertBST(node_bst * root, double data);
node_t * insert(node_t * head, double data);
node_t * removeNode(node_t * head, double data);
void display(node_t * head);
void swap(node_t * node1, node_t * node2);
node_t * sort_linked_list(node_t * head);
int list_length(node_t * head);
void print_matches(node_t * head1, node_t * head2);
node_bst * convert_ll_to_bst(node_t * head);
node_t * reverse(node_t * head);
node_t * copyNode(node_t * node);
void inorder(node_bst * root);
void printLevel(node_bst * root, int level);
int height(node_bst * root);

int main (void)
{
    node_t * head1 = NULL;
    node_t * head2 = NULL;
    for (int i = 0; i < 5; i++)
    {
        double rand_num = (rand() % 100) + ((rand() % 100) / 100.0);
        double rand_num2 = (rand() % 100) + ((rand() % 100) / 100.0);
        //printf("%.2lf\n", rand_num);
        head1 = insert(head1, rand_num);
        head2 = insert(head2, rand_num2);
    }


    printf("List length of head1: %d\n", list_length(head1));
    printf("List length of head2: %d\n", list_length(head2));

    printf("Sorting linked lists!\n");
    head1 = sort_linked_list(head1);
    head2 = sort_linked_list(head2);
    printf("Sorted head1\n");
    display(head1);
    printf("Sorted head2\n");
    display(head2);
    printf("Reversing both linked lists!\n");
    head1 = reverse(head2);
    printf("Reversed head2\n");
    head2 = reverse(head2);

    printf("Displaying reversed head1\n");
    display(head1);
    printf("Displaying reversed head2\n");
    display(head2);

    printf("Sorting reversed-sorted lists\n");
    head1 = sort_linked_list(head1);
    printf("Displaying head1\n");
    display(head1);
    head2 = sort_linked_list(head2);
    printf("Displaying head2\n");
    display(head2);


    print_matches(head1, head2);

    printf("Attempting to convert first LL to BST\n");
    node_bst * new_head1 = convert_ll_to_bst(head1);
    printf("Displaying newly created BST!\n");
    inorder(new_head1);
    printf("Attempting to convert second LL to BST\n");

    node_bst * new_head2 = convert_ll_to_bst(head2);
    printf("Displaying newly created BST!\n");
    inorder(new_head2);

    int height_num1 = 0;
    height_num1 = height(new_head1);
    int height_num2 = 0;
    height_num2 = height(new_head2);
    printf("Height of BST1 is %d\n", height_num1);
    printf("Height of BST2 is %d\n", height_num2);

    printf("Displaying converted BST 1\n");
    for (int i = 1; i <= height_num1; i++)
    {
        printLevel(new_head1, i);
        printf("\n");
    }

    printf("Displaying converted BST 2\n");
    for (int i = 1; i <= height_num2; i++)
    {
        printLevel(new_head2, i);
        printf("\n");
    }


    return 0;
}

int height(node_bst * root)
{
    if (root == NULL)
        return 0;

    int left_height = height(root->leftchild);
    int right_height = height(root->rightchild);

    if (left_height > right_height)
        return (1 + left_height);
    else
        return (1 + right_height);

}

void printLevel(node_bst * root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printLevel(root->leftchild, level - 1);
        printLevel(root->rightchild, level - 1);
    }
}

node_t * copyNode(node_t * node)
{
    node_t * copied_node = (node_t *) malloc(sizeof(node_t) * 1);
    if(copied_node == NULL)
    {
        printf("Fake and gay\n");
        exit(69);
    }

    copied_node->nextptr = node->nextptr;
    copied_node->data = node->data;
    return copied_node;
}

node_t * reverse(node_t * head)
{
    node_t * top = copyNode(head);
    top->nextptr = NULL;
    node_t * temp = head->nextptr;
    while (temp != NULL)
    {
        node_t * temp2 = copyNode(temp);
        temp2->nextptr = top;
        temp = temp->nextptr;
        top = temp2;
    }
    return top;
}

void inorder(node_bst * root)
{
    if (root != NULL)
    {
        inorder(root->leftchild);
        inorder(root->rightchild);
        printf("%.2lf\n",root->data);
    }


}

node_bst * createBSTnode(double data)
{
    node_bst * new_node = (node_bst *) malloc(sizeof(node_bst) * 1);
    new_node->leftchild = NULL;
    new_node->rightchild = NULL;
    new_node->data = data;
    return new_node;
}

node_bst * insertBST(node_bst * root, double data)
{
    if (root == NULL)
        return createBSTnode(data);
    if (data < root->data)
        root->leftchild = insertBST(root->leftchild, data);
    else if (data > root->data)
        root->rightchild = insertBST(root->rightchild, data);
    else
        return root;
}

node_bst * convert_ll_to_bst(node_t * head)
{

    node_bst * root = NULL;
    node_t * temp = head;
    while (temp != NULL)
    {
        root = insertBST(root, temp->data);
        temp = temp->nextptr;
    }

    return root;

}

void print_matches(node_t * head1, node_t * head2)
{
    int length = list_length(head1);
    node_t * temp1 = head1;
    node_t * temp2 = head2;
    while(temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
            temp1 = temp1->nextptr;
        else if (temp1->data > temp2->data)
            temp2 = temp2->nextptr;
        else if (temp1->data == temp2->data)
        {
            printf("%.2lf, %.2lf\n", temp1->data, temp2->data);
            temp1 = temp1->nextptr;
            temp2 = temp2->nextptr;
        }
    }

}

int list_length(node_t * head)
{
    int count = 0;
    if (head->nextptr == NULL)
        return 1;
    node_t * temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->nextptr;
    }
    return count;
}

node_t * sort_linked_list(node_t * head)
{

    int length = list_length(head);
    node_t * temp = head;
    for (int i = 0; i < length; i++)
    {
        temp = head;
        while (temp->nextptr != NULL)
        {
            if (temp->data > temp->nextptr->data)
                swap(temp, temp->nextptr);
            temp = temp->nextptr;
        }
    }
    return head;
}

void swap(node_t * node1, node_t * node2)
{
    double temp_data = node1->data;
    node1->data = node2->data;
    node2->data = temp_data;
}

void display(node_t * head)
{

    node_t * temp = head;
    while (temp != NULL)
    {
        printf(" ---\n");
        printf("| %.2lf |\n", temp->data);
        printf(" ---\n");
        temp = temp->nextptr;
    }
}
node_t * removeNode(node_t * head, double data)
{
    if (head == NULL)
    {
        printf("Nothing to remove!\n");
        return NULL;
    }

    node_t * temp = head;
    if (temp->data == data)
    {
        free(temp);
        return NULL;
    }


    while (temp->nextptr != NULL)
    {
        if (temp->nextptr->data = data)
        {
            node_t * mega_temp = temp->nextptr;
            temp->nextptr = temp->nextptr->nextptr;
            free(mega_temp);
            return head;
        }
    }
    printf("Didn't find that node!\n");
    return head;


}

node_t * insert(node_t * head, double data)
{
    if (head == NULL)
    {
        printf("Empty list!\n");
        return createNode(data);
    }
    node_t * temp = head;
    while (temp->nextptr != NULL)
        temp = temp->nextptr;
    temp->nextptr = createNode(data);
    temp->nextptr->nextptr = NULL;
    return head;
}

node_t * createNode(double data)
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);
    if (new_node == NULL)
    {
        printf("UH OHHH IT'S NULL OMG\n");
        exit(1);

    }

    new_node->nextptr = NULL;
    new_node->data = data;
    return new_node;
}


