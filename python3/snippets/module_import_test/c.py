import sys
from os.path import abspath, join, dirname
sys.path.append(join(abspath(dirname(__file__))))
import a
print("c import a")