# Sum Up

### Choose the Right Tool for the Job

Use QThread for long-running tasks requiring lifecycle control, QThreadPool for many short-lived tasks, and QtConcurrent when simplicity matters more than fine-grained control.

### Avoid Threading for Trivial Operations

Quick operations that complete in milliseconds don't benefit from threading. The overhead of thread creation, data passing, and synchronization can outweigh the benefits. So just operate them in main thread.

### Protect Shared Data Consistently

Race conditions, deadlocks, and data corruption are subtle bugs that may not appear during testing. Use QMutexLocker for automatic cleanup, and design thread interactions carefully.

### Communicate Safely Between Threads

Never access GUI elements from worker threads. Use queued connections, `QMetaObject::invokeMethod()`, or custom events to marshal data back to the main thread.