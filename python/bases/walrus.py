class Foo(type_ := int):

    @staticmethod
    def foo():
        return type_


assert Foo.foo() is int
assert int in Foo.__bases__
assert type_ is int