from typing import List

from lib.models.card import Card
from lib.models.fighter import Fighter
from lib.models.result import Code
from lib.models.summary import Summary
from lib.models.fight import Fight

History = List[Fight]


class FightService():
    def __init__(self,
                 player: Fighter,
                 fighter: Fighter,
                 history: History=None,
                 summary: Summary=None
                 )->None:
        self.player = player
        self.fighter = fighter
        self.history = [] if history is None else history
        self.summary = Summary() if summary is None else summary

    def fight(self, number_of_fight: int)->None:
        for _ in range(0, number_of_fight):
            player_card = self.player.nextcard(self.history)
            fighter_card = self.fighter.nextcard(self.history)
            result = self.judge(player_card, fighter_card)
            self.history.append(Fight(
                player_card=player_card,
                fighter_card=fighter_card,
                result=result
            ))
            self.summary.append(str(self.fighter.current_logic), result)

    def judge(self, player_card: Card, fighter_card: Card)->Code:
        if player_card == fighter_card:
            return Code.DRAW

        if (player_card == Card.Gu and fighter_card == Card.Choki) or \
                (player_card == Card.Pa and fighter_card == Card.Gu) or \
                (player_card == Card.Choki and fighter_card == Card.Pa):
            return Code.WIN

        return Code.LOSE
