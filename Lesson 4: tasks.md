ps:
-e за всички процеси
-o e output 

-- 04-a-5000 
Намерете командите на 10-те най-стари процеси в системата.

```ps -eo pid,cmd,etime | head```

alternatively po start_time:

```ps -e -o pid,cmd --sort=start_time ```

-- 04-a-6000 
Намерете PID и командата на процеса, който заема най-много виртуална памет в системата.

```ps -eo pid,cmd,%mem --sort=-%mem|head -n 2```

-- 04-a-6300
 Изведете командата на най-стария процес
 
```ps -eo cmd,etime|head -n 2```

-- 04-b-5000 
Намерете колко физическа памет заемат всички процеси на потребителската група root.  /*ps -fG root*/

```
ps -u root|ps -eo %mem>memory
awk '{sum1+=$1;sum2+=$2}
END {print "sum=" sum1;print sum2}' memory

awk '{sum1+=$1}
END {print "sum=" sum1}' memory
```

-- 04-b-6100 
Изведете имената на потребителите, които имат поне 2 процеса, чиято команда е vim (независимо какви са аргументите й)
```
ps -elf |grep 'vim'| awk '{if($(wc -l) > 2) print $15}'
```
-- 04-b-6200
Изведете имената на потребителите, които не са логнати в момента, но имат живи процеси
```
ps -elf | grep "$(ps -eo user |uniq |tail -n 1)"
```

-- 04-b-7000 
Намерете колко физическа памет заемат осреднено всички процеси на потребителската група root. Внимавайте, когато групата няма нито един процес.
-drs==the amount of physical memory
-rss==memory we need
```
ps -g root -o rss |awk 'BEGIN{rows=0;sum=0} {rows+=1;sum+=1}END{print sum/rows}'
```

-- 04-b-8000
Намерете всички PID и техните команди (без аргументите), които нямат tty, което ги управлява. Изведете списък само с командите без повторения.

```ps -eo pid,cmd,tty|grep '?$' |uniq```

meaning those processess don't have a terminal that's running them and there is a ?, so we select all and grep the ones with ? on tty

-- 04-b-9000
Да се отпечатат PID на всички процеси, които имат повече деца от родителския си процес.

