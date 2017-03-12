from typing import List

from lib.models import card
from lib.models.card import Card
from lib.models.fight import Fight


class Logic():
    def __init__(self):
        pass

    def init(self):
        pass

    def next(self, fight_history: List[Fight]):
        pass

    def __str__(self):
        return self.__class__.__name__


class FizzBuzzLogic(Logic):
    def next(self, fight_history: List[Fight]):
        n = len(fight_history) + 1
        if n % 3 == 0 and n % 5 == 0:
            return Card.Choki
        elif n % 3 == 0:
            return Card.Gu
        elif n % 5 == 0:
            return Card.Pa

        return card.random()


class SerialLogic(Logic):
    def __init__(self):
        self.prev_card = None

    def init(self):
        self.prev_card = None

    def next(self, fight_history: List[Fight]):
        n = len(fight_history) + 1
        if n % 3 == 1:
            return card.random()

        if self.prev_card is None:
            self.prev_card = Card.Gu
            return Card.Gu

        self.prev_card = card.next(
            self.prev_card
        )
        return self.prev_card


class ViewPastLogic(Logic):
    def next(self, fight_history: List[Fight]):
        n = len(fight_history) + 1
        if n % 3 == 1:
            return card.random()

        last = fight_history[-1]
        return card.next(last.player)
