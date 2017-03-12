from lib.models.card import Card


class Fighter():
    def __init__(self):
        self.current_logic = None

    def nextcard(self, fight_history)->Card:
        raise Exception("Method Not Implemented")
