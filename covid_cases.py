# -*- coding: utf-8 -*-
"""
Created on Tue Dec  1 17:36:29 2020

@author: guill
"""

import pandas as pd

def covid_cases(pays):
    
    confirmed = pd.read_csv("confirmed_covid-19.csv")
    confirmed = confirmed.drop(['Province/State','Lat','Long'], axis=1)
    confirmed = confirmed.groupby(confirmed['Country/Region']).aggregate('sum')
    confirmed = confirmed.T
    
    death = pd.read_csv("death_covid-19.csv")
    death = death.drop(['Province/State','Lat','Long'], axis=1)
    death = death.groupby(death['Country/Region']).aggregate('sum')
    death = death.T
    
    

    fd = open('cases.csv', 'w')
    for i in range(len(confirmed[pays][:])):
        print(confirmed[pays][i], file=fd)
    fd.close()
    
    fi = open('death.csv', 'w')
    for i in range(len(death[pays][:])):
        print(death[pays][i], file=fi)
    
covid_cases('  ')
