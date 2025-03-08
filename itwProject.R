df_iris = read.csv("~/Downloads/iris.data.csv")
print(head(df_iris))

mode <- function(x){
  freq = table(x)
  modes = names(freq[which(freq==max(freq))])
  return(modes)
}


data_mode = data.frame(
  X5.1 = mode(df_iris$X5.1),
  X3.5 = mode(df_iris$X3.5),
  X1.4 = mode(df_iris$X1.4),
  X0.2 = mode(df_iris$X0.2)
)
rownames(data_mode) = "Mode"

data_sd = data.frame(
  X5.1 = sd(df_iris$X5.1),
  X3.5 = sd(df_iris$X3.5),
  X1.4 = sd(df_iris$X1.4),
  X0.2 = sd(df_iris$X0.2)
)
rownames(data_sd) = "SD"
print(summary(df_iris))
print(data_mode)
print(data_sd)

colnames(df_iris)[colnames(df_iris) == "Iris.setosa"] <- "Species"
print(head(df_iris))
tab_iris <- table(df_iris$Species)
print(tab_iris)
barplot(tab_iris, 
        col = "pink", 
        main = "Comparison of Frequency of Species", 
        xlab = "Species", 
        ylab = "Number of Species")


boxplot(X5.1 ~ Species, data = df_iris, 
        main = "Distribution of Sepal Length by Species", 
        xlab = "Species", 
        ylab = "Sepal Length", 
        col = c("lightblue", "lightgreen", "lightpink"))


df_iris$Species_num <- as.numeric(factor(df_iris$Species))
corr <- cor(df_iris$X3.5, df_iris$Species_num)
cat("Correlation between Sepal Width and Species is : ", corr)

plot(df_iris$Species_numeric, df_iris$X3.5,
     main = "Sepal Width vs Species",
     xlab = "Species (Numeric)", ylab = "Sepal Width",
     col = c("lightblue", "lightgreen", "lightpink")[df_iris$Species_numeric],
     pch = 19)


