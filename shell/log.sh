function info(){
    msg=$1
    datetime=$(date "+%Y-%m-%d %H:%M:%S")
    logger --tag ecmnet "$datetime INFO:$msg"
    printf "\e[32m$msg\e[39m\n"
}

info "this is a test"