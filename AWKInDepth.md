**Syntax**

BEGIN {awk-commands}
The BEGIN block gets executed at program start-up. It executes only once. This is good place to initialize variables.
BEGIN is an AWK keyword and hence it must be in upper-case. This block is optional.

Body Block
The syntax of the body block is as follows −

/pattern/ {awk-commands}
The body block applies AWK commands on every input line. By default, AWK executes commands on every line. 
We can restrict this by providing patterns. Note that there are no keywords for the Body block.

END Block
The syntax of the END block is as follows −

END {awk-commands}
The END block executes at the end of the program. END is an AWK keyword and hence it must be in upper-case. This block is optional.

**task1.**
we have *marks.txt* looking like this

          1) Nasko Physics 80
          2) Bizi Maths 90
          3) Pusi Biology 87
          4) Bario English 85
          5) Moris History 89
          
Let's now display the file contents with header by using AWK script.
```awk 'BEGIN{printf "SrNo\tName\tSub\tMarks\n"} {print}' marks.txt```

Output

        SrNo Name Sub Marks
        1) Nasko Physics 80
        2) Bizi Maths 90
        3) Pusi Biology 87
        4) Bario English 85
        5) Moris History 89
**task2.**

*AWK Command Line*
 
We can specify an AWK command within single quotes at command line:

```awk [options] file ...```

 ```awk '{print}' marks.txt```
 
* AWK Program File - We can provide AWK commands in a script file:*

```awk [options] -f file ....``` - First, create a text file **command.awk** containing the AWK command as shown below :
**command.awk:**

          {print}
          
Now we can instruct the AWK to read commands from the text file and perform the action. Here, we achieve the same result as shown in the above example.

```awk -f command.awk marks.txt```

The -v option

This option assigns a value to a variable. It allows assignment before the program execution. The following example describes the usage of the -v option.

``` awk -v name=Kasko 'BEGIN{printf "Name = %s\n", name}'```

On executing this code, you get the following result 

      Name = Kasko

**Printing Column or Field**

Display only 3rd and 4th columns of marks.txt

``` awk '{print $3 "\t" $4}' marks.txt```

result:
```
Physics	80
Maths	90
Biology	87
English	85
History	89
```

**task3**. printing a pattern

```awk '/z/' marks.txt```

result:

```2) Bizi Maths 90```

only grades:
```awk '/a/ {print $3 "\t" $4}' marks.txt```

result:```Maths 90```

printing lines with certain length:

```awk 'length($0) > 18' marks.txt```

result: 
```
4) Bario English 85
5) Moris History 89
```

task4. working with variables

Standard AWK variables
- ARGC
It implies the number of arguments provided at the command line.

```awk 'BEGIN {print "Arguments =", ARGC}' One Two Three Four```

result: ```Arguments = 5```

```
awk 'BEGIN { 
   for (i = 0; i < ARGC - 1; ++i) { 
      printf "ARGV[%d] = %s\n", i, ARGV[i] 
   } 
}' one two three four
```

result:
```
ARGV[0] = awk
ARGV[1] = one
ARGV[2] = two
ARGV[3] = three
```

- CONVFMT -represents the conversion format for numbers. Its default value is %.6g.
- ENVIRON -an associative array of environment variables.
```awk 'BEGIN { print ENVIRON["USER"] }'```
- FILENAME - represents the current file name.

```awk 'END {print FILENAME}' marks.txt```

  task5. Regular expressions
  ```
  *dot*
  echo -e "cat\nbat\nfun\nfin\nfan" | awk '/f.n/'
  fun
  fin
  fan

*start of the line*
  echo -e "This\nThat\nThere\nTheir\nthese" | awk '/^The/'
  There
  Their
  
 *end of the line*
  
  echo -e "knife\nknow\nfun\nfin\nfan\nnine" | awk '/n$/'
  fun
  fin
  fan
  
  *set of characters*
  echo -e "Call\nTall\nBall" | awk '/[CT]all/'
  
  Call
  Tall
  
  *exclusive set*
  echo -e "Call\nTall\nBall" | awk '/[^CT]all/'
  Ball
  
  *alteration*
  echo -e "Call\nTall\nBall\nSmall\nShall" | awk '/Call|Ball/'
  call or ball
  
  *Zero or One Occurrence*
  echo -e "Colour\nColor" | awk '/Colou?r/'
  color 
  colour
  
  *Zero or More Occurrences*
  echo -e "ca\ncat\ncatt" | awk '/cat*/'
  ca
  cat
  catt
  
  *One or More Occurrences*
  echo -e "111\n22\n123\n234\n456\n222"  | awk '/2+/'
   22
  123
  234
  222
  
 Parentheses () are used for grouping and the character | is used for alternatives. For instance, the following regular expression matches the lines containing either Apple Juice or Apple Cake.
 Example
 echo -e "Apple Juice\nApple Pie\nApple Tart\nApple Cake" | awk '/Apple (Juice|Cake)/'
 ```
 
 AWK - Arrays
 ```
 awk 'BEGIN {
   fruits["mango"] = "yellow";
   fruits["orange"] = "orange"
   print fruits["orange"] "\n" fruits["mango"]
}'

awk 'BEGIN {
   fruits["mango"] = "yellow";
   fruits["orange"] = "orange";
   delete fruits["orange"];
   print fruits["orange"]
}'
```

Control flow
```
awk 'BEGIN {num = 10; if (num % 2 == 0) printf "%d is even number.\n", num }'
10 is even number.
```

Loops

```
awk 'BEGIN { for (i = 1; i <= 5; ++i) print i }'
awk 'BEGIN {i = 1; while (i < 6) { print i; ++i } }'
 awk 'BEGIN {
   sum = 0; for (i = 0; i < 20; ++i) { 
      sum += i; if (sum > 50) break; else print "Sum =", sum 
   } 
}'
*exit code 10*
awk 'BEGIN {
   sum = 0; for (i = 0; i < 20; ++i) {
      sum += i; if (sum > 50) exit(10); else print "Sum =", sum 
   } 
}'
```
redirection ``` awk 'BEGIN { print "Hello, World !!!" > "/tmp/message.txt" }'```

```awk 'BEGIN { print "hello, world !!!" | "tr [a-z] [A-Z]" }'```

Format specifiers like in c
  
  
