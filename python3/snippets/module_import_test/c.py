import sys
from os.path import abspath, dirname, join

sys.path.append(join(abspath(dirname(__file__))))
import a

print("c import a")
