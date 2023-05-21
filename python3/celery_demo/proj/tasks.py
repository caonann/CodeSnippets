from .celery import app


@app.task
def add(x, y):
    return x + y


@app.task
def mul(x, y):
    return x * y


@app.task
def xsum(numbers):
    return sum(numbers)


@app.task(bind=True)
def dump_context(self, x, y):
    print(
        "Executing task id {0.id}, args: {0.args!r} kwargs: {0.kwargs!r}".format(
            self.request
        )
    )
