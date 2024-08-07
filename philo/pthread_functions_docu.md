# Arguments

- `number_of_philosophers`
- `time_to_die`
- `time_to_eat`
- `time_to_sleep`
- `[number_of_times_each_philosopher_must_eat]`

# Authorized Functions:

- `memset`, `printf`, `malloc`, `free`, `write`
- `usleep`
- `gettimeofday`
- `pthread_create`
- `pthread_detach`
- `pthread_join`
- `pthread_mutex_init`
- `pthread_mutex_destroy`
- `pthread_mutex_lock`
- `pthread_mutex_unlock`

## int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void*), void *restrict arg);

If successful, the `pthread_create()` function shall return zero; otherwise, an error number shall be returned to indicate the error.

The `pthread_create()` function creates a new thread within a process, using the attributes specified by `attr`. If `attr` is `NULL`, default attributes are used. The thread's attributes will not be affected if `attr` is modified subsequently. Upon successful completion, `pthread_create()` stores the ID of the created thread in the location referenced by `thread`.

The thread is created executing `start_routine` with `arg` as its only argument. If `start_routine` returns, `pthread_exit()` is implicitly called with the return value of `start_routine` as the exit status. The new thread's signal is initialized by inheriting the creator thread's signal mask and having an empty pending signal set.

The specific locale and alternate stack are not inherited. The floating-point environment is inherited from the creator thread. If `pthread_create()` fails, no new thread is created, and the content of the location referenced by `thread` is undefined.

If `_POSIX_THREAD_CPUTIME` is defined, the new thread will have an accessible CPU time clock, initially set to zero. The behavior is undefined if `attr` does not refer to an initialized thread attribute object.

## int pthread_join(pthread_t thread, void **retval);

The `pthread_join()` function waits for the thread specified by `thread` to terminate. If that thread has already terminated, `pthread_join()` returns immediately. The thread specified by `thread` must be joinable.

If `retval` is not `NULL`, `pthread_join()` copies the exit status of the target thread (i.e., the value that the target thread supplied to `pthread_exit(3)`) into the location pointed to by `retval`. If the target thread was canceled, `PTHREAD_CANCELED` is placed in the location pointed to by `retval`.

If multiple threads simultaneously try to join with the same thread, the results are undefined. If the thread calling `pthread_join()` is canceled, the target thread will remain joinable (i.e., it will not be detached).

RETURN VALUE
On success, `pthread_join()` returns 0; on error, it returns an error number.

ERRORS
- `EDEADLK` - A deadlock was detected (e.g., two threads tried to join with each other); or `thread` specifies the calling thread.
- `EINVAL` - `thread` is not a joinable thread.
- `EINVAL` - Another thread is already waiting to join with this thread.
- `ESRCH` - No thread with the ID `thread` could be found.

## int pthread_detach(pthread_t thread);

The `pthread_detach()` function indicates to the implementation that the storage for the thread `thread` can be reclaimed when that thread terminates. If the thread has not terminated, `pthread_detach()` does not cause it to terminate.

The behavior is undefined if the value specified by the `thread` argument to `pthread_detach()` does not refer to a joinable thread.

If the call succeeds, `pthread_detach()` shall return 0; otherwise, an error number shall be returned to indicate the error.

## int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);

`pthread_mutex_init` — destroy and initialize a mutex

## int pthread_mutex_destroy(pthread_mutex_t *mutex);

Upon successful completion, these functions shall return zero; otherwise, an error number shall be returned to indicate the error.

The `pthread_spin_destroy()` function shall destroy the spin lock referenced by `lock` and release any resources used by the lock. The effect of subsequent use of the lock is undefined until the lock is reinitialized by another call to `pthread_spin_init()`. The results are undefined if `pthread_spin_destroy()` is called when a thread holds the lock, or if this function is called with an uninitialized thread spin lock.

## int pthread_mutex_lock(pthread_mutex_t *mutex);

The mutex object referenced by `mutex` shall be locked by a call to `pthread_mutex_lock()` that returns zero or `[EOWNERDEAD]`. 

If the mutex is already locked by another thread, the calling thread shall block until the mutex becomes available. This operation shall return with the mutex object referenced by `mutex` in the locked state with the calling thread as its owner. If a thread attempts to relock a mutex that it has already locked, `pthread_mutex_lock()` shall behave as described in the Relock column of the following table. If a thread attempts to unlock a mutex that it has not locked or a mutex which is unlocked, `pthread_mutex_unlock()` shall behave as described in the Unlock When Not Owner column of the following table.

The mutex object referenced by `mutex` shall be locked by a call to `pthread_mutex_lock()` that returns zero or `[EOWNERDEAD]`.  If the mutex is already locked by another thread, the calling thread shall block until the mutex becomes available. This operation shall return with the mutex object referenced by `mutex` in the locked state with the calling thread as its owner. If a thread attempts to relock a mutex that it has already locked, `pthread_mutex_lock()` shall behave as described in the Relock column of the following table. If a thread attempts to unlock a mutex that it has not locked or a mutex which is unlocked, `pthread_mutex_unlock()` shall behave as described in the Unlock When Not Owner column of the following table.

```
 ┌────────────┬────────────┬────────────────┬───────────────────────┐
 │ Mutex Type │ Robustness │     Relock     │ Unlock When Not Owner │
 ├────────────┼────────────┼────────────────┼───────────────────────┤
 │ NORMAL     │ non-robust │ deadlock       │ undefined behavior    │
 ├────────────┼────────────┼────────────────┼───────────────────────┤
 │ NORMAL     │ robust     │ deadlock       │ error returned        │
 ├────────────┼────────────┼────────────────┼───────────────────────┤
 │ ERRORCHECK │ either     │ error returned │ error returned        │
 ├────────────┼────────────┼────────────────┼───────────────────────┤
 │ RECURSIVE  │ either     │ recursive      │ error returned        │
 │            │            │ (see below)    │                       │
 ├────────────┼────────────┼────────────────┼───────────────────────┤
 │ DEFAULT    │ non-robust │ undefined      │ undefined behavior†   │
 │            │            │ behavior†      │                       │
 ├────────────┼────────────┼────────────────┼───────────────────────┤
 │ DEFAULT    │ robust     │ undefined      │ error returned        │
 │            │            │ behavior†      │                       │
 └────────────┴────────────┴────────────────┴───────────────────────┘
```

† If the mutex type is `PTHREAD_MUTEX_DEFAULT`, the behavior of `pthread_mutex_lock()` may correspond to one of the three other standard mutex types as described in the table above. If it does not correspond to one of those three, the behavior is undefined for the cases marked †.

Where the table indicates recursive behavior, the mutex shall maintain the concept of a lock count. When a thread successfully acquires a mutex for the first time, the lock count shall be set to one. Every time a thread relocks this mutex, the lock count shall be incremented by one. Each time the thread unlocks the mutex, the lock count shall be decremented by one. When the lock count reaches zero, the mutex shall become available for other threads to acquire.

The `pthread_mutex_trylock()` function shall be equivalent to `pthread_mutex_lock()`, except that if the mutex object referenced by `mutex` is currently locked (by any thread, including the current thread), the call shall return immediately. If the mutex type is `PTHREAD_MUTEX_RECURSIVE` and the mutex is currently owned by the calling thread, the mutex lock count shall be incremented by one and the `pthread_mutex_trylock()` function shall immediately return success.

The `pthread_mutex_unlock()` function shall release the mutex object referenced by `mutex`.  The manner in which a mutex is released is dependent upon the mutex's type attribute. If there are threads blocked on the mutex object referenced by `mutex` when `pthread_mutex_unlock()` is called, resulting in the mutex becoming available, the scheduling policy shall determine which thread shall acquire the mutex.

(In the case of `PTHREAD_MUTEX_RECURSIVE` mutexes, the mutex shall become available when the count reaches zero and the calling thread no longer has any locks on this mutex.)

If a signal is delivered to a thread waiting for a mutex, upon return from the signal handler the thread shall resume waiting for the mutex as if it was not interrupted.

If `mutex` is a robust mutex and the process containing the owning

 thread terminated while holding the mutex lock, a call to `pthread_mutex_lock()` shall return the error value `[EOWNERDEAD]`. If `mutex` is a robust mutex and the owning thread terminated while holding the mutex lock, a call to `pthread_mutex_lock()` may return the error value `[EOWNERDEAD]` even if the process in which the owning thread resides has not terminated. In these cases, the mutex is locked by the thread but the state it protects is marked as inconsistent. The application should ensure that the state is made consistent for reuse and when that is complete call `pthread_mutex_consistent()`.  If the application is unable to recover the state, it should unlock the mutex without a prior call to `pthread_mutex_consistent()`, after which the mutex is marked permanently unusable.

If `mutex` does not refer to an initialized mutex object, the behavior of `pthread_mutex_lock()`, `pthread_mutex_trylock()`, and `pthread_mutex_unlock()` is undefined.

RETURN VALUE
If successful, the `pthread_mutex_lock()`, `pthread_mutex_trylock()`, and `pthread_mutex_unlock()` functions shall return zero; otherwise, an error number shall be returned to indicate the error.

ERRORS
The `pthread_mutex_lock()` and `pthread_mutex_trylock()` functions shall fail if:

- `EAGAIN` - The mutex could not be acquired because the maximum number of recursive locks for `mutex` has been exceeded.
- `EINVAL` - The mutex was created with the protocol attribute having the value `PTHREAD_PRIO_PROTECT` and the calling thread's priority is higher than the mutex's current priority ceiling.
- `ENOTRECOVERABLE` - The state protected by the mutex is not recoverable.
- `EOWNERDEAD` - The mutex is a robust mutex and the process containing the previous owning thread terminated while holding the mutex lock. The mutex lock shall be acquired by the calling thread and it is up to the new owner to make the state consistent.

The `pthread_mutex_lock()` function shall fail if:

- `EDEADLK` - The mutex type is `PTHREAD_MUTEX_ERRORCHECK` and the current thread already owns the mutex.

The `pthread_mutex_trylock()` function shall fail if:

- `EBUSY` - The mutex could not be acquired because it was already locked.

The `pthread_mutex_unlock()` function shall fail if:

- `EPERM` - The mutex type is `PTHREAD_MUTEX_ERRORCHECK` or `PTHREAD_MUTEX_RECURSIVE`, or the mutex is a robust mutex, and the current thread does not own the mutex.

The `pthread_mutex_lock()` and `pthread_mutex_trylock()` functions may fail if:

- `EOWNERDEAD` - The mutex is a robust mutex and the previous owning thread terminated while holding the mutex lock. The mutex lock shall be acquired by the calling thread and it is up to the new owner to make the state consistent.

The `pthread_mutex_lock()` function may fail if:

- `EDEADLK` - A deadlock condition was detected.

These functions shall not return an error code of `[EINTR]`.

The following sections are informative.

## int pthread_mutex_unlock(pthread_mutex_t *mutex);

The `pthread_mutex_unlock()` function shall release the mutex object referenced by `mutex`. The manner in which a mutex is released is dependent upon the mutex's type attribute. 

If there are threads blocked on the mutex object referenced by `mutex` when `pthread_mutex_unlock()` is called, making the mutex available, the scheduling policy shall determine which thread shall acquire the mutex.
