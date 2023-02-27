from multiprocessing import Process, Queue
import time
def func(queue):
    for i in range(10):
        data = queue.get(True)
        print(f"getting data {data}")
    
if __name__ == "__main__":
    local_que = Queue(10)
    p = Process(target=func, args=(local_que,))
    p.start()
    while True:
        data=(b"aaaa",100)
        local_que.put(data, False)
        time.sleep(1)