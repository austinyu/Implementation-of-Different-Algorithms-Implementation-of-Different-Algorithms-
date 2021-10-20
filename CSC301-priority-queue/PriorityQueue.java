/**
 * A simple Priority Queue interface.
 */
public interface PriorityQueue<T>
{
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

  /**
   * Determine if the collection is empty.
   */
  public boolean isEmpty();
} // interface PriorityQueue<T>
