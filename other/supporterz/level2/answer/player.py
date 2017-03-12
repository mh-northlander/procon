from typing import List
from lib.models import card
from lib.models.card import Card, next
from lib.models.fight import Fight
from lib.models.fighter import Fighter
from lib.models.result import Code
from lib.models.logic import Logic, FizzBuzzLogic, SerialLogic, ViewPastLogic


class Player(Fighter):
    def __init__(self)->None:
        # card.random = lambda:Card.Gu
        self.logic = myLogic()

    def nextcard(self, fight_history)->Card:
        n = (len(fight_history) +1) % 100
        if n==1 or n==34 or n==67:
            self.logic = myLogic(len(fight_history))

        return self.logic.next(fight_history)

class myLogic(Logic):
    def __init__(self, n=0):
        self.n = n
        pass

    def next(self, fight_history: List[Fight])->Card:
        f = FizzBuzzLogic()
        s = SerialLogic()
        v = ViewPastLogic()

        rateF = clcRate(f, fight_history, len(fight_history) - self.n)
        rateS = clcRate(s, fight_history, len(fight_history) - self.n)
        rateV = clcRate(v, fight_history, len(fight_history) - self.n)

        m = max(rateF, rateS, rateV)
        if m == rateF:
            return next(f.next(fight_history))
        elif m == rateS:
            return next(s.next(fight_history))
        else:
            return next(v.next(fight_history))

def clcRate(logic:Logic, fight_history, n):
    if n == 0:
        return .0

    expect  = [logic.next(fight_history[:-(n-i)]) for i in range(n)]
    counter = [next(v) for v in expect]
    actual  = [v.fighter for v in fight_history[-n:]]
    battle  = [judge(z[0],z[1]) for z in zip(counter,actual)]
    return sum([(v==Code.WIN if 1 else 0) for v in battle]) / n

def judge(player_card: Card, fighter_card: Card)->Code:
    if player_card == fighter_card:
        return Code.DRAW

    if (player_card == Card.Gu and fighter_card == Card.Choki) or \
       (player_card == Card.Pa and fighter_card == Card.Gu) or \
       (player_card == Card.Choki and fighter_card == Card.Pa):
        return Code.WIN

    return Code.LOSE
