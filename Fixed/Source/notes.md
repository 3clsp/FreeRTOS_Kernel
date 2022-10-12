## Issues

- All:
	- Casting to _Ptr<void> since external macros expect it to be void.

- croutine.c: compiles
	- Unchecked scope with assume bounds since cast from void to a struct type is done.

- event_groups.c: compiles
	- To Fix: Line 471, 686: Unchecked passing of callback function as argument.

- list.c: compiles
	- struct xLIST_ITEM have a void* member
	- Added unchecked scope and assume bounds caste since there is cast from struct to struct of different size.

- queue.c: compiles
	- Need bounds for members of `QueuePointers_t`?
	- void* in parameter of copy function changed to uint8_t since it is used in memcpy and this change won't cause issues.
	- Memcpy with arguments of unknown bounds in unchecked scope.

- stream_buffer.c: compiles
	- Memcpy in unchecked scope.

- timers.c: compiles
	- void * for argument of callback function. 
	- timerId of struct `tmrTimerControl` is passed from outside and is void *.
	- Unchecked scope with assume bounds since cast from void to a struct type is done.

- tasks.c: compiles
	- Unchecked scope with assume bounds since cast from void to a struct type is done.
	- Assume bounds for strings where size is unknown.
	- void* for argument passed onto callback functions.
