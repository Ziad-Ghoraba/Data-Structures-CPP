# Data-Structures-CPP

Welcome to the **Data Structures in C++** repository! This repository is dedicated to exploring and implementing various data structures using C++.

## Topics Covered

1. Vectors  
   - Dynamic resizing, insertion, deletion, and rotations.  
   - Custom implementation showcasing internal workings.  
2. Singly Linked List  
   - Node-based structure with efficient insertion and deletion operations.  
   - Custom implementation to understand linked data representation.  

---

## 1. Vectors

This repository contains a custom implementation of a dynamic array, or **Vector**, in C++. Unlike the STL `std::vector`, this implementation delves into the low-level mechanisms of dynamic arrays, including memory management and resizing.

### Key Features:
- **Dynamic Resizing**: The vector doubles its capacity when the size exceeds the current capacity.  
- **Custom Memory Management**: Manages memory manually using raw pointers for deeper understanding of memory handling in dynamic arrays.  
- **Efficient Operations**:
  - `push_back`: Adds an element at the end, leveraging the capacity trick to minimize overhead.
  - `insert`: Inserts an element at a specific index with shifting.
  - `pop`: Removes an element from the end or a specific index.
  - `Rotations`: Performs left or right rotations, as well as multiple-step rotations.  
- **Search Optimization**:
  - `Usual Find`: Finds an element by iterating through the vector sequentially from the beginning to the end.
  - `Smart Find`: Implements a "move-to-front" optimization. If an element is found, it is moved to the front of the vector, improving the search performance for repeated accesses.
- **Access Methods**:
  - `get`: Retrieve an element by index.
  - `set`: Update an element at a specific index.
  - `get_front` and `get_back`: Access the first and last elements, respectively.

---

## 2. Singly Linked List

This repository also includes a **Singly Linked List**, implemented from scratch to demonstrate the basics of linked structures.

### Key Features:
- **Dynamic Node Allocation**: Each node is dynamically allocated, storing data and a pointer to the next node.  
- **Efficient Insertion and Deletion**:
  - `insert_front`: Inserts a new node at the head of the list.
  - `insert_end`: Inserts a new node at the tail of the list.
  - `delete_front`: Deletes the head node.
  - `delete_node_with_key`: Deletes a node by key value.
  - `delete_node_num`: Deletes a node by position in the list.
- **Traversal Methods**:
  - `print`: Iteratively prints the entire list.
  - `print_for`: Another iteration-based print function.
- **Advanced Operations**:
  - `get_nth`: Retrieves the nth node in the list.
  - `get_nth_back`: Retrieves the nth node from the end.
  - `reverse`: Reverses the entire list.
  - `remove_duplicates`: Removes duplicate values in the list.
  - `move_to_back`: Moves all occurrences of a specific value to the end of the list.
  - `left_rotate`: Rotates the list to the left by a specified number of positions.
  - `swap_head_tail`: Swaps the head and tail nodes of the list.
  - `swap_pairs`: Swaps adjacent nodes in pairs.
  - `insert_sorted`: Inserts a node in sorted order.
- **Search and Utility**:
  - `search`: Finds the index of a value in the list.
  - `improved_search`: Optimized search with "move-to-front" for frequently accessed values.
  - `max`: Recursively finds the maximum value in the list.
  - `is_same`: Compares two linked lists for equality.
- **Debugging Tools**:
  - `debug_to_string`: Converts the list to a string representation for debugging.
  - `debug_verify_data_integrity`: Validates the integrity of the list's structure.

### Prerequisites
- A working installation of a C++ compiler (e.g., GCC, Clang, or MSVC).
- A code editor or IDE that supports C++ (e.g., Visual Studio Code, CLion, or Visual Studio).

