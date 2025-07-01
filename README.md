# Data-Structures-CPP

Welcome to the **Data Structures in C++** repository! This repository is dedicated to exploring and implementing various data structures using C++.

## Topics Covered

📌 **1. Vectors**  
   - Dynamic resizing, insertion, deletion, and rotations.  
   - Custom implementation showcasing internal workings.

📌 **2. Singly Linked List**  
   - Node-based structure with efficient insertion and deletion operations.  
   - Custom implementation to understand linked data representation.

📌 **3. Doubly Linked List**  
   - Full implementation of a doubly linked list with forward and backward traversal.  
   - Efficient operations like insertion, deletion, and various utilities.

📌 **4. Stack**  
   - Multiple implementations of stack data structures.  
   - Stack-based algorithms for solving common computational problems.

📌 **5. Queue**  
   - Multiple implementations of queue data structures.  
   - Includes **Priority Queue** and **Queue using Stacks**.

📌 **6. Binary Tree**  
   - In-depth binary tree implementation.  
   - Includes traversals, symmetry checks, structural validations, and serialization.

📌 **7. Binary Search Tree (BST)**  
   - Fully functional BST with efficient insert, delete, search, and traversal.  
   - Advanced features like kth smallest, successor, and lowest common ancestor.

---

## 📌 1. Vectors

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

## 📌 2. Singly Linked List

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

---

## 📌 3. Doubly Linked List

This repository also includes a **Doubly Linked List**, implemented to explore the more advanced features of linked structures with both forward and backward traversal.

### Key Features:
- **Node Structure**: Each node contains pointers to both the next and previous nodes.
- **Efficient Operations**:
  - `insert_end`: Inserts a new node at the end of the list.
  - `insert_front`: Inserts a new node at the front of the list.
  - `delete_front`: Deletes the front node.
  - `delete_end`: Deletes the last node.
  - `delete_with_key`: Deletes nodes by specific value.
  - `delete_all_nodes_with_key`: Deletes all nodes that match a value.
  - `delete_even_positions`: Deletes nodes at even positions.
  - `delete_odd_positions`: Deletes nodes at odd positions.
  - `reverse`: Reverses the entire list.
  - `merge_2sorted_lists`: Merges two sorted lists into one.
- **Advanced Operations**:
  - `is_palindrome`: Checks if the list is a palindrome.
  - `middle`: Finds the middle element of the list.
  - `Swap`: Swaps the kth element from the front with the kth element from the back.
- **Debugging Tools**:
  - `debug_add_node`: Adds nodes to the debug list for visualization.
  - `debug_remove_node`: Removes nodes from the debug list.
  - `debug_print_address`: Prints node addresses and data.
  - `debug_print_node`: Prints details about a specific node.
  - `debug_print_list`: Prints the entire list with debug information.
---

## 📌 4. Stack

This repository now includes multiple implementations of the **Stack** data structure to explore various approaches and stack-based algorithms.

### Key Features:
- **Stack Implementations**:
  - **Array-based Stack**: Uses a dynamic array with push, pop, peek, and display operations.
  - **Two-Stack Implementation**: Implements two stacks in a single array for memory efficiency.
  - **Reverse Stack Operations**: Functions to reverse a stack using recursion and insertion at the bottom.
- **Stack-Based Algorithms**:
  - `reverse_subWords`: Reverses each word in a sentence while keeping the order of words.
  - `reverse_num`: Reverses the digits of a number.
  - `valid_parentheses`: Checks if a string contains balanced parentheses.
  - `removeDuplicates`: Removes consecutive duplicate characters from a string.
  - `asteroidCollision`: Simulates asteroid collisions using a stack.
  - `infix_to_postfix`: Converts an infix expression to postfix notation for easier computation.
  - `infix_to_postfix_efficient`: Optimized version of the infix-to-postfix conversion.
---

 ## 📌 5. Queue

This repository includes multiple implementations of the **Queue** data structure, including a **Priority Queue** and a **Queue using Stacks**.

### Key Features:
- **Queue Implementations**:
  - **LinkedList-based Queue**: Uses a singly linked list for efficient enqueue and dequeue operations.
  - **Array-based Queue**: Implements a circular queue using an array for fixed-size queues.
  - **Queue using Stacks**: Implements a queue using two stacks, showcasing how stacks can be used to simulate queue behavior.
- **Priority Queue**:
  - Implements a priority queue with three levels of priority (1, 2, and 3).
  - Ensures that elements with higher priority are dequeued first.
- **Efficient Operations**:
  - `enqueue`: Adds an element to the queue.
  - `dequeue`: Removes and returns the front element from the queue.
  - `is_empty`: Checks if the queue is empty.
  - `is_full`: Checks if the queue is full (for fixed-size queues).
  - `front`: Returns the front element without removing it.
- **Advanced Operations**:
  - `enqueue_front`: Adds an element to the front of the queue (for deque-like behavior).
  - `dequeue_rear`: Removes and returns the rear element from the queue (for deque-like behavior).
- **Debugging Tools**:
  - `display`: Prints the current state of the queue for debugging purposes.

---

## 📌 6. Binary Tree

This repository now includes a custom implementation of a **Binary Tree**, with a wide range of traversal, utility, and structural methods. It helps explore how binary trees work and supports solving many common tree-related problems.

### Key Features:

- **Tree Construction**:
  - `add`: Adds a node along a given path using a combination of values and directions (`L` or `R`), allowing flexible tree construction.

- **Traversal Methods**:
  - `print_in_order`: In-order traversal of the tree.
  - `level_order_traversal1`: Classic level-order traversal using a queue.
  - `level_order_traversal2`: Level-order traversal that prints nodes level-by-level.
  - `zigzagLevelOrder`: Level-order traversal in zigzag (alternating) pattern.

- **Tree Properties and Utilities**:
  - `find_max`, `find_max_2`: Find the maximum node value in the tree.
  - `sum_of_all_nodes`: Calculates the total sum of all node values.
  - `maxDepth`: Returns the maximum depth (height) of the tree.
  - `no_of_nodes`: Counts the total number of nodes.
  - `no_of_levels_prefectTree`: Returns the number of levels in a perfect tree.
  - `hasPathSum`: Checks if there's a root-to-leaf path with a specific sum.
  - `sumOfLeftLeaves`: Calculates the sum of all left leaf nodes.

- **Tree Type Checks**:
  - `is_full_BT`: Checks if the tree is a full binary tree.
  - `is_perfect`, `is_perfect_formula`: Checks if the tree is a perfect binary tree using two different techniques.
  - `isSymmetric`: Determines if the binary tree is symmetric (mirror image).

- **Tree Serialization & Patterns**:
  - `parenthesize`: Converts the tree into a parenthesis-encoded string representation.

- **Advanced Features**:
  - `duplicates_sub_trees`: Identifies all duplicate subtrees in the binary tree and returns their serialized patterns for comparison.

- **Private Helper Functions**:
  - Recursive and utility functions that support traversal, symmetry check, subtree detection, and tree serialization.

---

## 📌 6. Binary Search Tree (BST)

This repository now includes a fully functional **Binary Search Tree (BST)** implementation in C++, providing fundamental and advanced operations with efficient time complexities based on tree height (`O(h)`).

### Key Features:

- **Tree Construction**:
  - `insert`: Adds a value to the BST while maintaining its properties.
  - `add`: Flexible addition based on a path with directions (`L`, `R`), used for manual tree building and testing.

- **Search Operations**:
  - `normal_search`: Searches for a value using a brute-force method (`O(n)`).
  - `BST`: Searches using the BST property for improved performance (`O(h)`).

- **Traversal**:
  - `print_inorder`: In-order traversal to display elements in sorted order.
  - `_inorder_list`: Internal utility to collect elements in in-order.

- **Minimum and Successor**:
  - `minimum`: Finds the smallest element in the tree (`O(h)`).
  - `minimum_in_BST`: BST-specific optimized version.
  - `successor`: Finds the next greater value in in-order traversal.
  - `successor_v2`: More efficient version using parent tracking and subtrees.

- **Kth Smallest Element**:
  - `kthSmallest`: Returns the kth smallest element in the BST (`O(n)` if done via in-order).

- **Lowest Common Ancestor (LCA)**:
  - `lowestCommonAncestor`: Finds the LCA of two nodes in a BST (`O(h)`).

- **Conversion and Utilities**:
  - `sortedArrayToBST`: Converts a sorted array into a balanced BST.
  - `treeToDoubleList`: Converts BST to a **circular doubly linked list** using in-order order.
  - `isValidBST`: Verifies if the current tree structure is a valid BST.

- **Deletion**:
  - `Delete`: Removes a node from the BST while maintaining its properties (`O(h)`).

--- 
### Prerequisites
- A working installation of a C++ compiler (e.g., GCC, Clang, or MSVC).
- A code editor or IDE that supports C++ (e.g., Visual Studio Code, CLion, or Visual Studio).


