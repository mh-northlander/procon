from typing import List
import random

from lib.models.fighter import Fighter
from lib.models.fight_service import FightService
from lib.models.logic import Logic, FizzBuzzLogic, SerialLogic, ViewPastLogic
from lib.models import card
from lib.models.card import Card


class Bob(Fighter):
    def __init__(self,
                 name: str,
                 logics: List[Logic],
                 current_logic: Logic = None)->None:
        self.name = name
        self.current_logic = current_logic
        self.logics = logics

    def nextcard(self, fight_history)->Card:
        n = (len(fight_history) + 1) % 100
        if n == 1 or n == 34 or n == 67:
            self.current_logic = self.next_logic()

        return self.current_logic.next(fight_history) \
            if self.current_logic is not None else card.random()

    def next_logic(self)->Logic:
        logic = random.choice(self.logics)
        logic.init()
        return logic


def run(n, player):
    service = FightService(
        player,
        Bob(
            name="Bob",
            logics=[
                FizzBuzzLogic(),
                SerialLogic(),
                ViewPastLogic()
            ]
        ),
    )
    service.fight(n)
    print(service.summary)
