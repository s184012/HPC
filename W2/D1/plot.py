import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

def plot_runs(dfs: list[pd.DataFrame], dims: tuple[int, int]):
    if len(dfs) != dims[0]*dims[1]:
        print("")
        return 