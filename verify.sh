#!/bin/bash

LIB=../libft

BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
PINK="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
NORMAL="\033[0;39m"


# Check author
if test -f "$LIB/author"; then
	printf "$PINK%s %s!\n" "Hello" $(cat $LIB/author)
else
	printf "$RED%s\n" "Error: no author file"
fi

printf "$NORMAL%s\n" "Norminetting everything..."

# Check norme
norminette $LIB/ft*.c $LIB/libft.h | grep "Warning\|Error"

printf "\n"

# Check if all mandatory source files exist
while read file; do
	if test -f "$LIB/$file.c"; then
		printf "$GREEN%s\n" "$file.c found"
	else
		printf "$RED%s\n" "$file.c not found!"
	fi
done < ft_list.txt

printf "\n"

# Shows header prototype with function definition side by side

files=($(find $LIB -name "ft_*.c" -exec basename {} \; | cut -d '.' -f 1))
files_length=${#files[@]}

printf "$WHITE%s\n" "source file"
printf "$YELLOW%s\n" "header file"


for file in "${files[@]}"
do
	#cat ../libft/${file}.c | grep "${file}" | grep -v "\/\*"
	#printf $WHITE
	SRC=$(grep "${file}" $LIB/${file}.c | grep -v "\/\*" | grep -v ";" | tr -s \\t)
	#printf $YELLOW
	PRO=$(grep "${file}(" $LIB/libft.h | tr -s \\t | cut -d ";" -f 1)
	if [ "$SRC" != "$PRO" ]; then
		printf "$WHITE%s\n" "$SRC"
		printf "$YELLOW%s\n" "$PRO"
	fi
done

printf "$NORMAL\n"
if [ "$1" == "malloc" ]; then
	grep -A 1 "malloc(" $LIB/ft*.c
fi
