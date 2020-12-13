#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 28 14:52:13 2020

@author: leodurst
"""

from matplotlib import pyplot as plt
import numpy as np
import pandas as pd


"""
Import des valeurs simulées calculées par le programme 'fonction_simulation_virus.c'
depuis un fichier csv (rempli automatiquement par le programme).
"""

data_virus = pd.read_csv("/Users/leodurst/Documents/EPFL Ba3 C/Projet_C/dataSimulVirus_c.csv",
                         sep = ';', usecols = [1,2,3,4,5], index_col = 0,
                         )

"""
Initialisation du temps (nombre d'itération pour
laquelle la simulation a tourné) à la variable 'time_virus'.
"""

time_vir = open("/Users/leodurst/Documents/EPFL Ba3 C/Projet_C/time_virus.txt", "r")

time_viru = time_vir.readlines(0)

time_virus = int(time_viru[0])

"""
Affectation des valeurs récupérées depuis le fichier
csv dans des listes correspondant aux différents cas;
Respectivment : Sains, Contaminés, Infectés, Rétablis et Morts.

Dans cette simulation, la population totale (morts compris)
reste constante au court du temps et les données représentent
un rapport à la population totale (1 [ou 100%]). Cela implique
que la somme des valeurs des chaques tableaux à chaque instant
t doit être égale à 1 et que les valeurs se situent entre 0 et 1!
"""

Sain = []
Contam = []
Infect = []
Retab = []
Mort = []



for i in range(time_virus):
    Sain.append(data_virus["Sains"][i])
    Contam.append(data_virus["Contamines"][i])
    Infect.append(data_virus["Infectes"][i])
    Retab.append(data_virus["Retablis"][i])
    Mort.append(data_virus["Morts"][i])

time = np.arange(time_virus)

plt.figure(1)

plt.plot(time, Sain,'b',label="Sains", linewidth=0.7)
plt.plot(time, Contam,'y',label="Contamniés", linewidth=0.7)
plt.plot(time, Infect, 'g',label="Infectés", linewidth=0.7)
plt.plot(time, Retab, 'r',label="Rétablis", linewidth=0.7)
plt.plot(time, Mort,'m',label="Morts", linewidth=0.7)
plt.title("Simulation virus")
ax = plt.gca()
plt.legend(loc = 'upper left')
ax.set_ylabel("taux de la population concernée")
ax.set_xlabel("nombre de jours")
plt.grid(b=True, which='Major', axis='y')
plt.xlim(time[0], time[-1])


plt.savefig('fig_1.png')



plt.figure(2)
plt.plot(time, Contam,'y',label="Contamniés", linewidth=0.7)
plt.plot(time, Infect, 'g',label="Infectés", linewidth=0.7)
plt.plot(time, Retab, 'r',label="Rétablis", linewidth=0.7)
plt.plot(time, Mort,'m',label="Morts", linewidth=0.7)
plt.title("Simulation virus - focus sur la population touchée")
ax = plt.gca()
plt.legend(loc = 'upper left')
ax.set_ylabel("taux de la population concernée")
ax.set_xlabel("nombre de jours")
plt.grid(b=True, which='Major', axis='y')
plt.xlim(time[0], time[-1])

plt.savefig('fig_2.png')



plt.show()

