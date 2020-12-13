# -*- coding: utf-8 -*-
"""
Created on Tue Dec  1 17:36:29 2020
@author: guill
"""

import pandas as pd
import numpy as np
import os

def covid_cases(pays):
    
    confirmed = pd.read_csv("confirmed_covid-19.csv")
    confirmed = confirmed.drop(['Province/State','Lat','Long'], axis=1)
    confirmed = confirmed.groupby(confirmed['Country/Region']).aggregate('sum')
    confirmed = confirmed.T
    
    death = pd.read_csv("death_covid-19.csv")
    death = death.drop(['Province/State','Lat','Long'], axis=1)
    death = death.groupby(death['Country/Region']).aggregate('sum')
    death = death.T

    recovered  = pd.read_csv("death_covid-19.csv")
    recovered = recovered.drop(['Province/State','Lat','Long'], axis=1)
    recovered = recovered.groupby(recovered['Country/Region']).aggregate('sum')
    recovered = recovered.T 
    

    fc = open('cases.csv', 'w')
    for i in range(len(confirmed[pays][:])):
        print(confirmed[pays][i], file=fc)
    fc.close()
    
    
    
    fd = open('death.csv', 'w')
    for i in range(len(death[pays][:])):
        print(death[pays][i], file=fd)
    fd.close()
    
    fr = open('recovered.csv', 'w')
    for i in range(len(death[pays][:])):
        print(recovered[pays][i], file=fr)
    fr.close()
    
    



    population = pd.read_csv("population_mondiale.csv", usecols = [0,63], index_col = 0 )
    population=population.T
    population.header=0
    population = population[pays].values
    
    
    fpop = open('population.csv', 'w')
    print(population[0], file=fpop)
    fpop.close()
    
    
    fc = open('pays.csv', 'w')
    print(pays, file=fc)
    fc.close()

    




pay = open('donneur_pays.csv', 'r')
pays = pay.readline()



covid_cases(pays)







