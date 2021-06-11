
/*-------DEBUT PUSH_SWAP.H-----*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

# define OK 0
# define KO -1
# define STOP 1
			
typedef struct 	s_stack
{
    int				data;
    struct s_stack	*next;
}              	t_stack;

typedef struct	s_all
{
	t_stack 		stack_a;
	t_stack 		stack_b;
	t_stack 		instruction;
	int				size;
}				t_all;

			


/*-------FIN PUSH_SWAP.H-----*/
//____________________________________________________________________//






//____________________________________________________________________//

/*-------DEBUT DECLARATION-----*/

		//parsing//
int	ft_isdigit(int c);
size_t	ft_strlen(const char *str);
void	ft_putstr(char const *s);
void	error(int err);
int		ft_isblank(char c);
double	ft_atof(const char *str);
void	check_args(int argc, char **argv);
int	ft_isdigit(int c);

		//init struct//
t_stack *empty_stack(void);
int	is_empty_stack(t_stack *stack);
t_stack	*add_at(t_stack *stack, int data, int pos);
static t_stack	*create_cell(int data);
t_stack	*free_stack(t_stack *stack);
void	print_stack_a(t_stack *stack);
void	print_stack_b(t_stack *stack);
void init_2_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
t_stack *init_stack_a(t_stack *stack_a, int argc, char **argv);
int check_sort(t_stack *stack_a, t_stack *stack_b);
int size_stack(t_stack *stack_a);
t_stack *push_swap(t_stack *stack_a,t_stack * stack_b,t_stack * instruction, int argc);

/*-------FIN DECLARATION-----*/
//____________________________________________________________________//







//____________________________________________________________________//

/*-------DEBUT PUSH_SWAP-----*/
t_stack *push_swap(t_stack *stack_a,t_stack * stack_b,t_stack * instruction, int argc)
{
	int check;

	stack_b = empty_stack();
	instruction = empty_stack();

	check = size_stack(stack_a);
		if(check <= 5 && check == (argc - 1))
			printf("\nSMALL_TRI \n");
		else if(check > 5 && check <= 100 && check == (argc - 1))
			printf("\nMIDDLE_TRI \n");
		else if(check > 100 && check == (argc - 1))
			printf("\nBIG_TRI \n");
		else
			printf("\nERROR PAS DE TRI !!\n");
		return(instruction);
}



/*-------FIN PUSH_SWAP-----*/
//____________________________________________________________________//







//____________________________________________________________________//

/*-------DEBUT CHECK_SORT-----*/


int check_sort(t_stack *stack_a, t_stack *stack_b)
{
	int temp;

	if(stack_b != NULL)
	{
		printf("STACK B NON NULL !!\n");
		return (KO);
	}
	else
	{
		printf("STACK A READY TO SORT\n");
		while(stack_a)
		{
			temp = stack_a->data;
			while(stack_a)
			{
				if(temp > stack_a->data)
				{
					printf("STACK A NON TRIEE\n");
					return(STOP);
				}
				stack_a = stack_a->next;
			}
		}
	}	
	printf("STACK TRIEE AUCUN SOUCIS \n");
	return(OK);
}



/*-------FIN CHECK_SORT-----*/
//____________________________________________________________________//







//____________________________________________________________________//
/*-------DEBUT SIZE_STACK-----*/

int size_stack(t_stack *stack_a)
{
	int i;

	i = 0;
	while(stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return(i);
}

/*-------FIN SIZE_STACK-----*/
//____________________________________________________________________//








//____________________________________________________________________//
/*-------DEBUT INIT_STRUCTURE-----*/


	static t_stack	*create_cell(int data)
	{
		t_stack *stack = malloc(sizeof(t_stack));
		if(!stack)
			return(NULL);
		stack->data = data;
		stack->next = NULL;

		return (stack);
	}


	t_stack *empty_stack(void)
	{
		return NULL;
	};
	
	int	is_empty_stack(t_stack *stack)
	{
		return stack == NULL;
	}

	t_stack	*add_at(t_stack *stack, int data, int pos)
	{
		t_stack *stack_previous = stack;
		t_stack *stack_current = stack;
		int i;
		t_stack	*cell = create_cell(data);
		if(is_empty_stack(stack))
			return cell;
		if(pos == 0)
		{
			cell->next = stack;
			return cell;
		}
		i = 0;
		while(i < pos)
		{
			i++;
			stack_previous = stack_current;
			stack_current = stack_current->next;			
		}
		stack_previous->next = cell;
		cell->next = stack_current;

		return(stack);
	}

	t_stack	*free_stack(t_stack *stack)
	{
		t_stack *temp = NULL;
		while(stack)
		{
			temp = stack->next;
			free(stack);
			stack = temp;
		}
		return(stack);
	}

	void	print_stack_a(t_stack *stack)
	{
		int i;
		i = 0;
		while(stack)
		{
			printf("Stack A[%d] = [%d]\n", i, stack->data);
			stack = stack->next;
			i++;
		}
		printf("FIN DE STACK - A \n");

	}

		void	print_stack_b(t_stack *stack)
	{
		int i;
		i = 0;
		while(stack)
		{
			printf("Stack B[%d] = [%d]\n",i, stack->data);
			stack = stack->next;
			i++;
			
		}
		printf("FIN DE STACK - B \n");

	}


	void init_2_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
	{
		int i;
		stack_a = empty_stack();
		stack_b = empty_stack();
		i = 0;
		while(++i < argc)
		{
			if(i <= 3)
				stack_a = add_at(stack_a, atoi(argv[i]), 0);
			if(i > 3)
				stack_b = add_at(stack_b, atoi(argv[i]), 0);
		}


		printf("STACK A -> \n");
		print_stack_a(stack_a);
		printf("\nSTACK B -> \n");
		print_stack_b(stack_b);
		check_sort(stack_a, stack_b);

		stack_a = free_stack(stack_a);
		printf("\nFREE STACK A -> ");
		stack_b = free_stack(stack_b);
		print_stack_a(stack_a);
		printf("\nFREE STACK B -> ");
		print_stack_b(stack_b);

	}

	t_stack *init_stack_a(t_stack *stack_a, int argc, char **argv)
	{
		int i;
		stack_a = empty_stack();
		i = 0;
		while(++i < argc)
				stack_a = add_at(stack_a, atoi(argv[i]), 0);
		return(stack_a);

	}




/*-------FIN INIT_STRUCTURE-----*/
//____________________________________________________________________//







//____________________________________________________________________//
/*-------DEBUT PARSING-----*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

void	error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	return ;
}


int		ft_isblank(char c)
{
	return ((c == ' ' || c == '\n' || c == '\v' ||
			c == '\t' || c == '\r' || c == '\f'));
}


double	ft_atof(const char *str)
{
	int		sign;
	double	i;
	double	value;

	i = 1;
	sign = 0;
	value = 0;
	while (ft_isblank(*str))
		str++;
	*str == '-' ? sign = 1 : 0;
	*str == '-' || *str == '+' ? str++ : 0;
	while ('0' <= *str && *str <= '9')
		value = value * 10 + (*str++ - '0');
	if (*str == '.' && (str++))
		while ('0' <= *str && *str <= '9')
			value += (*str++ - '0') / (i *= 10);
	return (sign == 1 && value > 0 ? -value : value);
}


void	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	double	val;

	i = 0;
	j = 0;
	
	while (++i < argc)
	{
		k = -1;
		while (argv[i][++k])
			error(!(!ft_isdigit(argv[i][k]) && argv[i][k] != '-'));
		j = i;
		val = ft_atof(argv[i]);
		while (++j < argc)
			error(!(val == ft_atof(argv[j])));
		error(!(val > 2147483647 || val < -2147483648));
	}
}

/*-------FIN PARSING-----*/
//____________________________________________________________________//









int main(int argc, char **argv)
{

	int i;
	int check;
	//t_all *all_datas;


	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *instruction;
	

	if(argc == 1)
		return(0);
		//------PARSING------//
	//check_args(argc, argv);
		
		
		//------INIT_STRUCTURE-------//
	//init_2_stack(stack_a, stack_b, argc, argv);
	stack_a = init_stack_a(stack_a, argc, argv);
		
		
		//TEST
	print_stack_a(stack_a);
		
		
		//------CHECK_SORT-------//
	check = check_sort(stack_a, stack_b);

		//------PUSH_SWAP-------//
	if (check == OK)
		printf("\n FIIIIINI DE TRI3R ON ARRETE\n");
	else if(check == KO)
		printf("\nERROR STACK B ENCOMBRE \n");
	else
		instruction = push_swap(stack_a, stack_b, instruction, argc);
		
		
		//------PRINT_INSTRUCTION -------//
			// EN CONSTRUCTION
		//------EXIT_FREE_END-------//
			// EN CONSTRUCTION
			


			//TEST
	stack_a = free_stack(stack_a);
	printf("\nFREE STACK A -> ");
	print_stack_a(stack_a);

	return 0;
}