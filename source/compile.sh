#! /bin/bash

compile() {
    DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
    echo "$DIR"
    cd $DIR
    clear
    echo "Preparing Compile"
    make clean
    echo ""          #removes current game.exec
    echo "Compiling MemberManager" 
    echo "" 
    make                #runs makefile to compile individual .c files    
    #add .o files below
    g++ main.o member.o -o program     
    if [ -e program ]      #checks if MemberManager.exec was made
        then {
            echo ""
            echo "Compile Successful"
            echo ""
        } else {
            echo "Compile Failure"
            exit -1     #if file was not made compilation fails
        }
    fi
    # clear
    ./program
    read -p "Press [Enter] to end..."
    exit 0;
}

compile