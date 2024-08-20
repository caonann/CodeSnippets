def generator_a():
    yield 1
    yield 2
    yield 3

def generator_b():
    for value in generator_a():
        yield value
        
        
def generator_c():
    yield from generator_a()
    
if __name__ == '__main__':
    g = generator_c()
    for i in g:
        print(i)