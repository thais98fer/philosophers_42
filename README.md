*This project has been created as part of the 42 curriculum by thfernan*

# Description

It is an introduction to concurrent programming by solving the classic **Dining Philosophers Problem**.

The mandatory part simulates philosophers sitting at a round table, alternating between eating, thinking, and sleeping, while sharing forks.
The goal is to avoid deadlocks, data races, and starvation, ensuring no philosopher dies of hunger.

## Instructions
### Compilation

Clone the repository and compile the program with:

```bash
make - This will produce the philo binary.
```

Other useful make targets:

```
make clean – remove object files.

make fclean – remove binary and objects.

make re – force recompilation.

make val – run the program under Valgrind to check for memory leaks and errors.

make helgrind – run the program under Valgrind (Helgrind tool) to detect data races.

make sanitize – compile with ThreadSanitizer (-fsanitize=thread) and execute the program.
```

### Usage

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

number_of_philosophers: number of philosophers (and forks).

time_to_die (ms): maximum time a philosopher can go without eating before dying.

time_to_eat (ms): time it takes for a philosopher to eat.

time_to_sleep (ms): time a philosopher spends sleeping.

number_of_times_each_philosopher_must_eat (optional): if provided, the simulation stops after all philosophers have eaten at least this many times.


## Resources

* 42 Subject PDF — *philosophers.pdf*
* [Guide - by *vitosant* ](https://file.notion.com/f/f/5512123a-c9c3-415b-9b1b-e16675cd5c99/4daa13ff-2d08-48f5-9f97-10e67743500f/philo_guia.pdf?table=block&id=37ed6b81-a387-8046-9ab2-c15c7b30f4f6&spaceId=5512123a-c9c3-415b-9b1b-e16675cd5c99&expirationTimestamp=1781827200000&signature=8XOTkjNZg6NmjaUZ6L7ic4aHbpV7y7j-SimiRM9faRQ&downloadName=philo_guia.pdf)
* [Mutexes and Condition Variables – Linux man pages](https://man7.org/linux/man-pages/man7/pthreads.7.html)
* [ThreadSanitizer documentation](https://clang.llvm.org/docs/ThreadSanitizer.html)
* [Valgrind Helgrind manual](https://valgrind.org/docs/manual/hg-manual.html)

### AI Usage

AI tools were used during development to:

- Assist in debugging synchronization issues (data races, deadlocks).
- Organize this README.
- All algorithmic decisions, implementations, and final code were written and reviewed by the author.

## Notes
- The program follows the 42 Norm (strict code style, no for loops, no ternary operators, etc.).
- Error handling for invalid arguments is implemented (positive numbers only, max 200 philosophers).
- Under Valgrind, the simulation may run slower and produce premature deaths – this is expected and does not indicate a bug.