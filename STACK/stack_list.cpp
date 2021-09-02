#include <iostream>
using namespace std;
class StackNode
{
public:
    int data;
    StackNode *next;
};
StackNode *newNode(int data)
{
    StackNode *node = new StackNode();
    node->data = data;
    node->next = NULL;
    return node;
}
int isEmpty(StackNode *root)
{
    return !root;
}
void push(StackNode **root, int data)
{
    StackNode *node = newNode(data);
    node->next = *root;
    *root = node;
    cout << data << " pushed to stack\n";
}
int pop(StackNode **root)
{
    if (isEmpty(*root))
        return 0;
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    delete temp;
    return popped;
}
int peek(StackNode *root)
{
    if (isEmpty(root))
        return 0;
    return root->data;
}
int main()
{
    StackNode *root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    cout << pop(&root) << " popped from Stack\n";
    cout << " Top element is " << peek(root) << endl;
    cout << "Element present in Stack : ";
    while (!isEmpty(root))
    {
        cout <<peek(root)<<" ";
        pop(&root);
    }
    return 0;
}