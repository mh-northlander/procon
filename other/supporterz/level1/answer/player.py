from lib.models import card
from lib.models.card import Card, next
from lib.models.fighter import Fighter
from lib.models.logic import FizzBuzzLogic


class Player(Fighter):
    def __init__(self)->None:
        self.logic = FizzBuzzLogic()

    def nextcard(self, fight_history)->Card:
        return next(self.logic.next(fight_history))
