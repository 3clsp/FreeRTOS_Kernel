## Issues

- croutine.c: error compiling
	- listGET_OWNER_OF_NEXT_ENTRY macro casts from void* to struct that depends on the caller. Not allowed to cast like that. 
- event_groups.c: error compiling
	- To Fix: Line 471, 686: passing void* to non _Ptr<void> typedef callback function
- list.c: compiles
	- struct xLIST_ITEM have a void* member
	- listGET_OWNER_OF_NEXT_ENTRY: Argument 1 is not necessarily a TCB_t *

- queue.c: compiles
	- Bounds for struct members needed?
	- Bounds given to array_ptr vaiable in `xQueueGenericCreate`.
	- void* in parameter of copy functions: Most likey of size QueueDefinition

- stream_buffer.c: compiles
	- void in function parameters: changed all void* to uint8_t array_ptr

- timers.c: compiles
	- Make all voids into proper types

## Pending

- tasks.c
	- Created temporary TCB_t to be passed into list_end_insert and some other funtions. This might not work properly everywhere.
