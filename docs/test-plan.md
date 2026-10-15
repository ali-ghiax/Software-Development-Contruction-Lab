# Test Plan

## Student Task Tracker

Compile:

```bash
g++ -o task_tracker src/task_tracker.cpp
.\task_tracker.exe
```

| Step | Action | Expected result |
|------|--------|-----------------|
| 1 | Choose 2 before adding a task | `No tasks yet.` |
| 2 | Choose 1 and enter `Read the lab handout`, then choose 2 | `1. Read the lab handout` |
| 3 | Choose 1 and press Enter without a title | `Title cannot be empty.` |
| 4 | Choose 4 | `Invalid option. Please choose 1, 2, or 3.` |
| 5 | Choose 3 | `Goodbye.` |

## Hello program

Compile:

```bash
g++ -o hello hello.cpp
.\hello.exe
```

Expected output:

```text
Hello, Software Construction and Development Lab!
This is a simple C++ program.
```
