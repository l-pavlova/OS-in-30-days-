#!/bin/bash

echo "<table>"
echo "<th>Username</th>"
echo "<th>group</th>"
echo "<th>login shell</th>"
echo "<th>GECHO</th>"

#1 4 7 5 
while IFS= read -r line
do
	echo "<tr>""<td>"
	echo $line |cut -d ":" -f1
	echo "</td>"
 	echo "<td>"
	echo $line |cut -d ":" -f4
	echo "</td>" 
	echo "<td>"
  	echo $line |cut -d ":" -f7
	echo "</td>"
	echo "<td>"  
	echo $line | cut -d ":" -f5
	echo "</td>" 
	echo "</tr>" 
done < /etc/passwd
echo "</table>"

