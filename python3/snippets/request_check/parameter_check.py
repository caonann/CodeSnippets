# request(a="123",b=123,c=True)


class schema:
    @staticmethod
    def request(**args):
        print(f"request {args}")

        def _(func):
            print("func...")

            def wrap_func(**input_args):
                print(f"request input {input_args=}")
                ret = func(**input_args)
                return ret

            return wrap_func

        return _

    @staticmethod
    def response(**args):
        print(f"response {args=}")

        def _(func):
            def wrap_func(**input_args):
                print(f"response {input_args=}")
                ret = func(**input_args)
                return ret

            return wrap_func

        return _


@schema.request(a="123", b=123, c=True)
@schema.response()
def entry(**args):
    print("entry...")
    print(f"entry {args=}")
    return {"ret": "result"}


if __name__ == "__main__":

    entry_ret = entry(a="aaa", b=111, c=False)
    print(f"{entry_ret=}")
