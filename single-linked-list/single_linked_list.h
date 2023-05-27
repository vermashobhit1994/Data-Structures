
#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__



#include <stdio.h>
#include <stdlib.h>
typedef enum
{
	STATUS_SUCCESS = -1,
	STATUS_ALLOCATION_FAILED = 0,
	STATUS_EMPTY_LIST,
	STATUS_INVALID_USER_INPUT,
	STATUS_BUFFER_OVERFLOW_ERROR
}RETURN_STATUS;



								

/* single linked list node structure declaration*/
typedef struct single_linked_list_node
{
	int data ;
	struct single_linked_list_node *link;
}S_List_Node;





RETURN_STATUS create_single_linked_list( S_List_Node** pHead, S_List_Node** pLast, const int item );

RETURN_STATUS display_single_linked_list(const S_List_Node *pHead);



#endif 



