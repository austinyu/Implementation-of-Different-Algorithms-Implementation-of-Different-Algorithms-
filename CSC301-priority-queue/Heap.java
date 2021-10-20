import java.util.Comparator;
import java.util.ArrayList;

/**
 * An implementation of Priority Queues using heaps
 */
public class Heap < T >
  implements PriorityQueue < T > {
    // +--------+------------------------------------------------------
    // | Fields |
    // +--------+

    /**
     * The comparator used for the ordering.
     */
    Comparator < T > compare;

    /**
     * The array that stores the valules.
     */
    ArrayList < T > values;

    /**
     * The number of values stored.
     */
    int size;

    // +--------------+------------------------------------------------
    // | Constructors |
    // +--------------+

    public Heap(Comparator < T > compare) {
      this.compare = compare;
      this.values = new ArrayList < T > ();
    } // Heap(Comparator<T>)

    // +---------+-----------------------------------------------------
    // | Methods |
    // +---------+

    /**
     * Add an element to the priority queue.
     */
    public void add(T val) throws CollectionFullException {
      values.add(val);
      int child = values.lastIndexOf(val);
      int parent = (int) Math.floor((child - 1) / 2);
      while (compare.compare(values.get(parent), values.get(child)) < 0) {
        // while parent is smaller than child, swap 
        T temp = values.get(parent);
        values.set(parent, values.get(child));
        values.set(child, temp);
        child = parent;
        parent = (int) Math.floor((child - 1) / 2);
      }
    } // add(T)

    /**
     * Remove and return the highest priority element from the priority queue.
     */
    public T remove()
    throws CollectionEmptyException {
      if (values.isEmpty()) {
        throw new CollectionEmptyException();
      }
      if (this.values.size() == 1) {
        T result = values.get(0);
        values.remove(0);
        return result;
      }
      if (this.values.size() == 2) {
        T result = values.get(0);
        values.set(0, values.get(1));
        values.remove(1);
        return result;
      }
      T result = values.get(0);
      values.set(0, values.get(values.size() - 1));
      values.remove(values.size() - 1);
      int parent = 0;
      int child;
      if (this.values.size() == 2) {
        child = 1;
      } else {
        child = compare.compare(values.get(parent * 2 + 1), values.get(parent * 2 + 2)) > 0 ?
          parent * 2 + 1 : parent * 2 + 2;
      }
      while (compare.compare(values.get(parent), values.get(child)) < 0) {
        // while parent is smaller than child, swap
        T temp = values.get(parent);
        values.set(parent, values.get(child));
        values.set(child, temp);
        if (child * 2 + 1 >= values.size() || child * 2 + 2 >= values.size()) {
          break;
        }
        parent = child;
        child = compare.compare(values.get(parent * 2 + 1), values.get(parent * 2 + 2)) > 0 ?
          parent * 2 + 1 : parent * 2 + 2;
      }
      return result;
    } // remove()

    /**
     * Get the highest priority element from the priority queue without
     * removing the element.
     */
    public T peek()
    throws CollectionEmptyException {
      if (values.isEmpty()) {
        throw new CollectionEmptyException();
      }
      return values.get(0);
    } // peek()

    /**
     * Determine if the collection is empty.
     */
    public boolean isEmpty() {
      return this.size == 0;
    } // isEmpty()

  } // class Heap<T>