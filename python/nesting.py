class Bar:
    def __set_name__(self, cls, name):
        setattr(self, cls.__name__, getattr(cls, name))


class Foo:
    x = Bar()

    def oh_no(self):
        assert self.x == self.x.Foo
        assert self.x == self.x.Foo.Foo
        assert self.x == self.x.Foo.Foo.Foo
        assert self.x == self.x.Foo.Foo.Foo.Foo
        assert self.x == self.x.Foo.Foo.Foo.Foo.Foo
        assert self.x == self.x.Foo.Foo.Foo.Foo.Foo.Foo
        assert self.x == self.x.Foo.Foo.Foo.Foo.Foo.Foo.Foo

        print(":trollcrab:")


if __name__ == "__main__":
    oof = Foo()
    oof.oh_no()
