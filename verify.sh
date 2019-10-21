#!/bin/sh

files=(`find ../libft -name "ft_*.c" -exec basename {} \; | cut -d '.' -f 1`)
files_length=${#files[@]}

for file in "${files[@]}"
do
	grep "${file}" ../libft/${file}.c | grep -v "\/\*"
done
