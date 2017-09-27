import sklearn.linear_model

gdp_per_capita = [[12240], [27195], [37675], [50962], [55805]]
life_satisfication = [[4.9], [5.8], [6.5], [7.3], [7.2]]

lin_reg_model = sklearn.linear_model.LinearRegression()
lin_reg_model.fit(gdp_per_capita, life_satisfication)
X_new = [[22587]]
print(lin_reg_model.predict(X_new))
