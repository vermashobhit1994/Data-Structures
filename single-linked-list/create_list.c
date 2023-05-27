
#include "single_linked_list.h"

/*
   
  1 ->  2  -> 3 

 */






/**
 * \fn           - 
 * \brief        - 
 * \param[in1]   - 
 * \return       - 
 * note          - 
 */
RETURN_STATUS create_single_linked_list( S_List_Node** pHead, S_List_Node** pLast, const int item )
{
	RETURN_STATUS err_status = STATUS_SUCCESS;
	
	S_List_Node* pNewNode = calloc( 1, sizeof(S_List_Node));
	if(pNewNode)
	{
		//filling node details 
		pNewNode -> data = item;
		pNewNode -> link = NULL;
			
		//inserting only node 	
		if(*pHead == NULL)
		{
			(*pHead) = pNewNode;
			
		}			
		else
		{
			(*pLast) -> link = pNewNode;
		}
		*pLast = pNewNode;  
		
	}
	else
		err_status = STATUS_ALLOCATION_FAILED;
	return err_status ;
}



