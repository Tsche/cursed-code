from typing import Generator

PASSWORDS = ["watdafak", "plsno"]
TRIES = 3


def authenticate(provider) -> bool:
    def check() -> Generator[None, str, bool]:
        for _ in range(TRIES):
            current = yield
            if current in PASSWORDS:
                break
        else:
            return False
        return True

    try:
        for i in (provider, (ohno := check(), next(ohno))[0])[0]:
            ohno.send(i)
    except StopIteration as ret:
        return ret.value

    assert False, "unreachable"


def get_input():
    while True:
        yield input("Enter password: ")


def main():
    assert authenticate(["watdafak"])
    assert not authenticate(["ohno", "oof", "pydonghard"])
    assert not authenticate(["more", "than", "three tries", "watdafak"])

    # Try me in a terminal
    # print(authenticate(get_input()))


if __name__ == "__main__":
    main()
