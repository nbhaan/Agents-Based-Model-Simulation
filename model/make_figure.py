# make_figure.py
#
# written by: Niels Haan.

import sys
import pandas as pd
from matplotlib.figure import Figure
from matplotlib.backends.backend_agg import FigureCanvasAgg
from matplotlib import style

def plot_all(df, ax, column):
	row_length = int(len(df[column])/3)
	ax.plot(df.index[0:row_length], df[column][0:row_length], label='creative')
	ax.plot(df.index[0:row_length], df[column][row_length:2*row_length], label='normal')
	ax.plot(df.index[0:row_length], df[column][2*row_length:3*row_length], label='routinized')

def plot_ratio(df, ax):
	ax.plot(df['performance'], label='performance')
	ax.plot(df['costs'], label='costs')
	
def plot_jobs(df, ax):
	ax.plot(df['substitutable'], label='Substitutable')
	ax.plot(df['fired'], label='Fired')

def plot_machine_perf(df, ax):
	ax.plot(df['machinePerf'], label='machine performance')

def create_png(df, merge, plot, name, xlabel, ylabel, title):
	fig = Figure()
	ax = fig.subplots()

	if not merge:
		if plot == 'ratio':
			plot_ratio(df, ax)
		elif plot == 'jobs':
			plot_jobs(df, ax)
		elif plot == 'machine':
			plot_machine_perf(df, ax)
	else:
		plot_all(df, ax, plot)

	ax.set_xlabel(xlabel)
	ax.set_ylabel(ylabel)
	ax.set_title(title)
	ax.legend(loc='best')
	canvas = FigureCanvasAgg(fig)
	canvas.print_figure(name + ".png", dpi=120)
	print(name + ".png" + " created.")

def make_figures(file):
	df = pd.read_csv(file, header=None, delimiter=';')
	df.columns = ['time', 'performance', 'costs', 'substitutable', 'fired', 'machinePerf']
	
	row_length = int(len(df)/3)
	if (df['time'][0] == df['time'][row_length]):
		create_png(df, True, 'performance', file[:-4] + '_all_performance', 'Time (Number of Iterations)', 'Average Performance', 'Average Performance over Time')
		create_png(df, True, 'costs', file[:-4] + '_all_costs', 'Time (Number of Iterations)', 'Average Costs', 'Average Costs over Time')
		create_png(df, True, 'machinePerf', file[:-4] + '_all_machine_perf', 'Time (Number of Iterations)', 'Average Machine Performance ', 'Average Machine Performance over Time')
	else:
		create_png(df, False, 'ratio', file[:-4] + '_ratio', 'Time (Number of Iterations)', 'Average Performance and Costs', 'Average Performance and Costs over Time')
		create_png(df, False, 'jobs', file[:-4] + '_jobs', 'Time (Number of Iterations)', 'Average Jobs', 'Average Jobs over Time')
		create_png(df, False, 'machine', file[:-4] + '_machine_perf', 'Time (Number of Iterations)', 'Average Machine Performance ', 'Average Machine Performance over Time')

if __name__ == "__main__":
	if len(sys.argv) == 2:
		style.use('ggplot')
		make_figures(sys.argv[1])
		print("Done.")
	else:
		print("Usage: python3 make_figure.py input-file")