data <- c(10, 15, 20, 25)
# Create a bar chart
barplot(data, names.arg = c("Category A", "Category B", "Category C",
                            "Category D"),
        main = "Bar Chart Example", xlab = "Category", ylab = "Value",
        col = c("pink", "orange", "green", "yellow"))

data <- c(15, 25, 25, 35)
# Create a pie chart
pie(data, labels = c("Category A", "Category B", "Category C",
                     "Category D"),
    main = "Pie Chart Example",
    col = c("pink", "orange", "green", "yellow"))



install.packages("ggplot2")
library(ggplot2)
data <- data.frame(
  Category = c("A", "B", "C", "D"),
  Value = c(10, 15, 20, 25)
)
ggplot(data, aes(x = Category, y = Value)) +
  geom_bar(stat = "identity", fill = "pink") +
  labs(title = "Bar Chart Example", x = "Category", y = "Value")
