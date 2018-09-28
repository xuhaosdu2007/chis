#!/bin/bash
for i in $(seq 1 255)
do
	ping -c1 -w1 10.90.6.$i >/dev/null 2>&1
	if [ $? -eq 0 ]
	 then
		echo "$i is up" >> ./uplist.log
		echo "$i is up"
	else
		echo "$i is down"
		echo "$i is down" >> ./downlist.log
	fi
done
