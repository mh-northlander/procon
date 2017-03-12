import copy
from typing import List, Dict
import random

from lib.models import card
from lib.models.card import Card, next
from lib.models.fight import Fight
from lib.models.fighter import Fighter
from lib.models.result import Code
from lib.models.logic import Logic, FizzBuzzLogic, SerialLogic, ViewPastLogic


class Player(Fighter):
    def __init__(self)->None:
        self.logic = myLogic()
        # cheat code
        # without this cheats, this code achieves win-rate around 79%
        # card.random   = lambda : Card.Gu
        # random.choice = lambda x : x[2]

    def nextcard(self, fight_history)->Card:
        return self.logic.next(fight_history)

class myLogic(Logic):
    def __init__(self):
        self.n = 0
        self.deck = copy.deepcopy(initial_deck)

    def next(self, fight_history: List[Fight])->Card:
        n = len(fight_history) + 1
        itv = n % 100
        if itv==1 or itv==34 or itv==67:
            self.n = n
            self.sState = Card.Choki
            self.simF = []
            self.simS = []
            self.simV = []
        else:
            self.simF.append(self.simLastF(fight_history))
            self.simS.append(self.simLastS(fight_history))
            self.simV.append(self.simLastV(fight_history))

        rateF = clcRate(self.simF, fight_history[self.n-1:])
        rateS = clcRate(self.simS, fight_history[self.n-1:])
        rateV = clcRate(self.simV, fight_history[self.n-1:])

        m = max(rateF, rateS, rateV)
        if m == rateV:
            if n % 3 != 1:
                exp = next(fight_history[-1].player)
            else:
                exp = self.random_from_deck()
        elif m == rateS:
            if n % 3 != 1:
                exp = next(self.sState)
            else:
                exp = self.random_from_deck()
        else:
            if n % 3 == 0 and n % 5 == 0:
                exp = Card.Choki
            elif n % 3 == 0:
                exp = Card.Gu
            elif n % 5 == 0:
                exp = Card.Pa
            else:
                exp = self.random_from_deck()

        # update
        if(n % 3 != 1):
            self.sState = next(self.sState)
        if(n > 1):
            self.deck[fight_history[-1].fighter] -= 1

        return next(self.draw_card_from_deck(exp))

    def draw_card_from_deck(self, card:Card)->Card:
        if self.deck[Card.Gu] + self.deck[Card.Pa] + self.deck[Card.Choki] <= 0:
            self.deck = copy.deepcopy(initial_deck)

        return self._find_next_card(card)

    def _find_next_card(self, c: Card)->Card:
        if self.deck[c] > 0:
            return c
        return self._find_next_card(next(c))

    def random_from_deck(self):
        if (self.deck[Card.Gu] == 0) and (self.deck[Card.Pa] >  0) and (self.deck[Card.Choki] >  0):
            return Card.Pa
        if (self.deck[Card.Gu] >  0) and (self.deck[Card.Pa] == 0) and (self.deck[Card.Choki] >  0):
            return Card.Choki
        if (self.deck[Card.Gu] >  0) and (self.deck[Card.Pa] >  0) and (self.deck[Card.Choki] == 0):
            return Card.Gu
        return card.random()

    def simLastF(self, fight_history:List[Fight])->Card:
        # simulate fizzbuzz logic
        n = len(fight_history) + 1 - 1
        ret = fight_history[-1].fighter
        if n % 3 == 0 and n % 5 == 0:
            ret =  Card.Choki
        elif n % 3 == 0:
            ret =  Card.Gu
        elif n % 5 == 0:
            ret =  Card.Pa
        return self.draw_card_from_deck(ret)

    def simLastS(self, fight_history:List[Fight])->Card:
        # simulate serial logic
        n = len(fight_history) + 1 - 1
        ret = fight_history[-1].fighter
        if n % 3 != 1:
            ret = self.sState
        return self.draw_card_from_deck(ret)

    def simLastV(self, fight_history:List[Fight])->Card:
        # simulate view past logic
        n = len(fight_history) + 1 - 1
        ret = fight_history[-1].fighter
        if n % 3 != 1:
            ret = next(fight_history[-2].player)
        return self.draw_card_from_deck(ret)

def clcRate(expect: List[Card], actual: List[Fight])->float:
    n = len(expect)
    if n == 0:
        return 0.
    acc = 0
    for i in range(n):
        if expect[i] == actual[i].fighter:
            acc += 1
    return acc / n

initial_deck = {
    Card.Gu: 69,
    Card.Pa: 99,
    Card.Choki: 129,
}
