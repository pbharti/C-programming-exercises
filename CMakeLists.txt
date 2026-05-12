cmake_minimum_required(VERSION 4.1)
project(C_programming_exercises C)

set(CMAKE_C_STANDARD 11)

include_directories(bst/inc)
include_directories(command-parsing/inc)
include_directories(IPC/message-queue)
include_directories(LinkedList/inc)

add_executable(C_programming_exercises
        bst/inc/bst.h
        bst/src/bst.c
        command-parsing/inc/parser.h
        command-parsing/src/parser_main.c
        Ctutorial/bitwise-operation.c
        Ctutorial/post-pre-operator.c
        Ctutorial/StructHack.c
        gdb/program-with-buffer-overflow.c
        IPC/message-queue/msg_common.h
        IPC/message-queue/msgq_client.c
        IPC/message-queue/msgq_server.c
        IPC/parent-child-pipe.c
        LinkedList/inc/list_common.h
        LinkedList/inc/test.h
        LinkedList/src/sll_main.c
        LinkedList/src/sll_utils.c
        LinkedList/src/test.c
        Multi-threading/pthread-mutex/pthread_cond.c
        Multi-threading/pthread-mutex/pthread_mutex.c
        Multi-threading/pthread-sem/pthread-sem.c
        Multi-threading/pthread.c
        Process/child.c
        Process/parent-with-wait.c
        Process/parent.c
        sorting/bubblesort.c
        sorting/insertionsort.c
        sorting/mergesort.c
        sorting/quicksort.c
        sorting/selectionsort.c
        sorting/ss.c
        thread-programing/smp-print-even-odd.c
        heapsort/ascending.c)
