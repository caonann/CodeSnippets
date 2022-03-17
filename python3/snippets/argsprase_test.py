import argparse

if __name__ == "__main__":
    ### https://docs.python.org/zh-cn/3/library/argparse.html#metavar
    parser = argparse.ArgumentParser(description='Process some integers.')
    '''
    type可以为 str,int,list, str, tuple, set, dict等
    help 显示帮助，当输入-h时有用
    pos1为位置参数，必填，跟位置强相关
    '''
    parser.add_argument('pos1', 
                        type=int, nargs='+',
                        help='an integer')
    ''' nargs代表位置参数个数为1到n个，其余还有
        nargs='*' 表示参数可设置零个或多个
        nargs='+' 表示参数可设置一个或多个
        nargs='?' 表示参数可设置零个或一个
    '''

    parser.add_argument('pos2', 
                        type=int,
                        help='an integer')

    parser.add_argument('-v',
                        '--verbose',
                        default='default content',
                        type=str,
                        required=True,              #是否为必填选项
                        help='verbose information')
    parser.add_argument('-b',
                        action='store_true',
                        help='if defined ')         #如果定义了，默认就为true
    
    # 范围内可选参数值
    parser.add_argument('--option',
                        type=int,
                        choices=[1,2,3],
                        required=True,
                        help='option value 1,2,3')

    # 互斥参数
    group = parser.add_mutually_exclusive_group()
    group.add_argument("-a",action='store_true',help='互斥参数 a')
    group.add_argument('-c',action='store_false',help='互斥参数 c')
    args = parser.parse_args()

    print(args)