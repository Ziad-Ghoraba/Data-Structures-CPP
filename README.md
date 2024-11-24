# Data-Structures-CPP

Welcome to the **Data Structures in C++** repository! This repository is dedicated to exploring and implementing various data structures using C++.

## Topics Covered

1. Vectors  
   - Dynamic resizing, insertion, deletion, and rotations.  
   - Custom implementation showcasing internal workings.  

---

## 1. Vectors

This repository contains a custom implementation of a dynamic array, or **Vector**, in C++. Unlike the STL `std::vector`, this implementation delves into the low-level mechanisms of dynamic arrays, including memory management and resizing.

### Key Features:
- **Dynamic Resizing**: The vector doubles its capacity when the size exceeds the current capacity.  
- **Custom Memory Management**: Manages memory manually using raw pointers for deeper understanding.  
- **Efficient Operations**:
  - `push_back`: Adds an element at the end, leveraging the capacity trick to minimize overhead.
  - `insert`: Inserts an element at a specific index with shifting.
  - `pop`: Removes an element from the end or a specific index.
  - `**Rotations**`: Performs left or right rotations, as well as multiple-step rotations.  
- **Search Optimization**: Implements a `find` method with a "move-to-front" optimization to improve repeated search performance.  
- **Access Methods**:  
  - `get`: Retrieve an element by index.  
  - `set`: Update an element at a specific index.  
  - `get_front` and `get_back`: Access the first and last elements, respectively.  

