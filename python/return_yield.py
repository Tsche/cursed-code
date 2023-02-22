def foo():
    return


def bar():
    yield


def foobar():
    return
    yield  # unreachable, right?


for i in foo, bar, foobar:
    print(f"`{i.__name__}` return type: {type(i()).__name__}")
