# C++ Data Structures: Core Operations Guide

This repository contains a complete, beginner-friendly C++ project demonstrating the core operations of six fundamental Data Structures: Arrays, Stacks, Linked Lists, Queues, Trees, and Graphs. 

Designed as an educational assignment for studying Object-Oriented Programming and Data Structures, the code keeps implementations clean, readable, and strictly focused on core algorithmic logic without overcomplicating the syntax.

## 📂 Project Structure & Operations Implemented

* **`ArrayOps.cpp`** (5 Operations): Traversal, Insertion (with memory shifting), Deletion, Linear Search, and Update.
* **`StackOps.cpp`** (5 Operations): LIFO (Last-In, First-Out) behavior using a fixed array. Covers `push()`, `pop()`, `peek()`, `isEmpty()`, and `isFull()`.
* **`LinkedListOps.cpp`** (4 Operations): Singly Linked List utilizing dynamic pointers. Covers node Insertion, Deletion by value, Search, and Traversal.
* **`QueueOps.cpp`** (5 Operations): FIFO (First-In, First-Out) behavior using a fixed array. Covers `enqueue()`, `dequeue()`, `peekFront()`, `isEmpty()`, and `isFull()`.
* **`TreeOps.cpp`** (4 Operations): Binary Search Tree (BST) logic utilizing recursion. Covers Insertion, Search, Deletion (handling 0, 1, and 2 child nodes), and In-order Traversal.
* **`GraphOps.cpp`** (5 Operations): Undirected graph utilizing an Adjacency List (`unordered_map` and `vector`). Covers Add Vertex, Add Edge, Remove Edge, Remove Vertex, and Breadth-First Search (BFS) Traversal.

## 🛠️ Prerequisites
* A C++ compiler (like GCC/G++) installed on your system.
* A terminal environment (Windows PowerShell, CMD, or standard Linux/macOS terminal).

## 🚀 How to Compile and Run

You can compile each data structure independently. Open your terminal, navigate to the project folder, and run the standard G++ commands.

**Example for running the Graph operations:**
```powershell
g++ GraphOps.cpp -o graph
./graph
