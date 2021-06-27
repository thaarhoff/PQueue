# PQueue
When using a queue, we want do push an item into it and do assume it will be at the end. And therefore the FIFO equilibrium applies.<br>
Once priority comes into the equation the assumption would be not FIFO, but higher priority items get serverd before lower priority ones.<br>
But what happens with items of same priority.

## std::priority_queue
In short: Does. Not. Care.<br>
If 10 items with different get pushed into the queue, the queue is sorted and pop'ing them will result in the expected order of items.<br>
However if these 10 items have the same priority, the implementation does not keep up to FIFO. And the last added item could be served first, second, last or whatever. There is also no option to enforce this.<br>
You can run the std_reference.cpp implementation for example [Link](http://cpp.sh/42elg)

## PQueue
I provided an implementation PQueue.cpp [Link](http://cpp.sh/72oyk2) which is somewhat efficent in terms of general approach, but you have to alter the code to represent you data you want to put into the queue.
