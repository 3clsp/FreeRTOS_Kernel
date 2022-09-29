## Issues

- croutine.c
	- listGET_OWNER_OF_NEXT_ENTRY macro casts from void* to struct that depends on the caller. Not allowed to cast like that. 
- event_groups.c
	- To Fix: Line 471, 686
- list.c
	- struct xLIST_ITEM have a void* member
	- listGET_OWNER_OF_NEXT_ENTRY: Argument 1 is not necessarily a TCB_t *

- queue.c
	- Bounds for struct members needed?
	- Bounds given to array_ptr vaiable in `xQueueGenericCreate`.
	- void* in parameter of copy functions: Most likey of size QueueDefinition


## Pending

- timers.c
	- Type argument not accepted since callback function is member of a struct.
	- error: passing '_Ptr<void> const' to parameter of incompatible type '_Ptr<T>' (aka '_Ptr<(0, 0)>')
                    pxCallback->pxCallbackFunction( pxCallback->pvParameter1, pxCallback->ulParameter2 );  
- stream_buffer.c
	- Had to put memcpy and memset in unchecked region.
	- Issue when member of struct is array_ptr but it's size can't be inferred.
	- Added bounds for a variable manually after looking at how it is used. This is just a way to remove the error. Not a good way.
- tasks.c
	- Created temporary TCB_t to be passed into list_end_insert and some other funtions. This might not work properly everywhere.
