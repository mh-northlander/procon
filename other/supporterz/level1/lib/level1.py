from lib.models.fighter import Fighter
from lib.models.fight_service import FightService
from lib.models.logic import Logic, FizzBuzzLogic
from lib.models.card import Card


class Alice(Fighter):
    def __init__(self, name: str, logic: Logic)->None:
        self.name = name
        self.logic = logic
        self.current_logic = logic

    def nextcard(self, fight_history)->Card:
        return self.logic.next(fight_history)


def run(n, player):
    service = FightService(
        player,
        Alice(name="Alice", logic=FizzBuzzLogic()),
    )
    service.fight(n)
    print(service.summary)
