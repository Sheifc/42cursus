# Philosophers Project

# Warning

For Linux, after running `make` with the `-fsanitize=thread` flag, execute the following command:

```bash
setarch `uname -m` -R $SHELL
```

## General Instructions
- Your project must be written in C.
- Your project must adhere to the Norm. If you have additional files or functions, they are included in the Norm verification, and you will receive a 0 if there is any Norm error in any of them.
- Your functions must not terminate unexpectedly (segfault, bus error, double free, etc.), except in the case of undefined behaviors. If this happens, your project will be considered non-functional and will receive a 0 during evaluation.
- All memory allocated on the heap must be properly freed when necessary. Memory leaks will not be allowed.
- If specified in the statement, you must provide a Makefile that compiles your source files to the required output with the flags -Wall, -Werror, and -Wextra, using cc, and of course, your Makefile should not relink.
- Your Makefile must contain at least the rules $(NAME), all, clean, fclean, and re.
- To submit the bonus part of your project, you must include a bonus rule in your Makefile, in which you will add all the headers, libraries, or functions that are prohibited in the main part of the project. The bonus should be in separate files _bonus.{c/h}. The mandatory part and the bonus are evaluated separately.
- If your project allows the use of libft, you must copy its source and associated Makefiles into a libft directory with its corresponding Makefile. Your project’s Makefile should compile the library first using its Makefile, and then compile the project.
- We recommend creating test programs for your project, although this work will not be submitted or evaluated. This will give you the opportunity to verify that your program works correctly during your evaluation and that of your peers. And yes, you are allowed to use these tests during your evaluation or that of your peers.
- Submit your work to your assigned Git repository. Only the work in your Git repository will be evaluated. If Deepthought evaluates your work, it will do so after your peers. If an error is found during the Deepthought evaluation, it will end.

## General Description
Here is a list of things you should know if you want to pass this project:
- One or more philosophers sit at a round table.
- In the center of the table is a large bowl of spaghetti.
- Philosophers can only eat, think, or sleep.
  - While eating, they cannot think or sleep.
  - While thinking, they cannot sleep or eat.
  - And, of course, while sleeping, they cannot eat or think.
- There are also forks on the table, as many forks as there are philosophers.
- Because grabbing and eating spaghetti with one fork can be uncomfortable, philosophers must take the fork on their right and the one on their left, one in each hand.
- When a philosopher finishes eating, they will put the forks back on the table and immediately start sleeping. Once they wake up, they will start thinking again. The simulation stops when a philosopher dies of starvation.
- All philosophers need to eat and must never starve to death.
- Philosophers do not talk to each other.
- Philosophers do not know if another philosopher is about to die.
- It should go without saying that all must avoid dying!

## General Instructions
You must write a program for the mandatory part and another for the bonus part (only if you decide to do the bonus part). Both must comply with the following rules:
- Global variables are prohibited!
- Your program(s) must accept the following arguments: 
  `number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`
  - `number_of_philosophers`: the number of philosophers, but also the number of forks.
  - `time_to_die` (in milliseconds): if a philosopher does not start eating within `time_to_die` milliseconds since their last meal or the beginning of the simulation, they will die.
  - `time_to_eat` (in milliseconds): the time a philosopher has to eat. During this time, they will hold onto the forks.
  - `time_to_sleep` (in milliseconds): the time a philosopher has to sleep.
  - `number_of_times_each_philosopher_must_eat` (optional argument): if all philosophers eat at least `number_of_times_each_philosopher_must_eat` times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
- Each philosopher will be assigned a number from 1 to `number_of_philosophers`.
- Philosopher number 1 will sit next to philosopher number `number_of_philosophers`. Any other philosopher number N will sit between philosopher number N - 1 and philosopher number N + 1.

## Logs of Your Program:
- Any change in the state of a philosopher must have the following format:
  - `timestamp_in_ms X has taken a fork`
  - `timestamp_in_ms X is eating`
  - `timestamp_in_ms X is sleeping`
  - `timestamp_in_ms X is thinking`
  - `timestamp_in_ms X died`
  - Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher's number.
- The printed state should not be broken or altered by the state of other philosophers.
- You cannot have more than 10ms between the death of a philosopher and the moment you print their death.
- Remember, philosophers must avoid dying.
- Your program should not have any data races.

## Mandatory Part

### Program Name
- `philo`

### Files to Submit
- `Makefile`, `*.h`, `*.c` in the `philo/` directory

### Makefile
- Must contain: `NAME`, `all`, `clean`, `fclean`, `re`

### Arguments
- `number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`

### Authorized Functions
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

### Usage of libft
- Not allowed

### Description
- Philosophers using threads and mutex

## Specific Rules for the Mandatory Part

- **Each philosopher must be a thread.**
- **There is a fork between each philosopher. Therefore, if there are multiple philosophers, each philosopher must have a fork to their left and another to their right. If there is only one philosopher, there will be only one fork on the table.**
- **To prevent philosophers from duplicating forks, you must protect the state of the forks with a mutex for each of them.**

## Submission and Evaluation

- **Submit your project to your Git repository as usual. Only the work in your repository will be evaluated during the defense.**
- **Double-check the names of your files to ensure they are correct.**
- **Directory for the mandatory part: `philo/`**
