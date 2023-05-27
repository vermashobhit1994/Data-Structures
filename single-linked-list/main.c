/* Program to do various operations on single linked list.



*/




#include "single_linked_list.h"


char* ErrorMsg[100] = { "dynamic memory allocation failed" ,
                        "single linked list is empty",
					    "invalid user input ",
					    "user buffer out of bound "
						};	

void create_menu (void)
{
	
	fputs("\n\n1. CREATE SINGLE LINKED LIST\n"
	        "2. DISPLAY SINGLE LINKED LIST\n"
			"3. FREQUENCY OF ITEM \n"
			"4. FIND LARGEST AND SMALLEST ITEM\n"
			"5. EXIT\n\n", stdout);
}


#define BUF_SIZE (10)

char user_buffer[BUF_SIZE] = {0};
	
RETURN_STATUS input_data(int* pnum )
{
	RETURN_STATUS err_status = STATUS_SUCCESS;
	
	
	
	int user_buffer_len = sizeof(user_buffer)/ sizeof(user_buffer[0]);
	
	int i = 0;
	
	//input data and store into buffer

	char ch = 0;
	while( (ch = getchar() ) )   
	{
		if(ch == '\n' || ch == EOF)
			break;
		
		user_buffer[i++] = ch;
	}
	
	
	
	if (i < user_buffer_len)
	{
		user_buffer[i] = '\0';
	
		i=0;
		
		//giving initial value 
		*pnum = 0;
		//check if input string contains continuous numbers only 
		
		while( user_buffer[i] != '\0' && user_buffer[i] >= '0' &&  user_buffer[i] <= '9')
		{
			//convert character to numbers
			*pnum = *pnum * 10 + (user_buffer[i] - '0');
			i++;
		}
		
		//check if string contains other than numbers 
		if ( user_buffer[i] != '\0')
			err_status = STATUS_INVALID_USER_INPUT;
		
	}		
	else
		err_status = STATUS_BUFFER_OVERFLOW_ERROR;
	

	return err_status;
}


void clear_buffer(void)
{
	
}

void test_case_1(void)
{
	S_List_Node* pHead = NULL;
	S_List_Node* pLast = NULL;
	
	if ( create_single_linked_list(&pHead, &pLast, 12) == STATUS_SUCCESS)
	{
		if ( create_single_linked_list(&pHead, &pLast, 13) == STATUS_SUCCESS )
			display_single_linked_list(pHead);
	}
	
	
	
}

int main()
{
	
	S_List_Node* pHead = NULL;
	S_List_Node* pLast = NULL;
	
	int choice = 0;
		
	int item = 0;
	int freq_item = 0;
	
	while(1)
	{
	
		RETURN_STATUS err_status = STATUS_SUCCESS;
		
		create_menu();
		
		if ( (err_status = input_data(&choice)) == STATUS_SUCCESS)
		{
			
			switch(choice)
			{
				case 1:
					printf("Enter the item :    ");
					if ( (err_status = input_data(&item)) == STATUS_SUCCESS)
					{
						if ( (err_status = create_single_linked_list(&pHead, &pLast, item)) != STATUS_SUCCESS)
							printf("%s\n", ErrorMsg[err_status]);
					}
					else
						printf("%s\n", ErrorMsg[err_status]);
					break;
				case 2:
					if ( (err_status = display_single_linked_list(pHead)) != STATUS_SUCCESS)
						printf("%s\n", ErrorMsg[err_status]);
					break;
				case 3:
					printf("enter item to be find : ");
					if ( (err_status = input_data(&item)) == STATUS_SUCCESS)
					{
						if ((err_status = frequency_item_single_linked_list(pHead, item, &freq_item)) != STATUS_SUCCESS)
							printf("%s\n", ErrorMsg[err_status]);
						else
							printf("%d element occur %d times \n", item, freq_item);
					
					}
					break;
				case 4:
					break;
				case 5:
					exit(0);
				default:
					printf("invalid choice \n");
					
			}
		}
		else
			printf("%s\n", ErrorMsg[err_status]);
	}
	
	
	
}
