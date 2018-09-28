#!bin/bash
##fun define###
echo "fun define";

#fun define first ,the use
function hello(){

echo "hello!";
}
function hello_param(){
	echo "hello $1";
}

##fun use##
echo "fun use";
hello;

echo "fun param use"
hello_param smart;

##fun file##
echo "fun file use";
. demo_call.sh;
callfun smart;

##load##
echo "load";


funwithparam(){
	echo "first param is $1"
	echo "sec param is $2"
	echo "fifth param is $5"
	echo "amout of param is $# !"
	echo "string of param is $* !"
}

funwithparam 1 2 3 4 5

##return##
echo "fun retrun"

funwithreturn(){
	echo "get the sum of two nmubers"
	echo -n "first number"
	read anum
	echo -n "another number"
	read anothernum
	echo "the two nmubers is $anum and $anothernum !"
	return $(($anum + $anothernum))
	
}
funwithreturn
echo "the sum of two numbers is $? !"
