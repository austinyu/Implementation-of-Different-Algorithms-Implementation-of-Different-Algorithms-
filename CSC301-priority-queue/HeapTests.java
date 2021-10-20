
/**
 * Run the PriorityQueue tests on Heaps.
 */
public class HeapTests
  extends PriorityQueueTests
{
  public PriorityQueue<Integer> ipq() {
    return new Heap<Integer>((x,y) -> x.compareTo(y));
  } // setupInts

  public PriorityQueue<String> spq() {
    return new Heap<String>((x,y) -> x.compareTo(y));
  } // setupStrings

} // HeapTests
