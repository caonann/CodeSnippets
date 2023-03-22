import json
import traceback

from flask import Flask
from werkzeug.exceptions import HTTPException
from werkzeug.wrappers import Response

app = Flask(__name__)


class APIException(HTTPException):
    code = 500
    message = "Server Internal Error"

    def __init__(self, code=None, message=None, interface_name=None):
        if code is not None:
            self.code = code
        if message is not None:
            self.message += message
        self.interface_name = interface_name
        super(APIException, self).__init__(response=self.__make_response())

    def __make_response(self):
        r = {
            "ret_code": self.code,
            "ret_msg": self.message,
        }
        res_str = json.dumps(r, ensure_ascii=False)
        print("res:", res_str)

        return Response(res_str, mimetype="application/json")


@app.errorhandler(Exception)
def framework_error(e):
    err_msg = traceback.format_exc()
    print(err_msg)
    if isinstance(e, APIException):  # 手动触发的异常
        return e
    elif isinstance(e, HTTPException):  # 代码异常
        code = e.code if e.code == 401 else 200
        return APIException(e.code, e.description), code
    else:
        raise e


@app.route("/haha")
def haha():
    try:
        raise APIException("hahah")
    except APIException as e:
        print("this is api exception")
        print(e)


if __name__ == "__main__":
    with app.test_request_context("/haha"):
        try:
            raise APIException(code=111,message="hahah")
        except APIException as e:
            print("this is api exception")
            print(e)
