# Team Workflow Lab

Purpose: Practice the individual Git cycle, pull requests, and safe merge conflict resolution.

Team members: ali-ghiax

Tasks: Repository setup, feature implementation, review, and testing.

## Learning Objectives

- Explain the difference between Git and GitHub.
- Stage, commit, push, and pull changes from the terminal.
- Isolate a task on a feature branch and integrate it with a pull request.
- Recognize and resolve a basic merge conflict.

This repository is used for the Software Construction and Development lab on individual and team GitHub workflows.

## Student Task Tracker

`src/task_tracker.cpp` stores tasks and prints them. Choose 1 to add a task, 2 to list tasks, and 3 to exit.

```bash
g++ -o task_tracker src/task_tracker.cpp
.\task_tracker.exe
```

The checks for this program are in `docs/test-plan.md`.

## Hello program

`hello.cpp` prints a short message with `cout`.

```bash
g++ -o hello hello.cpp
.\hello.exe
```

## Repository

https://github.com/ali-ghiax/Software-Development-Contruction-Lab

## Contribution summary

ali-ghiax is the repository owner and carried out each lab role on its own branch:

- Added the project overview and the learning objectives.
- Added the task record, the add-task function, and task listing through separate pull requests.
- Added the test plan and a review comment on each tracker pull request.
- Resolved the merge conflict on the Purpose line in this file.
