#!/usr/bin/env python

import classes

t = classes.World()
t.set("bom dia!")
print (t.greet())

t.many(['Good Morning', 'Buon giorno', 'Kali mera'])
print (t.greet())


t = classes.CatYou()
print (t.add(1, 8))
print (t.cat(1, "8"))

print(classes.sayhi())

