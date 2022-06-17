from bs4 import BeautifulSoup

text = """<phoneme alphabet="py" ph="xu1 duo2">生活中，<phoneme alphabet="py" ph="xu1 duo2">许多</phoneme>美好的事情往往是我们难以发觉的。体会美好，也是一种很重要的能力。</phoneme>"""


cleantext = BeautifulSoup(text, "lxml").text
print(f"{cleantext=}")

text2 = "你好啊，我很好。"
cleantext = BeautifulSoup(text2, "lxml").text
print(f"{cleantext=}")


text3 = "<你好啊<>，<>>我很好。"
cleantext = BeautifulSoup(text3, "lxml").text
print(f"{cleantext=}")
