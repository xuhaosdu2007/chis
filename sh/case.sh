#!/bin/bash
case $1 in
	start | begin)
		echo "start"
	;;
	stop | end)
		echo "stop"
	;;
	*)
		echo "ignorant"
	;;
esac
