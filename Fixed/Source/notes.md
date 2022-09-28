## Done

- croutine.c
- event_groups.c
- list.c

## Kind of done
- queue.c
	- Had to put memcpy in Unchecked region
	- Moved a variable decalration to after to another variable declaration so that the second one can be used as bounds for the first one in Funtion `xQueueGenericCreate`.

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

## Pending
- tasks.c
