from enum import Enum
import random as rnd


class Card(Enum):
    Gu = 0
    Pa = 1
    Choki = 2


def random(n: int = None)->Card:
    n = n if n is not None else rnd.randrange(0, 3)
    return from_number(n)


def from_number(n: int)->Card:
    if n == 0:
        return Card.Gu
    elif n == 1:
        return Card.Pa
    elif n == 2:
        return Card.Choki
    else:
        raise ValueError("There are no enum value for {}".format(n))


def next(h)->Card:
    return from_number((h.value + 1) % 3)
