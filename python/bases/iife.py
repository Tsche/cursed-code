class Foo((lambda x: str if x > 3 else int)(5)):
    ...


assert str in Foo.__bases__
