#!/usr/bin/env python

import demo

t = demo.World()
t.set("bom dia!")
print(t.greet())

t.many(['Good Morning', 'Buon giorno', 'Kali mera'])
print(t.greet())


t = demo.CatYou()
print(t.add(1, 8))
print(t.cat(1, "8"))

print(demo.sayhi())

t = demo.Clslst()

t.setvec([1, 2, 3])
print(t.sum())
print(t.getvec())
