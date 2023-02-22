def ohno(fnc):
    args = ', '.join(fnc.__code__.co_varnames[:fnc.__code__.co_argcount])
    return eval(f"lambda {args}: {fnc.__doc__}")


@ohno
def square(num):
    """ num^2 """
    return num ** 2


assert square(3) == 1
