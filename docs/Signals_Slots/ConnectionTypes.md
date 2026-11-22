# Connection Types

### `Qt::AutoConnection`

- Default connection type – chooses DirectConnection if receiver and emitter objects are on the same thread and QueuedConnection otherwise
- Connection type determined at signal emission time

### `Qt::DirectConnection`

- Slot invoked immediately when the signal is emitted
- Slot executed on the thread that the signal is emitted from

### `Qt::QueuedConnection`

- Slot executed in receiver’s thread when the receiving thread is ready
- Requires an event loop to be running on that thread

### `Qt::BlockingQueuedConnection`

- Slot executed in receiver’s thread but will block the signaling thread until the slot returns
- Do not use if the emitter and receiver are on the same thread - this will cause the program to deadlock

### `Qt::UniqueConnection`

- Flag that can be added to any other connection type using bitwise OR
- Unique connection prevents a connection if the connection already exists