import ast

# Tweak this. Just enough will crash your interpreter, too much will cause a MemoryError
LEVELS = 429496100

foo = f"""
from {'.'*LEVELS}_ import _
"""

print(ast.parse(foo).body[0].level)