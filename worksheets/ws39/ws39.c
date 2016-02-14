To illustrate, assume the list to be sorted is as follows:
624 762 852 426 197 987 269 146 415 301 730 78 593
The following table shows the sequences of elements found in each bucket during the
four steps involved in sorting the list. During pass 1 the one’s place digits are ordered.
Each value that ends in the same digit is placed into the same bucket. During pass 2, the
ten’s place digits are ordered. However, because we are using a queue the relative
positions set by the earlier pass are maintained. Again all elements that are the same in
the 10’s place are placed in the same bucket. On pass 3, the hundred’s place digits are
ordered. After three passes, the result is a completely ordered collection.
Bucket Pass 1 Pass 2 Pass 3
0 730 301 78
1 301 415 146,197
2 762, 852 624, 426 269
3 593 730 301
4 624 146 415, 426
5 415 852 593
6 426, 146 762, 269 624
7 197, 987 78 730, 762
8 78 987 852
9 269 593, 197 987
As a function of d, the number of digits in each number, and n, the number of values
being sorted, what is the algorithmic complexity of radix sorting?
How does this compare to merge sort, quick sort, or any of the other fast sorting
algorithms we have seen?
In the space in the right of the table above perform a radix sort on the following values,
showing the result after each pass: 742 247 391 382 616 872 453 925 732 142 562.