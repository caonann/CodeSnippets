#!/bin/bash -x

red_text() { printf "\e[31m$1\e[39m"; }
green_text() { printf "\e[32m$1\e[39m"; }
yellow_text() { printf "\e[33m$1\e[39m"; }
red_nl_text() { printf "\n\e[31m$1\e[39m\n"; }
green_nl_text() { printf "\n\e[32m$1\e[39m\n"; }
yellow_nl_text() { printf "\n\e[33m$1\e[39m\n"; }

green_arrow_done() { green_text " --> DONE" && echo; }
green_check_ok() { green_text " ... OK" && echo; }
terminate_with_msg() { red_nl_text "ERROR: $1"; exit 1; }

function check_ip() {
    IP=$1
    VALID_CHECK=$(echo $IP|awk -F. '$1<=255&&$2<=255&&$3<=255&&$4<=255{print "yes"}')
    if echo $IP|grep -E "^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$">/dev/null; then
        if [ ${VALID_CHECK:-no} == "yes" ]; then
            echo "IP $IP available."
            return 0
        else
            echo "IP $IP not available!"
            return 1
        fi
    else
        echo "IP format error!"
        return 2
    fi
}

function valid_ip()
{
    local  ip=$1
    local  stat=1

    if [[ $ip =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]; then
        OIFS=$IFS
        IFS='.'
        ip=($ip)
        IFS=$OIFS
        [[ ${ip[0]} -le 255 && ${ip[1]} -le 255 \
            && ${ip[2]} -le 255 && ${ip[3]} -le 255 ]]
        stat=$?
    fi
    return $stat
}

function parse_int_from_ip()
{
    [ $# -eq 1 ] || terminate_with_msg "Usage: ${FUNCNAME[0]} ip_addr (e.g. ${FUNCNAME[0]} 192.168.0.1)"
    local a b c d ip_int prefix=0
    IFS=. read a b c d <<< "$1"
    printf $(((((((a << 8) | b) << 8) | c) << 8) | d))
}

function parse_ip_from_int()
{
    [ $# -eq 1 ] || terminate_with_msg "Usage: ${FUNCNAME[0]} ip_int (e.g. ${FUNCNAME[0]} 3232235521)"
    local ip_addr="" num=$1;
    for i in {1..4}; do
        ip_addr=$((num & 0xff))${ip_addr:+.}$ip_addr
        ((num >>= 8))
    done
    printf $ip_addr
}

function parse_cidr_prefix_from_netmask()
{
    [ $# -eq 1 ] || terminate_with_msg "Usage: ${FUNCNAME[0]} netmask (e.g. ${FUNCNAME[0]} 255.255.255.0)"
    local prefix=0
    for (( i=$(parse_int_from_ip $1); i>0; i>>=1 )); do
        [ $(( $i & 1 )) -eq 1 ] && (( prefix++ ))
    done
    printf $prefix
}

# Example
check_ip 192.168.1.1
echo $?
check_ip 256.1.1.1
echo $?

parse_cidr_prefix_from_netmask 255.255.255.240
parse_int_from_ip 192.168.13.12
parse_ip_from_int 283232238860
parse_ip_from_int

