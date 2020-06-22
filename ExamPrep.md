1. egrep -v '[a-w]' pjf.txt | egrep '[0-9]'| wc -l

5. find . -user $USER | wc -l

6. find -type f -size 0 | xargs rm

7.egrep -a /SI/ ../../passwd | cut -d ":" -f 1,5 | awk '{print substr($0,2,2)}'| sort -n | tail -n 1
without family name check

8.find . -type f -printf "%n %p\n" | sort -n | head -n 5 | cut -d "/" -f2

9. ls -li -lc | grep grade | sort -t ' ' -gk3,3r -gk8,8 | cut -d " " -f 1 | head -n 1

10. cat ../../passwd |grep "SI" | cut -c2- | sort -t ":" -n -k 1 | cut -d ":" -f5,6 

11.$ cat ../../passwd | grep /home/SI | cut -d ":" -f5- | cut -d ',' -f4 | find -type f -printf "%T@ %p"

12. pwd $(ls -li | grep $(ls -li | grep grade | ls -li | grep grade | sort -t ' ' -k 8| cut -d " " -f 1 | head -n 1)) | tr '/' ' ' | wc -w
