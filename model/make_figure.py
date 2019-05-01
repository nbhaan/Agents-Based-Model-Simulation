# make_figure.py
#
# written by: Niels Haan.

import sys
import pandas as pd
from matplotlib.figure import Figure
from matplotlib.backends.backend_agg import FigureCanvasAgg

def plot_ratio(df, ax):
	ax.plot(df['ratio'], label='Performance')

def plot_jobs(df, ax, cols):
	ax.plot(df[cols[0]], label='Substitutable')
	ax.plot(df[cols[1]], label='Fired')

def create_png(df, cols, name, xlabel, ylabel, title):
	fig = Figure()
	ax = fig.subplots()
	if cols == 'ratio':
		plot_ratio(df, ax)
	else:
		plot_jobs(df, ax, cols)
	ax.set_xlabel(xlabel)
	ax.set_ylabel(ylabel)
	ax.set_title(title)
	ax.legend(loc='best')
	canvas = FigureCanvasAgg(fig)
	canvas.print_figure(name + ".png", dpi=60)
	print(name + ".png" + " created.")

def make_figures(file):
	df = pd.read_csv(file, header=None, delimiter=';')
	df.columns = ['time', 'performance', 'costs', 'ratio', 'substitutable', 'fired']
	create_png(df, 'ratio', file[:-4] + '_perf', 'Time (Number of Iterations)', 'Average Performance', 'Average Performance over Time')
	create_png(df, ('substitutable', 'fired'), file[:-4] + '_jobs', 'Time (Number of Iterations)', 'Average Jobs', 'Average Jobs over Time')

if __name__ == "__main__":
	if len(sys.argv) == 2:
		make_figures(sys.argv[1])
		print("Done.")
	else:
		print("Usage: python3 make_figure.py input-file")