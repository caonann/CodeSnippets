from celery import group

from proj.tasks import add

group(add.s(i, i) for i in range(10))().get()
