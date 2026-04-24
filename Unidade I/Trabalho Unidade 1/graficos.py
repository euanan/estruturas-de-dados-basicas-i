import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_csv('dados.csv')

plt.figure(figsize=(10, 6))
for alg in df['Algoritmo'].unique():
    subset = df[df['Algoritmo'] == alg]
    plt.plot(subset['N'], subset['Tempo'], marker='o', label=alg)

plt.title('Análise Empírica: Tempo vs Tamanho da Entrada')
plt.xlabel('N')
plt.ylabel('Tempo (s)')
plt.legend()
plt.grid(True)
plt.savefig('grafico_resultados.png')
plt.show()