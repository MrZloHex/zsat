#!/bin/bash

MAN_PATH="/usr/local/man/man1"
OS_TYPE="linux"

load(){
	while [ 1 ]
	do
		echo >&6 -ne "."
		sleep 0.3
	done
}

get_os(){
	case "$OSTYPE" in 
		darwin*)
			OS_TYPE="darwin"
			MAN_PATH="/usr/share/man/man1"
		;;

		*) 
			OS_TYPE="linux"
			MAN_PATH="/usr/local/man/man1"
		;;
	esac		
}

install(){
	# installing program
	
	echo >&6 -n "Installing"

	load &
	PID=$!

    make compile

	cd cmp
	sudo mv cmp/zsat /usr/local/bin

	cd ..
	sudo mkdir $MAN_PATH
	cd src
	sudo mv zsat.1 $MAN_PATH
	sudo gzip $MAN_PATH/zsat.1
	
	if [[ $OS_TYPE == "linux" ]]
	then
		sudo mandb
	fi

	sleep 1
	echo >&6 ""

    make clean

	kill $PID
}

uninstall() {
	
	echo >&6 -n  "Uninstalling"
	load &
	PID=$!

	sudo rm /usr/local/bin/zsat
	sudo rm $MAN_PATH/zsat.1.gz

	sleep 1
	echo >&6 ""

	kill $PID
}

main(){
    exec 6>&1 >/dev/null
	sudo ls

	if [[ $2 != '-v' ]]
	then
		exec 2>/dev/null
	
	elif [[ $2 == '-v' ]] 
	then
		echo >&6 "verbose mode"	
	fi



	get_os

	case $1 in
		"-i" | "--install") 
			install
			echo >&6 "DONE!!!"
			;;
		"-u" | "--uninstall")
			uninstall
			echo >&6 "DONE!!!"
			;;
		*)
			echo >&6 "For installation run:"
			echo >&6 "	./deploytment.sh -i"
			echo >&6 "	./deploytment.sh --install"
			echo >&6 "For uninstallation run:"
			echo >&6 "	./deploytment.sh -u"
			echo >&6 "	./deploytment.sh --uninstall"
			;;
	esac
	
}


main "$@"