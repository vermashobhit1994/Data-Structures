/* Program to count the number of times an element repeat in single linked list */

#include "single_linked_list.h"

RETURN_STATUS frequency_item_single_linked_list(const S_List_Node *pHead, const int searchItem, int* freqSearchItem)
{
	RETURN_STATUS err_status = STATUS_SUCCESS;
	
	unsigned int countItem = 0;
	
	if(pHead)
	{
		while(pHead)
		{
			if(pHead -> data == searchItem)
			countItem++;
			pHead = pHead -> link;
		}
		
		*freqSearchItem = countItem;
		
	}
	else
		err_status = STATUS_EMPTY_LIST;
	return err_status;
}