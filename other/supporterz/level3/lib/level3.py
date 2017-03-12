import random
import copy
from typing import List, Dict

from lib.models.fighter import Fighter
from lib.models.fight_service import FightService
from lib.models.logic import Logic, FizzBuzzLogic, SerialLogic, ViewPastLogic
from lib.models import card
from lib.models.card import Card


class Charlie(Fighter):
    def __init__(self,
                 name: str,
                 logics: List[Logic],
                 deck: Dict[Card, int],
                 current_logic: Logic = None)->None:
        self.name = name
        self.logics = logics
        self.initial_deck = copy.deepcopy(deck)
        self.deck = deck
        self.current_logic = current_logic

    def nextcard(self, fight_history)->Card:
        n = (len(fight_history) + 1) % 100
        if n == 1 or n == 34 or n == 67:
            self.current_logic = self.next_logic()

        c = self.current_logic.next(fight_history) \
            if self.current_logic is not None else card.random()
        return self.draw_card_from_deck(c)

    def next_logic(self)->Logic:
        logic = random.choice(self.logics)
        logic.init()
        return logic

    def draw_card_from_deck(self, card: Card)->Card:
        if self.deck[Card.Gu] + \
                self.deck[Card.Pa] + self.deck[Card.Choki] <= 0:
            self.deck = copy.deepcopy(self.initial_deck)

        return self._find_next_card(card, self.deck)

    def _find_next_card(self, c: Card, deck: Dict[Card, int])->Card:
        if deck[c] > 0:
            deck[c] -= 1
            return c
        return self._find_next_card(card.next(c), deck)


def run(n, player):
    service = FightService(
        player,
        Charlie(
            name="Charlie",
            logics=[
                FizzBuzzLogic(),
                SerialLogic(),
                ViewPastLogic()
            ],
            deck={
                Card.Gu: 69,
                Card.Pa: 99,
                Card.Choki: 129
            }
        ),
    )
    service.fight(n)
    print(service.summary)
