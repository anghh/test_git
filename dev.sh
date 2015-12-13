#!/bin/sh
find_result()
{
	if [ -f tempd.txt ]; then {
		while read line
		do
			grep -r "dtsi" ./$line >> tempa.txt
		done < tempd.txt
	}
    fi
    
	if [ -f tempa.txt];then{
		sed 's/#include "//g' tempa.txt > tempb.txt
		sed 's/"//g' tempb.txt > tempc.txt
		sed 's/^[ \t]//g' tempc.txt > tempd.txt
		sed 's/^[ \t]//g' tempc.txt > result.txt
		rm tempa.txt
		find_result
	}
    fi
}
echo $1 > result.txt
grep -r "dtsi" $1 > tempa.txt
find_result
sed 's/^[ \t]//g' result.txt > final_result.txt

if [ $# -eq 2 ]; then {
	mkdir $2
	sed 's/^/cp -rf /g' result.txt result1.txt
	sed 's/^/ '$2'/g' result1.txt result3.txt
	chmod 777 result3.txt
	./result3.txt
}
fi
rm result* temp*
