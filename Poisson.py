import numpy as np
import pandas as pd
from scipy.stats import poisson
import matplotlib.pyplot as plt
def myBinPoisson(lam=10.0, size=None, p=0.5):
    # Return random vector
    k = np.random.randint(low = 0, high = 10, size = size)
    outcome2=[] 
    for i in range(0,size-1):
        px = lam**k[i]/(np.math.factorial(k[i]))*np.exp(-lam)
        outcome2.append(px)
    return outcome2

# Create an empty horizontal vector
distributions = np.empty((0, 30))

df = pd.DataFrame(columns=range(30))
for lam in range(12):
    sample1 = myBinPoisson(lam,100000)
    # Add rows to horizontal vector
    empirical_pmf = np.zeros(30)
    for value in range(30):
        empirical_pmf[value] = 0.00001*sample1.count(value)
    df = df.append(pd.Series(empirical_pmf), ignore_index=True)

# Write output file
pd.DataFrame(df).to_csv("challenge-Poisson.csv", float_format='%.5f')