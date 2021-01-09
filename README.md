# CodeDojo

81. Given a mapping of digits to letters (as in a phone number), and a digit string, return all possible letters the number could represent. You can assume each valid number in the mapping is a single digit. For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].

82. Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters. For example, given a file with the content “Hello world”, three read7() returns “Hello w”, “orld” and then “”.

83. Invert a binary tree. For example, given the following tree:
``` 
    a          a
   / \        / \
  b   c  =>  c   b
 / \  /      \  / \
d   e f       f e  d
```

84. Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water. For example, this matrix has 4 islands.
```
1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
```

85. Given three 32-bit integers x, y and b, return x if b is 1 and y if b is 0, using only mathematical or bit operations. You can assume b can only be 1 or 0.

86. Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid (i.e. each open parenthesis is eventually closed). For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must remove all of them.

87. A rule looks like this:
```
A NE B
```
This means point A is located northeast of point B.
```
A SW C
```
means that point A is southwest of C.

Given a list of rules, check if the sum of the rules validate. For example:
```
A N B
B NE C
C N A
```
does not validate, since A cannot be both north and south of C.
```
A NW B
A N B
```
is considered valid.
