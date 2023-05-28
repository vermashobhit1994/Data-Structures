
#include "single_linked_list.h"
/*

 1 -> 2 -> 3 -> 4 -> 5
 
 s             L
 1             2
 1             3
 1             4
 1             5

*/

RETURN_STATUS find_largest_smallest_single_linked_list(const S_List_Node *pHead, int *pLargest, int* pSmallest)
{
	RETURN_STATUS err_status = STATUS_SUCCESS;
	if(pHead)
	{
		*pLargest = pHead -> data;
		*pSmallest = pHead -> data ;
		while(pHead)
		{
			if(pHead -> data  > *pLargest)
				*pLargest = pHead -> data ;
			else if (pHead -> data < *pSmallest)
				*pSmallest = pHead -> data;
			pHead = pHead -> link;
		}
	}
	else
		err_status = STATUS_EMPTY_LIST;
	return err_status;
}
