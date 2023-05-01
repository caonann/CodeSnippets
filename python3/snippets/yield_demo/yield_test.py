from flask import Flask, Response

app = Flask(__name__)

def generate():
    data = []
    for i in range(10):
        data.append(str(i))
        yield str(i)
    # 在生成器函数返回之后，可以使用 data 列表来进行后续的处理
    print(data)#想要在这里收集汇总数据

@app.route('/')
def index():
    return Response(generate())

if __name__ == '__main__':
    app.run()