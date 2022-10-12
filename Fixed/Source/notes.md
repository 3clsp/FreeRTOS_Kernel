## Issues

- croutine.c: compiles
	- Nothing to fix

- event_groups.c: compiles
	- To Fix: Line 471, 686: passing void* to non _Ptr<void> typedef callback function
	- Casting to _Ptr<void> since external macros expect it to be void.

- list.c: compiles
	- struct xLIST_ITEM have a void* member
	- Added unchecked scope and assume bounds caste since there is cast from struct to struct of different size.

- queue.c: compiles
	- Bounds for struct members needed?
	- Bounds given to array_ptr vaiable in `xQueueGenericCreate`.
	- void* in parameter of copy functions: Most likey of size QueueDefinition

- stream_buffer.c: compiles
	- void in function parameters: changed all void* to uint8_t array_ptr

- timers.c: compiles
	- Make all voids into proper types

- tasks.c: compiles
	- Nothing to fix
