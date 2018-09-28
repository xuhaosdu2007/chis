//enum a wrong number test,don't report wrong

#include <stdio.h>
#include <stdlib.h>

enum TEST
{
	fir = 1,
	sec = 2
};
main()
{

enum TEST
{
	fir = 1,
	sec = 2
};
enum TEST  ss;
ss = (enum TEST)(4);
printf("ss is %d",ss);
}
