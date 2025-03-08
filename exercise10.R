countries <- c("USA", "China", "Japan", "Germany", "India", 
               "UK", "France", "Brazil", "Italy", "Canada")
gdp <- c(21427, 14342, 5081, 4357, 2875, 2825, 2775, 1886, 1835, 1770)


# Create the barplot
barplot(
  gdp,
  names.arg = countries,
  col = c("steelblue","red"),
  main = "Top 10 Countries by GDP in 2020",
  xlab = "GDP (in billions USD)",
  ylab = "Country",
)

countries <- c("USA", "Brazil", "India", "Russia", "South Africa")
cases <- c(5720000, 3340000, 3070000, 1000000, 579000)
barplot(
  cases,
  names.arg = countries,
  col = "red",
  main = "COVID-19 Cases by Country",
  xlab = "Number of Cases",
  horiz = TRUE,
  las = 1
)

age_groups <- c("0-14", "15-29", "30-44", "45-59", "60+")
percentages <- c(25, 30, 20, 15, 10)
pie(
  percentages,
  labels = paste(age_groups, percentages, "%"),
  col = c("green","pink"),
  main = "Percentage Distribution of Age Groups"
)


products <- c("Product A", "Product B", "Product C", "Product D", "Product E")
sales <- c(350, 400, 200, 300, 450)

barplot(
  sales,
  names.arg = products,
  col = "skyblue",
  main = "Sales Performance of Products",
  xlab = "Products",
  ylab = "Sales",
  ylim = c(0, max(sales) + 50),
  las = 1
)

pie(
  sales,
  labels = paste(products, sales),
  col = rainbow(length(products)),
  main = "Sales Distribution by Products"
)
