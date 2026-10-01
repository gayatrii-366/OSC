# Operating Systems Laboratory

A comprehensive repository containing practical implementations of core Operating Systems concepts, system calls, shell scripts, and classical synchronisation problems in C and Bash.

---

## 📁 Repository Structure

The programs are grouped into four primary categories:

```text
.
├── Shell Scripting
│   ├── hello.sh              # Basic shell syntax & environment verification
│   ├── arithmetic.sh         # Arithmetic operations in Bash
│   ├── menu_driven.sh        # Interactive menu-based script execution
│   ├── filemanage.sh         # File handling, search, and directory operations
│   └── os_practical          # Consolidated lab runner / utility script
│
├── Process Management & System Calls
│   ├── fork_fun.c            # Introduction to fork() and process creation
│   ├── fork_fun1.c – 5.c     # Process hierarchy, PID tracking, and execution flows
│   ├── parent_sort.c         # Inter-process task splitting (parent/child sorting)
│   ├── orphan.c              # Demonstration of orphan processes
│   ├── zombieprocesses.c     # Zombie process simulation and state analysis
│   └── zombieprocesses1.c    # Preventing zombie processes with wait()
│
├── CPU Scheduling & Memory Management
│   ├── fcfs.c                # First-Come, First-Served (non-preemptive)
│   ├── srtf.c                # Shortest Remaining Time First (preemptive SJF)
│   └── page_replacement.c   # Page replacement algorithms (FIFO / LRU / Optimal)
│
└── Inter-Process Communication & Synchronisation
    ├── pipe.c                # Unidirectional IPC using anonymous pipes
    └── readers_writers.c     # Classical Readers-Writers problem using POSIX semaphores
