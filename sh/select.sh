#!/bin/bash
select ch in "begin" "end" ""; do
case $ch in
	"start" | "begin")
		echo "start"
	;;
	"stop" | "end")
		echo "stop"
	;;
	*)
		echo "ignorant"
	;;
esac
done;
