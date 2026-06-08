*This project has been created as part of the 42 curriculum by mimeyer*

# Description

Codexion is a concurrency simulation in C where multiple coder threads compete for a limited set of USB dongles in order to compile, debug, and refactor. Each coder needs two adjacent dongles to compile, and the program stops when every coder has completed the required number of compilations or when any coder burns out by missing a compile deadline.

The project implements a custom scheduler for dongle access using a thread-safe binary heap. It supports both `fifo` and `edf` arbitration policies while enforcing dongle cooldown and precise burnout detection.

# Instructions

1. Build the program:
   - `make re`

2. Run the simulation with 8 mandatory arguments:
   - `./codexion [CODERS] [BURNOUT] [COMPILE] [DEBUG] [REFACTOR] [REQUIRED] [COOLDOWN] [SCHEDULER]`

3. Example:
   - `./codexion 10 500 50 25 25 5 50 edf`

4. Argument rules:
   - `CODERS`: number of coder threads and number of dongles (must be greater than 1)
   - `BURNOUT`: milliseconds until a coder burns out if they do not start compiling
   - `COMPILE`: compile duration in milliseconds
   - `DEBUG`: debug duration in milliseconds
   - `REFACTOR`: refactor duration in milliseconds
   - `REQUIRED`: required number of compilations per coder before stopping
   - `COOLDOWN`: dongle cooldown in milliseconds after release
   - `SCHEDULER`: either `fifo` or `edf`

5. The program rejects invalid inputs, including negative values, non-integer strings, or an unsupported scheduler.

# Resources

- Codexion project PDF (assignment description)
- `pthread` manuals
- [C Program to Implement Binary Heap - GeeksforGeeks](https://www.geeksforgeeks.org/c/c-program-to-implement-binary-heap/)
- [Binary Heap - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/binary-heap/)
- [Binary heap - Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)
- [Intro to threads - YouTube](https://www.youtube.com/watch?v=ldJ8WGZVXZk)
- [Intro to mutex - YouTube](https://www.youtube.com/watch?v=raLCgPK-Igc)
- [Intro to condition variables - YouTube](https://www.youtube.com/watch?v=0sVGnxg6Z3k)
- Miro (design planning)
- ChatGPT / Copilot: used for minor debugging, heap implementation understanding, and README drafting only

# Blocking cases handled

## Deadlock prevention

- Coders never try to acquire dongle locks until they have been granted permission by the heap manager.
- Each coder waits on its own condition variable and is only woken when both adjacent dongles are confirmed available.
- Once woken, the coder locks both adjacent dongles and begins compiling, eliminating circular wait across threads.

## Starvation prevention

- The heap queue feeds the next eligible coder according to the selected scheduler.
- `fifo` preserves request order, and `edf` prioritizes the coder with the earliest compile deadline.
- Every coder re-enters the heap after debugging and refactoring, ensuring all threads get repeated access to the scheduler.

## Cooldown handling

- Dongle release times are tracked using an earliest-available timestamp array.
- The heap manager checks both adjacent dongles before waking a coder, ensuring cooldown has expired on both.
- This prevents a coder from grabbing a recently released dongle too early.

## Precise burnout detection

- A dedicated monitor thread checks each coder's last compile start time against `time_to_burnout`.
- If a coder misses a compile deadline, the monitor logs burnout immediately and stops the simulation.
- The log mutex ensures the burnout message is printed without interference from other threads.

## Log serialization

- All log output passes through a single `pthread_mutex_t`.
- This guarantees messages like `X has taken a dongle`, `X is compiling`, `X is debugging`, `X is refactoring`, and `X burned out` are never interleaved.

# Thread synchronization mechanisms

- Each coder has:
  - `pthread_mutex_t lock` to protect its internal state
  - `pthread_cond_t wake` to wait for permission from the heap manager
- Each dongle has:
  - `pthread_mutex_t lock` to enforce exclusive access while compiling
- The heap uses:
  - `pthread_mutex_t lock` to serialize insertions, removals, and priority updates
- The log uses:
  - `pthread_mutex_t lock` to serialize output and prevent mixed lines

How they coordinate:

- Coders insert themselves into the shared heap when they are ready to compile.
- The heap manager thread sorts requests and checks whether both neighboring dongles are cooled down.
- When a coder is selected, the manager broadcasts on that coder's condition variable.
- The coder then locks both dongles and proceeds to compile.
- The monitor thread polls coder state safely under each coder mutex and prints burnout or completion events.
