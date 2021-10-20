This is an implementation of priority queue. There are two implementations based on sorted array and heap. 

Both implementations implement the priority interface, which has operations

```java
/**
   * Add an element to the priority queue.
   */
public void add(T val) throws CollectionFullException;

/**
   * Remove and return the highest priority element from the priority queue.
   */
public T remove() throws CollectionEmptyException;

/**
   * Get the highest priority element from the priority queue without
   * removing the element.
   */
public T peek() throws CollectionEmptyException;
```

# File Cookbook

- `APQ.java`, an implementation priority queue based on unsorted array 
- `APQTest.java`, a JUnit Test for `APQ.java`
- `Heap.java`: an implementation priority queue based on heap
- `HeapTests.java`, a JUnit Test for `Heap.java`
- `PriorityQueue.java`, an interface for priority queue

# Analysis

The time complexity for `add`, `remove`, and `peek` operations for array based and heap based priority queue. 

| Operation | APQ    | Heap         |
| --------- | ------ | ------------ |
| add       | $O(1)$ | $O(\log(n))$ |
| remove    | $O(n)$ | $O(\log(n))$ |
| peek      | $O(n)$ | $O(\log(n))$ |

# Credit

This is class homework of Grinnell College [CSC-301](https://rebelsky.cs.grinnell.edu/Courses/CSC301/2021Fa/syllabus/) taught by professor [Samuel A. Rebelsky](https://www.grinnell.edu/user/rebelsky). 

