
#include "mutex.h"
#include "interrupt.h"
#include "process.h"

void mutex_lock(struct mutex *m)
{
	interrupt_block();
	while(m->locked) {
		process_wait(&m->waitqueue);
		interrupt_block();
	}
	m->locked = 1;
	interrupt_unblock();
}

void mutex_unlock(struct mutex *m)
{
	interrupt_block();
	m->locked = 0;
	process_wakeup(&m->waitqueue);
	interrupt_unblock();
}
