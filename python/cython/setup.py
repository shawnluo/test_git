from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext



from distutils.core import setup
from Cython.Build import cythonize

setup(name='Hello world',
   ext_modules=cythonize("*.py"))