import sys
from os.path import abspath, join, dirname
sys.path.append(join(abspath(dirname(__file__))))
import a

dir = join(abspath(dirname(__file__)))

a.hello_a()