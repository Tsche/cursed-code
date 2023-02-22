import random


class Foo(random.choice([int, str])):
    ...


print(Foo.__base__)
