# ftrace
Function call tracer - Syscall, Internal and shared functions

ftrace allows to list all of the different inputs and outputs of a program’s function.
- system calls,
- a program’s internal function calls with their name and address,
- signals received from other programs,
- function calls contained in the shared libraries (.so).

# Example
```
Entering function main at 0x42ff231
Entering function my_putstr at 0x42ff9fd
Entering function my_putchar at 0x43aa123
Syscall write (0x1, 0xff3210123, 0x1) = 0x1
Leaving function mu_putchar
Entering function my_putchar at 0x43aa123
Syscall write (0x1, 0xff3210124, 0x1) = 0x1
Leaving function mu_putchar
Entering function my_putchar at 0x43aa123
Syscall write (0x1, 0xff3210125, 0x1) = 0x1
Received signal SIGWINCH
Leaving function mu_putchar
Entering function my_putchar at 0x43aa123
Syscall write (0x1, 0xff3210126, 0x1) = 0x1
Leaving function mu_putchar
Leaving function my_putstr
Entering function printf at 0x877621fda31
```

# Usage
```bash
$> make
$> ./ftrace -h
```
