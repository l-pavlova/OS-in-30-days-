-- 03-a-0200

 Сортирайте /etc/passwd лексикографски по поле UserID.
 
  ```sort -t : -k 3 passwd```

-t, --field-separator we say sort by field sep semicolon, and order by third column with -k

03-a-0201

 Сортирайте /etc/passwd числово по поле UserID.(Открийте разликите с лексикографската сортировка) 

```sort -t : -k 3 -n passwd``` -n for numeric

-- 03-a-0210

Изведете само 1-ва и 5-та колона на файла /etc/passwd спрямо разделител ":".

```cat passwd | sed 's/:/ /' |awk '{print $1, $5}'```

-- 03-a-0211

Изведете съдържанието на файла /etc/passwd от 2-ри до 6-ти символ.

```cat passwd| head -c 6 | tail -c 4 ```
-c for character

-- 03-a-1500

Намерете броя на символите в /etc/passwd. А колко реда има в /etc/passwd?

```cat passwd|wc -m```
 -m, --chars print the character counts
 
-- 03-a-2100

Отпечатайте потребителските имена и техните home директории от /etc/passwd.

```cat passwd| sed 's/:/ /'|awk '{print $1, $6}'```
-s, --separate by semicol and replace it with empty space

-- 03-a-2110

 Отпечатайте втората колона на /etc/passwd, разделена спрямо символ '/'.

```cat passwd|cut -d'/' -f2```

-- 03-a-3000

 Запаметете във файл в своята home директория резултатът от командата ls -l изпълнена за вашата home директорията.
Сортирайте създадения файла по второ поле (numeric, alphabetically).
```
ls -l>filesAtHome.txt
cat filesAtHome.txt | sort -n -k 2
```

-- 03-a-5001

Колко хора не се казват Ivan според /etc/passwd
```
cat passwd |sed '/Ivan/d'|wc -l
```
takes password deletes ivan entries and counts the lines

-- 03-a-5002

Изведете имената на хората с второ име по-дълго от 7 (>7) символа според /etc/passwd

```awk -F ":" 'length($5) >7 {print $5}' passwd``` setting field separator with -F

-- 03-a-5003

Изведете имената на хората с второ име по-късо от 8 (<=7) символа според /etc/passwd // !(>7) = ?
```awk -F ":" 'length($5) <=7 {print $5}' passwd```



-- 03-a-5004

Изведете целите редове от /etc/passwd за хората от 03-a-5003

```awk -F ":" 'length($5) <7 {print }' passwd```

-- 03-b-0300

Намерете факултетния си номер във файлa /etc/passwd.

```awk -F ":" '/Lusi/ {print $1 "\t"}' passwd```


-- 03-b-3000

Запазете само потребителските имена от /etc/passwd във файл users във вашата home директория.
```awk -F "[:|,]" '{print $5 > "users"}' passwd```


-- 03-b-3400

Колко коментара има във файла /etc/services ? Коментарите се маркират със символа #, след който всеки символ на реда се счита за коментар.
```awk '/#/ {print}' /etc/services| wc -l```

-- 03-b-3450

Вижте man 5 services. Напишете команда, която ви дава името на протокол с порт естествено число N. Командата да не отпечатва нищо, ако търсения порт не съществува (например при порт 1337). Примерно, ако номера на порта N е 69, командата трябва да отпечати tftp.



-- 03-b-3500

Колко файлове в /bin са shell script? (Колко файлове в дадена директория са ASCII text?)

``` find /bin/ -type f -name "*.sh"|wc -l```


-- 03-b-3600

Направете списък с директориите на вашата файлова система, до които нямате достъп. Понеже файловата система може да е много голяма, търсете до 3 нива на дълбочина. А до кои директории имате достъп? Колко на брой са директориите, до които нямате достъп?

```find ~ -maxdepth 3 ! -writable |wc -l```

-- 03-b-4000

Създайте следната файлова йерархия.
/home/s...../dir1/file1
/home/s...../dir1/file2
/home/s...../dir1/file3 

```
cd ./dir1
touch file1
touch file2
touch file3
```
Посредством vi въведете следното съдържание:
file1:
1
2
3

file2:
s
a
d
f

file3:
3
2
1
45
42
14
1
52

Изведете на екрана:
	* статистика за броя редове, думи и символи за всеки един файл ```wc -l -w -c <file1```
	* статистика за броя редове и символи за всички файлове ```wc -l -c <file1```
	* общия брой редове на трите файла  ```awk '{print}' file1 file2 file3|wc -l```

-- 03-b-4001

Във file2 подменете всички малки букви с главни.

```tr '[a-z]' '[A-Z]' <file2.txt```

-- 03-b-4002

Във file3 изтрийте всички "1"-ци.

```sed 's/1/ /' file3```


-- 03-b-4003

Изведете статистика за най-често срещаните символи в трите файла.
``` cat file1 file2 file3 | sort | uniq -c | head -n 1 ```


-- 03-b-4004

Направете нов файл с име по ваш избор, който е конкатенация от file{1,2,3}.
Забележка: съществува решение с едно извикване на определена програма - опитайте да решите задачата чрез него.

```cat file1 file2 file3 >newfile```

-- 03-b-4005

Прочетете текстов файл file1 и направете всички главни букви малки като запишете резултата във file2.
```tr '[a-z]' '[A-Z]' <file1 >file2 ```

-- 03-b-5200

Изтрийте всички срещания на буквата 'a' (lower case) в /etc/passwd и намерете броят на оставащите символи.

```tr -d 'a' < /etc/passwd |wc -m ```

-- 03-b-5300

Намерете броя на уникалните символи, използвани в имената на потребителите от /etc/passwd.

```sort passwd |uniq|wc -m```

-- 03-b-5400

Отпечатайте всички редове на файла /etc/passwd, които не съдържат символния низ 'ov'.

``` egrep '^[ov]' passwd```

-- 03-b-6100

Отпечатайте последната цифра на UID на всички редове между 28-ми и 46-ред в /etc/passwd.

```cat passwd |head -n 47| tail -n 20 |awk -F ":" '{print $3}' ```


-- 03-b-6700

Отпечатайте правата (permissions) и имената на всички файлове, до които имате read достъп, намиращи се в директорията /tmp.

```find /tmp -type f -perm -u=r (not correct)```


-- 03-b-6900

Намерете имената на 10-те файла във вашата home директория, чието съдържание е редактирано най-скоро. На първо място трябва да бъде най-скоро редактираният файл. Намерете 10-те най-скоро достъпени файлове. (hint: Unix time)

```find / -type f -print "%T@ %f \n " | sort -k 1 | tail -n 10 | cut -d " " -f 2 ```


-- 03-b-7000

Файловете, които съдържат C код, завършват на `.c`. Колко на брой са те във файловата система (или в избрана директория)? Колко реда C код има в тези файлове?
```find ~ -type f -name [.c$]|wc -l```

-- 03-b-7500

Даден ви е ASCII текстов файл (например /etc/services). Отпечатайте хистограма на N-те (например 10) най-често срещани думи.



-- 03-b-8000

Вземете факултетните номера на студентите от СИ и ги запишете във файл si.txt сортирани.

```awk -F ":" '{print $1}' passwd| sed 's/s//'|sort -n >si.txt```

-- 03-b-8500

За всеки логнат потребител изпишете "Hello, потребител", като ако това е вашият потребител, напишете "Hello, потребител - this is me!".

Пример:
hello, human - this is me!
Hello, s63465
Hello, s64898

```awk -v var=$(whoami) -F ":" '{if(var==$1) print "Hello, $var this is me!"; else printf "Hello, %s\n", $1}' passwd```

-- 03-b-8520

Изпишете имената на студентите от /etc/passwd с главни букви.

``` awk -F "[:|,]" '{print $5}' passwd |tr "[a-z]" "[A-Z]" ```


-- 03-b-8600

Shell Script-овете са файлове, които по конвенция имат разширение .sh. Всеки такъв файл започва с "#!<interpreter>" , където <interpreter> указва на операционната система какъв интерпретатор да пусне (пр: "#!/bin/bash", "#!/usr/bin/python3 -u"). 

Намерете всички .sh файлове и проверете кой е най-често използваният интерпретатор.



-- 03-b-8700

Намерете 5-те най-големи групи подредени по броя на потребителите в тях.



-- 03-b-9000

Направете файл eternity. Намерете всички файлове, които са били модифицирани в последните 15мин (по възможност изключете .).  Запишете във eternity името на файла и часa на последната промяна.

-- 03-b-9051
make a get request for population.csv
```curl```-взима резултата от http request в терминала
 curl "http:/rnd.qtrp.org/population.csv" >population.csv

Използвайки файл population.csv, намерете колко е общото население на света през 2008 година. А през 2016?



-- 03-b-9052

Използвайки файл population.csv, намерете през коя година в България има най-много население.




-- 03-b-9053

Използвайки файл population.csv, намерете коя държава има най-много население през 2016. А коя е с най-малко население?
(Hint: Погледнете имената на държавите)

-- 03-b-9054

Използвайки файл population.csv, намерете коя държава е на 42-ро място по население през 1969. Колко е населението й през тази година?


-- 03-b-9101
В home директорията си изпълнете командата `curl -o songs.tar.gz "http://fangorn.uni-sofia.bg/misc/songs.tar.gz"`

Да се разархивира архивът songs.tar.gz в папка songs във вашата home директорията.
 
 ```tar -xvf songs.tar.gz ```

-- 03-b-9102
Да се изведат само имената на песните.

```awk -F "[-|(]" '{print $2}' songs.txt```

-- 03-b-9103

Имената на песните да се направят с малки букви, да се заменят спейсовете с долни черти и да се сортират.

```awk -F "[-|(]" '{print $2}' songs.txt| tr "[A-Z]" "[a-z]"|sed 's/ //'|sed 's/ /_/g'|sort```

-- 03-b-9104

Да се изведат всички албуми, сортирани по година.

```awk -F "[-|(|)]" '{print $3}' songs.txt|sort -t, -nk2 ``` - -t delimeter for sort, numerical, column 2

-- 03-b-9105

Да се преброят/изведат само песните на Beatles и Pink.

```grep '[Beatles|Pink]' songs.txt|wc -l```

-- 03-b-9106

Да се направят директории с имената на уникалните групи. За улеснение, имената от две думи да се напишат слято:
Beatles, PinkFloyd, Madness
```
cat songs.txt | cut -d " " -f 1 | sort | uniq |exec mkdir {}
cat songs.txt | cut -d " " -f 1 | sort | uniq |xargs -I{} mkdir {} 
-I  replace-str

```

-- 03-b-9200

Напишете серия от команди, които извеждат детайли за файловете и директориите в текущата директория, които имат същите права за достъп както най-големият файл в /etc директорията.

```
 find . -perm $(find /etc -printf "%s %m %p \n" 2>/dev/null| sort -nk 1 | tail -n 1 | cut -d " " -f 2) -print 2>/dev/null | xargs -I{} stat {}
```
-- 03-b-9300

Дадени са ви 2 списъка с email адреси - първият има 12 валидни адреса, а вторията има само невалидни. Филтрирайте всички адреси, така че да останат само валидните. Колко кратък регулярен израз можете да направите за целта?

Валидни email адреси (12 на брой):
email@example.com
firstname.lastname@example.com
email@subdomain.example.com
email@123.123.123.123
1234567890@example.com
email@example-one.com
_______@example.com
email@example.name
email@example.museum
email@example.co.jp
firstname-lastname@example.com
unusually.long.long.name@example.com

Невалидни email адреси:
#@%^%#$@#$@#.com
@example.com
myemail
Joe Smith <email@example.com>
email.example.com
email@example@example.com
.email@example.com
email.@example.com
email..email@example.com
email@-example.com
email@example..com
Abc..123@example.com
(),:;<>[\]@example.com
just"not"right@example.com
this\ is"really"not\allowed@example.com


```grep -E '^[A-Za-z0-9+._-]+@([a-zA-Z0-9-]+\.)+[a-zA-Z]$' mails.txt ```
/*idk tho, not really working*/



