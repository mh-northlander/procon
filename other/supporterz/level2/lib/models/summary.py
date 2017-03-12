from typing import Dict
from collections import Counter

from lib.models.result import Code


class Summary():
    def __init__(self,
                 all: Counter=None,
                 per_logic: Dict[str, Counter]=None
                 )->None:
        self.all = Counter() if all is None else all
        self.per_logic = {} if per_logic is None else per_logic

    def append(self, logic: str, result: Code)->None:
        if logic not in self.per_logic:
            self.per_logic[logic] = Counter()

        self.all[str(result)] += 1
        self.per_logic[logic][str(result)] += 1

    def __str__(self):
        messages = []
        n = sum(self.all.values())
        messages.append(
            "\n".join([
                "勝率",
                "WIN: {} %".format(100.0 * self.all["WIN"] / n),
                "LOSE: {} %".format(100.0 * self.all["LOSE"] / n),
                "DRAW: {} %".format(100.0 * self.all["DRAW"] / n),
                ""
            ])
        )
        for (logic, counter) in self.per_logic.items():
            n = sum(counter.values())
            messages.append(
                "\n".join([
                    "{}に対する勝率 N: {}".format(logic, n),
                    "WIN: {} %".format(100.0 * counter["WIN"] / n),
                    "LOSE: {} %".format(100.0 * counter["LOSE"] / n),
                    "DRAW: {} %".format(100.0 * counter["DRAW"] / n),
                    ""
                ])
            )
        return "\n".join(messages)
