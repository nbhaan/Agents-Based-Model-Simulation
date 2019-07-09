# Agents-Based-Model-Simulation

## Prerequisites
	
These steps work for Mac OS X/Linux, for Windows other steps are probably necessary.
	
Make sure Brew is installed, follow instructions on:
```
https://brew.sh
```
That you install gcc using Brew with the following command:
```
brew install gcc
```

## Instructions

### Step 1
You can navigate to the folder where you extracted the files using the 'change directory' command in terminal:

```
cd
```

### Step 2
Once you are in the correct folder, you can use the command:

```
make
```

It will automatically compile the source files using the Makefile. And it will create an executable.

### Step 3
To run the executable use the following command:
```
./simulator input-file [out-file]
```

The input-file is obligatory, it contains all the parameters in this order:
```
- time (the length of the time period, our case this is 1000)
- number of humans 
- number of firms 
- introduction machine
- cost performance dependency; how much costs is defined by performance
- type of work (can be: creative, normal, routinized)
- costs related to the machine
- initial performance of the machine
- learning rate of the machine
- substitutable treshold
- job variety
- learning rate decay of the machine
```

You can use the 1.in file to set your input parameters or create an input file yourself.

The out file is not obligatory, you can use this argument if you would like to specify a name for output file. If no name is specified it will be the same name as the input file with a .out extension.

Note that once you specify for a 1000 simulations, it will take some time for the program to terminate.

### Step 4
Once the program is finished your output file will be created in the same folder as the input-file. The columns in your outfile will look like this:

```
time; avg performance; avg costs; avg number of people who are substitutable; avg number of people fired; avg machine performance
```

### Step 5
A figure can be created using a python script. For this script you need matplotlib and pandas to be installed. Assuming you already have python3. Otherwise you need to install this, MAC comes with preinstalled with version 2 of python. However, it probably won't work with python 2 (I didn't test for this). To install matplotlib and pandas you can use the following commands:

```
pip3 install matplotlib
```
```
pip3 install pandas
```


### Step 6
When installation is complete, use the following command to create the figures for your data:

```
python3 make_figure.py out-file
```

The out-file is the file you created using the C++ program.

### Step 7
The .png files which will be created can be found in the same folder as the out-file.




