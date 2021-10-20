import java.util.Comparator;

/**
 * Run the PriorityQueue tests on APQs.
 */
public class APQTests
  extends PriorityQueueTests
{
  public PriorityQueue<Integer> ipq() {
    return new APQ<Integer>((x,y) -> x-y);
  } // setupInts

  public PriorityQueue<String> spq() {
    return new APQ<String>((x,y) -> x.compareTo(y));
  } // setupStrings
} // APQTests
