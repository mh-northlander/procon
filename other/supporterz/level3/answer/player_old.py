import copy
from typing import List, Dict

from lib.models import card
from lib.models.card import Card, next
from lib.models.fight import Fight
from lib.models.fighter import Fighter
from lib.models.result import Code
from lib.models.logic import Logic, FizzBuzzLogic, SerialLogic, ViewPastLogic


class Player(Fighter):
    def __init__(self)->None:
        # card.random = lambda:Card.Gu
        self.logic = myLogic(0)

    def nextcard(self, fight_history)->Card:
        return self.logic.next(fight_history)

class myLogic(Logic):
    def __init__(self, n=0):
        self.n = n
        self.initial_deck = copy.deepcopy(initial_deck)
        self.deck = copy.deepcopy(initial_deck)

    def next(self, fight_history: List[Fight])->Card:
        n = (len(fight_history) +1) % 100
        if n==1 or n==34 or n==67:
            self.n = n

        f = FizzBuzzLogic()
        s = SerialLogic()
        v = ViewPastLogic()

        rateF = clcRate(f, fight_history, len(fight_history) - self.n)
        rateS = clcRate(s, fight_history, len(fight_history) - self.n)
        rateV = clcRate(v, fight_history, len(fight_history) - self.n)

        m = max(rateF, rateS, rateV)
        if m == rateF:
            tmpCard = f.next(fight_history)
        elif m == rateS:
            tmpCard = s.next(fight_history)
        else:
            tmpCard = v.next(fight_history)

        return self.draw_card_from_deck(tmpCard)

    def draw_card_from_deck(self, card:Card)->Card:
        if self.deck[Card.Gu] + \
                self.deck[Card.Pa] + self.deck[Card.Choki] <= 0:
            self.deck = copy.deepcopy(self.initial_deck)

        return self._find_next_card(card, self.deck)

    def _find_next_card(self, c: Card, deck: Dict[Card, int])->Card:
        if deck[c] > 0:
            deck[c] -= 1
            return next(c)
        return self._find_next_card(card.next(c), deck)


def clcRate(logic:Logic, fight_history:List[Fight], n):
    if n == 0:
        return .0

    expect  = [logic.next(fight_history[:-(n-i)]) for i in range(n)]
    counter = [next(v) for v in expect]
    actual  = [v.fighter for v in fight_history[-n:]]
    battle  = [judge(z[0],z[1]) for z in zip(counter,actual)]
    return sum([(v==Code.WIN if 1 else 0) for v in battle]) / n

initial_deck = {
    Card.Gu: 69,
    Card.Pa: 99,
    Card.Choki: 129,
}

def judge(player_card: Card, fighter_card: Card)->Code:
    if player_card == fighter_card:
        return Code.DRAW

    if (player_card == Card.Gu and fighter_card == Card.Choki) or \
       (player_card == Card.Pa and fighter_card == Card.Gu) or \
       (player_card == Card.Choki and fighter_card == Card.Pa):
        return Code.WIN

    return Code.LOSE
