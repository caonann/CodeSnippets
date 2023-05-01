import docker

client = docker.from_env()

# 拉起容器
"""
detach参数用于控制Docker容器的运行模式。当使用Python Docker SDK运行容器时，detach参数决定是否以分离模式运行容器。

当detach设置为True时，容器将以分离模式运行，这意味着容器将在后台运行并且不会阻塞您的Python脚本。在这种模式下，您可以继续执行其他操作，如检查容器的日志、执行容器内的命令等。
当detach设置为False时，容器将以非分离模式运行，这意味着容器将阻塞您的Python脚本，直到容器停止。在这种模式下，您将无法在容器运行期间执行其他操作。
通常，如果您希望在容器运行期间与容器进行交互（如执行命令、获取日志等），最好将detach设置为True。如果您只关心容器的运行结果，可以将detach设置为False。
"""
container = client.containers.run("my_python_function", detach=True)

# 调用容器中的Python函数
result = container.exec_run(
    "python -c 'from function import hello_world; print(hello_world(\"John\"))'"
)

# 获取返回结果
print(result)
output = result.output.decode("utf-8")
print(output, type(output))
