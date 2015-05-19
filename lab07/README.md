#Part B 

Set (Self-Balancing Tree)
Advantages:
- Already balanced and sorted
- Uses less memory to store the items
- Better worst case complexities 
- Worst case O(log n)

Disadvantages
- It is slower than a hash table since it is ordered
- Average case is worse than Hash Tables
- Overall find and insert operations are much slower on average

Unordered Set (Hash Table)
Advantages:
- Has a faster runtime because it is unordered
- Average case is usually much faster
- O(1) average case

Disadvantages
- It may not be balanced
- Takes more memory to store the items
- O(N) at worst case

What else might you like to be able to measure to compare the
two data structures?
- You may want to test the runtime of the 
  erase operation to see which one is more efficient.
- You may also want to test the runtime of the swap operation to see
  which of the two is more efficient.
- You may also want to measure the time it takes to implement each and
  may want to try multiple coding scenarios to see which is the more
  efficient in each case.