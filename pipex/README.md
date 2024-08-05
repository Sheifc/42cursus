<div align="justify">

# Pipex

![pipex](https://github.com/user-attachments/assets/3f0d87f5-94ed-48ca-92fd-2492f2f2e529)


The "pipex" project is a programming assignment that mimics the behavior of the Unix pipeline mechanism using C programming. The main objective of the project is to recreate a simplified version of the shell command pipeline `cmd1 | cmd2` using the Unix processes and file descriptors.

Here’s a breakdown of what the project typically involves:

1. **Process Creation**: The program needs to create processes using the `fork()` system call, which is fundamental in handling multiple processes in Unix-like operating systems.

2. **Pipe Creation**: It involves using the `pipe()` system call to create a pipeline between two processes. This pipe acts as a conduit allowing data to flow from one process to another.

3. **Redirection**: The project requires redirecting the standard input (stdin) and standard output (stdout) using `dup2()` system call. For example, the output of the first command (cmd1) is not displayed on the terminal but is sent directly into the input of the second command (cmd2).

4. **Command Execution**: Executing commands within each process is handled using `execve()` or similar variants. This system call replaces the current running process with a new program, running the commands that need to be piped.

5. **File Handling**: The program starts by reading from an input file and ends by writing the output to an output file, thus emulating the effect of `cmd1 < infile | cmd2 > outfile`.

6. **Error Handling**: Implementing robust error handling is crucial, ensuring that all possible failures in process creation, file management, or execution are properly managed.

The "pipex" project is an excellent exercise for students to understand inter-process communication, process management, and command-line interfacing in Unix systems. This project not only reinforces the concepts of system programming but also provides a deeper understanding of how shell commands and pipelines work under the hood.

# Bonus

For the bonus part of the "pipex" project, additional features are typically added to enhance the functionality and complexity of the basic pipeline simulation. Here are some common extensions that might be included in the bonus section:

1. **Multiple Pipes**: Extending the program to handle more than two commands, thus simulating more complex pipelines like `cmd1 | cmd2 | cmd3 | ...`. This involves managing multiple pipes and processes in a loop or recursive structure.

2. **Here Document (`<<`) Support**: Implementing the here document feature, which allows direct input from the terminal to be used as the input for a command within the pipeline, similar to the shell's `<<` operator.

3. **Additional Redirections (`<<`, `>>`)**: Besides the basic input and output redirections, handling appending to a file with `>>`, and using here-documents as input redirection `<<` to simulate more advanced shell operations.

4. **Error Management Enhancements**: Improving error handling to more robustly manage scenarios with invalid commands, broken pipes, and file access issues.

5. **Environment Variables Handling**: Optionally, handling environment variables to allow `execve()` to execute programs that rely on these settings.

6. **Command Search**: Implementing a path resolution feature where the program searches for the executable in the directories specified by the `PATH` environment variable, similar to how a shell resolves command locations.

These enhancements significantly increase the complexity and learning outcomes of the project, providing a deeper dive into Unix system programming and shell functionalities.
