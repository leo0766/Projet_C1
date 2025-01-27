#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Dec  6 22:01:26 2020

@author: leodurst
"""


"""
Import des données:
"""

import numpy as np
from matplotlib import pyplot as plt
import pandas as pd
import os
os.system('python covid_casesgui.py')



confirmed = pd.read_csv("confirmed_covid-19.csv")
confirmed = confirmed.drop(['Province/State','Lat','Long'], axis=1)
confirmed = confirmed.groupby(confirmed['Country/Region']).aggregate('sum')
confirmed = confirmed.T
confirmed.header = 0


death = pd.read_csv("death_covid-19.csv")
death = death.drop(['Province/State','Lat','Long'], axis=1)
death = death.groupby(death['Country/Region']).aggregate('sum')
death = death.T
death.header = 0


recovered = pd.read_csv("recovered_covid-19.csv")
recovered = recovered.drop(['Province/State','Lat','Long'], axis=1)
recovered = recovered.groupby(recovered['Country/Region']).aggregate('sum')
recovered = recovered.T
recovered.header = 0

date = ["1/22/20","1/23/20","1/24/20","1/25/20","1/26/20","1/27/20","1/28/20","1/29/20","1/30/20","1/31/20","2/1/20","2/2/20","2/3/20","2/4/20","2/5/20","2/6/20","2/7/20","2/8/20","2/9/20","2/10/20","2/11/20","2/12/20","2/13/20","2/14/20","2/15/20","2/16/20","2/17/20","2/18/20","2/19/20","2/20/20","2/21/20","2/22/20","2/23/20","2/24/20","2/25/20","2/26/20","2/27/20","2/28/20","2/29/20","3/1/20","3/2/20","3/3/20","3/4/20","3/5/20","3/6/20","3/7/20","3/8/20","3/9/20","3/10/20","3/11/20","3/12/20","3/13/20","3/14/20","3/15/20","3/16/20","3/17/20","3/18/20","3/19/20","3/20/20","3/21/20","3/22/20","3/23/20","3/24/20","3/25/20","3/26/20","3/27/20","3/28/20","3/29/20","3/30/20","3/31/20","4/1/20","4/2/20","4/3/20","4/4/20","4/5/20","4/6/20","4/7/20","4/8/20","4/9/20","4/10/20","4/11/20","4/12/20","4/13/20","4/14/20","4/15/20","4/16/20","4/17/20","4/18/20","4/19/20","4/20/20","4/21/20","4/22/20","4/23/20","4/24/20","4/25/20","4/26/20","4/27/20","4/28/20","4/29/20","4/30/20","5/1/20","5/2/20","5/3/20","5/4/20","5/5/20","5/6/20","5/7/20","5/8/20","5/9/20","5/10/20","5/11/20","5/12/20","5/13/20","5/14/20","5/15/20","5/16/20","5/17/20","5/18/20","5/19/20","5/20/20","5/21/20","5/22/20","5/23/20","5/24/20","5/25/20","5/26/20","5/27/20","5/28/20","5/29/20","5/30/20","5/31/20","6/1/20","6/2/20","6/3/20","6/4/20","6/5/20","6/6/20","6/7/20","6/8/20","6/9/20","6/10/20","6/11/20","6/12/20","6/13/20","6/14/20","6/15/20","6/16/20","6/17/20","6/18/20","6/19/20","6/20/20","6/21/20","6/22/20","6/23/20","6/24/20","6/25/20","6/26/20","6/27/20","6/28/20","6/29/20","6/30/20","7/1/20","7/2/20","7/3/20","7/4/20","7/5/20","7/6/20","7/7/20","7/8/20","7/9/20","7/10/20","7/11/20","7/12/20","7/13/20","7/14/20","7/15/20","7/16/20","7/17/20","7/18/20","7/19/20","7/20/20","7/21/20","7/22/20","7/23/20","7/24/20","7/25/20","7/26/20","7/27/20","7/28/20","7/29/20","7/30/20","7/31/20","8/1/20","8/2/20","8/3/20","8/4/20","8/5/20","8/6/20","8/7/20","8/8/20","8/9/20","8/10/20","8/11/20","8/12/20","8/13/20","8/14/20","8/15/20","8/16/20","8/17/20","8/18/20","8/19/20","8/20/20","8/21/20","8/22/20","8/23/20","8/24/20","8/25/20","8/26/20","8/27/20","8/28/20","8/29/20","8/30/20","8/31/20","9/1/20","9/2/20","9/3/20","9/4/20","9/5/20","9/6/20","9/7/20","9/8/20","9/9/20","9/10/20","9/11/20","9/12/20","9/13/20","9/14/20","9/15/20","9/16/20","9/17/20","9/18/20","9/19/20","9/20/20","9/21/20","9/22/20","9/23/20","9/24/20","9/25/20","9/26/20","9/27/20","9/28/20","9/29/20","9/30/20","10/1/20","10/2/20","10/3/20","10/4/20","10/5/20","10/6/20","10/7/20","10/8/20","10/9/20","10/10/20","10/11/20","10/12/20","10/13/20","10/14/20","10/15/20","10/16/20","10/17/20","10/18/20","10/19/20","10/20/20","10/21/20","10/22/20","10/23/20","10/24/20","10/25/20","10/26/20","10/27/20","10/28/20","10/29/20","10/30/20","10/31/20","11/1/20","11/2/20","11/3/20","11/4/20","11/5/20","11/6/20","11/7/20","11/8/20","11/9/20","11/10/20","11/11/20","11/12/20","11/13/20","11/14/20","11/15/20","11/16/20","11/17/20","11/18/20","11/19/20","11/20/20","11/21/20","11/22/20","11/23/20","11/24/20","11/25/20","11/26/20","11/27/20","11/28/20","11/29/20","11/30/20","12/1/20"]

fc = open('pays.csv', 'r')
pays = fc.readline()
pays = pays.strip('\n') 

fp = open('population.csv', 'r')
population = fp.readline()
population = population.strip('\n')
population = float(population)
population = int(population)
print(population)





fc.close()

print(len(date))





"""Création des graphiques matplotlib:"""
"""
figure1= plt.figure(1)
plt.subplot(2,1,1)
plt.plot(date, confirmed[pays],'b' ,linewidth=0.8,label = 'Infectés')
plt.plot(date, death[pays], 'y',linewidth=0.8,label = 'Morts')
plt.plot(date, recovered[pays][:-5],'r', linewidth=0.8,label = 'Recovered')
ax = plt.gca()
plt.legend(loc = 'upper left')
ax.set_ylabel("population infectée")
ax.set_xlabel("date")
ax.xaxis.set_major_locator(plt.MaxNLocator(8))
plt.title(label=pays)
figure1.autofmt_xdate()
plt.xlim(date[0], date[-1])
plt.grid(b=True, which='Major', axis='both')




plt.subplot(2,1,2)
plt.plot(date, death[pays], 'y',linewidth=0.8,label = 'Morts')
plt.plot(date, recovered[pays],'r', linewidth=0.8,label = 'recovered')

ax = plt.gca()
plt.legend(loc = 'upper left')
ax.set_ylabel("population infectée")
ax.set_xlabel("date")
ax.xaxis.set_major_locator(plt.MaxNLocator(8))
plt.title(label=pays)
figure3.autofmt_xdate()
plt.xlim(date[0], date[-1])
plt.grid(b=True, which='Major', axis='both')

"""


def truncate(f, n):
    '''Truncates/pads a float f to n decimal places without rounding'''
    s = '%.12f' % f
    i, p, d = s.partition('.')
    return '.'.join([i, (d+'0'*n)[:n]])


nbf = 7/3
print(nbf)
retour = truncate(nbf, 4)
print(type(retour))

ligne1 = "ddd" + pays 
str(population)

fig2=plt.figure(3)
plt.text(0.1,0.9,population)
plt.text(0.1,0.83,'cakakas')
plt.axis('off')

plt.show()