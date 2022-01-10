#include "stdio.h"
#include "stdlib.h"
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("  %d",root->data);
		inorder(root->right);
	}
}
// C function to search a given key in a given BST
struct node* search(struct node* root, int data)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == data)
       return root;

    // Key is greater than root's key
    if (root->data < data)
       return search(root->right, data);

    // Key is smaller than root's key
    return search(root->left, data);
}
/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;//10
}

struct node* deleteNode(struct node* root, int data) {
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (data < root->data)
        root->left = deleteNode(root->left, data);

        // If the key to be deleted
        // is greater than the root's
        // key, then it lies in right subtree
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

        // if key is same as root's key,
        // then This is the node
        // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node *temp =
                (root->right);

        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);


        return root;
    }
}
    int main()
    {
        struct node *root = NULL;
        int n, i, item, data;
        struct node *p, *q;
        printf("Enter the number of nodes to be insert: ");
        setbuf(stdout, 0);
        scanf("%d", &n);

        printf("\nPlease enter the numbers to be insert: ");
        setbuf(stdout, 0);
        for (i = 0; i < n; i++) {
            p = (struct node *) malloc(sizeof(struct node));//every node you have to take memo location
            scanf("%d", &item);
            p->data = item;
            p->left = NULL;
            p->right = NULL;

            if (i == 0) {
                root = p;
            } else {
                q = root;   // q is used to traverse the tree
                while (1) {
                    if (p->data > q->data) {
                        if (q->right == NULL) {
                            q->right = p;
                            break;
                        } else {
                            q = q->right;
                        }
                    } else {
                        if (q->left == NULL) {
                            q->left = p;
                            break;
                        } else {
                            q = q->left;
                        }

                    }
                }

            }
        }
        printf("\nBinary Search Tree nodes in Inorder Traversal: ");
        inorder(root);

        printf("\nPlease enter the numbers to be search: ");
        setbuf(stdout, 0);//for debugging purpose
        scanf("%d", &data);
        struct node *result = search(root, data);
        if (result == NULL) {
            printf("Element is not present in tree");
        } else {
            printf("Element is present in tree");
        }

        printf("\nPlease enter the numbers to be delete: ");
        setbuf(stdout, 0);//for debugging purpose
        scanf("%d", &data);
        printf("\nAfter Deletion\n");
        root = deleteNode(root, data);
        printf("Inorder traversal of the modified tree \n");
        inorder(root);

        printf("\n");
        return 0;
    }
//Implementaion of Binary Search Tree with C
