from celery.exceptions import TimeoutError

from proj.tasks import add, dump_context

r = add.delay(4, 4)
print(r.id, r.get(timeout=1), r.state)
print(add.name)
r = add.apply_async((2, 2), queue="lopri", countdown=10)
try:
    print(r.get(timeout=1))
except TimeoutError as exc:
    print(r.traceback)
    print(r.id)

r = dump_context.delay(1, 2)
r.get()
