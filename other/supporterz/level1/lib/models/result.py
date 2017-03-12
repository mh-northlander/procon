from enum import Enum


class Code(Enum):
    WIN = "WIN"
    LOSE = "LOSE"
    DRAW = "DRAW"

    def __str__(self):
        return self.value
