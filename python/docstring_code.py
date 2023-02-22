def ohno(fnc):
    return eval(f"lambda {', '.join(fnc.__code__.co_varnames)}: {fnc.__doc__}")


@ohno
def square(num):
    """ num^2 """
    return num ** 2


assert square(3) == 1
