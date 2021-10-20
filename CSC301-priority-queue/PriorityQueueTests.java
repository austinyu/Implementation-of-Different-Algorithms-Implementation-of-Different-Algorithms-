/**
 * A generic set of priority queue tests (I hope).  Do not run these
 * tests directly.  Rather, subclass and implement setupInts and
 * setupStrings.
 */

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertAll;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.RepeatedTest;
import org.junit.jupiter.api.Test;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Comparator;

public abstract class PriorityQueueTests {
  /**
   * Create a priority queue of integers, using the standard ordering.
   */
  abstract PriorityQueue < Integer > ipq();

  /**
   * Create a priority queue of strings, using the standard ordering.
   */
  abstract PriorityQueue < String > spq();

  @Test
  void addOneElement() throws Exception {
    PriorityQueue < Integer > ints = ipq();
    PriorityQueue < String > strs = spq();
    assertAll(() -> ints.add(5),
      () -> strs.add("five"));
  } // addOneElement()

  @Test
  void addMultipleElements1() throws Exception {
    PriorityQueue < Integer > ints = ipq();
    ints.add(1);
    ints.add(2);
    ints.add(3);
    assertEquals(3, ints.peek());
  } // addMultipleElements1()

  @Test
  void addMultipleElements2() throws Exception {
    PriorityQueue < Integer > ints = ipq();
    ints.add(3);
    ints.add(2);
    ints.add(1);
    assertEquals(3, ints.peek());
  } // addMultipleElements1()

  @Test
  void trombones()
  throws Exception {
    PriorityQueue < Integer > instruments = ipq();
    instruments.add(76);
    assertEquals(instruments.peek(), 76);
    assertEquals(instruments.remove(), 76);
    assertTrue(instruments.isEmpty());
  } // trombones

  @Test
  void addToNonemptyPQ()
  throws Exception {
    PriorityQueue < Integer > numbers = ipq();
    numbers.add(5);
    numbers.add(100);
    assertEquals(numbers.peek(), 100);
    assertEquals(numbers.remove(), 100);
  } // addToNonempty 

  @Test
  void isEmptyTest()
  throws Exception {
    PriorityQueue < Integer > numbers = ipq();
    assertTrue(numbers.isEmpty());
  } // isEmptyTest()

  @Test
  void peakTest()
  throws Exception {
    PriorityQueue < Integer > numbers = ipq();
    numbers.add(5);
    numbers.add(6);
    numbers.add(3);
    numbers.add(13);
    int first = numbers.peek();
    numbers.add(0);
    int second = numbers.peek();
    assertEquals(first, second);
  } // peakTest() 

  @Test
  void EmptyExceptionTest()
  throws Exception {
    PriorityQueue < Integer > numbers = ipq();
    assertThrows(CollectionEmptyException.class,
      () -> numbers.remove());
    assertThrows(CollectionEmptyException.class,
      () -> numbers.peek());
  } // EmptyExceptionTest()

  @Test
  void CompTest()
  throws Exception {
    PriorityQueue < Integer > numbers = ipq();
    numbers.add(8);
    numbers.add(2);
    numbers.add(18);
    numbers.add(1);
    numbers.add(4);
    numbers.add(6);
    numbers.add(90);
    numbers.add(23);
    numbers.add(55);
    numbers.add(0);
    assertEquals(numbers.peek(), 90);
    assertEquals(numbers.remove(), 90);
    assertEquals(numbers.remove(), 55);
  } // CompTest()

  @Test
  void randomTest() throws Exception {
    PriorityQueue < Integer > ints = ipq();
    ArrayList < Integer > book = new ArrayList < Integer > ();
    int current;
    int iter = 10000;
    for (int i = 0; i < iter; i++) {
      Random r = new Random();
      current = r.nextInt(1000);
      ints.add(current);
      book.add(current);
      //System.out.println(book.get(book.size() - 1) + " : " + current);
    }
    book.sort(Comparator.naturalOrder());
    Collections.reverse(book);
    int pop;
    for (int i = 0; i < iter; i++) {
      pop = ints.remove();
      // System.out.println(book.get(i) + " Expected : Heap " + pop + " : index : " + i);
      assertEquals(book.get(i), pop);
    }
  } // randomTest()

} // class PriorityQueueTests