from email import message
import traceback
import functools
import sys

EXCEPTION_MESSAGE_MAP = {
    'InternalError': '内部错误',
    'InvalidParameter': '请求中指定的参数无效、不支持或不能使用。',
    'InputJsonInvalid': '输入json格式错误'
}


class APIException(Exception):
    message = '未知错误。'
    code = 'InternalError'

    # 如果入参是一个列表，需要格式化，而不能依赖python的repr，否则，会暴露后端语言。
    def __init__(self, **kwargs):
        #super().__init__(self,kwargs)
        print(kwargs)
        self.kwargs = kwargs
        _msg = EXCEPTION_MESSAGE_MAP[kwargs['message'] if 'message' in kwargs else self.__class__.code]
        self.message = _msg

    def __str__(self):
        return self.message

class InternalError(APIException):
    code = 'InternalError'

class InvalidParameter(APIException):
    code = 'InvalidParameter'
    class InputJsonInvalid(APIException):
        code = 'InputJsonInvalid'

def FormatError(func):
	@functools.wraps(func)
	def Format(*args, **kwargs):
		try:
			func(*args, **kwargs)
		except Exception as e:
			exc_type, exc_value, exc_traceback = sys.exc_info()
			frame = traceback.extract_tb(exc_traceback) #返回一个异常栈的FrameSummary对象
			#格式化成字符串输出
			mapStack = map(str, frame)
			sErrorStack = "\n".join(mapStack)
			print("异常栈：")
			print(sErrorStack)
			#输出异常原因
			print(repr(e))
			#输出报错函数的局部变量
			lasttb = None
			while exc_traceback:
				lasttb = exc_traceback
				exc_traceback = exc_traceback.tb_next
			print("局部变量：")
			print(lasttb.tb_frame.f_locals)
	return Format

def FormatError2(func):
    @functools.wraps(func)
    def error_handler(*args, **kwargs):
        try:
            try:
                func(*args, **kwargs)
            except APIException as e:
                err_msg = traceback.format_exc()
                print(f"APIException exception test {e} {err_msg}")
        except BaseException as e:
            err_msg = traceback.format_exc()
            print(f"base exception test {e} {err_msg}")
    return error_handler

@FormatError
def test_err_api():
    raise InvalidParameter(message='InvalidParameter')

@FormatError2
def test_err_api2():
    raise InvalidParameter.InputJsonInvalid()

if __name__ == "__main__":
    #test_err_api()
    test_err_api2()