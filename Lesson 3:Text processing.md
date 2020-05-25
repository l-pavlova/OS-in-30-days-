# OS-in-30-days
learning os concepts for the os uni course from the start with me



# Lesson 3:Text processing

**File redirection**

- ```cmd >file``` redirects stdout to a file
- ```cmd 2>file``` redirects stderr to a file (overwrite)
- ```cmd 2>/dev/null``` discard stderr of cmd
- ```cmd <file``` pass file to stdin of cmd
```cmd <EEOL \n line1 \n line2 \n EOL``` pass file to stdin of cmd
- ```{cmd1; cmd2;}>file ```
- ```cmd1|cmd2``` pass stdout of cmd1 to stdin of cmd2
- ```cmd1 2>&1 |cmd2 ``` stdout and stderr
- ```cmd |tee file``` redirect stdout to a file and print it to the screen

examples:
-``` sort < /etc/passwd```
-``` echo 100000 > /proc/sys/fs/file-max```
-``` ls -alR /proc/ 2> /dev/null```
-``` ls -R /proc/ > output 2>&1```
-``` ls -R /proc/ &> output```

summary:
```
- < STDIN from a file
- > STDOUT to a file (overwrite)
- >> STDOUT to a file (append)
- 2> STDERR to a file (overwrite)
- 2>> STDERR to a file (append)
- &> both STDOUT and STDERR
```
**Piping commands together**
- ls -al | less
- cut -d: -f6 /etc/passwd|sort|uniq -c|sort -rn
- redirection and piping can be combined
- usually used for feeding STDERR into the pipeline along with STDOUT

**Combining files and merging text**
- ```cat - concatenate files
- ```paste ```- merges text from multiple files
            -s option to merge files serially
            - uses tabs as default delimiter
- ```wc``` - print line, word, and byte counts for each file

       -c, --bytes - print the byte counts
       
       -m, --chars - print the character counts
       
       -l, --lines - print the newline counts
       
       -w, --words - print the word counts

- ```cut``` - extracts sections from each line of files

               -c - characters
               
               -f - fields
               
               -d - delimiter (TAB)
               
 most useful on structured input (text with columns), cannot change order (𝑁 ≤ 𝑀)

- ```grep``` searches for patterns within files

         -n shows line numbers
         
         -A NUM prints match and NUM lines after match
         
         -B NUM prints match and preceding NUM lines
         
         -C NUM prints match and NUM lines before and after
         
         -i performs case insensitive match
                  
         -v inverts match; prints what doesn’t match
         
         --color highlight matched string in color
                 
         
**The streaming editor**
 - ```sed``` - stream editor for filtering and transforming textq, usually the output of another program,  often used to automate edits on many files quickly, small and very efficient
 
           -i option for in place edits with modern versions
           
-```tr a-z A-Z``` translates one set of characters into another(Replacing text characters with tr)
               squeeze collapses duplicate characters
               ```tr -s '\n'```
               deletes a set of characters
               ```tr -d '\000'```

**Text processing with awk**
- ```awk``` - pattern scanning and processing language
- splits lines into fields (like cut)
- regex pattern matching (like grep)
- math operations, control statements, variables,IO


```BEGIN {awk-commands}```

The BEGIN block gets executed at program start-up. It executes only once. This is good place to initialize variables. BEGIN is an AWK keyword and hence it must be in upper-case. Please note that this block is optional.

Body Block

The syntax of the body block is as follows −

```/pattern/ {awk-commands}```
The body block applies AWK commands on every input line. By default, AWK executes commands on every line. We can restrict this by providing patterns. Note that there are no keywords for the Body block.

END Block

```END {awk-commands}```
The END block executes at the end of the program. END is an AWK keyword and hence it must be in upper-case. Please note that this block is optional.
examples:

    -  awk '{ print $1 }' 
    -  awk -F ':' '$1 ~ "foo" { print $2 }'
    -  awk '$1 != 1 { print $2 }'
    -  awk '{ sum += $1 } END { print sum }'
    -  awk -v "foo=${BAR}" '....'
more in https://github.com/l-pavlova/OS-in-30-days-/blob/master/AWKInDepth.md
**Text sorting**
- ```sort``` sorts text, can sort on different columns

      -  -k, --key=KEYDEF
      -  -t, --field-separator=SEP
     
- by default sorts in lexicographical order aka  1, 2, 234, 265, 29, 3, 4, 5
- can be told to sort numerically (-n) aka 1, 2, 3, 4, 5, 29, 234, 265
- can merge and sort multiple files simultaneously
- can sort in reverse order -r
- often used to prepare input for the uniq command

**Duplicate removal utility**
- ```uniq``` - removes duplicate adjacent lines from sorted text
-  -c - prefixes each line of output with a number indicating number of occurrences

**Filename matching**
- many commands take a list of filenames as arguments
- wildcard patterns,  “file globbing”

**Wildcard patterns**
- ? - matches any single character
- * - matches anything (any number of characters)
- [...] - character classes
- the - character denotes a range
- examples: [abcd2345] [a-d2-5] [a-gA-Z0-5]

**Brace expansion**
- allows generation of arbitrary strings
- similar to wildcards, but target files or directories don’t need to exist
- {m,n,o,on} expands to: m, n, o and on
- b{a,o,u,e,i}g expands to: bag, bog, bug, beg, big
- can be combined with wildcards; brace expansion occurs before globbing

**General quoting rules**

- metacharacters \ ? ( )-executes first the comand inside $-gets value of variable ... * % { } [ ]
- backslash \ - supresses one character, that character doesn't get read e.g new line
- double Quotes " " runs string as code, notices $ and ``
- single Quotes ' ' runs string without special characters

**Nesting commands**

- command substitution - substitutes output of command in place of “embedded” command-
- `command` - do not use
- $(command) - preferred method

**Multiple and multi-line commands**

- entering multiple commands on one command line
- separate commands with a semi-colon ;
- entering multi-line commands
- use backslash \
- line wrapping / continuation
**Regular expressions**

- Regular Expressions (REs) provide a mechanism to select specific strings from one or more lines of text
- grep, sed, perl, …
- man 7 regex
- most characters, letters and numbers match themselves
- special characters are matchable
- . matches any single character
- specify where the match must occur with anchors

- \t tab
- \n newline/line feed
- \r carriage return
- \f form feed
- \c control characters
- \x character in hex
- . any single character

**RE anchors**

- ^RE anchor RE at start of line
- RE$ anchor RE at end of line
- \<RE anchor RE at start of word
- RE\> anchor RE at end of word

**RE character classes**

- Character classes, [...], match any single character in the list
- RE [0123456789] matches any single digit
- Some predefined character classes
- [:alnum:] [:alpha:] [:cntrl:] [:digit:]
- [:lower:] [:punct:] [:space:] [:upper:]
- The - character denotes a range
- RE [[:alnum:]] equivalent to [0-9A-Za-z]

**RE character classes examples**
- grep [[:upper:]] /etc/passwd
- egrep '^[rb]' /etc/passwd
- egrep '^[^rb]' /etc/passwd

**RE quantifiers**
- Control the number of times a preceding RE is allowed to match
- * match 0 or more times
- + match 1 or more times
- ? match 0 or 1 times
- {n} match exactly n times
- {n,} match at least n times
- {n,m} match at least n but not more than m times

      egrep '^[stu].{14}$' /usr/share/dict/words
      egrep '^[aeiou].{9}ion$' /usr/share/dict/words
      egrep '^c.{15,}$' /usr/share/dict/words
      egrep '^n.{6,10}c$' /usr/share/dict/words
**RE parenthesis**

- (RE) creating a new atom
- (RE)\n non-zero digit - storing values
- (RE1|RE2) alternation: RE1 or RE2
- abc{3} vs. (abc){3}
   ```$ cat file```
Parenthesis allow you to store matched patterns.
```$ sed -r 's/(.)\1/\[\1\1\]/g' file```
Parenthesis a[ll]ow you to store matched
pa[tt]erns.
```egrep '(dog|cat)' file```

**Text editing**

vi / vim
- vi The Visual Editor
- :help
Basic vi
- Insert Mode:  i keystrokes are inserted into the document
- Command Mode:  esc keystrokes are interpreted as commands
- hjkl up down left right
- i a [ESC] x dd
- Saving & exiting
- :w safe
- :q quit
- :wq safe and quit
- :wq!

