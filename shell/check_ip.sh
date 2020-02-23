#!/bin/bash

function check_ip() {
    IP=$1
    VALID_CHECK=$(echo $IP|awk -F. '$1<=255&&$2<=255&&$3<=255&&$4<=255{print "yes"}')
    if echo $IP|grep -E "^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$">/dev/null; then
        if [ ${VALID_CHECK:-no} == "yes" ]; then
            echo "IP $IP available."
        else
            echo "IP $IP not available!"
        fi
    else
        echo "IP format error!"
    fi
}
# Example
check_ip 192.168.1.1
check_ip 256.1.1.1


