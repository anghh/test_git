#!/bin/bash
for i in 'find ./ -name "*.conf"';do
	sed -i -r 's/([^,]*,){10}/&\n/g' $i
	sed -i "s/0x//g" $i
	sed -i "s/,//g" $i
	sed -i "s/\s\+$//g" $i
done
