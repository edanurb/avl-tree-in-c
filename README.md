# avl-tree-in-c

In-order walk on avl tree produce the sorted list

<br>
When the program runs, it will expect you to enter the numbers you want to insert. After you have entered all the numbers, you will end the number entry process by pressing the -1
key.When the process is finished, you will have inserted all the numbers into the avl tree and the structure of this avl tree will be printed on the screen.
<br>

## Example:
**Input:** <br>
72<br>
18<br>
28<br>
36<br>
27<br>
117<br>
108<br>
90<br>
-1<br>
<br>
**Output:** <br>
18<br>
27<br>
28<br>
36<br>
72<br>
90<br>
108<br>
127<br>

28 (-1 B)<br>
18 (28 L) (-1 B) 72 (28 R) (-1 B)<br>
27 (18 R) (0 B) 36 (72 L) (0 B) 108 (72 R) (0 B)<br>
90 (108 L) (0 B) 117 (108 R) (0 B)<br>
