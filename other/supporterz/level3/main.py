import argparse

from lib import level3
from answer.player import Player

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("--number", "-n",
                        default=1000,
                        dest="number",
                        type=int)
    args = parser.parse_args()
    level3.run(args.number, Player())
