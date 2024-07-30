import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
import seaborn as sns

# Reading the data from the csv file
data = pd.read_csv("weatherHistory.csv")

# Handling missing data
data.fillna(method='ffill', inplace=True)

# Handling duplicates
data.drop_duplicates(inplace=True)

# Numerical features for prediction
features = data[['Temperature (C)', 'Apparent Temperature (C)', 
                'Humidity', 'Wind Speed (km/h)', 
                'Wind Bearing (degrees)', 
                'Visibility (km)', 'Pressure (millibars)']]

target = data['Summary']

# Scaling the features
scaler = StandardScaler()
features_scaled = scaler.fit_transform(features)

X_train, X_test, y_train, y_test = train_test_split(features_scaled, target, test_size=0.2, random_state=42)

models = {
    'Decision Tree': DecisionTreeClassifier(),
    'Random Forest': RandomForestClassifier(n_estimators=100, random_state=0),
    'Support Vector Machine': SVC(kernel='linear')  # Using linear kernel
}

for name, model in models.items():
    print(f"Training {name}...")
    model.fit(X_train, y_train)
    print(f"{name} trained.")
    y_pred = model.predict(X_test)
    print(f"Predictions made for {name}.")
    print(f"Model: {name}")
    print("Accuracy:", accuracy_score(y_test, y_pred))
    print("Report:", classification_report(y_test, y_pred))
    print("\n")

# Plotting confusion matrix for the Random Forest model
rf_model = models['Random Forest']
y_pred_rf = rf_model.predict(X_test)
conf_matrix = confusion_matrix(y_test, y_pred_rf)

plt.figure(figsize=(10, 6))
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues')
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix for Random Forest Model')
plt.show()