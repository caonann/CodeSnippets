from celery import chain

from proj.tasks import add, mul

chain(add.s(4, 4) | mul.s(8))().get()
