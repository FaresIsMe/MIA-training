import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

"""Task 4.1
    Load the dataset as a dataframe.

    Clean and preprocess the data (handle missing values,
    remove duplicates and handle incorrect data).

    Plot temperature over time.
    Create a histogram of temperature distribution.

    Plot a scatter plot of temperature vs. humidity.

    Generate a correlation heatmap of the dataset and explain the
    output in a markdown cell.

Dataset Link Weather Dataset

"""

#Reading the data from a CSV file
data_file = pd.read_csv("Weather Dataset.csv")

#Handling duplicates
data_file.drop_duplicates(inplace=True)

#Handling missing data
data_file.fillna(method='ffill', inplace=True)

#handling incorrect data
data_file = data_file[data_file["Temperature (C)"] >= -30 & data_file["Humidity"] >= 0]

constant_temp = data_file['Temperature (C)'].value_counts().idxmax()
constant_periods = data_file[data_file['Temperature (C)'] == constant_temp]

data_file = data_file[data_file['Temperature (C)'] != constant_temp]

#PLotting temperature over time
plt.figure(figsize=(16, 10))
plt.plot(data_file["Formatted Date"], data_file["Temperature (C)"])
plt.title("Temperature over Time")
plt.ylabel("Temperature")
plt.xlabel("Time")
plt.xticks(rotation=45)
plt.gca().xaxis.set_major_locator(plt.MaxNLocator(nbins=10))
plt.show()

#Histogram of temperatures
plt.hist(data_file["Temperature (C)"], bins=20)
plt.show()

#Scatter plot of temperature vs. humidity

plt.scatter(data_file["Temperature (C)"], data_file["Humidity (%)"])
plt.title("Temperature vs. Humidity")
plt.xlabel("Temperature")
plt.ylabel("Humidity")
plt.show()

#Correlation heatmap
plt.figure(figsize=(10, 5))
corr = data_file.corr()
sns.heatmap(corr, annot=True)
cmap = 'coolwarm'
plt.title('Correlation Heatmap')

plt.show()

"""
"""
