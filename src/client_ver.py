#!/usr/bin/python
f = open('./cgame/etmodc.h')
for l in f:
	if 'ETMODC_VERSION' in l:
		v = l.split('\"')[1]
		print v
		break

