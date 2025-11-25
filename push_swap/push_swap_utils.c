void sa(t_point *stack_A)
{
    int temp;

    if (stack_A->size < 2)
        return;
    temp = stack_A->top->data;
    stack_A->top->data = stack_A->top->next->data;
    stack_A->top->next->data = temp;
}

void sb(t_point *stack_B)
{
    int temp;
    
    if (stack_B->size < 2)
        return;
    temp = stack_B->top->data;
    stack_B->top->data = stack_B->top->next->data;
    stack_B->top->next->data = temp;
}

void ss(t_point *stack_A, t_point *stack_B)
{
    sa(stack_A);
    sb(stack_B);
}

void pa(t_point *stack_A, t_point *stack_B)
{

}