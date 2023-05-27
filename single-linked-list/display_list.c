

#include "single_linked_list.h"


RETURN_STATUS display_single_linked_list(const S_List_Node *pHead)
{
	RETURN_STATUS err_status = STATUS_SUCCESS;
	
	if ( pHead)
	{
		while(pHead)
		{
			//print -> only if more than 1 element 
			if(pHead -> link )
				printf("%d -> ", pHead -> data);
			else
				printf("%d  ", pHead -> data );

			//move the pointer to next node
			pHead = pHead -> link;
		}
		printf("\n\n");
	}
	else
		err_status = STATUS_EMPTY_LIST;
		
	return err_status;
} 
