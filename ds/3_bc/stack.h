//FILE: stack.h

//char stack
struct char_stack
{
	int top;
	char items[32];
};
void char_push(struct char_stack *, char);
char char_pop(struct char_stack *);


//int stack
struct int_stack
{
	int top;
	int items[32];
};
void int_push(struct int_stack *, int);
int int_pop(struct int_stack *);
