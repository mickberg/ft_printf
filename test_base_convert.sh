# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_base_convert.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 18:39:18 by mberglun          #+#    #+#              #
#    Updated: 2019/12/18 19:01:28 by mberglun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

i=0;
while [ $i -lt 1214748364 ]; do
	test=$(./printf "$i" 10 16)
	exp=$(echo "ibase=10; obase=16; $i" | bc)
	echo "$test" > test_tmp
	echo "$exp" > exp_tmp

	diff=$(diff exp_tmp test_tmp)
	if [[ ! -z "$diff" ]]; then
		echo "$i ==>> $diff"
	fi

	echo -en "\n$i"

	i=$((i+1))
done
