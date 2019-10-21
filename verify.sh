#!/bin/bash

BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
PINK="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
NORMAL="\033[0;39m"

files=($(find ../libft -name "ft_*.c" -exec basename {} \; | cut -d '.' -f 1))
files_length=${#files[@]}

printf "$WHITE%s\n" "source file"
printf "$YELLOW%s\n" "header file"


for file in "${files[@]}"
do
	#cat ../libft/${file}.c | grep "${file}" | grep -v "\/\*"
	printf $WHITE
	grep "${file}" ../libft/${file}.c | grep -v "\/\*" | grep -v ";" | tr -s \\t
	printf $YELLOW
	grep "${file}(" ../libft/libft.h | tr -s \\t

done
