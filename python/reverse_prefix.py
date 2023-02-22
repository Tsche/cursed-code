class R(type):
    def __getitem__(cls, args):
        ''' enables this prefix for lists '''
        return [*reversed(args)]


class r(metaclass=R):
    def __new__(cls, *args):
        ''' enables this prefix for tuples '''
        return tuple(reversed(args))


assert r[1, 2, 3, 4] == [4, 3, 2, 1]
assert isinstance(r[1, 2, 3, 4], list)

assert r(1, 2, 3, 4) == (4, 3, 2, 1)
assert isinstance(r(1, 2, 3, 4), tuple)
