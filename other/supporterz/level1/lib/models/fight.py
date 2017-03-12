from lib.models.result import Code
from lib.models.card import Card


class Fight():
    def __init__(self,
                 player_card: Card,
                 fighter_card: Card,
                 result: Code
                 )->None:
        self.player = player_card
        self.fighter = fighter_card
        self.result = result
