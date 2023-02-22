class Test:
    __foo = 3

    def set(self, x):
        self.__foo = x

    def get(self):
        return self.__foo


oof = Test()
oof.__foo = 4
oof.set(5)
print(oof.__dict__)

print(oof.__foo)
print(oof.get())

oof._Test__foo = 6
print(oof.get())
