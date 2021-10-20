import java.util.Comparator;
import java.util.ArrayList;

/**
 * An implementation of Priority Queues using unsorted arrays.
 */
public class APQ < T >
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

    public APQ(Comparator < T > compare) {
      this.compare = compare;
      this.values = new ArrayList < T > ();
    } // APQ(Comparator<T>)

    // +---------+-----------------------------------------------------
    // | Methods |
    // +---------+

    /**
     * Add an element to the priority queue.
     */
    public void add(T val)
    throws CollectionFullException {
      this.values.add(val);
    } // add(T)

    /**
     * Remove and return the highest priority element from the priority queue.
     */
    public T remove()
    throws CollectionEmptyException {
      if (values.isEmpty() ){
        throw new CollectionEmptyException();
      }
      int maxID = 0;
      int currentID = 0;
      T maxVal = this.values.get(0);
      for (T element : this.values){
        if (compare.compare(element, maxVal) > 0){
          maxID = currentID;
          maxVal = element;
        }
        currentID ++;
      }
      this.values.remove(maxID);
      return maxVal;
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
      int currentID = 0;
      T maxVal = this.values.get(0);
      for (T element : this.values){
        if (compare.compare(element, maxVal) > 0){
          maxVal = element;
        }
      }
      return maxVal;
    } // peek()

    /**
     * Determine if the collection is empty.
     */
    public boolean isEmpty() {
      return this.size == 0;
    } // isEmpty()

  } // class APQ<T>