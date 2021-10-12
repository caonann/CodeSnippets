import collections
from random import choice
Card=collections.namedtuple('Card',['rank','suit'])
#namedtuple 用以构建只有少数属性但是没有方法的对象，比如数据库条目
print(Card(7,'diaomonds'))

class FrenchDeck:
    ranks=[str(n) for n in range(2,11)]+list('JQKA')
    suits='spades diaomonds clubs hearts'.split(' ')
    def __init__(self) -> None:
        self.cards=[Card(rank,suit) for suit in self.suits for rank in self.ranks]

    def __len__(self):
        return len(self.cards)

    def __getitem__(self,position):
        return self.cards[position]

deck=FrenchDeck()
#print(deck[:])
print(len(deck))
print(deck[-1])
print(deck[:3])
print(choice(deck))
print(deck[12::13])